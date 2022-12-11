#include <iostream>
double y[10];
using namespace std;

void Setup(double& a_, double& b_, double& c_, double& d_, double& u_, double& y0_, int& t_) //Ввод констант
{
	cout << "Введите константы a, b, c и d.\na: "; cin >> a_;
	cout << "b: "; cin >> b_;
	cout << "c: "; cin >> c_;
	cout << "d: "; cin >> d_;
	cout << "Введите коэффициент u(t): "; cin >> u_;
	do
	{
		cout << "Введите время, т.е. количество итераций (должно быть больше, чем 1): "; cin >> t_;
	} while (t_ <= 1);
	cout << "Введите температуру комнаты: "; cin >> y0_;
}

void NonLinear(double a_, double b_, double c_, double d_, double u_, double y0_, int t_)			//Расчёт нелинейной функции
{
	cout << "Итоговая нелинейная функция: y(t+1): " << a_ << "*y(t) - " << c_ << "*y^2(t-1) + " << b_ << "*u(t) + " << d_ << "*sin(u(t-1)), где u принятно за константу и равно " << u_ << ".\n";
	double* y = new double[t_ + 1];
	y[0] = y0_;
	cout << "0\t" << y0_ << endl;
	y[1] = a_ * y[0] + b_ * u_ + d_ * sin(u_);				//т.к. на первой итерации y(t-1) = 0
	cout << "1\t" << y[1] << endl;
	for (int i = 1; i < t_; i++)
	{
		y[i + 1] = a_ * y[i] - c_ * y[i - 1] * y[i - 1] + b_ * u_ + d_ * sin(u_);
		cout << i + 1 << "\t" << y[i + 1] << endl;
	}
	delete[] y;
}

void Linear(double a_, double b_, double u_, double y0_, int t_)				//Расчёт линейной функции
{
	cout << "Итоговая линейная функция: y(t+1) = " << a_ << "*y(t) + " << b_ << "*u(t), где u(t) принято постоянным и равным " << u_ << ".\n";
	double* y = new double[t_ + 1];
	y[0] = y0_;
	cout << "0\t" << y0_ << endl;
	for (int i = 0; i < t_; i++)
	{
		y[i + 1] = a_ * y[i] + b_ * u_;
		cout << i + 1 << "\t" << y[i + 1] << endl;
	}
	delete[] y;
}

int main()
{
	setlocale(LC_ALL, "rus");
	double a, b, u, y0, c, d;
	int t;
	Setup(a, b, c, d, u, y0, t);
	Linear(a, b, u, y0, t);
	NonLinear(a, b, c, d, u, y0, t);
	return 0;
}