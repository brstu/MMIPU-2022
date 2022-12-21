#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

const double ROOM_TEMPERATURE = 24.5;

double A1 = 1.0000046, B1 = 1.00000012;
double emulate_linear_model(std::vector<double>&, std::vector<double>&, const int&);

double A2 = A1, B2 = 0.0000000056, C2 = B1, D2 = 0.0833;
double emulate_nonlinear_model(std::vector<double>&, std::vector<double>&, const int&);

void emulate_intput_warm(std::vector<double>&, const int&);

int main() {
    std::vector<double> input_warm_per_moment;
    std::vector<double> temperature_in_linear_model;
    std::vector<double> temperature_in_nonlinear_model;

    double linear_model_result;
    double nonlinear_model_result;

    int time_moment;

    char action = 'g';

    do {
        system("cls");
        input_warm_per_moment.clear();
        temperature_in_linear_model.clear();
        temperature_in_nonlinear_model.clear();

        std::cout << "Enter the time moment: ";
        std::cin >> time_moment;
        if (time_moment < 0) time_moment *= -1;
        emulate_intput_warm(input_warm_per_moment, time_moment);

        nonlinear_model_result = emulate_nonlinear_model(temperature_in_nonlinear_model, input_warm_per_moment, time_moment);
        linear_model_result = emulate_linear_model(temperature_in_linear_model, input_warm_per_moment, time_moment);

        std::cout << "Results:\n"
            << "nonlinear_model = " << linear_model_result << '\n'
            << "nonlinear_model = " << nonlinear_model_result << '\n';

        std::cout << "Once again? (n - no, anything else - yes) ";
        std::cin >> action;

    } while (action != 'n');

    std::cout << "\nDo you want to save full data per each time moment? (y - yes, anything else - no) ";
    std::cin >> action;
    if (action == 'y') {
        std::ofstream file_for_results;
        file_for_results.open("results.txt");

        file_for_results << "Results fоr each time moment: \n\n"
            << "Room temperatur = " << ROOM_TEMPERATURE << '\n';
        for (int i = 0; i <= time_moment; i++) {
            file_for_results << "\ntime moment = " << i
                << "\nlinear model = " << temperature_in_linear_model[i]
                << "\nnonlinear model = " << temperature_in_nonlinear_model[i] << '\n';
        }

        std::cout << "\nData have been saved\n";
        file_for_results.close();
    }

    return 0;
}

double emulate_linear_model(std::vector<double>& temperature_in_linear_model, std::vector<double>& input_warm_per_moment, const int& time_moment) {
    if (time_moment >= 0) {
        temperature_in_linear_model.push_back(ROOM_TEMPERATURE);
    }

    for (int i = 1; i <= time_moment; i++) {
        temperature_in_linear_model.push_back(
            A1 * temperature_in_linear_model[i - 1]
            + B1 * input_warm_per_moment[i - 1]);
    }

    return temperature_in_linear_model[time_moment];
}

double emulate_nonlinear_model(std::vector<double>& temperature_in_nonlinear_model, std::vector<double>& input_warm_per_moment, const int& time_moment) {
    if (time_moment >= 0) {
        temperature_in_nonlinear_model.push_back(ROOM_TEMPERATURE);
        if (time_moment >= 1) {
            temperature_in_nonlinear_model.push_back(
                A2 * ROOM_TEMPERATURE
                + B2 * input_warm_per_moment[0]);
        }
    }

    for (int i = 2; i <= time_moment; i++) {
        temperature_in_nonlinear_model.push_back(
            A2 * temperature_in_nonlinear_model[i - 1]
            - B2 * std::pow(temperature_in_nonlinear_model[i - 2], 2)
            + C2 * input_warm_per_moment[i - 1]
            + D2 * std::sin(input_warm_per_moment[i - 2]));
    }

    return temperature_in_nonlinear_model[time_moment];
}

void emulate_intput_warm(std::vector<double>& input_warm_per_moment, const int& time_moment) {
    if (time_moment >= 0) {
        input_warm_per_moment.push_back(ROOM_TEMPERATURE / 676);
    }

    for (int i = 1; i <= time_moment; i++) {
        double warm_upper = (double(i) / 103) + ROOM_TEMPERATURE / 776;
        input_warm_per_moment.push_back(input_warm_per_moment[i - 1] + warm_upper);
    }
}