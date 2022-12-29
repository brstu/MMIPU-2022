#include <iostream>
#include <cmath>
/**
 * @mainpage
 * @brief ПИД-регулятор
 */

/**
 * @class Abstract_Model
 * @brief Абстрактный класс моделей вычисления
 */
class Abstract_Model{
public:
    virtual double m(double _t, double _w) = 0;
};
/**
 * @class NoLinealModel
 * @brief Класс нелинейной модели
 * @details Является подклассом Abstract_Model
 */
class NoLinealModel:public Abstract_Model{
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
    const double a = 1, b = 0.0033, c = 0.525, d =0.525;
    double _w_step_minus1 = 0;
    double _t_step_minus1 = 0;
public:
    /**
     * @brief   Метод вычисления емпературы для нелинейной температуры
     * @param   _w   Выходное тепло
     * @return  double
     */
    double m(double _t, double _w) {
        double temp;
        temp = a * _t - b * pow(_t_step_minus1, 2) + c * _w + d * sin(_w_step_minus1);
        _w_step_minus1 = _w;
        _t_step_minus1 = _t;
        return temp;
    }
};
/**
 * @class PID
 * @brief Абстрактный класс пид-контроллера
 */
class PID{
private:
    /**
     * @brief controller
     *
     * @param   T   Параметр Т
     * @param   T0  Параметр Т0
     * @param   Td  Параметр Td
     * @param   K   Параметр k
     */
    double u = 0, Td = 50, T =10, T0 = 10, k = 0.1;
public:
    double calc(double e, double e1, double e2){

        double q0 = k*(1+(Td/T0));

        double q1 = -1*k*(1+2*(Td/T0)-(T0/T));

        double q2 = k * (Td/T0);

        u += q0*e + q1*e1 + q2*e2;

        return u;
    }
    double PID_D(double w, double y0, Abstract_Model* m){
        double eP = 0, e2P = 0, y = y0;
        for (int i = 0; i <100; i++) {
            double er, u;
            er = w - y;
            u = calc(er, eP, e2P);
            y = m->m(y0, u);
            std::cout << "E = " << er << ", Y = " << y << ", U = " << u << "\n";
            e2P = eP;
            eP = er;
        }
    }
};

int main(){
    double w = 80, y = 10;
    PID* pid = new PID;
    NoLinealModel* nlModel = new NoLinealModel;
    pid->PID_D(w,y,nlModel);
    return 0;
}