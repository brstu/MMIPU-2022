#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>


// абстрактный класс моделей вычисления
class Model {
public:

    virtual double model(double input_temp, double input_warm) = 0; // input_warm - входное тепло, input_temp - текущая температура
};


// класс линейной модели
class LinealModel:public Model {
private:
   
    const double a = 0.1, b = 0.2; // a,b - параметры
public:
    
    // вычисление температуры по линейной модели
    double model(double input_temp, double input_warm) override{

        double temp ;
        temp = a * input_warm + b* input_warm;
        return temp;
    }
};


// класс нелинейной модели
class NoLinealModel:public Model {
private:
    
    const double a = 1, b = 0.0033, c = 0.525, d =0.525; // a,b,c,d - параметры
    double input_warm_step_minus1 = 0;
    double input_temp_step_minus1 = 0;
public:
    
    // вычисление емпературы для нелинейной температуры
    double model(double input_temp, double input_warm) {

        double temp;
        temp = a * input_temp - b * pow(input_temp_step_minus1, 2) + c * input_warm + d * sin(input_warm_step_minus1);
        input_warm_step_minus1 = input_warm;
        input_temp_step_minus1 = input_temp;

        return temp;
    }
};


// класс пид-контроллера
class pidController {
private:
    
    double u = 0, Td = 50, T =10, T0 = 10, k = 0.1; // T, T0, Td, K - параметры
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

    double pidContr(double w, double y0, Model* model){

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

    pidController* pid_contr = new pidController;
    LinealModel* lModel = new LinealModel;
    NoLinealModel* nlModel = new NoLinealModel;

    std::cout<<"1- Noline, 2- line, 3- quit"<<std::endl;
    std::cout<<"Input: ";
    std::cin>>number;

    switch (number) {

        case(1):
            pid_contr->pidContr(w,y,nlModel);
            break;

        case(2):
            pid_contr->pidContr(w,y,lModel);
            break;

        case(0):break;
    }
    
    return 0;
}