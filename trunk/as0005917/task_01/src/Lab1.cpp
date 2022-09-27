#include<iostream>
#include<Windows.h>
#include<vector>
#include<cmath>

using namespace std;

const double INITIAL_TEMPERATURE = 18;

double linearTemperature(double a, double b, double inputWarm, int iteration);



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<double>temperature;
	int iterNum;

	cout << "Количество итераций: "; cin >> iterNum;
	
	/*Коэффициенты для линейного уравнения*/
	double a_lin, b_lin;

	cout << "Коэффициент а: "; cin >> a_lin;
	cout << "Коэффициент b: "; cin >> b_lin;
	
	/*Количество теплоты*/
	double warm;
	cout << "Количество теплоты: "; cin >> warm;

	for (int i = 0; i < iterNum; i++)
	{
		cout << linearTemperature(a_lin, b_lin, warm, iterNum) << endl;
	}


}

double linearTemperature(double a, double b, double inputWarm, int iteration)
{
	


}

//double nonlin_model(int time_moment) {
//	if (time_momnet == 0)
//		return ROOM_TEMPERSTURE;
//	else if ()time_momnet == 1)
//		return linear_model();
//	else
//		return nonlinear_model();
//}