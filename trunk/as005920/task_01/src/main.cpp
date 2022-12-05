#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

const double a = 1, b1 = 0.05,b2 = 0.00001, c=0.05, d = 0.005;
double LineModel(double& y_t, double& f_t, int time);
double NoLineModel(double& y_t, double& ctime, double& f_t, int time);

int main ()
{
    setlocale(LC_ALL,"RUS");
    double y_t, f_t;
    int time;
    int number;
    cout<<"Выберите модель (1- линейная, 2 - нелинейная): ";
    cin>>number;
    ofstream file;
    file.open("Rezultat.txt");
    switch(number)
    {
        case 1:
        {
            cout << "Введите начальную температуру (y_t): ";
            cin >> y_t;
            cout << endl;
            cout << "Введите температуру(в наст момент време) (f_t): ";
            cin >> f_t;
            cout << endl;
            cout << "Введите время (>0): ";
            cin >> time;
            file << "Линейная модель" << endl;
            for (int i = 0; i < time; i++) {
                y_t = LineModel(y_t, f_t, time);
                cout << "Результат линейной функции: " << y_t << endl;
                file << i << "\t" << y_t << endl;
            }
            file << endl;
            break;
        }
        case 2:
        {
            double ctime = 0;
            cout << "Введите начальную температуру (y_t): ";
            cin >> y_t;
            cout << endl;
            cout << "Введите температуру(в наст момент време) (f_t): ";
            cin >> f_t;
            cout << endl;
            cout << "Введите время (>0): ";
            cin >> time;
            file<<"Нелинейная модель"<<endl;
            for(int i = 0;i<time;i++){
                double temp= ctime;
                y_t= NoLineModel(y_t,ctime,f_t,time);
                cout<<"Результат нелинейной функции: "<<y_t<<endl;
                file<<i<<"\t"<<y_t<<endl;
                ctime+=temp;
            }
            file<<endl;
            break;
        }
    }
    file.close();
    return 0;

}

double LineModel(double& y_t, double& f_t, int time){
    return a*y_t + b1*f_t;
}
double NoLineModel(double& y_t, double& ctime, double& f_t, int time){
    return a*y_t - b2*pow(ctime,2) + c* f_t + d*sin(f_t);
}
