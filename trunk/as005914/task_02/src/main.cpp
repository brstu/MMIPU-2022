#include <iostream>
#include <cmath>
#include <algorithm>
/**
 * @mainpage
 * @brief ПИД-регулятор
 */

/**
 * @class NoLinealFunct
 * @brief Класс нелинейной модели
 */
class NoLinealFunct{
protected:
    /**
     * @brief Константы нелинейной модели
     *
     * @param   temp        Текущая температура
     * @param   a           Параметр А
     * @param   b           Параметр B
     * @param   c           Параметр С
     * @param   d           Параметр D
     */
    const double a = 1, b = 0.0033, c = 0.525, d = 0.525;
    double i_w_minus1 = 0;
    double i_t_minus1 = 0;
public:
    /**
     * @brief   Метод вычисления температуры для нелинейной температуры
     * @param   i_w    Выходное тепло
     * @return  double
     */
    double funct(double i_t, double i_w) {

        double buf;

        buf = a * i_t - b * pow(i_t_minus1, 2) + c * i_w + d * sin(i_w_minus1);

        i_w_minus1 = i_w;

        i_t_minus1 = i_t;

        return buf;
    }
};

/**
 * @class AXCF
 * @brief Абстрактный класс пид-контроллера
 */
class AXCF{
protected:
    /**
     * @brief AXCF_contr
     *
     * @param   T   Параметр Т
     * @param   T0  Параметр Т0
     * @param   Td  Параметр Td
     * @param   K   Параметр k
     */
    double u = 0, _Td = 45, _T =11, _T0 = 10, k = 0.1;
public:
    double AXCF_contr(double e, double e1, double e2){

        double q0 = k*(1+(_Td/_T0));

        double q1 = -1*k*(1+2*(_Td/_T0)-(_T0/_T));

        double q2 = k * (_Td/_T0);

        u += q0*e + q1*e1 + q2*e2;

        return u;
    }

    double PID_contr(double w, double y0, NoLinealFunct* nlfunct){

        double ep = 0, e2p = 0, y = y0;

        for (int i = 0; i <100; i++) {

            double error, u;

            error = w - y;

            u = AXCF_contr(error, ep, e2p);

            y = nlfunct->funct(y0, u);

            std::cout << "E = " << error << ", Y = " << y << ", U = " << u << std::endl;

            e2p = ep;

            ep = error;
        }
    }
};

int main(){
    double w = 250, y = 20;
    AXCF* pid_contr = new AXCF;
    NoLinealFunct* nlModel = new NoLinealFunct;
    pid_contr->PID_contr(w,y,nlModel);
    return 0;
}