#include <iostream>

using namespace std;

const double a = 1.0005, b = 1.0005, b1 = 0.00001, d = 0.005;

void question(double& y, double& warm, int& iter, int& choice) {
    cout << "Start value temperature: ";
    cin >> y;
    cout << "Temperature increase: ";
    cin >> warm;
    cout << "iter(Number of iterations): ";
    cin >> iter;
    if (iter < 0) {
        cout << "Bad iter!" << endl;
        return;
    }
    cout << "input 1 or 2(linear - 1, non linear - 2): " << endl;
    cin >> choice;
}

double linear(int iter, double warm, double y) {
    if (iter == 0) {
        return y;
    }
    return a * linear(iter - 1, warm, y) + b * warm;
}

double Nonlinear(int iter, double warm, double y) {
    if (iter == 0) {
        return y;
    }
    else if (iter == 1) {
        return a * y + b * warm;
    }
    else {
        return a * Nonlinear(iter - 1, warm, y) - b1 * pow(Nonlinear(iter - 2, warm, y), 2) + b * warm + d * sin(warm);
    }
}

int main()
{
    double y, warm;
    int iter, choice;
    question(y, warm, iter, choice);
    switch (choice) {
    case 1:
        for (int i = 1; i <= iter; i++) {
            cout << "Linear: " << linear(i, warm, y) << endl;
        }
        break;
    case 2:
        for (int i = 1; i <= iter; i++) {
            cout << "Non linear: " << Nonlinear(i, warm, y) << endl;
        }
        break;
    default:
        break;
    }
    cin.get();
    return 0;
}