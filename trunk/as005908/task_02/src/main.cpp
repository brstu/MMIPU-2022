#include <iostream>
#include <cmath>
/**
 * @mainpage
 * @brief ПИД-регулятор
 */

/**
 * @class NoLineModel
 * @brief Абстрактный класс нелинейной модели
 */
class NoLineModel{
private:
    /**
     * @brief Константы линейной модели
     *
     * @param   a       Параметр А
     * @param   b       Параметр B
     * @param   c       Параметр C
     * @param   d       Параметр D
     */
    const double a = 2;
    const double b = 0.003;
    const double c = 0.530;
    const double d = 0.520;
public:
    /**
     * @brief   Метод вычисления температуры для нелинейной температуры
     * @param   buf    Выходное тепло
     * @return  double
     */
    double NoLineTemperature(double temperature, double temperature_1){
        double buf;
        buf = a * temperature + b * pow(temperature_1,2) + c * temperature + d * sin(temperature_1);
        return buf;
    }
};
/**
 * @class PID_controller
 * @brief Абстрактный класс пид-контроллера
 */
class PID_Controller{
private:
    /**
    * @brief controller
    *
    * @param   T   Параметр Т
    * @param   T0  Параметр Т0
    * @param   Td  Параметр Td
    * @param   K   Параметр k
    */
    double u = 0;
    double Td = 45;
    double T = 11;
    double T0 = 11;
    double k = 0.1;
    double rashogdenie;
public:
    /**
     * @brief   Метод вычисления u
     */
    PID_Controller() {}
    double controller(double e, double e1, double e2){
        double q0 = k*(1+(Td/T0));
        double q1 = -1*k*(1+2*(Td/T0)-(T0/T));
        double q2 = k * (Td/T0);
        u += q0*e + q1*e1 + q2*e2;
        return u;
    }

    double PID_contr(double w, double y0, NoLineModel* func_model,int& number){
        double temp = 0, temp_1 = 0, y = y0;
        for (int i = 0; i <number; i++) {
            rashogdenie = w - y;
            u = controller(rashogdenie, temp, temp_1);
            y = func_model->NoLineTemperature(y0, u);
            temp_1 = temp;
            temp = rashogdenie;
        }
    }
    ~PID_Controller() {}

};


int main(){
    double w = 70, y = 15;
    int number;
    std::cout<<"Введите колл времени: \n";
    std::cin>>number;
    PID_Controller* pid_contr = new PID_Controller;
    NoLineModel* nolinemodel = new NoLineModel;
    pid_contr->PID_contr(w,y,nolinemodel,number);
}