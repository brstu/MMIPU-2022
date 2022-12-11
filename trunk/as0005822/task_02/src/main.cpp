#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
int i;
vector <double> symbol_noline;
vector <double> symbol_line;
class Control{
public:
    virtual double Model(vector <double>& symbol, double t) =0;
};
class LinealModel:public Control{
private:
    const double a = 0.1, b = 0.2;
public:
    double Model(vector <double>& symbol_line, double input_warm) override{
        double temp ;
        temp = a * symbol_line[i] + b* input_warm;
        return temp;
    }
};
class NoLinealModel:public Control{
private:
    const double a = 0.7, b = 0.033, c = 0.0525, d = 0.525;
public:
    double Model(vector <double> &symbol_noline, double input_warm) override {
        double temp;
        temp = a * symbol_noline[i] - b * pow(symbol_noline[i - 1], 2) + c * input_warm + d * sin(input_warm);
        symbol_noline[i]=temp;
        return temp;
    }
};
class PID_controller {
private:
    double u = 0, Td = 50, T =10, T0 = 10, k = 0.1;
public:
    double controller(double e, double e1, double e2) {
        double q0 = k * (1 + (Td / T0));
        double q1 = -1 * k * (1 + 2 * (Td / T0) - (T0 / T));
        double q2 = k * (Td / T0);
        u = q0 * e + q1 * e1 + q2 * e2;
        return u;
    }
    void Reset_U() {
        u = 0;
    }
    double PID_contr(double w, double y0,Control *control ,vector <double> symbol) {
        double errorPrev = 0, error2Prev = 0, y = y0;
        for (int i = 0; i < 25; i++) {
            double error, u;
            error = w - y;
            u = controller(error, errorPrev, error2Prev);
            y = control->Model(symbol, u);
            std::cout << "E = " << error << ", Y = " << y << ", U = " << u << std::endl;
            error2Prev = errorPrev;
            errorPrev = error;
        }
    }
};
int main() {
    for (int i = 0; i < 25; i++) {
        symbol_noline.push_back(0);
    }
    for (int i = 0; i < 25; i++) {
        symbol_line.push_back(0);
    }
    double w = 15, y = 10;
    int number;
    PID_controller* pid_contr = new PID_controller;
    LinealModel* lModel = new LinealModel;
    NoLinealModel* nlModel = new NoLinealModel;
    std::cout<<"1- Noline, 2- line, 3- quit"<<std::endl;
    std::cout<<"Input: ";
    std::cin>>number;
    switch (number) {
        case(1):
            pid_contr->PID_contr(w,y,nlModel,symbol_noline);
            break;
        case(2):
            pid_contr->PID_contr(w,y,lModel,symbol_line);
            break;
        case(0):break;
    }
    return 0;
}