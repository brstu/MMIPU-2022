
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

const double a = 1, b1 = 0.05,b2 = 0.00001, c=0.05, d = 0.005;
const int room_t = 26;

double linear_model(double& starting_temperature, double& temperature_change, int time);
double nolinear_model(double& starting_temperature, double& ctime, double& temperature_change, int time);

int main ()
{
    //y_t
    setlocale(LC_ALL,"RUS");
    double starting_temperature, temperature_change, ctime=0;
    int time;
    cout<<"Введите начальную температуру (y_t): ";
    cin>>starting_temperature;
    cout<<endl;
    cout<<"Введите температуру(в наст момент време) (f_t): ";
    cin>>temperature_change;
    cout<<endl;
    cout<<"Введите время (>0): ";
    cin>>time;
    if(time < 0)    return room_t;
    else{
        ofstream fout;
        fout.open("rezult.txt");
        fout<<"Линейная модель"<<endl;
        for(auto i =0;i<time;i++){
            starting_temperature = linear_model(starting_temperature,temperature_change,time);
            cout<<"Результат линейной функции: "<<starting_temperature<<endl;
            fout<<i<<"\t"<<starting_temperature<<endl;
        }
        fout<<endl;
        fout<<"Нелинейная модель"<<endl;
        for(auto i = 0;i<time;i++){
            double temperature_per_step_minus_1 = ctime;
            starting_temperature= nolinear_model(starting_temperature,ctime,temperature_change,time);
            cout<<"Результат нелинейной функции: "<<starting_temperature<<endl;
            fout<<i<<"\t"<<starting_temperature<<endl;
            ctime+=temperature_per_step_minus_1;
        }
        fout<<endl;
        fout.close();
    }

    return 0;
}

double linear_model(double& starting_temperature, double& temperature_change, int time){
    if(time<0)  return room_t;
    else{
        return a*starting_temperature + b1*temperature_change;
    }
}
double nolinear_model(double& starting_temperature, double& ctime, double& temperature_change, int time){
    if(time<0)  return room_t;
    else{
        return a*starting_temperature - b2*pow(ctime,2) + c* temperature_change + d*sin(temperature_change);
    }
}
