#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
/**
* \mainpage
* \brief ПИД-регулятор
* \author Дубяга Александр
*/
using namespace std;
/**
* \class model
* \brief Абстрактный класс, который будет использоваться для построения линейных и нелинейных моделей
*/
class model
{
public:
    /**
    * \details абстрактная функция для переопределения в дочерних классах
    */
    virtual float equation(float y_t, float u_t) = 0;
};
/**
* \class LinearMod
* \brief Класс, представляющий линейную модель контролируемого объекта
* \details Дочерний класс, который расширяет класс model
*/
class LinearMod : public model
{
private:
    float a, b, y_t1;///< a, b - просто коэффициенты, y_t1 - температура на выходе
public:
    LinearMod(float a, float b, float y_t1)
    {
    /**
    * \details конструктор для LinearMod
    */
        this->a = a;
        this->b = b;
        this->y_t1 = y_t1;
    }
    /**
    * \details считаем температуру по линейной модели
    */
    float equation(float y_t, float u_t)
    {
        y_t1 = a * y_t + b * u_t;
        return y_t1;
    }
};
/**
* \class NonLinearMod
* \brief Класс, представляющий нелинейную модель контролируемого объекта
* \details Дочерний класс, который расширяет класс model
*/
class NonLinearMod : public model
{
private:
    float a, c, d, b;///< a, b, c, d - просто коэффициенты
    float y_t0 = 0, y_t1;///< y_t0 - предыдущее(начальное) значение температуры, y_t1 - текущее значение температуры на выходе
    float u_t0 = 0;///< u_t0 - переменная для предыдущего значения тепла
public:
    NonLinearMod(float a, float b, float c, float d, float y_t1)
    {
    /**
    * \details конструктор для NonLinearMod
    */
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->y_t1 = y_t1;
    }
    /**
    * \details считаем температуру по нелинейной модели
    */
    float equation(float y_t, float u_t)
    {
        y_t1 = a * y_t - b * pow(y_t0, 2) + c * u_t + d * sin(u_t0);
        u_t0 = u_t;
        y_t0 = y_t;
        y_t = y_t1;
        return y_t1;
    }
};
/**
* \class regulator
* \brief Класс для реализации регулятора
*/
class regulator
{
private:
    float T, T0, TD, K, y_t1 = 0;
public:
    regulator(float T, float T0, float TD, float K) {
    /**
    * \details конструктор для regulator
    */
        this->T = T;
        this->T0 = T0;
        this->TD = TD;
        this->K = K;
    }
    /**
    * \param q0, q1, q2 значения текущей, прошлой и позапрошлой ошибок
    */
    float temperature(float e, float em1, float em2) {
        float q0 = K * (1 + TD / T0);
        float q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        float q2 = K * TD / T0;
        y_t1 += q0 * e + q1 * em1 + q2 * em2;
        return y_t1;
    }
};
/**
* \brief Функция, которая моделирует ПИД-регулятор
* \param w желаемое значение
* \param *reg указатель на экземпляр regulator
* \param *md указатель на экземпляр model
* \param y0 начальное значение y
*/
void PIDregulator(float w, float y0, regulator* reg, model* md) {
    float e = 0, em1 = 0, em2 = 0, u = 0, y = y0;
    ofstream fout;
    fout.open("E:\\PID.txt", ios_base::out | ios_base::app);
    if (fout.is_open()) {
        for (int i = 0; i < 100; i++) {
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
/**
* \brief Функция main, создаём экземпляры всех классов и вызываем функцию PIDregulator
*/
int main()
{
    setlocale(0, "");
    ofstream fout;
    fout.open("E:\\PID.txt", ios_base::out | ios_base::app);
    if (fout.is_open()) {
        fout << "Linear Model:" << endl;
        LinearMod* l = new LinearMod(0.333, 0.667, 1);
        regulator* regl = new regulator(10, 10, 50, 0.1);
        PIDregulator(5, 2, regl, l);
        fout << "NonLinear Model:" << endl;
        NonLinearMod* nl = new NonLinearMod(1, 0.0033, 0.525, 0.525, 1);
        regulator* regnl = new regulator(10, 10, 50, 0.1);
        PIDregulator(5, 2, regnl, nl);
    }
    cout << "Данные были сохранены в файл PID.txt" << endl;
    return 0;
}