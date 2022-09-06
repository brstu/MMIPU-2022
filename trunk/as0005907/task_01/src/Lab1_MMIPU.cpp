#include <iostream>
#include <cmath>
const int a = 1, b = 1, c = 1, d = 1;
void calculateLinearModel(int time, float yCurrent, const float& inputWarm);
//float calculateNonlinearModel(); Work in progress
int main()
{
	float yCurrent = 0.0, inputWarm = 0.0;
	int time = 0;
	do
	{
		std::cout << "Pls input time (positive): "; std::cin >> time;
	} while (time <= 0);
	std::cout << "Input a temperature: "; std::cin >> yCurrent;
	std::cout << "Input a warm: "; std::cin >> inputWarm;
	calculateLinearModel(time, yCurrent, inputWarm);
	return 0;
}
void calculateLinearModel(int time, float yCurrent, const float& inputWarm)
{
	float yNext = 0.0;
	while (time--)
	{
		yNext = (a * yCurrent) + (b * inputWarm);
		std::cout << yNext << std::endl;
		yCurrent = yNext;
	}
}

//float calculateNonlinearModel()
//{
//	return;
//}