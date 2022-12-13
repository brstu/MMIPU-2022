#include <fstream>
#include <cmath>
#include <iostream>

class No_Line_Model{
private:
    long double inT_step=0;
    long double inW_step=0;
public:
    long double No_Line_Functoin(long double inT, long double inW,long double& a,long double& b,long double& c,long double& d){
        double buf;
        inT_step = inT;
        inW_step = inW;
        buf = a*inT - b*pow(inT_step,2) + c*inW +d*sin(inW_step);
        return buf;
    }
};

class AXCF_controller{
private:
    long double u = 0;
    const long double Td = 40;
    const long double T =10;
    const long double T0 = 10.01;
    const long double k = 0.1;
public:
    double Find_U(double e, double e1, double e2){
        double q0 = k*(1+(Td/T0));
        double H = T0/T;
        double q1 = -1*k*(1+2*(Td/T0)-H);
        double q2 = k * (Td/T0);
        u += q0*e + q1*e1 + q2*e2;
        return u;
    }
    double Regulator(double w, double y0, No_Line_Model* nolinemodel,long double& a,long double& b,long double& c,long double& d){
        std::ofstream fout;
        fout.open("text.txt");
        double temp1 = 0, temp2 = 0, y = y0;
        for (int i = 0; i <100; i++) {
            double temp, u;
            temp = w - y;
            u = Find_U(temp, temp1, temp2);
            y = nolinemodel->No_Line_Functoin(y0, u,a,b,c,d);
            fout<<temp<<"\t"<<y<<"\t"<<u<<"\n";
            temp2 = temp1;
            temp1 = temp;
        }
        fout.close();
    }
};

int main(){
    long double a,b,c,d;
    std::cout<<"Input a: ";
    std::cin>>a;
    std::cout<<"Input b: ";
    std::cin>>b;
    std::cout<<"Input c: ";
    std::cin>>c;
    std::cout<<"Input d: ";
    std::cin>>d;
    double w = 70, y = 17;
    AXCF_controller* pid_contr = new AXCF_controller;
    No_Line_Model* nlModel = new No_Line_Model;
    pid_contr->Regulator(w,y,nlModel,a,b,c,d);
    return 0;
}
