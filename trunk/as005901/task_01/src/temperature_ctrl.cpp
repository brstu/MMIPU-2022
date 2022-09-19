#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>

typedef const unsigned int conunint;

const double room_temperature = 24.5;
double a1 = 1.000046, b1 = 1.0000012, a2 = a1, b2 = 0.00000036, c2 = b1, d2 = 0.00433;

double linear_model(conunint& time_moment, const double& warm_now) {
    if (time_moment == 0)
        return room_temperature;
    else
        return a1 * linear_model(time_moment - 1, warm_now) + b1 * warm_now;
}

double nonlinear_model(conunint& time_moment, const double& warm_now, const double& warm_before) {
    if (time_moment == 0)
        return room_temperature;
    else if (time_moment == 1)
        return a1 * room_temperature + b1 * warm_now;
    else
        return a2 * nonlinear_model(time_moment - 1, warm_now, warm_before)
        - b2 * std::pow(nonlinear_model(time_moment - 2, warm_now, warm_before), 2)
        + c2 * warm_now + d2 * std::sin(warm_before);
}

inline void emulation_intput_warm(double& warm_now, double& warm_before, const int& time_index) {
    for (int i = 0; i <= time_index; i++) {
        warm_before = warm_now;
        warm_now = warm_before + (double(time_index) / 103) + room_temperature / 776;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double warm_now = 0, warm_before = 0; 
    char step = 'f';
    int time_index;

    do {
        system("cls");
        std::cout << "Введите момент вермени (желательно до 35): ";
        std::cin >> time_index;
        if (time_index < 0) time_index *= -1;
        emulation_intput_warm(warm_now, warm_before, time_index);

         std::cout << "Результаты:\n"
            << "линейная функция = " << linear_model(time_index, warm_now) << '\n'
            << "нелинейная функция = " << nonlinear_model(time_index, warm_now, warm_before) << '\n';
         warm_now = warm_before = 0;

         std::cout << "Повтороить? (n - нет, любая клавиша - да) ";
         std::cin >> step;
    } while (step != 'n');

    std::cout << "\nЗаписать в файл информацию по каждому моменту времени? (у - да, любая клавиша - нет) ";
    std::cin >> step;
    if (step == 'y') {
        std::ofstream fout;
        fout.open("results.txt");
        SetConsoleCP(1251);

        fout << "отчёт о каждом моменте вермени: \n\n"
            << "комнатная температура = " << room_temperature << '\n';
        for (int i = 0; i < time_index + 1; i++) {
            emulation_intput_warm(warm_now, warm_before, i);
            fout << "\nмомент времени = " << i
                << "\nлинейная функция = " << linear_model(i, warm_now)
                << "\nнелинейная функция = " << nonlinear_model(i, warm_now, warm_before) << '\n';
            warm_now = warm_before = 0;
        }

        SetConsoleCP(866);
        std::cout << "\nданные сохранены\n";
        fout.close();
    }

    return 0;
}