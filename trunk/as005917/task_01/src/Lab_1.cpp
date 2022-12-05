#include<iostream>
#include<Windows.h>
#include<fstream>
#include<cmath>
using namespace std;

/*Начальная температура*/
const double INITIAL_TEMPERATURE = 18;

double linearTemperature(double a, double b, double inputWarm, double temperatureParam, int iterNum);
double nonLinearTemperature(double a, double b, double inputWarm, double temperatureParam, int iterNum, double c, double d);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	int iterNum;

	cout << "Количество итераций: "; cin >> iterNum;
	
	/*Коэффициенты для линейного уравнения*/
	double a=1 , b_lin = 0.05;

	
	/*Количество теплоты*/
	double warm;
	cout << "Количество теплоты: "; cin >> warm;
	
	/*Файлы, для записи значений функций*/
	ofstream linOutput("linear.txt");
	ofstream nonLinOutput("nonlinear.txt");
	
	cout << "Линейная функция:\n";
	for (int i = 0; i < iterNum; i++)
	{
		cout << i<<"s\t"<<linearTemperature(a, b_lin, warm, INITIAL_TEMPERATURE, i) << endl;
		linOutput << i <<"\t"<< linearTemperature(a, b_lin, warm, INITIAL_TEMPERATURE, i)<<endl;
	}

	/*Коэффициенты для нелинейного уравнения*/
	double b_nonLin = 0.0001;

	cout << "Неинейная функция:\n";
	for (int i = 0; i < iterNum; i++)
	{
		cout << i << "s\t" << nonLinearTemperature(a, b_nonLin, warm, INITIAL_TEMPERATURE, i,0.05,0.005)<< endl;
		nonLinOutput << i << "\t" << nonLinearTemperature(a, b_nonLin, warm, INITIAL_TEMPERATURE, i, 0.05, 0.005) << endl;

	}

}

double linearTemperature(double a, double b, double inputWarm, double temperatureParam,int iterNum)
{
	if (iterNum == 0)
		return INITIAL_TEMPERATURE;
	else
	 return a * linearTemperature(a,b,inputWarm,temperatureParam,iterNum-1) + b * inputWarm;
		
}


double nonLinearTemperature(double a, double b, double inputWarm, double temperatureParam, int iterNum, double c, double d)
{
	if (iterNum == 0)
		return INITIAL_TEMPERATURE;
	else if (iterNum == 1)
			return a * temperatureParam - b*pow(INITIAL_TEMPERATURE,2.0) + c*inputWarm+d*sin(inputWarm);
	else return a * nonLinearTemperature(a, b,inputWarm,temperatureParam, iterNum-1, c, d) - b * pow(nonLinearTemperature(a, b, inputWarm, temperatureParam, iterNum-2, c, d), 2.0) + c * inputWarm + d * sin(inputWarm);

}
