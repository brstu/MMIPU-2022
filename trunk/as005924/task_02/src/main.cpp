#include <iostream>
#include <cmath>
#include <iomanip>


// абстрактный класс моделей вычисления
class TemperatureCalculator
{
public:
    
    // вычислениt сделующего значения температуры
    virtual double CalculateNextTemperature(double input_warm) = 0;
protected:
    TemperatureCalculator(){};
};


// класс линейной модели
class LinearCalculator: public TemperatureCalculator 
{
private:
    double _a, _b;
    double _current_temperature;
public:
    
    // конструктор
    LinearCalculator(double current_temperature, double a, double b)
    {
        _a = a;
        _b = b;
        _current_temperature = current_temperature;
    }

    // вычисление температуры
    virtual double CalculateNextTemperature(double input_warm) 
    {
        _current_temperature = _a * _current_temperature + _b * input_warm;
        return _current_temperature;
    }
};


// класс нелинейной модели
class NonlinearCalculator: public TemperatureCalculator
{
private:
    double _a, _b, _c, _d;
    double _current_temperature, _previous_temperature;
public:
    
    // конструктор
    NonlinearCalculator(double current_temperature, double a, double b, double c, double d)  // current_temperature - екущая температура, a,b,c,d - параметры
    {
        _a = a;
        _b = b;
        _c = c;
        _d = d;
        _current_temperature = current_temperature;
        _previous_temperature = 0.0;
    }

    // вычисление температуры
    virtual double CalculateNextTemperature(double input_warm) 
    {
        double buffer_temperature = _current_temperature;
        _current_temperature = _a * _current_temperature - _b * _previous_temperature * _previous_temperature + _c * input_warm + _d * sin(input_warm);
        _previous_temperature = buffer_temperature;
        return _current_temperature;
    }
};


// абстрактный класс элементов системы
class Element
{
protected:
    Element* _next_element = nullptr;
public:
    
    // вычисление значения
    virtual double Calculate(double) = 0;

    // получение внутреннего значения
    virtual double GetValue() = 0;
};


// класс элемента обратной связи
class Feedback: public Element
{
private:
    double _expected_value;
    double _e = 0;
public:
    
    // конструктор
    Feedback(Element* next_element, double expected_value) // next_element - следующий элемент схемы, expected_value - ожидаемое значение
    {
        _expected_value = expected_value;
        _next_element = next_element;
    }

    // вычисление значения
    double Calculate(double prev_value) // prev_value - значение предыдущего элемента
    {
        double result = _expected_value - prev_value;
        _e = result;
        if (_next_element != nullptr) {
            result = _next_element->Calculate(result);
        }
        return result;
    }

    // получение внутреннего значения
    double GetValue()
    {
        return _e;
    }

    // деструктор
    ~Feedback()
    {
        delete _next_element;
    }
};


// класс регулятор
class Regulator: public Element
{
private:
    double _T, _T0, _TD, _K;
    double _u = 0;
    double _e2 = 0, _e1 = 0;
public:
    
    // конструктор
    Regulator(Element* next_element, double T, double T0, double TD, double K) //  next_element - следующий элемент цепи, T, T0, TD, K - параметры
    {
        _T = T;
        _T0 = T0;
        _TD = TD;
        _K = K;
        _next_element = next_element;
    }

    // вычисление значения
    double Calculate(double prev_value) // prev_value - значение предыдущего элемента
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

    // получение внутреннего значения
    double GetValue()
    {
        return _u;
    }

    // деструктор
    ~Regulator()
    {
        delete _next_element;
    }
};


// класс компонента контролируемого объекта
class ControlObject: public Element
{
private:    
    TemperatureCalculator* _temperature_calculator;
    double _temperature = 0;
public:
    
    // конструктор
    ControlObject(Element* next_element, TemperatureCalculator* temperature_calculator) // next_element - следующий элемент цепи, temperature_calculator - способ вычисления температуры 
    {
        _next_element = next_element;
        _temperature_calculator = temperature_calculator;
    }

    // вычисление значения
    double Calculate(double prev_value) // prev_value - значение предыдущего элемента
    {
        double result = _temperature_calculator->CalculateNextTemperature(prev_value);
        _temperature = result;
        if (_next_element != nullptr) {
            result = _next_element->Calculate(result);
        }
        return result;
    }

    // получение внутреннего значения
    double GetValue()
    {
        return _temperature;
    }

    // деструктор
    ~ControlObject()
    {
        delete _next_element;
        delete _temperature_calculator;
    }
};


int main()
{    
    TemperatureCalculator* temperature_calculator;
    double a, b, current_temperature;
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
            temperature_calculator = new LinearCalculator(current_temperature, a, b);
            break;
        }
        case 1:
        {
            double c, d;
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
            temperature_calculator = new NonlinearCalculator(current_temperature, a, b, c, d);
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
