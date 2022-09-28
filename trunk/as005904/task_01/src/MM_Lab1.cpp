#include <iostream>
#include <cmath>

using namespace std;

void linear_model(double, double, int);
void nonlinear_model(double, double, int);

int main()
{
    setlocale(LC_ALL, "Russian");

    int time;
    double input_warm;
    double room_temp; 

    cout << "Введите нужное время: ";
    cin >> time;
    cout << "Введите комнатную температуру: ";
    cin >> room_temp;
    cout << "Введите изменение температуры за единицу времени: ";
    cin >> input_warm;
    cout << endl;

    linear_model(room_temp, input_warm, time);
    cout << endl;
    nonlinear_model(room_temp, input_warm, time);
    return 0;
}

void linear_model(double room_temp, double input_warm, int time)
{
    double a = 1, b = 1, c = 1, d = 1;
    double tempNext;

    cout << endl << "Линейная модель: " << endl;
    for (int i = 0; i < time; i++)
    {
        tempNext = a * room_temp + b * input_warm;
        room_temp = tempNext;
        cout << "После " << i + 1 << " секунд температура равна " << room_temp << endl;
    }
}

void nonlinear_model(double room_temp, double input_warm, int time)
{
    double a = 1, b = 0.00001, c = 1, d = 1;
    double tempNext = 0, tempPrev = 0;

    cout << endl << "Нелинейная модель: " << endl;
    for (int i = 0; i < time; i++)
    {
        tempNext = a * room_temp - b * pow(tempPrev, 2) + c * input_warm + d * sin(input_warm);
        tempPrev = room_temp;
        room_temp = tempNext;
        cout << "После " << i + 1 << " секунд температура равна " << room_temp << endl;
    }
}