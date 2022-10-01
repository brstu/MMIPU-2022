#include <iostream>
using namespace std;

void linear(double y0, double u0, int n);
void nonlinear(double y0, double u0, int n, double y_, double u_);

double a = 1;
double b = 0.001;
double d = 1.253;
double c = 1.699;


int main()
{
	double y0, u0;
	double y_ = 1.005, u_ = 0.95;
	size_t n;

	cout << "input the starting temperature of the object\n";
	cin >> y0;

	cout << "input the starting warm\n";
	cin >> u0;

	cout << "input the amount of time of modeling\n";
	cin >> n;

	cout << "linear model:\n\n";
	linear(y0, u0, n);

	cout << "\nnon-linear model:\n\n";
	nonlinear(y0, u0, n, y_, u_);

}

 void linear(double y0, double u0, int n)
{
	n--;
	cout << y0 << '\n';
	y0 = a * y0 + b * u0;
	if (n >= 0)
	{
		linear(y0, u0, n);
	}
}

 void nonlinear(double y0, double u0, int n, double y_, double u_)
 {
	 n--;
	 cout << y0 << '\n';
	 double y0_copy = y0;
	 y0 = a * y0 - b * pow(y_, 2) + c * u0 + d * sin(u_);

	 y_ = y0_copy;
	 if (n >= 0)
	 {
		 nonlinear(y0, u0, n, y_, u_);
	 }

 }