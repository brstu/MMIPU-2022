#include <iostream>
#include <cmath>
const float a = 1, bLin = 1, bNonlin = 0.00001, c = bLin, d = 0.1;
void calculateLinearModel(int time, float yCurrent, const float& inputWarm);
void calculateNonlinearModel(int time, float yCurrent, float inputWarm);
int main()
{
	setlocale(0, "");
	float yCurrent = 0.0, inputWarm = 0.0;
	int time = 0;
	do
	{
		std::cout << "Введите время (положительное число): "; std::cin >> time;
	} while (time <= 0);
	std::cout << "Введите температуру помещения: "; std::cin >> yCurrent;
	std::cout << "Введите значение тепла, на которое будет меняться температура: "; std::cin >> inputWarm;
	std::cout << "Линейная модель: " << std::endl;
	calculateLinearModel(time, yCurrent, inputWarm);
	std::cout << "Нелинейная модель: " << std::endl;
	calculateNonlinearModel(time, yCurrent, inputWarm);
	return 0;
}
void calculateLinearModel(int time, float yCurrent, const float& inputWarm)
{
	float yNext = 0.0;
	while (time--)
	{
		yNext = (a * yCurrent) + (bLin * inputWarm);
		std::cout << yNext << std::endl;
		yCurrent = yNext;
	}
}

void calculateNonlinearModel(int time, float yCurrent, float inputWarm)
{
	float yNext = 0.0, yPrev = 0.0, inputWarmPrev = 0.0;
	while (time--)
	{
		yNext = (a * yCurrent) - (bNonlin * pow(yPrev, 2)) + (c * inputWarm) + (d * sin(inputWarmPrev));
		std::cout << yNext << std::endl;
		yPrev = yCurrent;
		yCurrent = yNext;
		inputWarmPrev = inputWarm;
	}
}