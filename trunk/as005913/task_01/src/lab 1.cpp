#include <iostream>
using namespace std;

void linear(double y0, double u0, double a, double b, int n);

int main()
{
	double a = 2.35;
	double b = 6.005;
	double y0, u0;
	size_t n;

	cout << "input the starting temperature of the object\n";
	cin >> y0;

	cout << "input the starting warm\n";
	cin >> u0;

	cout << "input the amount of time of modeling\n";
	cin >> n;

	cout << "linear model:\n\n";
	linear(y0, u0, a, b, n);

	cout << "\nnon-linear model:\n\n";

}

 void linear(double y0, double u0, double a, double b, int n)
{
	n--;
	cout << y0 << '\n';
	y0 = a * y0 + b * u0;
	if (n >= 0)
	{
		linear(y0, u0, a, b, n);
	}
}
