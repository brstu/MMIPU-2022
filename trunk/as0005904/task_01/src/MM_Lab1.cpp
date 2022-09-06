#include <iostream>
#include <cmath>

using namespace std;

const int a = 1, b = 1, c = 1, d = 1;
void linear_model(int, int, int);
void nonlinear_model();

int main()
{
    int t;   //time
    int y_t; //input temperature
    int u_t; //input warm
    int Y_0; //room temperature

    cout << "Input time: ";
    cin >> t;
    cout << endl << "Input temperature: ";
    cin >> y_t;
    cout << endl << "Input warm: ";
    cin >> u_t;
    cout << endl << "Input room temperature: ";
    cin >> Y_0;
    cout << endl;

    linear_model(y_t, u_t, t);
    return 0;
}

void linear_model(int y_t, int u_t, int t)
{
    int y_t1;

    cout << endl << "Linear model:" << endl;
    for (int i = 0; i < t; i++)
    {
        y_t1 = a * y_t + b * u_t;
        y_t = y_t1;
        cout << "At t = " << i + 1 << " temperature is " << y_t << endl;
    }
}

void nonlinear_model()
{
    cout << endl << "Nonlinear model:" << endl;
}