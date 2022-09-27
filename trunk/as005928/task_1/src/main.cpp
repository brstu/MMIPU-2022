#include <iostream>
#include <cmath>

using namespace std;

// Kонстанты,(b_l - для линейной, b_nl - для нелинейной)
const double A = 1, B_L = 0.05, B_noL = 0.000001, C = 0.05, D = 0.005;

// Нелинейная модель
double NonLinearMod(double y_t, double f_t, double previous_y_t, int t) { // y_t - начальная температура, f_t - теплота (изменение температуры), previous_y_t - значение температуры в предыдущий момент времени, t - количество времени
	while (t >= 0) {
		return A * y_t - B_noL * pow(previous_y_t, 2) + C * f_t + D * sin(f_t);
	}
}

// Линейная модель
double LinearMod(double y_t, double f_t, int t) { // y_t - начальная температура, f_t - теплота (изменение температуры), t - количество времени
	while (t >= 0) {
		return A * y_t + B_L * f_t;
	}
}


int main() {
	setlocale(LC_ALL, "");
	double y_t, f_t, previous_y_t, t;
Begin:
	int choice;
	cout << "1.По линейной модели" << endl;
	cout << "2.По нелинейной модели" << endl;
	cout << "Какое из действий выполнить? (1 или 2):" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Введите начальное значение температуры: ";
		cin >> y_t;
		cout << "Введите значение теплоты: ";
		cin >> f_t;
		cout << "Введите количество итераций: ";
		cin >> t;
		if (t > 0) {
			for (int i = 0; i < t; i++) {
				y_t = LinearMod(y_t, f_t, t);
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
		cout << "Введите количество итераций: ";
		cin >> t;
		previous_y_t = 0;
		if (t > 0) {
			for (int i = 0; i < t; i++) {
				double fb = y_t;//переменная для записи в EXy_t
				y_t = NonLinearMod(y_t, f_t, previous_y_t, t);
				cout << "Результат изменения температуры по нелинейной модели: " << y_t << endl;
				previous_y_t += fb;
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
