#include <iostream>
#include <cmath>

using namespace std;

const double A = 1, B_L = 0.05, B_noL = 0.000001, C = 0.05, D = 0.005; // Создаем константы // B_L - линейная, B_noL - нелинейная

// Создаем линейную модель
// y_t - начальная температура, f_t - теплота (изменение температуры), time - количество времени
double Linear(double y_t, double f_t, int time)
{
  while (time >= 0)
  {
    return A * y_t + B_L * f_t;
  }

  return 0;
}

// Создаем нелинейную модель
// y_t - начальная температура, f_t - теплота (изменение температуры), prev_y_t - значение температуры в предыдущий момент времени, time - количество времени
double NonLinear(double y_t, double f_t, double prev_y_t, int time)
{
  while (time >= 0)
  {
    return A * y_t - B_noL * pow(prev_y_t, 2) + C * f_t + D * sin(f_t);
  }
  return 0;
}

int main()
{
  setlocale(LC_ALL, "");
  double y_t, f_t, prev_y_t, time;
Begin:
  int choice;
  cout << "1. Линейная модель" << endl;
  cout << "2. Нелинейная модель" << endl;
  cout << "Какую из модель выполнить? (1 или 2):" << endl;
  cin >> choice;
  switch (choice)
  {
  case 1:
    cout << "Введите начальное значение температуры: ";
    cin >> y_t;
    cout << "Введите значение теплоты: ";
    cin >> f_t;
    cout << "Введите количество итераций: ";
    cin >> time;
    if (time > 0)
    {
      for (int i = 0; i < time; i++)
      {
        y_t = Linear(y_t, f_t, time);
        cout << y_t << endl;
      }
    }
    else
    {
      cout << "Некорректный ввод" << endl;
      goto Begin;
    }
    break;
  case 2:
    cout << "Введите начальное значение температуры: ";
    cin >> y_t;
    cout << "Введите начальное значение теплоты: ";
    cin >> f_t;
    cout << "Введите количество итераций: ";
    cin >> time;
    prev_y_t = 0;
    if (time > 0)
    {
      for (int i = 0; i < time; i++)
      {
        double fb = y_t; //переменная для записи в prev_y_t
        y_t = NonLinear(y_t, f_t, prev_y_t, time);
        cout << y_t << endl;
        prev_y_t += fb;
      }
    }
    else
    {
      cout << "Некорректный ввод" << endl;
      goto Begin;
    }
    break;
  default:
    cout << "Ошибка, некорректный ввод" << endl;
    goto Begin;
    break;
  }
}
