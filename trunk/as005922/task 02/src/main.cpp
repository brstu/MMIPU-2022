#include <iostream>
#include <cmath>
#include <fstream>


// абстрактный класс, который предоставляет виртуальную функцию
class AbstrModel
{
public:

    virtual double calculateModel(double yCurrent, double inputWarm) = 0; // yCurrent - температура помещения, inputWarm - входящее тепло
};


// класс линейной модели
class LinearModel : public AbstrModel
{
private:
    double a_, b_, // коэффициенты
        yNext_; // Получаемая нами температура
public:

    // конструктор
    LinearModel(double a, double b, double yNext)
    {
        a_ = a;
        b_ = b;
        yNext_ = yNext;
    }
 
    // рассчёт линейной модели
    double calculateModel(double yCurrent, double inputWarm)
    {
        yNext_ = a_ * yCurrent + b_ * inputWarm;
        return yNext_;
    }
};

// класс нелинейной модели
class NonLinearModel : public AbstrModel
{
private:
    double a_, b_, c_, d_, // коэфициенты 
        yPrev_, // предыдущая температура 
        yNext_, // получаемая нами температура
        wPrev_; // предыдущее тепло
public:

    // конструктор
    NonLinearModel(double a, double b, double c, double d, double yNext)
    {
        a_ = a;
        b_ = b;
        c_ = c;
        d_ = d;
        yPrev_ = 0;
        wPrev_ = 0;
        yNext_ = yNext;
    }
  
    // рассчёт нелинейной модели
    double calculateModel(double yCurrent, double inputWarm)
    {
        yNext_ = a_ * yCurrent - b_ * pow(yPrev_, 2) + c_ * inputWarm + d_ * sin(wPrev_);
        yPrev_ = yCurrent;
        wPrev_ = inputWarm;
        return yNext_;
    }
};

// класс регулятор
class Regulator
{

private:

    double T_, // постоянная интегрирования
        T0_, // шаг для квантования
        TD_, // постоянная дифференцирования
        K_, // коэффициент передачи
        uk_; // текущее значение управляющего воздействия
    
    // рассчёт текущего значения управляющего воздействия на объект
    double calculateUk(double ek, double ek1, double ek2)
    {
        
        double q0 = K_ * (1 + TD_ / T0_); /// q0 - Параметр регулятора
        double q1 = -K_ * (1 + 2 * TD_ / T0_ - T0_ / T_); /// q1 - Параметр регулятора
        double q2 = K_ * TD_ / T0_; /// q2 - Параметр регулятора
        uk_ += q0 * ek + q1 * ek1 + q2 * ek2;
        return uk_;
    }
public:

    // конструктор
    Regulator(double T, double T0, double TD, double K) 
    {
        T_ = T;
        T0_ = T0;
        TD_ = TD;
        K_ = K;
        uk_ = 0;
    }

    // моделируем ПИД-регулятор и записываем результаты
    void pidRegulatorAndWrite(double need, double start) // need - елаемое значение, start - тартовое значение y
    {
        std::ofstream fout;
        fout.open("results.txt");
        if (fout) 
        {
            double ek = 0,ek1 = 0, ek2 = 0, y = start, u = 0;
            LinearModel* linear = new LinearModel(0.333, 0.667, 1);
            fout << "LinearModel: " << std::endl;
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
            fout << " NonLinearModel: " << std::endl;
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
    //создаем екземпляр класса Regulator и вызываем метод для рассчёта и записи результатов
    setlocale(0, "");
    Regulator object(10,10,40,0.1);
    object.pidRegulatorAndWrite(5, 2);
    std::cout << "data was writen to results.txt" << std::endl;
    return 0;
}