#include <iostream>

using namespace std;

// outside consts
const double RoomTemperature = 25.2;
const double Warm = 0.5;
// for linear model
const double La = 1.025;
const double Lb = 1.0005;
// for nonlinear model
const double Nb = 0.0000001;
const double Nd = 0.005;

double LinearModel(const int& time) {
    if (time == 0) {
        return RoomTemperature;
    }
    else {
        return La * LinearModel(time - 1) + Lb * Warm;
    }
}

double NonlinearModel(const int& time) {
    if (time == 0) {
        return RoomTemperature;
    }
    else if (time == 1) {
        return La * RoomTemperature + Lb * Warm;
    }
    else {
        return La * NonlinearModel(time - 1) - Nb * pow(NonlinearModel(time - 2), 2) + Lb * Warm + Nd * sin(Warm);
    }
}

int main()
{
    int time;

    cout << "enter time: ";
    cin >> time;
    if (time < 0)
        time *= -1;

    cout << "Resuls:\n";
    for (int i = 0; i <= time; i++) {
        cout << "\niteration = " << i << endl
            << "linear model = " << LinearModel(i) << endl
            << "nonlinear model = " << NonlinearModel(i) << endl;
    }

    return 0;
}