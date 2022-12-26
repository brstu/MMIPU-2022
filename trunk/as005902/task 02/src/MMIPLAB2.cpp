#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

class System
{
protected:
	const double k = 0.1, t = 15, td = 50, t_0 = 10, a = 1, b = 0.0035, y_0 = 20, c = 0.5, d = 0.5, wt = 150;
	const int j = 150;
	double e = 0, e_prev = 0, e_2prev = 0, u = 0, du = 0, u_prev = 0, q0, q1, q2;
public:
	virtual void Calculation() = 0;
};

class Lin : public System
{
public:
	void Calculation()
	{
		ofstream fout("D:\\Lin.txt");
		if (!fout.is_open())
		{
			cout << "Ошибка открытия файла!\n";
			return;
		}
		double* y = new double[j + 1];
		y[0] = y_0;
		q0 = k * (1 + td / t_0);
		q1 = -k * (1 + 2 * td / t_0 - t_0 / t);
		q2 = k * td / t_0;
		for (int i = 0; i < j; i++)
		{
			u_prev = u;
			e_2prev = e_prev;
			e_prev = e;
			e = wt - y[i];
			du = q0 * e + q1 * e_prev + q2 * e_2prev;
			u = u_prev + du;
			y[i + 1] = a * y[i] + b * u;
			fout << i << "\t" << y[i] << "\t" << u << "\t" << e << endl;

		}
		fout << j << "\t" << y[j] << "\t" << u << "\t" << e << endl;
		delete[] y;
		fout.close();
		cout << "Файл Lin.txt перезаписан!\n";
	}
};

class NonLin : public System
{
private:
public:
	void Calculation()
	{
		ofstream fout("D:\\NonLin.txt");
		if (!fout.is_open())
		{
			cout << "Ошибка открытия файла!\n";
			return;
		}
		double* y = new double[j + 1];
		y[0] = y_0;
		q0 = k * (1 + td / t_0);
		q1 = -k * (1 + 2 * td / t_0 - t_0 / t);
		q2 = k * td / t_0;
		for (int i = 0; i < j; i++)
		{
			u_prev = u;
			e_2prev = e_prev;
			e_prev = e;
			e = wt - y[i];
			du = q0 * e + q1 * e_prev + q2 * e_2prev;
			u = u_prev + du;
			if (i != 0) y[i + 1] = a * y[i] - b * y[i - 1] * y[i - 1] + c * u + d * sin(u_prev);
			else y[i + 1] = a * y[i] + c * u + d * sin(u_prev);
			fout << i << "\t" << y[i] << "\t" << u << "\t" << e << endl;
		}
		fout << j << "\t" << y[j] << "\t" << u << "\t" << e << endl;
		delete[] y;
		fout.close();
		cout << "Файл NonLin.txt обновлён!\n";
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	Lin l;
	NonLin nl;
	l.Calculation();
	nl.Calculation();
	return 0;
}