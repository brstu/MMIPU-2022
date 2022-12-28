#include <math.h>
#include <fstream>
#include <iostream>

const double a = 1, b1 = 0.06,b2 = 0.0001, c=0.04, d = 0.004;

double Line_Funct(double& s_T, double& t_change, int t);
double NoLine_Funct(double& s_T, double& ct, double& t_change);

int main ()
{
    //y_t
    setlocale(LC_ALL,"RUS");
    double s_T, t_change, ctime=0;
    int t;
    std::cout<<"Введите начальную температуру (y_t): ";
    std::cin>>s_T;
    std::cout<<std::endl;
    std::cout<<"Введите температуру(в наст момент време) (f_t): ";
    std::cin>>t_change;
    std::cout<<std::endl;
    std::cout<<"Введите время (>0): ";
    std::cin>>t;
    std::ofstream file;
    file.open("otw.txt");
    file<<"Линейная модель"<<std::endl;
        for(auto i =0;i<t;i++){
            s_T = Line_Funct(s_T,t_change,t);
            file<<i<<"\t"<<s_T<<std::endl;
        }
        file<<std::endl;
        file<<"Нелинейная модель"<<std::endl;
        for(auto i = 0;i<t;i++){
            double temperature_per_step_minus_1 = ctime;
            s_T= NoLine_Funct(s_T,ctime,t_change);
            file<<i<<"\t"<<s_T<<std::endl;
            ctime+=temperature_per_step_minus_1;
        }
        file<<std::endl;
        file.close();

    return 0;
}

double Line_Funct(double& s_T, double& t_change, int t){
        return a*s_T + b1*t_change;
}
double NoLine_Funct(double& s_T, double& ct, double& t_change){
        return a*s_T - b2*pow(ct,2) + c* t_change + d*sin(t_change);
}
