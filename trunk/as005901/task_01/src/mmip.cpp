#include <iostream>
#include <thread>

double lin_y(double uo, int index) {
    int a = 10, b = 15;
    if (index == 0)
        return 0;
    else if (index > 0)
        return a * lin_y(uo, index - 1) + b * uo;
    else return 0;
}

double not_lin_y(double uo, int index) {
    int a = 10, b = 15, c = 20, d = 25;
    if (index == 0)
        return 0;
    else if (index == 1)
        return lin_y(uo, index); // не изветсно, что нужно возвращать 
    else
        return a * not_lin_y(uo, index - 1) - b * not_lin_y(uo, index - 2) * not_lin_y(uo, index - 2)
        + c * uo + d * std::sin(uo - 1);
}

int main()
{
    int index;
    std::cout << "index = ";
    std::cin >> index;

    double uo;
    std::cout << "uo = ";
    std::cin >> uo;

    std::thread t([=]() {
        std::cout << not_lin_y(uo, index) << '\n';
    });

    double result = lin_y(uo, index);

    t.join();

    std::cout << result;

    return 0;
}
