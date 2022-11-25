#include <iostream>
#include <cmath>
#include <algorithm>
/**
 * @mainpage
 * @brief ПИД-регулятор
 * @author Лукашук Сергей Игоревич
 */

/**
 * @class Regulator
 * @brief Абстрактный класс моделей вычисления
 */
class Regulator{
public:
    Regulator(){}
    virtual double regulator(double in_temp, double in_warm) = 0;
    ~Regulator (){}
};

/**
 * @class nolinemodel
 * @brief Класс нелинейной модели
 * @details Является подклассом Model
 */
class nolinemodel: public Regulator{
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
    double c_warm = 0;
    double c_temp = 0;
public:
    nolinemodel (){}
    /**
     * @brief   Метод вычисления температуры для нелинейной температуры
     * @param   in_warm    Выходное тепло
     * @return  double
     */
    double regulator(double in_temp, double in_warm) {
        double temp;
        temp = a * in_temp - b * pow(c_temp, 2) + c * in_warm + d * sin(c_warm);
        c_warm = in_warm;
        c_temp = in_temp;
        return temp;
    }
    ~nolinemodel(){}
};
/**
 * @class PID_controller
 * @brief Абстрактный класс пид-контроллера
 */
class PID_controller{
private:
    /**
     * @brief controller
     *
     * @param   T   Параметр Т
     * @param   T0  Параметр Т0
     * @param   Td  Параметр Td
     * @param   K   Параметр k
     */
    double u = 0, Td = 45, T =11, T0 = 14, k = 0.1;
public:
    PID_controller(){}
    double controller(double e, double e1, double e2){
        double q0 = k*(1+(Td/T0));
        double q1 = -1*k*(1+2*(Td/T0)-(T0/T));
        double q2 = k * (Td/T0);
        u += q0*e + q1*e1 + q2*e2;
        return u;
    }
    void Reset_U(){
        u = 0;
    }
    double PID_contr(double w, double y0, Regulator* model){
        double errorPrev = 0, error2Prev = 0, y = y0;
        for (int i = 0; i <100; i++) {
            double error, u;
            error = w - y;
            u = controller(error, errorPrev, error2Prev);
            y = model->regulator(y0, u);
            std::cout << "E = " << error << ", Y = " << y << ", U = " << u << std::endl;
            error2Prev = errorPrev;
            errorPrev = error;
        }
    }
    ~PID_controller(){}

};

int main(){
    double w = 80, y = 10;
    int number;
    PID_controller* pid_contr = new PID_controller;
    nolinemodel* nlModel = new nolinemodel;
    pid_contr->PID_contr(w,y,nlModel);
    return 0;
}