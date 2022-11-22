#include <iostream>
#include <cmath>
#include <fstream>
/**
* \mainpage
* \brief Лабораторная работа 2. ПИД-регулятор
* \author Горчинский Никита Сергеевич. АС-59
*/

/**
* \class AbstractModel
* \brief Класс, который необходим классам, рассчитывающим линейную и нелинейную модель
* 
* Абстрактный класс, который предоставляет виртуальную функцию уравнения calculateModel 
* и от которого наследуются классы LinearModel и NonLinearModel
*/
class AbstractModel
{
public:
    /**
    * \brief Виртуальная функция, переопределенная в дочерних классах LinearModel и NonLinearModel
    * 
    * Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели.
    * \param yCurrent Температура помещения
    * \param inputWarm Входящее тепло
    */
    virtual double calculateModel(double yCurrent, double inputWarm) = 0;
};
/**
* \class LinearModel
* \brief Класс, который служит для реализации линейной модели
* 
* Дочерний класс от AbstractModel, который реализует линейную модель через переопределённую функцию calculateModel
*/
class LinearModel : public AbstractModel
{
private:
    double a_, ///< Коэффициент
        b_, ///< Коэффициент
        yNext_; ///< Получаемая нами температура
public:
    LinearModel(double a, double b, double yNext)
    {
        /**
        * Конструктор LinearModel
        * 
        * Код:
        * \code
        * a_ = a;
        * b_ = b;
        * yNext_ = yNext;
        * \endcode
        */
        a_ = a;
        b_ = b;
        yNext_ = yNext;
    }
    /**
    * Переопределённый метод для рассчёта линейной модели
    * 
    * Код:
    * \code
    * yNext_ = a_ * yCurrent + b_ * inputWarm;
    * return yNext_;
    * \endcode
    */
    double calculateModel(double yCurrent, double inputWarm)
    {
        yNext_ = a_ * yCurrent + b_ * inputWarm;
        return yNext_;
    }
};
/**
* \class NonLinearModel
* \brief Класс, который служит для реализации нелинейной модели
* 
* Дочерний класс от AbstractModel, который реализует нелинейную модель через переопределённую функцию calculateModel
*/
class NonLinearModel : public AbstractModel
{
private:
    double a_, ///< Коэффициент
        b_, ///< Коэффициент
        c_, ///< Коэффициент
        d_, ///< Коэффициент
        yPrev_, ///< Предыдущая температура 
        yNext_, ///< Получаемая нами температура
        wPrev_; ///< Предыдущее тепло
public:
    NonLinearModel(double a, double b, double c, double d, double yNext)
    {
        /**
        * Конструктор NonLinearModel
        * 
        * Код:
        * \code
        * a_ = a;
        * b_ = b;
        * c_ = c;
        * d_ = d;
        * wPrev_ = 0;
        * yPrev_ = 0;
        * yNext_ = yNext;
        * \endcode
        */
        a_ = a;
        b_ = b;
        c_ = c;
        d_ = d;
        yPrev_ = 0;
        wPrev_ = 0;
        yNext_ = yNext;
    }
    /**
    * Переопределённый метод для рассчёта нелинейной модели
    * 
    * Код:
    * \code
    * yNext_ = a_ * yCurrent - b_ * pow(yPrev_, 2) + c_ * inputWarm + d_ * sin(wPrev_);
    * yPrev_ = yNext_;
    * wPrev_ = inputWarm;
    * return yNext_;
    * \endcode
    */
    double calculateModel(double yCurrent, double inputWarm)
    {
        yNext_ = a_ * yCurrent - b_ * pow(yPrev_, 2) + c_ * inputWarm + d_ * sin(wPrev_);
        yPrev_ = yCurrent;
        wPrev_ = inputWarm;
        return yNext_;
    }
};
/**
* \class Regulator
* \brief Класс регулятора
* 
* Отдельный класс, в котором мы моделируем регулятор
*/
class Regulator
{
private:
    double T_, ///< Постоянная интегрирования
        T0_, ///< Шаг для квантования
        TD_, ///< Постоянная дифференцирования
        K_, ///< Коэффициент передачи
        uk_; ///< Текущее значение управляющего воздействия
    double calculateUk(double ek, double ek1, double ek2)
    {
        /**
        * \brief Метод для рассчёта uk_
        *
        * Метод рассчёта текущего значения управляющего воздействия на объект управления
        * 
        * Код:
        * \code
        * double q0 = K_ * (1 + TD_ / T0_); 
        * double q1 = -K_ * (1 + 2 * TD_ / T0_ - T0_ / T_); 
        * double q2 = K_ * TD_ / T0_; 
        * uk_ += q0 * ek + q1 * ek1 + q2 * ek2;
        * return uk_;
        * \endcode
        */
        double q0 = K_ * (1 + TD_ / T0_); /// q0 - Параметр регулятора
        double q1 = -K_ * (1 + 2 * TD_ / T0_ - T0_ / T_); /// q1 - Параметр регулятора
        double q2 = K_ * TD_ / T0_; /// q2 - Параметр регулятора
        uk_ += q0 * ek + q1 * ek1 + q2 * ek2;
        return uk_;
    }
public:
    Regulator(double T, double T0, double TD, double K) 
    {
        /**
        * Конструктор Regulator
        * 
        * Код:
        * \code
        * T_ = T;
        * T0_ = T0;
        * TD_ = TD;
        * K_ = K;
        * uk_ = 0;
        * \endcode
        */
        T_ = T;
        T0_ = T0;
        TD_ = TD;
        K_ = K;
        uk_ = 0;
    }
    void PIDRegulatorCalculateAndWrite(double need, double start)
    {
        /**
        * \brief Метод моделирования ПИД-регулятора
        *
        * В данном методе мы моделируем ПИД-регулятор и записываем результаты в файл results.txt
        * \param need Желаемое значение
        * \param start Стартовое значение y
        * 
        * Код:
        * \code
        * std::ofstream fout;
        * fout.open("results.txt");
        * if (fout) 
        * {
        *    double ek = 0,ek1 = 0, ek2 = 0, y = start, u = 0;
        *    LinearModel* linear = new LinearModel(0.333, 0.667, 1);
        *    fout << "Линейная модель: " << std::endl;
        *    for (int i = 0; i < 50; ++i) 
        *    {
        *        ek = need - y;
        *        u = calculateUk(ek, ek1, ek2);
        *        y = linear->calculateModel(start, u);
        *        fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
        *        ek2 = ek1;
        *        ek1 = ek;
        *    }
        *    delete linear;
        *
        *    ek = 0, ek1 = 0, ek2 = 0, y = start, u = 0;
        *    fout << "Нелинейная модель: " << std::endl;
        *    NonLinearModel* nonLinear = new NonLinearModel(1, 0.0033, 0.525, 0.525, 1);
        *    for (int i = 0; i < 50; ++i)
        *    {
        *        ek = need - y;
        *        u = calculateUk(ek, ek1, ek2);
        *        y = nonLinear->calculateModel(start, u);
        *        fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
        *        ek2 = ek1;
        *        ek1 = ek;
        *    }
        *    delete nonLinear;
        * }
        * else
        * {
        *    std::cout << "Не удалось открыть файл для записи результатов." << std::endl;
        * }
        * fout.close();
        * \endcode
        */
        std::ofstream fout;
        fout.open("results.txt");
        if (fout) 
        {
            double ek = 0,ek1 = 0, ek2 = 0, y = start, u = 0;
            LinearModel* linear = new LinearModel(0.333, 0.667, 1);
            fout << "Линейная модель: " << std::endl;
            for (int i = 0; i < 50; ++i) 
            {
                ek = need - y;
                u = calculateUk(ek, ek1, ek2);
                y = linear->calculateModel(start, u);
                fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
                ek2 = ek1;
                ek1 = ek;
            }
            delete linear;

            ek = 0, ek1 = 0, ek2 = 0, y = start, u = 0, uk_ = 0;
            fout << "Нелинейная модель: " << std::endl;
            NonLinearModel* nonLinear = new NonLinearModel(1, 0.0033, 0.525, 0.525, 1);
            for (int i = 0; i < 50; ++i)
            {
                ek = need - y;
                u = calculateUk(ek, ek1, ek2);
                y = nonLinear->calculateModel(start, u);
                fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
                ek2 = ek1;
                ek1 = ek;
            }
            delete nonLinear;
        }
        else
        {
            std::cout << "Не удалось открыть файл для записи результатов." << std::endl;
        }
        fout.close();
    }
};

int main()
{
    /**
    * \brief Главная функция main
    *
    * Создаём объект класса Regulator и вызываем метод для рассчёта и записи результатов в файл
    * 
    * Код: 
    * \code
    * setlocale(0, "");
    * Regulator object(10,10,50,0.1);
    * object.PIDRegulatorCalculateAndWrite(5, 2);
    * std::cout << "Данные были сохранены в файл results.txt" << std::endl;
    * return 0;
    * \endcode
    */
    setlocale(0, "");
    Regulator object(10,10,40,0.1);
    object.PIDRegulatorCalculateAndWrite(5, 2);
    std::cout << "Данные были сохранены в файл results.txt" << std::endl;
    return 0;
}