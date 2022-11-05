#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ofstream file,file2;

    const double temp_in_room = 20;
    vector <double> linear_equal(1,temp_in_room);

    file.open("myfile.txt");      
    

    int time_moment;
    cout << "Input initial time t in seconds: ";
    cin >> time_moment;

    double init_a = 0, init_b = 0, init_warm = 0, init_c = 0, init_d = 0;
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

    file2.open("myfile2.txt");
    vector <double> nolinear_equal(1, temp_in_room);
    cout << "Input initial values c and d " << endl;
    cout << "c: ";
    cin >> init_c;
    cout << "d: ";
    cin >> init_d;

    //nolinear_equal.push_back(init_a * linear_equal[0] + 2 * init_b * init_warm - init_c * linear_equal[0] * linear_equal[0] + init_d * sin(init_warm));
    for (int i = 0; i <= time_moment-1; i++) 
    {
        cout << i + 1;
        cout << ". " << nolinear_equal[i] << endl;
        nolinear_equal.push_back(init_a*nolinear_equal[i]+2*init_b*init_warm-init_c*nolinear_equal[i]* nolinear_equal[i]+init_d*sin(init_warm));
        file2 << nolinear_equal[i] << endl;
    }

    file2.close();
}
