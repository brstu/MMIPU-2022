#include <iostream>
#include <cmath>
#include <fstream>
const double a = 1, b1 = 0.05,b2 = 0.00001, c=0.05, d = 0.005;
double nolinemodel(double& x, double& y,double& t){
    return a * x - b2*pow(y,t) + c* y + d* sin(y);
}
double linemodel(double&x, double& y){
    return a* x + b1*y;
}
int main(){
    double x, y, t=0;
    std::cout<<"Input (y_t): ";
    std::cin>>x;
    std::cout<<std::endl;
    std::cout<<"Input (x_t): ";
    std::cin>>y;
    std::cout<<"Input t: ";
    std::cin>>t;
    std::ofstream file;
    file.open("answ.txt");
    file<<"Line model\n";
    for(int i = 0;i<t;i++){
        x = linemodel(x,y);
        file<<x<<"\n";
    }
    file<<"\n";
    file<<"NolineModel\n";
    for(int i=0;i<t;i++){
        x = nolinemodel(x,y,t);
        file<<x<<"\n";
    }
    file<<"\n";
    file.close();
    return 0;
}