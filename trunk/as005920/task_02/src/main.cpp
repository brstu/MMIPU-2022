#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/**
 * @mainpage
 * @brief ПИД-регулятор
 * @author Лукашук Сергей Игоревич
 */


/**
 * @class Nolinealmodel
 * @brief Класс нелинейной модели
 */
class Nolinealmodel{
private:
    /**
     * @brief Константы нелинейной модели
     *
     * @param   temp        Текущая температура
     * @param   a           Параметр А
     * @param   b           Параметр B
     * @param   c           Параметр С
     * @param   d           Параметр D
     */
    const double a = 1, b = 0.0043, c = 0.515, d =0.515;
    double c_w = 0;
    double c_t = 0;
public:
    Nolinealmodel(){}
    /**
     * @brief   Метод вычисления температуры для нелинейной температуры
     * @param   in_w    Выходное тепло
     * @param   in_t    Выходная температура
     */
    double nolinemodel_controller(double in_t, double in_w) {
        double buf;
        buf = a * in_t - b * pow(c_t, 2) + c * in_w + d * sin(c_w);
        c_w = in_w;
        c_t = in_t;
        return buf;
    }
    ~Nolinealmodel(){}
};
/**
 * @class PID
 * @brief Абстрактный класс пид-контроллера
 */
class PID{
private:
    /**
     * @param   T   Параметр Т
     * @param   T0  Параметр Т0
     * @param   Td  Параметр Td
     * @param   K   Параметр k
     */
    const double Td = 45, T =11, T0 = 14, k = 0.1;
    double u = 0;
public:
    PID(){}
    double contr(double e, double e1, double e2){
        double q0 = k*(1+(Td/T0));
        double q1 = -1*k*(1+2*(Td/T0)-(T0/T));
        double q2 = k * (Td/T0);
        u += q0*e + q1*e1 + q2*e2;
        return u;
    }

    double PID_regulator(double w, double y0, Nolinealmodel* model){
        double ePr = 0, e2Pr = 0, y = y0;
        for (int i = 0; i <100; i++) {
            double E, u;
            E = w - y;
            u = contr(E, ePr, e2Pr);
            y = model->nolinemodel_controller(y0, u);
            cout << "E = " << E << ", Y = " << y << ", U = " << u << std::endl;
            e2Pr = ePr;
            ePr = E;
        }
    }
    ~PID(){}
};
int main(){
    double w = 75, y = 15;
    PID* pid = new PID;
    Nolinealmodel* nolineModel = new Nolinealmodel;
    pid->PID_regulator(w,y,nolineModel);
    return 0;
}