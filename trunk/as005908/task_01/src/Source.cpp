#include<iostream>
#include<cmath>
using namespace std;
void one(double y, double u)
{
	const double a = 1, b = 1;
	for (int i = 0; i < 10; i++)
	{
		cout << y << endl;
		y = a * y + b * u;
	}
	cout << y;
}
void two(double y0, double u0)
{
	const double a = 1, b = 0.0001,c=1,d=0.01;
	double y1;
	cout << y0 << endl;
	cout << y0 * a + b * u0 << endl;
	y1 = y0 * a+b*u0;
	for (int i = 2; i < 10; i++)
	{
		
		cout << a * y1 - b * pow(y0, 2) + c * u0 + d * sin(u0) << endl;
		
		y0 = y1;
		y1 = a * y1 - b * pow(y0, 2) + c * u0 + d * sin(u0);

	}
	cout << y1;
	
}
int main()
{
	setlocale(LC_ALL, "rus");
	double y, u;
	cout << "¬ведите входную температуру: "; cin >> y; cout << endl;
	cout << "¬ведите входное тепло: "; cin >> u; cout << endl;
	cout << "ѕерва€ зависимость:" << endl;
	one(y, u);
	cout << endl;
	double y0, u0;
	cout << "¬ведите y0 "; cin >> y0; cout << endl;
	cout << "¬ведите u0 "; cin >> u0; cout << endl;
	cout << endl << "¬тора€ зависимомть" << endl;
	two(y0,u0);
	return 0;
}