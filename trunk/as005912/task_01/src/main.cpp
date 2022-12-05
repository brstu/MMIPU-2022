#include <iostream>
#include <cmath>


class TemperatureCalculator
{
public:
    virtual double CalculateNextTemperature(double input_warm) = 0;
protected:
    TemperatureCalculator(){};
};


class LinearTemperatureCalculator: public TemperatureCalculator 
{
private:
    double _a, _b;
    double _current_temperature;
public:
    LinearTemperatureCalculator(double current_temperature, double a, double b)
    {
        _a = a;
        _b = b;
        _current_temperature = current_temperature;
    }

    virtual double CalculateNextTemperature(double input_warm) 
    {
        _current_temperature = _a * _current_temperature + _b * input_warm;
        return _current_temperature;
    }
};


class NonlinearTemperatureCalculator: public TemperatureCalculator
{
private:
    double _a, _b, _c, _d;
    double _current_temperature, _previous_temperature;
public:
    NonlinearTemperatureCalculator(double current_temperature, double a, double b, double c, double d) 
    {
        _a = a;
        _b = b;
        _c = c;
        _d = d;
        _current_temperature = current_temperature;
        _previous_temperature = 0.0;
    }

    virtual double CalculateNextTemperature(double input_warm) 
    {
        double buffer_temperature = _current_temperature;
        _current_temperature = _a * _current_temperature - _b * _previous_temperature * _previous_temperature + _c * input_warm + _d * sin(input_warm);
        _previous_temperature = buffer_temperature;
        return _current_temperature;
    }
};


class TemperatureViewer
{
private:    
    TemperatureCalculator* _temperature_calculator;
public:
    TemperatureViewer(TemperatureCalculator* temperature_calculator) 
    {
        _temperature_calculator = temperature_calculator;
    }

    void GetTemperaturesToConsole(int iterations_number, double input_warm)
    {
        for (int i = 0; i < iterations_number; i++) {
            std::cout << _temperature_calculator->CalculateNextTemperature(input_warm) << std::endl;
        }
    }

    ~TemperatureViewer()
    {
        delete _temperature_calculator;
    }
};


int main()
{    
    TemperatureViewer* temperature_viewer;
    double a, b, c, d, current_temperature;
    int strategy_choise;
    std::cout << "Choose calculate strategy (0 - linear, 1 - nonlinear):" << std::endl;
    std::cin >> strategy_choise;

    switch (strategy_choise) {
        case 0:
        {
            std::cout << "A: ";
            std::cin >> a;
            std::cout << "B: ";
            std::cin >> b;
            std:: cout << "Current temperature: ";
            std::cin >> current_temperature;
            TemperatureCalculator* linear_temperature_calculator = new LinearTemperatureCalculator(current_temperature, a, b);
            temperature_viewer = new TemperatureViewer(linear_temperature_calculator);
            break;
        }
        case 1:
        {
            std::cout << "A: ";
            std::cin >> a;
            std::cout << "B: ";
            std::cin >> b;
            std::cout << "C: ";
            std::cin >> c;
            std::cout << "D: ";
            std::cin >> d;
            std:: cout << "Current temperature: ";
            std::cin >> current_temperature;
            TemperatureCalculator* nonlinear_temperature_calculator = new NonlinearTemperatureCalculator(current_temperature, a, b, c, d);
            temperature_viewer = new TemperatureViewer(nonlinear_temperature_calculator);
            break;
        }
        default:
            break;
    }

    double input_warm;
    int iterations_number;
    std::cout << "Input warm: ";
    std::cin >> input_warm;
    std::cout << "Iterations count: ";
    std::cin >> iterations_number;
    temperature_viewer->GetTemperaturesToConsole(iterations_number, input_warm);
    delete temperature_viewer;
    return 0;
}

