#include <iostream>
#include <cmath>
using namespace std;

class Regulator{
public:
    virtual double regulator(double in_temp, double in_warm,double _a, double _b, double _c, double _d) = 0;
};

class NoLineModel: public Regulator{
private:

    double c_warm = 0;
    double c_temp = 0;
public:
    double regulator(double in_temp, double in_warm, double _a, double _b, double _c, double _d) {
        double temp;
        temp = _a * in_temp - _b * pow(c_temp, 2) + _c * in_warm + _d * sin(c_warm);
        c_warm = in_warm;
        c_temp = in_temp;
        return temp;
    }
};

class PID_controller{
private:
    double u=0;
public:
    double controller(double& e, double& e1, double& e2,double& _Td, double& _T, double& _T0, double& _k){
        double q0 = _k*(1+(_Td/_T0));
        double q1 = -1*_k*(1+2*(_Td/_T0)-(_T0/_T));
        double q2 = _k * (_Td/_T0);
        u += q0*e + q1*e1 + q2*e2;
        return u;
    }
    double PID_contr(double& w, double& y0, Regulator* model,double& _a, double& _b, double& _c, double& _d,double& _Td, double& _T, double& _T0, double& _k){
        double errorPrev = 0, error2Prev = 0, y = y0;
        for (int i = 0; i <100; i++) {
            double error, u;
            error = w - y;
            u = controller(error, errorPrev, error2Prev,_Td,_T,_T0,_k);
            y = model->regulator(y0,u,_a,_b,_c,_d);
            error2Prev = errorPrev;
            errorPrev = error;
        }
    }
};

int main(){

    double w , y;
    double a , b , c , d ;
    double Td, T, T0, k;
    cout<<"Input w: ";
    cin>>w;
    cout<<"Input y: ";
    cin>>y;
    cout<<"Input a: ";
    cin>>a;
    cout<<"Input b: ";
    cin>>b;
    cout<<"Input c: ";
    cin>>c;
    cout<<"Input d: ";
    cin>>d;
    cout<<"Input Td: ";
    cin>>Td;
    cout<<"Input T: ";
    cin>>T;
    cout<<"Input T0: ";
    cin>>T0;
    cout<<"Input k: ";
    cin>>k;
    PID_controller* pid_contr = new PID_controller;
    NoLineModel* nlModel = new NoLineModel;
    pid_contr->PID_contr(w,y,nlModel,a,b,c,d,Td,T,T0,k);
    return 0;
}