#include <iostream>

using namespace std;

/// \brief Абстрактный класс для переопределения моделей подсчёта
class Models {

public:

    virtual double calculateModel(double init_room, double init_warm) = 0;
};

/// \brief Класс линейной модели
class Linear : public Models {

private:

    double A = 0.00335, B = 0.00671;

public:

    /// \param init_room начальная температура
    /// \param init_warm значение увеличения температуры
    double calculateModel(double init_room, double init_warm) {

        double temperature;
        temperature = A * init_room + B * init_warm;
        return temperature;
    }

};

/// \brief Класс нелинейной модели
class NonLinear : public Models
{
private:
    double A = 1.0005, B = 0.0035, C = 0.535, D = 0.535, tempPr = 0, warmPr = 0;

public:

    /// \param init_room начальная температура
    /// \param init_warm значение увеличения температуры
    double calculateModel(double init_temp, double init_warm) {

        double temperature = A * init_temp - B * pow(tempPr, 2) + C * init_warm + D * sin(warmPr);
        warmPr = init_warm;
        tempPr = init_temp;
        return temperature;
    }

};

/// \brief Класс пид регулятора
class PidRegulator {
private:
    double T = 10, T0 = 10, TD = 50, K = 0.1, u = 0, iters = 15;

public:
    /// \param error основаня ошибка
    /// \param error1 предыдущая ошибка
    /// \param error2 дважды предыдущая ошибка
    double reg(double error, double error1, double error2) {
        double q0 = K * (1 + TD / T0);
        double q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        double q2 = K * TD / T0;
        u += q0 * error + q1 * error1 + q2 * error2;
        return u;
    }

    /// \param y0 начальная температура
    /// \param warm значение увеличения температуры
    /// \param Models указатель на абстрактный класс
    void pid(double warm, double y0, Models* Models)
    {
        double error1 = 0, error2 = 0, y = y0;
        for (int i = 0; i < iters; i++) {
            double error, u;
            error = warm - y;
            u = reg(error, error1, error2);
            y = Models->calculateModel(y0, u);
            cout << "E = " << error << ", Y = " << y << ", U = " << u << endl;
            error2 = error1;
            error1 = error;
        }
        this->u = 0;
    }
};


/// \brief основаня функция с использованием свитчей для выбора модели
int main()
{
    setlocale(0, "");
    double warm = 30, y = 15;
    int choice;
    PidRegulator* Pid = new PidRegulator;
    Linear* lModels = new Linear;
    NonLinear* nlModels = new NonLinear;
    cout << "1 - linear, 2 - nonlinear " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        cout << "Linear: " << endl;
        Pid->pid(warm, y, lModels);
        break;
    case 2:
        cout << "NonLinear: " << endl;
        Pid->pid(warm, y, nlModels);
        break;
    default:
        break;
    }
    cin.get();
    return 0;
}
