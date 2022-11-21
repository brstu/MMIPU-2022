#include <iostream>

using namespace std;

/// \brief Abstract class with start values for models and method ovveride
class Main
{
public:
    double a = 0.699, b = 0.899, a1 = 0.857, b1 = 0.0022,c1 = 0.467, d1 = 0.398;
public:
    virtual double method(double temp, double warm) = 0;
};

/// \brief Class linear model
class Linear : public Main
{
private:
    double aL, bL, resL = 0;
public:
    Linear():aL(a), bL(b) {}

    /// \param temp start temperature
    /// \param warm value of increasing
    double method(double temp, double warm)
    {
        resL = aL * temp + bL * warm;
        return resL;
    }
};

/// \brief Class nonLinear model
class NonLinear : public Main
{
private:
    double aNL, bNL, cNL, dNL;
    double lastcalculate = 0;
    double lastTemp = 0;
public:
    NonLinear(): aNL(a1), bNL(b1), cNL(c1), dNL(d1){}

    /// \param temp start temperature
    /// \param warm value of increasing
    double method(double temp, double calculate)
    {
        double tempNext;
        tempNext = aNL * temp - bNL * pow(lastTemp, 2) + cNL * calculate + dNL * sin(lastcalculate);
        lastcalculate = calculate;
        lastTemp = temp;
        return tempNext;
    }
};

/// \brief Class pid generator q-values and result pid value
class Pid
{
private:
    double T = 10, T0 = 10, TD = 50, K = 0.085, U = 0;
public:
    /// \param e main error
    /// \param error1 prev error
    /// \param error2 prev prev error
    double calculate(double e, double error1, double error2) {
        double Q0 = K * (1 + TD / T0);
        double Q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        double Q2 = K * TD / T0;
        U += Q0 * e + Q1 * error1 + Q2 * error2;
        return U;
    }

    /// \param iter count of iterations
    /// \param temp start temperature
    /// \param warm increasing value of temp
    /// \param pid pointer to Pid class
    /// \param res pointer to Res class
    void result(int iter, double temp, double warm, Pid* pid, Main* res) {
        double error1 = 0, error2 = 0, y = warm;
        for (int i = 0; i < iter; i++) {
            double e = 0, u = 0;
            e = temp - y;
            u = pid->calculate(e, error1, error2);
            y = res->method(warm, u);
            cout << "\tE=" << e << " \tY=" << y << " \tU=" << u << endl;
            error2 = error1;
            error1 = e;
        }
    }
};

/// \brief main function
/// **Example using**
/// \code
int main()
{
    setlocale(0, "");
    int ROOM_TEMP = 30, WARM = 15, iter = 100, choice;
    Linear* l = new Linear();
    NonLinear* nl = new NonLinear();
    Pid* pid = new Pid();
    cout << "Choose pid for models(1 - linear, 2 - nonlinear) " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        pid->result(iter, ROOM_TEMP, WARM, pid, l);
        break;
    case 2:
        pid->result(iter, ROOM_TEMP, WARM, pid, nl);
        break;
    default:
        break;
    }
    cin.get();
    return 0;
}
/// \endcode
