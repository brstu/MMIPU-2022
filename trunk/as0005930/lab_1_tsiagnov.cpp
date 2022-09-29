#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;

const double a1 = 1.0;
const double a2 = 1.0;
const double b1 = 1;
const double b2 = 0.0005;
const double c = 2.0;
const double d = 2.0;
typedef const double c_tmp;

double LinearFunction (double temperature, double input_warm) {
    return a1 * temperature + b1 * input_warm;
}

double NonLinearFunction(c_tmp& temperature, double& input_warm, int& time) {
    return a2 * temperature - b2 * pow((temperature-1), 2) + c * input_warm + d * sin(input_warm);
}

int main()
{
    ofstream fout;
    fout.open("rezult.txt");
    setlocale(LC_ALL, "RUS");
    int time;
    double temperature =0;
    double input_warm;
     double t_temperature = 0;
    cout << "Введите входящую температуру (t): ";
    cin>>temperature;
    cout << "Введите входящее тепло (U): ";
    cin >> input_warm;
    cout << "Введите time: ";
    cin>>time;

    cout << "Линейная функция: "<<endl;

    for (int i= 0; i < time; i++) {
        temperature = LinearFunction(temperature, input_warm);
        
        cout << temperature<<endl;
        fout << temperature << endl;
        
    }
    fout << endl;
    cout << "Нелинейная функция: " << endl;

    for (int l = 0; l < time; l++) {
   
        temperature = NonLinearFunction(temperature, input_warm, time);
        cout << temperature << endl;
        fout << temperature << endl;
}
    fout.close();
    return 0;
}

