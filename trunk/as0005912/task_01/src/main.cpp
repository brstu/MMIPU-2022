#include <iostream>
#include <cmath>


const double A = 1.0, B = 1.0, C = 5.0, D = 5.0;


double calculate_linear_temperature(double curr_temperature, double input_warm)
{
    return A * curr_temperature + B * input_warm;
}


double calculate_nonlinear_temperature(double curr_temperature, double prev_temperature, double input_warm)
{
    return A * curr_temperature - B * prev_temperature * prev_temperature + C * input_warm + D * sin(input_warm);
}


int main()
{
    double curr_temperature, prev_temperature, input_warm;
    std::cin >> curr_temperature;
    prev_temperature = 0;
    std::cin >> input_warm;
    for (int i = 0; i < 100; i++) {
        curr_temperature = calculate_nonlinear_temperature(curr_temperature, prev_temperature, input_warm);
        std::cout << curr_temperature << std::endl;
        prev_temperature = curr_temperature;
    }
    return 0;
}
