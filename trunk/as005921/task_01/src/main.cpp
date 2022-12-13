#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

const double a = 1, b1 = 0.06,b2 = 0.00002, c=0.04, d = 0.004;
double linealmodel(double& y_t, double& f_t, int t);
double nolinealmodel(double& y_t, double& ct, double& f_t, int t);

int main ()
{
    setlocale(LC_ALL,"RUS");
    double y_t, f_t, ct=0;
    int t;
    ofstream fout;
    fout.open("Rezultat.txt");
    cout << "Введите начальную температуру (y_t): ";
    cin >> y_t;
    cout << "\n";
    cout << "Введите температуру (f_t): ";
    cin >> f_t;
    cout << "\n";
    cout << "Введите время: ";
    cin >> t;
    fout << "Линейная модель\n";
    for (auto i = 0; i < t; i++) {
        y_t = linealmodel(y_t, f_t, t);
        fout << i << "\t" << y_t << "\n";
    }
    fout << "\n";
    fout<<"Нелинейная модель\n";
    for(auto i = 0;i<t;i++){
        double temp= ct;
        y_t= nolinealmodel(y_t,ct,f_t,t);
        fout<<i<<"\t"<<y_t<<"\n";
        ct+=temp;
    }
    fout<<"\n";
    fout.close();
    return 0;
}

double linealmodel(double& y_t, double& f_t, int t){
    return a*y_t + b1*f_t;
}
double nolinealmodel(double& y_t, double& ct, double& f_t, int t){
    return a*y_t - b2*pow(ct,2) + c* f_t + d*sin(f_t);
}
