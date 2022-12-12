#pragma once
#include <iostream>

class Regulator
{
private:

    double T = 10, T0 = 10, TD = 50, K = 0.1;
    double u = 0;
    double num = 100;

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


    void PIDregulator(double w, double y0, Model* model)
    {
        double errorPrev = 0, error2Prev = 0, y = y0;
        for (int i = 0; i < num; i++) {
            double error, u;
            error = w - y;
            u = Regulate(error, errorPrev, error2Prev);
            y = model->Iteration(y0, u);
            std::cout << "E = " << error << ", Y = " << y << ", U = " << u << std::endl;
            error2Prev = errorPrev;
            errorPrev = error;
        }
    }

};