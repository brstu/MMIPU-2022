#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    //открываем поток
    ofstream flow,
             flow2;

    const double temp = 20;
    vector <double> linear_equal(1, temp);

    flow.open("myfile.txt");      
    

    int time_moment;
    cout << "Input initial time t in seconds: ";
    cin >> time_moment;

    const double A = 1, B = 0.05, C = 0.05, D = 0.005;

    double init_warm;
    cout << "Input initial warm " << endl;

    cout << "u: ";
    cin >> init_warm;
    
   
    for (int i = 0; i <= time_moment-1; i++) {
        cout << i + 1;
        linear_equal.push_back(A * linear_equal[i] + B * init_warm);
        cout<< ". " << " " << linear_equal[i] << endl;
        flow << linear_equal[i] << endl;
    }
    
    flow.close();

    flow2.open("myfile2.txt");
    vector <double> nolinear_equal(1, temp);

    //nolinear_equal.push_back(init_a * linear_equal[0] + 2 * init_b * init_warm - init_c * linear_equal[0] * linear_equal[0] + init_d * sin(init_warm));
    for (int i = 0; i <= time_moment-1; i++) 
    {
        cout << i + 1;
        cout << ". " << nolinear_equal[i] << endl;
        nolinear_equal.push_back(A * nolinear_equal[i] + 2 * B * init_warm - C * nolinear_equal[i] * nolinear_equal[i] + D * sin(init_warm));
        flow2 << nolinear_equal[i] << endl;
    }

    flow2.close();
}