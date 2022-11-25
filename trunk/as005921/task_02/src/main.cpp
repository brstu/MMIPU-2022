#include <iostream>
#include <cmath>
#include <algorithm>
/**
 * @mainpage
 * @brief ПИД-регулятор
 * @author Манюк Ксения Владимировна
 */

/**
 * @class Reg_controller
 * @brief Абстрактный класс моделей вычисления
 */
class Reg_controller{
public:
    virtual double reg(double _temp, double _warm) = 0;
};

/**
 * @class NoLineModel
 * @brief Класс нелинейной модели
 * @details Является подклассом Model
 */
class NoLineModel: public Reg_controller{
private:
    /**
     * @brief Константы нелинейной модели
     *
     * @param   t        Текущая температура
     * @param   a           Параметр А
     * @param   b           Параметр B
     * @param   c           Параметр С
     * @param   d           Параметр D
     */
    const double a = 1, b = 0.0043, c = 0.515, d =0.515;
    double warm = 0;
    double t = 0;
public:
    /**
     * @brief   Метод вычисления температуры для нелинейной температуры
     * @param   _warm    Выходное тепло
     * @return  double
     */
    double reg(double _temp, double _warm) {
        double t;
        t = a * _temp - b * pow(t, 2) + c * _warm + d * sin(warm);
        warm = _warm;
        t = _temp;
        return t;
    }
};
/**
 * @class PID_contr
 * @brief Абстрактный класс пид-контроллера
 */
class PID_contr{
private:
    /**
     * @brief PID_contr
     *
     * @param   T   Параметр Т
     * @param   T0  Параметр Т0
     * @param   Td  Параметр Td
     * @param   K   Параметр k
     */
    double u = 0, Td = 50, T =11, T0 = 11, k = 0.1;
public:
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
    double PID_controller(double w, double y0, Reg_controller* model){
        double e1Prev = 0, e2Prev = 0, y = y0;
        for (int i = 0; i <100; i++) {
            double error, u;
            error = w - y;
            u = controller(error, e1Prev, e2Prev);
            y = model->reg(y0, u);
            std::cout << "E = " << error << ", Y = " << y << ", U = " << u << std::endl;
            e2Prev = e1Prev;
            e1Prev = error;
        }
    }
};

int main(){
    double w = 80, y = 10;
    PID_contr* pid_contr = new PID_contr;
    NoLineModel* nolinemodel = new NoLineModel;
    pid_contr->PID_controller(w,y,nolinemodel);
    return 0;
}