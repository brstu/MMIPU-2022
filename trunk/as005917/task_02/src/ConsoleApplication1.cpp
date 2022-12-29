#include <fstream>
#include <cmath>
#include <iostream>

/**
 * @mainpage
 * @brief Работа регулятора
 * @author Левоцкий Никита Дмитриевич
 */
 /**
 * @class mode_model
 * @brief Интерфейс для модели
 */
class mode_model {
public:
    virtual long double No_Line_Functoin(long double inT, long double inW, long double& a, long double& b, long double& c, long double& d) = 0;
};
/**
* @class No_Line_Model
* @brief Класс нелинейной модели
*/
class No_Line_Model :mode_model {
private:
    /**
    * @brief                Массивы
    *
    * @param   inT_array    Хранит температуру
    * @param   inW_array    Хранит тепло
    */
    long double* inT_array = new long double[99];
    long double* inW_array = new long double[99];
public:
    /**
     * @brief Метод вычисления температуры для нелинейной модели
     * @return buf          Временная переменная
     */
    long double No_Line_Functoin(long double inT, long double inW, long double& a, long double& b, long double& c, long double& d) {
        double buf;
        inT_array[0] = inT;
        inW_array[0] = inW;
        for (auto i = 0; i < 100; i++) {
            if (i == 0) {
                buf = a * inT_array[i] - b * pow(0, 2) + c * inW_array[i] + d * sin(0);
            }
            else {
                buf = a * inT_array[i] - b * pow(inT_array[i - 1], 2) + c * inW_array[i] + d * sin(inW_array[i - 1]);
                inT_array[i - 1] = inT_array[i];
                inW_array[i - 1] = inW_array[i];
            }
            return buf;
        }
    }
};

class PIDRegulator{
private:
    /**
     * @brief       Константы контроллера
     *
     * @param   T   Параметр Т
     * @param   T0  Параметр Т0
     * @param   Td  Параметр Td
     * @param   K   Параметр k
     */
    long double u = 0;
    const long double Td = 40;
    const long double T = 10;
    const long double T0 = 10.01;
    const long double k = 0.1;
public:
    /**
     * @brief            Метод вычисления U
     * @return U         U
     */
    double Find_U(double e, double e1, double e2) {
        double q0 = k * (1 + (Td / T0));
        double H = T0 / T;
        double q1 = -1 * k * (1 + 2 * (Td / T0) - H);
        double q2 = k * (Td / T0);
        u += q0 * e + q1 * e1 + q2 * e2;
        return u;
    }
    /**
     * @brief            ПИД-Регулятор
    **/
    void Regulator(double w, double y0, No_Line_Model* nolinemodel, long double& a, long double& b, long double& c, long double& d) {
        std::ofstream fout;
        fout.open("text.txt");
        double temp1 = 0, temp2 = 0, y = y0;
        for (int i = 0; i < 100; i++) {
            double temp, u;
            temp = w - y;
            u = Find_U(temp, temp1, temp2);
            y = nolinemodel->No_Line_Functoin(y0, u, a, b, c, d);
            fout << temp << "\t" << y << "\t" << u << "\n";
            std::cout<<"E= " <<temp << "\tY= " << y << "\tU= " << u << "\n";
            temp2 = temp1;
            temp1 = temp;
        }
        fout.close();
    }
};

int main() {
  
    long double a = 1, b = 0.0033, c = 0.525, d = 0.525;
    double w = 70, y = 17;
    PIDRegulator* pid_contr = new PIDRegulator;
    No_Line_Model* nlModel = new No_Line_Model;
    pid_contr->Regulator(w, y, nlModel, a, b, c, d);
    return 0;
}
