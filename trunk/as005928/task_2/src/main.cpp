#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;


class Model // абстрактный класс, для построения линейных и нелинейных моделей
{
public:
    
    // абстрактная функция для переопределения
    virtual float equation(float y_t, float u_t) = 0;
};

// класс линейной модели
class LinearMod : public Model
{
private:
    float a, b, y_t1; // a, b - коэффициенты, y_t1 - температура на выходе
public:

    LinearMod(float a, float b, float y_t1) 
    {
        this->a = a;
        this->b = b;
        this->y_t1 = y_t1;
    }
    
    // вычисление температуры
    float equation(float y_t, float u_t)
    {
        y_t1 = a * y_t + b * u_t;
        return y_t1;
    }
};


// класс нелинейной модели
class NonLinearMod : public Model
{
private:
    float a, c, d, b; // a, b, c, d - коэффициенты
    float y_t0 = 0, y_t1; // y_t0 - предыдущее значение температуры, y_t1 - текущее значение температуры на выходе
    float u_t0 = 0; // u_t0 - переменная для предыдущего значения тепла
public:

    NonLinearMod(float a, float b, float c, float d, float y_t1)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->y_t1 = y_t1;
    }
  
    // вычисление температуры
    float equation(float y_t, float u_t)
    {
        y_t1 = a * y_t - b * pow(y_t0, 2) + c * u_t + d * sin(u_t0);
        u_t0 = u_t;
        y_t0 = y_t;
        return y_t1;
    }
};


// класс регулятора
class Regulator
{
private:
    float T, T0, TD, K, u = 0; // K - коэффициент передачи,T0 - шаг,TD - постоянная диференцирования,T - постоянная интегрирования
public:
   
    Regulator(float T, float T0, float TD, float K) {
        this->T = T;
        this->T0 = T0;
        this->TD = TD;
        this->K = K;
    }
    /**
    * \details функция для подсчёта управляющей переменной
    * \param 
    */
    float temperature(float e, float em1, float em2) { // e - значения текущей ошибки, em1 - значение прошлой ошибки, em2 - значение позапрошлой ошибки

        float q0 = K * (1 + TD / T0);
        float q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        float q2 = K * TD / T0;
        u += q0 * e + q1 * em1 + q2 * em2;
        return u;
    }
};


// функция для имитации работы ПИД-регулятора
void pidRegulator(float w, float y0, Regulator* reg, Model* md) { // w желаемое значение, *reg указатель на экземпляр regulator, *md указатель на экземпляр Model, y0 начальное значение y
    ofstream fout;
    fout.open("E:\\PID.txt", ios_base::out | ios_base::app);
    if (fout.is_open()) {
        float em1 = 0, em2 = 0, y = y0;
        for (int i = 0; i < 50; i++) {
            float e, u;
            e = w - y;
            u = reg->temperature(e, em1, em2);
            y = md->equation(y0, u);
            fout << "E=" << e << " Y=" << y << " U=" << u << endl;
            em2 = em1;
            em1 = e;
        }
    }
    fout.close();
}

// создаём экземпляры всех классов и вызываем функцию PIDregulator
int main()
{
    setlocale(0, "");
    ofstream fout;
    fout.open("D:\3 course\\МатМодели\\PID.txt", ios_base::out | ios_base::app);
    if (fout.is_open()) {
        fout << "Linear Model:" << endl;
        LinearMod* l = new LinearMod(0.333, 0.667, 1);
        Regulator* regl = new Regulator(10, 10, 50, 0.1);
        pidRegulator(5, 2, regl, l);
        fout << "NonLinear Model:" << endl;
        NonLinearMod* nl = new NonLinearMod(1, 0.0033, 0.525, 0.525, 1);
        Regulator* regnl = new Regulator(10, 10, 50, 0.1);
        pidRegulator(5, 2, regnl, nl);
    }
    cout << "successfully, the data was written to PID.txt" << endl;
    return 0;
}