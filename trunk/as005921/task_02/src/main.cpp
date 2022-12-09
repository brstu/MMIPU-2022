#include <iostream>
#include <cmath>
#include <algorithm>

class NoLineModel:PID_contr{
private:
    double warm = 0;
    double t = 0;
public:

    NoLineModel(){}
    double reg(double _temp, double _warm,double& _a,double& _b, double& _c,double& _d) {
        t = _a * _temp - _b * pow(t, 2) + _c * _warm + _d * sin(warm);
        warm = _warm;
        t = _temp;
        return t;
    }
    ~NoLineModel() {}
};

class PID_contr{
private:
    double u = 0;
    const double  Td = 50, T =11, T0 = 11, k = 0.1;
public:
    PID_contr() {}
    double controller(double e, double e1, double e2){
        double q0 = k*(1+(Td/T0));
        double q1 = -1*k*(1+(2*(Td/T0))-(T0/T));
        double q2 = k * (Td/T0);
        u += q0*e + q1*e1 + q2*e2;
        return u;
    }

    double PID_controller(double w, double y0, NoLineModel* model,double& _a,double& _b, double& _c,double& _d){
        double e1Prev = 0, e2Prev = 0, y = y0;
        for (int i = 0; i <100; i++) {
            double error, u;
            error = w - y;
            u = controller(error, e1Prev, e2Prev);
            y = model->reg(y0, u,_a,_b,_c,_d);
            e2Prev = e1Prev;
            e1Prev = error;
        }
    }
    ~PID_contr() {}
};

int main(){
    setlocale(LC_ALL,"RUS");
    double a, b, c, d;
    int w,y;
    std::cout<<"Введите a: ";
    std::cin>>a;
    std::cout<<"Введите b: ";
    std::cin>>b;
    std::cout<<"Введите c: ";
    std::cin>>c;
    std::cout<<"Введите d: ";
    std::cin>>d;
    std::cout<<"Введите w: ";
    std::cin>>w;
    std::cout<<"Введите y: ";
    std::cin>>y;
    PID_contr* pid_contr = new PID_contr;
    NoLineModel* nolinemodel = new NoLineModel;
    pid_contr->PID_controller(w,y,nolinemodel,a,b,c,d);
    return 0;
}