#include <iostream>
#include <cmath>

using namespace std;

double a = 1, lb = 1, nlb = 0.00001, c = 1, d = 0.1;

void calculate_and_cout(const int& t, double temp, const double& warm)
{
	float nonlin_prev = 0;
	for (int i = 0; i < t; ++i)
	{
		float lin_temp, nonlin_temp, lin_now = temp, nonlin_now = temp;
		lin_temp = a * lin_now + lb * warm;
		lin_now = lin_temp;

		nonlin_temp = a * nonlin_now - nlb * pow(nonlin_prev, 2) + c * warm + d * sin(warm);
		nonlin_prev = nonlin_now;
		nonlin_now = nonlin_temp;

		cout << i + 1 << "-ая итерация:\nЛинейная модель: " << lin_temp << endl << "Нелинейная модель: " << nonlin_temp << endl << endl;
	}
}

int main()
{
	setlocale(0, "");
	char check = 0;
	do
	{
		do
		{
			system("cls");
			cout << "Коэффициенты a, lb, nlb, c и d соответственно равны: " << a << ", " << lb << ", " << nlb << ", " << c << ", " << d
				<< ".\nЖелаете изменить?\n1)Да\n2)Нет\n";
			cin >> check;
			if (check == '1')
			{
				cout << "Введите а: "; cin >> a;
				cout << "Введите lb: "; cin >> lb;
				cout << "Введите nlb: "; cin >> nlb;
				cout << "Введите c: "; cin >> c;
				cout << "Введите d: "; cin >> d;
				check = '0';
				break;
			}
		} while (check != '2');
		int t = 0;
		do
		{
			cout << "Введите количество итераций: "; cin >> t;
			if (t < 1)
			{
				cout << "Должно быть положительным числом." << endl;
			}
		} while (t < 1);
		double temp = 0.0;
		cout << "Введите температуру помещения: "; cin >> temp;
		double warm = 0.0;
		cout << "Введите теплоту для изменения: "; cin >> warm;
		calculate_and_cout(t, temp, warm);
		do
		{
			cout << "Желаете повторить?\n1)Да\n2)Нет\n";
			cin >> check;
		} while (check != '1' && check != '2');
	} while (check != '2');
	return 0;
}