#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double a = 1, b_l = 0.9, b_nl = 0.0000000009, c = 0.05, d = 0.1;//константы, сделал отдельную константу b для линейной и нелинейной моделей (b_l - для линейной, b_nl - для нелинейной)

double LinearMod(double y_t, double f_t, int t) { //линейная модель, где y_t - начальная температура, f_t - теплота (изменение температуры), time - количество времени
	return a * y_t + b_l * f_t;
}

double NonLinearMod(double y_t, double f_t, double EXy_t, double EXf_t, int t) { //нелинейная модель, где y_t - начальная температура, f_t - теплота (изменение температуры), EXy_t - значение температуры в предыдущий момент времени, time - количество времени
	return a * y_t - b_nl * pow(EXy_t, 2) + c * f_t + d * sin(EXf_t);
}

double f_tMod(double f_t) {//изменение теплоты
	return f_t * 1.2545;
}

int main() {
	setlocale(LC_ALL, "");
	double y_t, f_t, EXy_t, EXf_t, t;
	cout << "Введите начальное значение температуры: ";
	cin >> y_t;
	cout << "Введите значение теплоты (то, на сколько будет изменяться температура): ";
	cin >> f_t;
	cout << "Введите целевое значение температуры (больше 0): ";
	cin >> t;
	int choice;
	cout << "1.Температура по линейной модели" << endl;
	cout << "2.Температура по нелинейной модели" << endl;
	cout << "Какое из действий выполнить? (1 или 2):" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		if (t > 0) {
			ofstream fout;
			fout.open("D:\\linearX.txt");
			if (fout.is_open()) {
				fout << "Time\t" << "Temperature" << endl;
				for (double time = 1; y_t <= t; time++) {
					y_t = LinearMod(y_t, f_t, t);
					if (y_t < t) {
						fout << time << '\t' << y_t << endl;
					}
					else {
						fout << "Следующее значение превысит целевой уровень температуры" << endl;
					}
				}
			}
			fout.close();
		    cout << "Данные были сохранены в файл linearX.txt" << endl;
		}
		break;
	case 2:
		if (t > 0) {
			ofstream fout;
			fout.open("D:\\nonlinearX.txt");
			EXy_t = 0;
			EXf_t = 0;
			if (fout.is_open()) {
				fout << "Time\t" << "Temperature" << endl;
				for (double time = 1; y_t <= t; time++) {
					double _EXy_t_ = y_t;//переменная для записи в EXy_t
					double _EXf_t_ = f_t;//переменная для записи в EXf_t
					y_t = NonLinearMod(y_t, f_t, EXy_t, EXf_t, t);
					f_t = f_tMod(f_t);
					if (y_t < t) {
						fout << time << '\t' << y_t << endl;
					}
					else {
						fout << "Следующее значение превысит целевой уровень температуры" << endl;
					}
					EXy_t = _EXy_t_;
					EXf_t = _EXf_t_;
				}
			}
			fout.close();
		    cout << "Данные были сохранены в файл nonlinearX.txt" << endl;
		}
		break;
	default:
		cout << "error" << endl;
		break;
	}
}
