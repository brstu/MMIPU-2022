#include <iostream>
#include <fstream>
using namespace std;

void Linear(double _a, double _b, double _u, double _y0, int _t)				
{
	ofstream fout("D://MMIPLab1/Linear.txt");
	if (!fout.is_open()) return;
	double* y = new double[_t + 1];
	y[0] = _y0;
	fout << "0\t" << _y0 << endl;
	for (int i = 0; i < _t; i++)
	{
		y[i + 1] = _a * y[i] + _b * _u;
		fout << i + 1 << "\t" << y[i + 1] << endl;
	}
	delete[] y;
	fout.close();
}

void Nonlinear(double _a, double _b, double _c, double _d, double _u, double _y0, int _t)		
{
	ofstream fout("D://MMIPLab1/Nonlinear.txt");
	if (!fout.is_open()) return;
	double* y = new double[_t + 1];
	y[0] = _y0;
	fout << "0\t" << _y0 << endl;
	y[1] = _a * y[0] + _b * _u + _d * sin(_u);				
	fout << "1\t" << y[1] << endl;
	for (int i = 1; i < _t; i++)
	{
		y[i + 1] = _a * y[i] - _c * y[i - 1] * y[i - 1] + _b * _u + _d * sin(_u);
		fout << i + 1 << "\t" << y[i + 1] << endl;
	}
	delete[] y;
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "rus");
	double a = 0.9, b = 1.7, u = 2, y0 = 18, c = 0.0005, d = 0.001;
	int t = 20;
	Linear(a, b, u, y0, t);
	Nonlinear(a, b, c, d, u, y0, t);
	return 0;
}