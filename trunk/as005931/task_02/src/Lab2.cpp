#include <iostream>
#include <fstream>
#include <cmath>
/**
* \class abs_model
* \brief Абстрактный класс для наследования для наследования конкретными моделями.
*/
class abs_model
{
public:
    /**п
    * \brief Виртуальный метод, который будет переопределяться
    * \param y_current Температура
    * \param input_warm Тепло
    */
    virtual double virtual_model_method(double y_current, double input_warm) = 0;
};
/**
* \class lin_model
* \brief Класс для линейной модели
*/
class lin_model : public abs_model
{
private:
    double m_a, ///< Коэффициент
        m_b, ///< Коэффициент
        m_y_next; ///< Получаемая нами температура
public:
    lin_model(double a, double b, double y_next)
    {
        /**
        * Конструктор lin_model
        */
        m_a = a;
        m_b = b;
        m_y_next = y_next;
    }
    /**
    * Переопределённый метод
    */
    double virtual_model_method(double y_current, double input_warm)
    {
        m_y_next = m_a * y_current + m_b * input_warm;
        return m_y_next;
    }
};
/**
* \class nonlinear_model
* \brief Класс для нелинейной модели
*/
class nonlinear_model : public abs_model
{
private:
    double m_a, ///< Коэффициент
        m_b, ///< Коэффициент
        m_c, ///< Коэффициент
        m_d, ///< Коэффициент
        m_y_prev, ///< Прошлая температура 
        m_y_next, ///< Новая температура
        m_w_prev; ///< Прошлое тепло
public:
    nonlinear_model(double a, double b, double c, double d, double y_next)
    {
        /**
        * Конструктор nonlinear_model
        */
        m_a = a;
        m_b = b;
        m_c = c;
        m_d = d;
        m_y_prev = 0;
        m_w_prev = 0;
        m_y_next = y_next;
    }
    /**
    * Переопределённый метод
    */
    double virtual_model_method(double y_current, double input_warm)
    {
        m_y_next = m_a * y_current - m_b * pow(m_y_prev, 2) + m_c * input_warm + m_d * sin(m_w_prev);
        m_y_prev = y_current;
        m_w_prev = input_warm;
        return m_y_next;
    }
};
/**
* \class pid_regulator
* \brief Класс моделирования регулятора
*/
class pid_regulator
{
private:
    double m_T, ///< Постоянная интегрирования
        m_T0, ///< Шаг квантования
        m_TD, ///< Постоянная дифференцирования
        m_K, ///< Коэффициент передачи
        m_uk; ///< Значение управляющего воздействия
    double UKCalculate(double ek, double ek1, double ek2)
    {
        /**
        * \brief Метод для расчёта m_uk
        */
        double q0 = m_K * (1 + m_TD / m_T0);

        double q1 = -m_K * (1 + 2 * m_TD / m_T0 - m_T0 / m_T);

        double q2 = m_K * m_TD / m_T0;

        m_uk += q0 * ek + q1 * ek1 + q2 * ek2;

        return m_uk;
    }
public:
    pid_regulator(double T, double T0, double TD, double K)
    {
        /**
        * Конструктор pid_regulator
        */
        m_uk = 0;
        m_T = T;
        m_T0 = T0;
        m_TD = TD;
        m_K = K;
    }
    /**
    * \brief Метод моделирования ПИД-регулятора
    * \param need Значение, которое хотим получить
    * \param start Начальное значение y
    */
    void CalculatePIDRegulator(double need, double start)
    {
        std::ofstream out;
        out.open("results.txt");
        if (out)
        {
            double ek = 0, ek1 = 0, ek2 = 0, y = start, u = 0;
            lin_model* l = new lin_model(0.333, 0.667, 1);
            out << "Linear: " << std::endl;

            for (int i = 0; i < 50; ++i)
            {
                ek = need - y;

                u = UKCalculate(ek, ek1, ek2);

                y = l->virtual_model_method(start, u);

                out << "E=" << ek << " Y=" << y << " U=" << u << std::endl;

                ek2 = ek1;

                ek1 = ek;
            }
            delete l;

            ek = 0,
                ek1 = 0,
                ek2 = 0,
                y = start,
                u = 0,
                m_uk = 0;

            out << "Nonlinear: " << std::endl;
            nonlinear_model* nl = new nonlinear_model(1, 0.0033, 0.525, 0.525, 1);
            for (int i = 0; i < 50; ++i)
            {
                ek = need - y;
                u = UKCalculate(ek, ek1, ek2);
                y = nl->virtual_model_method(start, u);
                out << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
                ek2 = ek1;
                ek1 = ek;
            }

            delete nl;
        }
        else
        {
            std::cout << "Ошибка при работе с файлом." << std::endl;
        }
        out.close();
    }
};
/**
* \brief Главная функция main
*/
int main()
{
    setlocale(LC_ALL, "Rus");
    pid_regulator obj(10, 10, 40, 0.1);
    obj.CalculatePIDRegulator(5, 2);
    std::cout << "Результаты сохранены в файл results.txt" << std::endl;
    return 0;
}