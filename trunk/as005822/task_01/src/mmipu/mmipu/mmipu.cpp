#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ofstream file;

    const double temp_in_room = 20;
    vector <double> linear_equal(1,temp_in_room);

    file.open("myfile.txt");      
    

    int time_moment;
    cout << "Input initial time t in seconds: ";
    cin >> time_moment;
    int init_a = 0, init_b = 0, init_warm = 0;
    cout << "Input initial values a and b and initial warm " << endl;
    cout << "a: ";
    cin >> init_a;
    cout << "b: ";
    cin >> init_b;
    cout << "u: ";
    cin >> init_warm;
    
   
    for (int i = 0; i <= time_moment-1; i++) {
        cout << i + 1;
        linear_equal.push_back(init_a * linear_equal[i] + init_b * init_warm);
        cout<< ". " << " " << linear_equal[i] << endl;
        file << linear_equal[i] << endl;
    }
    
    file.close();
   
    
    
    
    
    
    
   /* list<double> temperature_in_nonlinear_model(2, temp_in_room, ;
   
    int ; cin >> time_moment;

    for (int i = 2; i <= time_moment, i++) {
        temperature_in_nonlinear_model.push_back(A);
    }

    cout << "Input amount of iterations: ";

    cout << "For solving this problem input constants a and b" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "Input initial temperature y[0] :";
    cin >> y[0];
    cout << "Input input warm u[0] :";
    cin >> u;

    for (int i = 1; i < n; i++) {
        y[i] = y[i-1] * a + u * b;
        cout << y[i] << endl;
    }*/
}


