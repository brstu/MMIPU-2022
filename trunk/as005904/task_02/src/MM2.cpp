#include <iostream>
#include <math.h>
#include "Models.h"
#include "Regulator.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    double w = 24, y = 18;

    Regulator* reg = new Regulator;
    LinearModel* lModel = new LinearModel;
    NonLinearModel* nlModel = new NonLinearModel;

    std::cout << "Linear Model:" << std::endl;
    reg->PIDregulator(w, y, lModel);

    reg->ResetU();

    std::cout << "NonLinear Model:" << std::endl;
    reg->PIDregulator(w, y, nlModel);
    return 0;
}