#include <iostream>
#include <cmath>

using namespace std;

const double a = 1, b_l = 0.05, b_nl = 0.000001, c = 0.05, d = 0.005;//константы, сделал отдельную константу b для линейной и нелинейной моделей (b_l - для линейной, b_nl - для нелинейной)

double LinearMod(double y_t, double f_t, int time) { //линейная модель, где y_t - начальная температура, f_t - теплота (изменение температуры), time - количество времени
	while (time >= 0) {
		return a * y_t + b_l * f_t;
	}
}

double NonLinearMod(double y_t, double f_t, double EXy_t, int time) { //нелинейная модель, где y_t - начальная температура, f_t - теплота (изменение температуры), EXy_t - значение температуры в предыдущий момент времени, time - количество времени
	while (time >= 0) {
		return a * y_t - b_nl * pow(EXy_t, 2) + c * f_t + d * sin(f_t);
	}
}

int main() {
	setlocale(LC_ALL, "");
	double y_t, f_t, EXy_t, time;
Begin:
	int choice;
	cout << "1.Температура по линейной модели" << endl;
	cout << "2.Температура по нелинейной модели" << endl;
	cout << "Какое из действий выполнить? (1 или 2):" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Введите начальное значение температуры: ";
		cin >> y_t;
		cout << "Введите значение теплоты (то, на сколько будет изменяться температура): ";
		cin >> f_t;
		cout << "Введите количесвто времени (больше 0): ";
		cin >> time;
		if (time > 0) {
			for (int i = 0; i < time; i++) {
				y_t = LinearMod(y_t, f_t, time);
				cout << "Результат изменения температуры по линейной модели: " << y_t << endl;
			}
		}
		else {
			cout << "Некорректный ввод" << endl;
			goto Begin;
		}
		break;
	case 2:
		cout << "Введите начальное значение температуры: ";
		cin >> y_t;
		cout << "Введите начальное значение теплоты: ";
		cin >> f_t;
		cout << "Введите время (больше 0): ";
		cin >> time;
		EXy_t = 0;
		if (time > 0) {
			for (int i = 0; i < time; i++) {
				double fb = y_t;//переменная для записи в EXy_t
				y_t = NonLinearMod(y_t, f_t, EXy_t, time);
				cout << "Результат изменения температуры по нелинейной модели: " << y_t << endl;
				EXy_t += fb;
			}
		}
		else {
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
