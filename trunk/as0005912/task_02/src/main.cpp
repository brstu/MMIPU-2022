#include <iostream>
#include <cmath>
#include <iomanip>
/**
* @mainpage
* @brief ПИД-регулятор
* @author Качан Дмитрий
*/


/**
* @class TemperatureCalculator
* @brief Абстрактный класс моделей вычисления
*/
class TemperatureCalculator
{
public:
    /**
    * @details Абстрактный метод для вычисления сделующего значения температуры
    */
    virtual double CalculateNextTemperature(double input_warm) = 0;
protected:
    TemperatureCalculator(){};
};


/**
* @class LinearTemperatureCalculator
* @brief Класс линейной модели
* @details Является подклассом TemperatureCalculator
*/
class LinearTemperatureCalculator: public TemperatureCalculator 
{
private:
    double _a, _b;
    double _current_temperature;
public:
    /**
     * @brief    Construct a new Linear Temperature Calculator object
     * 
     * @param    current_temperature Текущая температура
     * @param    a                   Параметр А
     * @param    b                   Параметр В
     */
    LinearTemperatureCalculator(double current_temperature, double a, double b)
    {
        _a = a;
        _b = b;
        _current_temperature = current_temperature;
    }

    /**
     * @brief    Метод вычисления температуры
     * 
     * @param    input_warm          Входное тепло
     * @return   double 
     */
    virtual double CalculateNextTemperature(double input_warm) 
    {
        _current_temperature = _a * _current_temperature + _b * input_warm;
        return _current_temperature;
    }
};


/**
* @class NonlinearTemperatureCalculator
* @brief Класс нелинейной модели
* @details Является подклассом TemperatureCalculator
*/
class NonlinearTemperatureCalculator: public TemperatureCalculator
{
private:
    double _a, _b, _c, _d;
    double _current_temperature, _previous_temperature;
public:
    /**
     * @brief    Construct a new Nonlinear Temperature Calculator object
     * 
     * @param    current_temperature Текущая температура
     * @param    a                   Параметр А
     * @param    b                   Параметр В
     * @param    c                   Параметр С
     * @param    d                   параметр D
     */
    NonlinearTemperatureCalculator(double current_temperature, double a, double b, double c, double d) 
    {
        _a = a;
        _b = b;
        _c = c;
        _d = d;
        _current_temperature = current_temperature;
        _previous_temperature = 0.0;
    }

    /**
     * @brief    Метод вычисления температуры
     * 
     * @param    input_warm          Входное тепло
     * @return   double 
     */
    virtual double CalculateNextTemperature(double input_warm) 
    {
        double buffer_temperature = _current_temperature;
        _current_temperature = _a * _current_temperature - _b * _previous_temperature * _previous_temperature + _c * input_warm + _d * sin(input_warm);
        _previous_temperature = buffer_temperature;
        return _current_temperature;
    }
};


/**
* @class Element
* @brief Абстрактный класс элементов системы
*/
class Element
{
protected:
    Element* _next_element = nullptr;
public:
    /**
     * @brief    Абстрактный метод для вычисления значения
     * 
     * @return   double 
     */
    virtual double Calculate(double) = 0;

    /**
     * @brief    Абстрактный метод для получения внутреннего значения
     * 
     * @return   double 
     */
    virtual double GetValue() = 0;
};


/**
* @class Feedback
* @brief Класс элемента обратной связи
* @details Является подклассом Element
*/
class Feedback: public Element
{
private:
    double _expected_value;
    double _e = 0;
public:
    /**
     * @brief    Construct a new Feedback object
     * 
     * @param    next_element        Следующий элемент схемы
     * @param    expected_value      Ожидаемое значение
     */
    Feedback(Element* next_element, double expected_value)
    {
        _expected_value = expected_value;
        _next_element = next_element;
    }

    /**
     * @brief    Метод вычисления значения
     * 
     * @param    prev_value          Значение предыдущего элемента
     * @return   double 
     */
    double Calculate(double prev_value)
    {
        double result = _expected_value - prev_value;
        _e = result;
        if (_next_element != nullptr) {
            result = _next_element->Calculate(result);
        }
        return result;
    }

    /**
     * @brief    Метод получения внутреннего значения
     * 
     * @return   double 
     */
    double GetValue()
    {
        return _e;
    }

    /**
     * @brief    Destroy the Feedback object
     * 
     */
    ~Feedback()
    {
        delete _next_element;
    }
};


/**
* @class Regulator
* @brief Класс элемента регулятора
* @details Является подклассом Element
*/
class Regulator: public Element
{
private:
    double _T, _T0, _TD, _K;
    double _u = 0;
    double _e2 = 0, _e1 = 0;
public:
    /**
     * @brief    Construct a new Regulator object
     * 
     * @param    next_element        Следующий элемент цепи
     * @param    T                   Параметр Т
     * @param    T0                  Параметр Т0
     * @param    TD                  Параметр ТD
     * @param    K                   Параметр K
     */
    Regulator(Element* next_element, double T, double T0, double TD, double K)
    {
        _T = T;
        _T0 = T0;
        _TD = TD;
        _K = K;
        _next_element = next_element;
    }

    /**
     * @brief    Метод вычисления значения
     * 
     * @param    prev_value          Значение предыдущего элемента
     * @return   double 
     */
    double Calculate(double prev_value)
    {
        double q0 = _K * (1 + _TD / _T0);
        double q1 = -_K * (1 + 2 * _TD / _T0 - _T0 / _T);
        double q2 = _K * _TD / _T0;
        _u += q0 * prev_value + q1 * _e1 + q2 * _e2;
        double result = _u;
        if (_next_element != nullptr) {
            result = _next_element->Calculate(result);
        }
        _e2 = _e1;
        _e1 = prev_value;
        return result;
    }

    /**
     * @brief    Метод получения внутреннего значения
     * 
     * @return   double 
     */
    double GetValue()
    {
        return _u;
    }

    /**
     * @brief    Destroy the Regulator object
     * 
     */
    ~Regulator()
    {
        delete _next_element;
    }
};


/**
* @class ControlObject
* @brief Класс компонента контролируемого объекта
* @details Является подклассом Element
*/
class ControlObject: public Element
{
private:    
    TemperatureCalculator* _temperature_calculator;
    double _temperature = 0;
public:
    /**
     * @brief    Construct a new Control Object object
     * 
     * @param    next_element        Следующий элемент цепи
     * @param    temperature_calculator Способ вычисления температуры 
     */
    ControlObject(Element* next_element, TemperatureCalculator* temperature_calculator) 
    {
        _next_element = next_element;
        _temperature_calculator = temperature_calculator;
    }

    /**
     * @brief    Метод вычисления значения
     * 
     * @param    prev_value          Значение предыдущего элемента
     * @return   double 
     */
    double Calculate(double prev_value)
    {
        double result = _temperature_calculator->CalculateNextTemperature(prev_value);
        _temperature = result;
        if (_next_element != nullptr) {
            result = _next_element->Calculate(result);
        }
        return result;
    }

    /**
     * @brief    Метод получения внутреннего значения
     * 
     * @return   double 
     */
    double GetValue()
    {
        return _temperature;
    }

    /**
     * @brief    Destroy the Control Object object
     * 
     */
    ~ControlObject()
    {
        delete _next_element;
        delete _temperature_calculator;
    }
};


int main()
{    
    TemperatureCalculator* temperature_calculator;
    double a, b, c, d, current_temperature;
    int strategy_choise;
    std::cout << "Choose calculate strategy (0 - linear, 1 - nonlinear):" << std::endl;
    std::cin >> strategy_choise;

    switch (strategy_choise) {
        case 0:
        {
            std::cout << "A: ";
            std::cin >> a;
            std::cout << "B: ";
            std::cin >> b;
            std:: cout << "Current temperature: ";
            std::cin >> current_temperature;
            temperature_calculator = new LinearTemperatureCalculator(current_temperature, a, b);
            break;
        }
        case 1:
        {
            std::cout << "A: ";
            std::cin >> a;
            std::cout << "B: ";
            std::cin >> b;
            std::cout << "C: ";
            std::cin >> c;
            std::cout << "D: ";
            std::cin >> d;
            std:: cout << "Current temperature: ";
            std::cin >> current_temperature;
            temperature_calculator = new NonlinearTemperatureCalculator(current_temperature, a, b, c, d);
            break;
        }
        default:
            break;
    }

    double expected_temperature;
    std::cout << "Expected temperature: ";
    std::cin >> expected_temperature;
    int iterations_number;
    std::cout << "Iterations count: ";
    std::cin >> iterations_number;
    
    Element* control_object = new ControlObject(nullptr, temperature_calculator);
    Element* regulator = new Regulator(control_object, 10, 10, 50, 0.1);
    Element* feedback = new Feedback(regulator, expected_temperature);
    
    double result = current_temperature;
    std::cout.precision(12);
    for (int i = 0; i < iterations_number; i++) {
        result = feedback->Calculate(result);
        std::cout << feedback->GetValue() << ' ' << regulator->GetValue() << ' ' << result << std::endl;
    }
    return 0;
}

