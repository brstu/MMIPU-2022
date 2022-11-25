#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class nolinefunct{
private:
    const double a = 1, b = 0.0033, c = 0.525, d =0.525;
    double in_w_1 = 0;
    double in_t_1 = 0;
public:
    nolinefunct(){}
    double functreg(double in_t, double in_w){
        return a * in_t - b * pow(in_t_1, 2) + c * in_w + d * sin(in_w_1);
        in_w_1 = in_w;
        in_t_1 = in_t;
    }
};

class PIDregulator{
private:
    const int  Td = 50, T = 10, T0 = 10, k = 0.1;
    double u =0;
public:
    double controll(double e, double e1, double e2){
        double q0 = k*(1+(Td/T0));
        double q1 = -1*k*(1+2*(Td/T0)-(T0/T));
        double q2 = k * (Td/T0);
        u += q0*e + q1*e1 + q2*e2;
        return u;
    }
    double pidregulator(double w, double y0, nolinefunct* nolinemodel) {
        double er1 = 0, er2 = 0, y = y0;
        for (int i = 0; i < 100; i++) {
            double er, u;
            er = w - y;
            u = controll(er, er1, er2);
            y = nolinemodel->functreg(y0, u);
            er2 = er1;
            er1 = er;
        }
    }
};
int main(){
    double w = 80, y = 10;
    PIDregulator* pid_contr = new PIDregulator;
    nolinefunct* nlModel = new nolinefunct;
    pid_contr->pidregulator(w,y,nlModel);
    return 0;
}


