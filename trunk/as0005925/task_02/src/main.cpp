#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
/**
 * @mainpage
 * @brief ПИД-регулятор
 * @author Сахацкий Александр Сергеевич
 */

/**
 * @class Model
 * @brief Абстрактный класс моделей вычисления
 */
class Model{
public:
    virtual double model(double input_temp, double input_warm) = 0;
};

/**
 * @class LinealModel
 * @brief Класс линейной модели
 * @details Является подклассом Model
 */
class LinealModel:public Model{
private:
    /**
     * @brief Константы линейной модели
     *
     * @param   temp    Текущая температура
     * @param   a       Параметр А
     * @param   b       Параметр B
     */
    const double a = 0.1, b = 0.2;
public:
    /**
     * @brief Метод вычисления температуры для линейной модели
     *
     * @param input_warm    Вхрдное тепло
     * @return double
     */
    double model(double input_temp, double input_warm) override{
        double temp ;
        temp = a * input_warm + b* input_warm;
        return temp;
    }
};

/**
 * @class NoLinealModel
 * @brief Класс нелинейной модели
 * @details Является подклассом Model
 */
class NoLinealModel:public Model{
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
    double input_warm_step_minus1 = 0;
    double input_temp_step_minus1 = 0;
public:
    /**
     * @brief   Метод вычисления емпературы для нелинейной температуры
     * @param   input_warm    Выходное тепло
     * @return  double
     */
    double model(double input_temp, double input_warm) {
        double temp;
        temp = a * input_temp - b * pow(input_temp_step_minus1, 2) + c * input_warm + d * sin(input_warm_step_minus1);
        input_warm_step_minus1 = input_warm;
        input_temp_step_minus1 = input_temp;
        return temp;
    }
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
    double u = 0, Td = 50, T =10, T0 = 10, k = 0.1;
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
    double PID_contr(double w, double y0, Model* model){
        double errorPrev = 0, error2Prev = 0, y = y0;
        for (int i = 0; i <100; i++) {
            double error, u;
            error = w - y;
            u = controller(error, errorPrev, error2Prev);
            y = model->model(y0, u);
            std::cout << "E = " << error << ", Y = " << y << ", U = " << u << std::endl;
            error2Prev = errorPrev;
            errorPrev = error;
        }
    }
};

int main(){
    double w = 80, y = 10;
    int number;
    PID_controller* pid_contr = new PID_controller;
    LinealModel* lModel = new LinealModel;
    NoLinealModel* nlModel = new NoLinealModel;
    std::cout<<"1- Noline, 2- line, 3- quit"<<std::endl;
    std::cout<<"Input: ";
    std::cin>>number;
    switch (number) {
        case(1):
            pid_contr->PID_contr(w,y,nlModel);
            break;
        case(2):
            pid_contr->PID_contr(w,y,lModel);
            break;
        case(0):break;
    }
    return 0;
}