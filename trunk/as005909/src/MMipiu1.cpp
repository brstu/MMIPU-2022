#include <iostream>
#include <cmath> 

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a = 3, b_nel = 0.000003, b_l = 7, c = 7, d = 0.00009;
    double y_t, y_t_1 = 0, y_o, u_t, y_l, y_nel, vrema;
    cout << "Введите входную температуру: ";
    cin >> y_t; //6 для графика
    cout << "Введите входную теплоту: ";
    cin >> u_t; // 8 для графика
    cout << "Введите время: ";
    cin >> vrema;
    if (vrema >= 0) {
        for (int j = 0; j <= vrema; j++) {
            y_o = y_t; // переменная, которая сохранит предыдущее значение
            y_l = a * y_t + b_l * u_t; // линейное уравнение
            y_nel = a * y_t - b_nel * pow(y_t_1, 2) + c * u_t + d * sin(u_t); // нелинейное уравнение
            y_t_1 += y_o;
        }
        cout << "Время, найденное по линейному уравнению: " << y_l << endl;
        cout << "Время, найденное по нелинейному уравнению: " << y_nel;
    }
    else {
        cout << "Время не может быть отрицательным";
    }


}