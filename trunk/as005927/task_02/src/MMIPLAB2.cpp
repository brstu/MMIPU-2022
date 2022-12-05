#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

class Regulator
{
protected:
	const double k = 0.1, t = 15, t_d = 50, t_0 = 10;
	const double a = 1, b = 0.0033, y_0 = 18, c = 0.525, d = 0.525, w_t = 100;
	const int j = 150;
	double e = 0;
	double prev_e = 0;
	double prev2_e = 0;
	double u = 0;
	double d_u = 0;
	double prev_u = 0;
};

class Linear : public Regulator
{
private:
	double* y = new double[j + 1];
	double q0, q1, q2;
public:
	Linear()
	{
		ofstream fout("D:\\repos\\MMIPLAB2\\Linear.txt");
		if (!fout.is_open())
		{
			cout << "Ошибка открытия файла!\n";
			return;
		}
		y[0] = y_0;
		q0 = k * (1 + t_d / t_0);
		q1 = -k * (1 + 2 * t_d / t_0 - t_0 / t);
		q2 = k * t_d / t_0;
		for (int i = 0; i < j; i++)
		{
			prev_u = u;
			prev2_e = prev_e;
			prev_e = e;
			e = w_t - y[i];
			d_u = q0 * e + q1 * prev_e + q2 * prev2_e;
			u = prev_u + d_u;
			y[i + 1] = a * y[i] + b * u;
			fout << i << "\t" << y[i] << "\t" << u << "\t" << e << endl;

		}
		fout << j << "\t" << y[j] << "\t" << u << "\t" << e << endl;
		fout.close();
		cout << "Файл Linear.txt обновлён!\n";
	}
	~Linear()
	{
		delete[] y;
	}
};

class NonLinear : public Regulator
{
private:
	double* y = new double[j + 1];
	double q0, q1, q2;
public:
	NonLinear()
	{
		ofstream fout("D:\\repos\\MMIPLAB2\\NonLinear.txt");
		if (!fout.is_open())
		{
			cout << "Ошибка открытия файла!\n";
			return;
		}
		y[0] = y_0;
		q0 = k * (1 + t_d / t_0);
		q1 = -k * (1 + 2 * t_d / t_0 - t_0 / t);
		q2 = k * t_d / t_0;
		for (int i = 0; i < j; i++)
		{
			prev_u = u;
			prev2_e = prev_e;
			prev_e = e;
			e = w_t - y[i];
			d_u = q0 * e + q1 * prev_e + q2 * prev2_e;
			u = prev_u + d_u;
			if (i != 0) y[i + 1] = a * y[i] - b * y[i - 1] * y[i - 1] + c * u + d * sin(prev_u);
			else y[i + 1] = a * y[i] + c * u + d * sin(prev_u);
			fout << i << "\t" << y[i] << "\t" << u << "\t" << e << endl;
		}
		fout << j << "\t" << y[j] << "\t" << u << "\t" << e << endl;
		fout.close();
		cout << "Файл NonLinear.txt обновлён!\n";
	}
	~NonLinear()
	{
		delete[] y;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Linear L;
	NonLinear NL;
	return 0;
}