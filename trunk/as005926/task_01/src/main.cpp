#include <iostream>
#include <cmath>

using namespace std;


const double A = 1, B_Line = 0.05, B_noLine = 0.000001, C = 0.05, D = 0.005; // B_Line - линейная, B_noLine - нелинейная

// линейная модель
double Linear(double y_t, double f_t, int time) { 
	while (time >= 0) {
		return A * y_t + B_Line * f_t;
	}
	return 0;
}

// нелинейная модель
double NonLinear(double y_t, double f_t, double prev_y_t, int time) { 
	while (time >= 0) {
		return A * y_t - B_noLine * pow(prev_y_t, 2) + C * f_t + D * sin(f_t);
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	double y_t, f_t, prev_y_t, time;
Begin:
	int choice;
	cout << "1. Выполнить линейную модель" << endl;
	cout << "2. Выполнить нелинейную модель" << endl;
	cout << "Какую из модель выполнить? (1 или 2):" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Введите начальное значение температуры: ";
		cin >> y_t;
		cout << "Введите значение теплоты: ";
		cin >> f_t;
		cout << "Введите количество итераций: ";
		cin >> time;
		if (time > 0) {
			for (int i = 0; i < time; i++) {
				y_t = Linear(y_t, f_t, time);
				cout << y_t << endl;
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
		cin >> time;
		prev_y_t = 0;
		if (time > 0) {
			for (int i = 0; i < time; i++) {
				double fb = y_t; //переменная для записи в prev_y_t
				y_t = NonLinear(y_t, f_t, prev_y_t, time);
				cout << y_t << endl;
				prev_y_t += fb;
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
