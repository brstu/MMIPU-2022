
#include<iostream>
#include<Windows.h>
#include<fstream>
#include<cmath>
#include<vector>

using namespace std;

/*Начальная температура*/
const double INITIAL_TEMPERATURE = 18;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector <double>  linearTemperature(1, INITIAL_TEMPERATURE);
	vector <double> nonLinearTemperature(1, INITIAL_TEMPERATURE);

	int iterNum;

	cout << "Количество итераций: "; cin >> iterNum;

	/*Коэффициенты для линейного уравнения*/
	double a = 1, b_lin = 0.05;


	/*Количество теплоты*/
	double warm;
	cout << "Количество теплоты: "; cin >> warm;
	/*Файлы, для записи значений функций*/
	ofstream linOutput("linear.txt");
	ofstream nonLinOutput("nonlinear.txt");
	for (int i = 0; i < iterNum; i++) {
		
		linearTemperature.push_back(a * linearTemperature[i] + b_lin * warm);


	}

	cout << "Линейная функция:\n";
	for (int i = 0; i < iterNum; i++)
	{
		cout << ". " << " " << linearTemperature[i] << endl;
		linOutput << i << "\t" << linearTemperature[i] << endl;
	}

	/*Коэффициенты для нелинейного уравнения*/
	double b_nonLin = 0.0001;
	for (int i = 0; i < iterNum; i++)
	{
		nonLinearTemperature.push_back(linearTemperature[i] - b_nonLin * pow(1.005, 2) + 1.69 * warm + 1.25 * sin(0.95));
		
	}
	cout << "Нелинейная функция:\n";
	for (int i = 0; i < iterNum; i++)
	{
		cout << i << "s\t" << nonLinearTemperature[i] << endl;
		nonLinOutput << i << "\t" << nonLinearTemperature[i] << endl;


	}
}

