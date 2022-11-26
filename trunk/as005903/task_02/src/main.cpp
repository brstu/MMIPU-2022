#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/**
 * @mainpage
 * @brief ПИД-регулятор
 * @author Бурда Дмитрий Сергеевич
 */

/**
 * @class Function
 * @brief Абстрактный класс моделей вычисления
 */
class Function{
public:
    virtual double function (double wh_t, double wh_w ) = 0;
};
/**
 * @class LinealFunction
 * @brief Класс линейной модели
 * @details Является подклассом Function
 */

class LineFunction: public Function{
private:
    /**
     * @brief Константы линейной модели
     *
     * @param   a       Параметр А
     * @param   b       Параметр B
     */
    const double a = 0.2, b = 0.1;
public:
    double function ( double wh_t, double wh_w) override{
        double rezult;
        rezult = a * wh_w + b* wh_w;
        return rezult;
    }
};
/**
 * @class NoLinealFunction
 * @brief Класс нелинейной модели
 * @details Является подклассом Function
 */
class NoLineFunction:public Function{
private:
    /**
     * @brief Константы нелинейной модели
     *
     * @param   a           Параметр А
     * @param   b           Параметр B
     * @param   c           Параметр С
     * @param   d           Параметр D
     */
    const double a = 1, b = 0.0033, c = 0.525, d =0.525;
    double wh_w_1 = 0;
    double wh_t_1 = 0;
public:
    double function (double wh_t,double wh_w) override{
        double rezult;
        rezult = a * wh_t - b * pow(wh_t_1, 2) + c * wh_w + d * sin(wh_w_1);
        wh_w_1 = wh_w;
        wh_t_1 = wh_t;
        return rezult;
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
    double controller(double e, double e1, double e2){
        double q0 = k*(1+(Td/T0));
        double q1 = -1*k*(1+2*(Td/T0)-(T0/T));
        double q2 = k * (Td/T0);
        u += q0*e + q1*e1 + q2*e2;
        return u;
    }
    double PID_contr(double w, double y0, Function* model){
        double buf1 = 0, buf2 = 0, y = y0;
        for (int i = 0; i <100; i++) {
            double er, u;
            er = w - y;
            u = controller(er, buf1, buf2);
            y = model->function(y0, u);
            buf2 = buf1;
            buf1 = er;
        }
    }
};

int main(){
    double w = 80, y = 10;
    int number;
    cout<<"Выберите тип функции ( 1 - линейная, 2 - нелинейная): ";
    cin>>number;
    switch(number){
        case 1:{
            PID* pid = new PID;
            LineFunction* lfunct = new LineFunction;
            pid->PID_contr(w,y,lfunct);
            break;
        }
        case 2:{
            PID* pid = new PID;
            NoLineFunction* nlfunct = new NoLineFunction;
            pid->PID_contr(w,y,nlfunct);
            break;
        }
        case 0:{
            break;
        }
    }
}


