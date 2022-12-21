#include <iostream>
#include <math.h>
using namespace std;

class Model
{
public:
    virtual double Iter(double roomTemp, double inputWarm) = 0;
};


class LinearModel : public Model
{
private:

    const double A = 0.333, B = 0.667;

public:

    double Iter(double roomTemp, double inputWarm)
    {
        double tempNext;
        tempNext = A * roomTemp + B * inputWarm;
        return tempNext;
    }

};



class NonLinearModel : public Model
{
private:

    const double A = 1, B = 0.0033, C = 0.525, D = 0.525;
    double tempPrev = 0;
    double warmPrev = 0;

public:

    double Iter(double roomTemp, double inputWarm)
    {
        double tempNext;
        tempNext = A * roomTemp - B * pow(tempPrev, 2) + C * inputWarm + D * sin(warmPrev);
        warmPrev = inputWarm;
        tempPrev = roomTemp;
        return tempNext;
    }

};

class Reg
{
private:

    double T = 10, T0 = 10, TD = 50, K = 0.1;
    double u = 0;
    double num = 25;

public:

    double Regulate(double e, double e1, double e2)
    {
        double q0 = K * (1 + TD / T0);
        double q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        double q2 = K * TD / T0;
        u += q0 * e + q1 * e1 + q2 * e2;
        return u;
    }


    void ResetU()
    {
        u = 0;
    }


    void PID(double w, double y0, Model* model)
    {
        double errorPrev = 0, error2Prev = 0, y = y0;
        for (int i = 0; i < num; i++) {
            cout << i << " ";
            double error, u;
            error = w - y;
            u = Regulate(error, errorPrev, error2Prev);
            y = model->Iter(y0, u);
            cout << "E = " << error << ", Y = " << y << ", U = " << u <<endl;
            error2Prev = errorPrev;
            errorPrev = error;
        }
    }

};

int main()
{
    system("color F0");
    double w = 24, y = 18;

    Reg* reg = new Reg;
    LinearModel* lModel = new LinearModel;
    NonLinearModel* nlModel = new NonLinearModel;

    cout << "Linear Model:" << endl;
    reg->PID(w, y, lModel);

    reg->ResetU();

    cout << "NonLinear Model:" << endl;
    reg->PID(w, y, nlModel);
    return 0;
}