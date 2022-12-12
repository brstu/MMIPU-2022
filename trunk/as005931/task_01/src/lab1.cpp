#include <iostream>
#include <cmath>

using namespace std;

const double a = 1, linear_b = 1, nonlinear_b = 0.0005, c = 1, d = 0.2;

double linear(double y, double f) {
	return a * y + linear_b * f;
}

double nonlinear(double y, double f, double prev_y) { 
	return a * y - nonlinear_b * pow(prev_y, 2) + c * f + d * sin(f);
}

int main() {
	setlocale(LC_ALL, "Russian");
	double y, f, prev_y = 0, t;
	cout << "Введите начальную температуру: ";
	cin >> y;
	cout << "Введите теплоту: ";
	cin >> f;
	cout << "Введите время: ";
	cin >> t;
	int decision;
	cout << "1.Температура по линейной модели" << endl;
	cout << "2.Температура по нелинейной модели" << endl;
	cin >> decision;
	switch (decision) {
	case 1:
		for (int i = 1; i < t; ++i) {
			y = linear(y, f);
			cout << "Момент:" << i << endl << "Температура:" << y << endl << endl;
		}
		break;
	case 2:
		for (int i = 1; i < t; ++i) {
			double y_ = y;
			y = nonlinear(y, f, prev_y);
			prev_y = y_;
			cout << "Момент:" << i << endl << "Температура:" << y << endl << endl;
		}
	default:
		cout << "Что-то пошло не так..." << endl;
		break;
	}
}