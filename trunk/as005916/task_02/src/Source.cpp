#include <fstream>
#include <cmath>
#include <iostream>
#include <vector>

/**
 * @mainpage
 * @brief Работа регулятора
 * @author Кулиш Сергей
 */
 /**
 * @class Reg_model
 * @brief  Интерфейс для модели
 */
class Reg_model {
public:
    virtual long double No_Line_Functoin(long double Ter, long double War, long double& a, long double& b, long double& c, long double& d) = 0;
    
};
/**
* @class NL_Model
* @brief Класс нелинейной модели
*/
class NL_Model :Reg_model {
private:
    /**
    * @brief                Массивы
    *
    * @param   TempArr    Хранит температуру
    * @param   WarmArr    Хранит тепло
    */
     
    std::vector<long double> TempArr;
    std::vector<long double> WarmArr;
public:
    /**
     * @brief Метод вычисления температуры для нелинейной модели
     * @return buf         Временная переменная
     */
    long double No_Line_Functoin(long double TeR, long double WaR, long double& a, long double& b, long double& c, long double& d) {
        double buf;
        TempArr.resize(100);
        WarmArr.resize(100);
        TempArr[0] = TeR;
        WarmArr[0] = WaR;
        for (auto i = 0; i < 100; i++) {
            if (i == 0) {
                buf = a * TempArr[i] - b * pow(0, 2) + c * WarmArr[i] + d * sin(0);
            }
            else {
                buf = a * TempArr[i] - b * pow(TempArr[i - 1], 2) + c * WarmArr[i] + d * sin(WarmArr[i - 1]);
                TempArr[i - 1] = TempArr[i];
                WarmArr[i - 1] = WarmArr[i];
            }
            return buf;
        }
    }
};

class PIDRegulator {
private:
    /**
     * @brief       Константы контроллера
     *
     * @param   T   Параметр Ò
     * @param   T0  Параметр Ò0
     * @param   Td  Параметр Td
     * @param   K   Параметр k
     */
    long double u = 0;
    const long double Td = 25;
    const long double T = 5;
    const long double T0 = 5.01;
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
    void Regulator(double w, double y0, NL_Model* nolinemodel, long double& a, long double& b, long double& c, long double& d) {
        std::ofstream fout;
        fout.open("text.txt");
        double temp1 = 0, temp2 = 0, y = y0;
        for (int i = 0; i < 100; i++) {
            double temp, u;
            temp = w - y;
            u = Find_U(temp, temp1, temp2);
            y = nolinemodel->No_Line_Functoin(y0, u, a, b, c, d);
            fout << temp << "\t" << y << "\t" << u << "\n";
            std::cout << "E= " << temp << "\tY= " << y << "\tU= " << u << "\n";
            temp2 = temp1;
            temp1 = temp;
        }
        fout.close();
    }
};

int main() {
    
    long double a = 1, b = 0.0030, c = 0.520, d = 0.520;
    double w = 60, y = 14;
    PIDRegulator* pid_contr = new PIDRegulator;
    NL_Model* nlModel = new NL_Model;
    pid_contr->Regulator(w, y, nlModel, a, b, c, d);
    return 0;
}
