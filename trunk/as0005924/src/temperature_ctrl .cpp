#include <iostream>
#include <fstream>

#define _ROOM_TEMPERATURE_ 24.3
#define _LINEAR_INPUT_WARM_ 1.2

typedef const unsigned int cuint;

using std::cout;
using std::cin;

const double Lin_A = 1.05, Lin_B = 1.0005;
const double NonLin_A = Lin_A, NonLin_B = 0.00001, NonLin_C = Lin_B, NonLin_D = 0.001;

double linear_graph(cuint& time_moment);
double nonlinear_graph(cuint& time_moment);

int main()
{
    setlocale(LC_ALL, "Russian");

    int model_time;

    cout << "Введите момент вермени: ";
    cin >> model_time;
    if (model_time < 0) model_time *= -1;

    cout << "Результаты:\n";

    for(int i = 0; i <= model_time; i++) 
        cout << "линейная функция = " << linear_graph(i) << '\n'
            << "нелинейная функция = " << nonlinear_graph(i) << "\n\n";

    return 0;
}

double linear_graph(cuint& time_moment)
{
    if (time_moment == 0)
        return _ROOM_TEMPERATURE_;
    else
        return Lin_A * linear_graph(time_moment - 1) + Lin_B * _LINEAR_INPUT_WARM_;
}

double nonlinear_graph(cuint& time_moment) {
    if (time_moment == 0)
        return _ROOM_TEMPERATURE_;
    else if (time_moment == 1)
        return Lin_A * _ROOM_TEMPERATURE_ + Lin_B;
    else
        return NonLin_A * nonlinear_graph(time_moment - 1)
        - NonLin_B * std::pow(nonlinear_graph(time_moment - 2), 2)
        + NonLin_C * _LINEAR_INPUT_WARM_
        + NonLin_D * std::sin(_LINEAR_INPUT_WARM_);
}
