#pragma once
#include <iostream>

class Model
{
public:
    virtual double Iteration(double roomTemp, double inputWarm) = 0;
};


class LinearModel : public Model
{
private:

    const double A = 0.333, B = 0.667;

public:

    double Iteration(double roomTemp, double inputWarm)
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

    double Iteration(double roomTemp, double inputWarm)
    {
        double tempNext;
        tempNext = A * roomTemp - B * pow(tempPrev, 2) + C * inputWarm + D * sin(warmPrev);
        warmPrev = inputWarm;
        tempPrev = roomTemp;
        return tempNext;
    }

};
