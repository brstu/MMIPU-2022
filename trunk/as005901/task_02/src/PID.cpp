#include <iostream>
#include <vector>
#include <fstream>

using std::vector;

/**
* \brief Абстрактный класс объекта регулирования
* 
* Предоставляет интерфейс для взаимодействия с объектом управления
*/
class TemperatureManipulationObject 
{
protected:
	double ROOM_TEMPERATURE; ///< содержит начальную температуру печи - принята комнатная температура

	size_t time_moment; ///< содержит момент времени, на котором происходит работа оюъекта регулирования

	vector<double> input_warm_per_moment; ///< содержит всё информацию о входном тепле

	/**	
	* для эмуляции входной температуры 
	*/
	virtual void emulate_intput_warm() = 0;
	
	/**
	* для эмуляции изменения температуры
	*/
	virtual void emulate_temperature_changes() = 0;

public:
	/**
	* для установки необходимого для анализа момента времени
	* \param time_moment определяет момент времи, на котором необходимо отрегулировать объект
	*/
	virtual void set_time(size_t time_moment) = 0;
	/**
	* для установки управляющего воздейсвия регулятора
	* \param managing определяет управляющее воздействия для объекта регулирования
	*/
	virtual void set_input_warm(double managing) = 0;

	/**
	* для получения температуры в необходимый момент времени
	* \param time_moment определяет время, на котором необходимо получить температуру 
	* \return температура в определённый момент времени
	*/
	virtual double get_temperature(size_t time_moment) = 0;

	TemperatureManipulationObject(size_t time_moment, double room_temperature) {
	   /**
	   * Конструктор TemperatureManipulationObject
	   *
	   * Код:
	    \code
		this->time_moment = time_moment;
		this->ROOM_TEMPERATURE = room_temperature;
	    \endcode
	   */
		this->time_moment = time_moment;
		this->ROOM_TEMPERATURE = room_temperature;
	}
	virtual ~TemperatureManipulationObject() {/// виртуальный деструктор
	}
};

/**
* \brief Объект регулярования - печь
*
* Унаследован от абстрактного класса объекта регулирования. Содержит в себе нелинейную функцию изменения температуры.
*/
class Bake : public TemperatureManipulationObject
{
private:
	/// коэфициенты нелинейной модели изменения температуры
	double nonlin_A = 1.0000046; ///< коэффициент при y(t - 1)
	double nonlin_B = 0.000000056; ///< коэффициент при y^2(t - 2)
	double nonlin_C = 0.00075; ///< коэффициент при u(t)
	double nonlin_D = 0.0833; ///< коэффициент при sin(u(t - 1))

	size_t time_border; ///< содержит информацию о последнем моменте времени, при котором работал объект

	vector<double> temperature_in_nonlinear_model; ///< содержит всё информацию о температуре объекта

	virtual void emulate_intput_warm() override {
		this->input_warm_per_moment.push_back(0.25);
	}

	virtual void emulate_temperature_changes() override {
		/// определения нулевого значение для рекурентной функции
		if (time_moment == 0) {
			temperature_in_nonlinear_model.push_back(ROOM_TEMPERATURE);
			time_border++;
		}
		/// определения первого значение для рекурентной функции
		if (time_moment == 1) {
			temperature_in_nonlinear_model.push_back(
				nonlin_A * ROOM_TEMPERATURE
				+ nonlin_B * input_warm_per_moment[0]);
			time_border++;
		}

		/// производит вычисление температуры в определённый момент времени
		for (int i = this->time_border; i <= time_moment && this->time_border > 1; i++) {
			temperature_in_nonlinear_model.push_back(
				nonlin_A * temperature_in_nonlinear_model[i - 1]
				- nonlin_B * std::pow(temperature_in_nonlinear_model[i - 2], 2)
				+ nonlin_C * input_warm_per_moment[i - 1]
				+ nonlin_D * std::sin(input_warm_per_moment[i - 2]));
			time_border++;
		}
	}

public:
	virtual void set_time(size_t time_moment) override {
		/// устанавливает новую температуру
		if (this->time_moment < time_moment) {
			this->time_moment = time_moment;
			this->emulate_temperature_changes();
		}
	}
	virtual void set_input_warm(double managing) override {
		/// подменяем входое тепло управляющим воздействием регулятора
		this->input_warm_per_moment.push_back(managing);
	}

	virtual double get_temperature(size_t time_moment) override {
		/// получаем температуцру в определённый момент времени 
		return this->temperature_in_nonlinear_model[time_moment];
	}
	
	Bake(size_t time_moment) : TemperatureManipulationObject(time_moment, 24.5) explicit {
	   /**
	   * Конструктор Bake
	   *
	   * Код:
		\code
		time_border = 0;

		this->emulate_intput_warm();
		this->emulate_temperature_changes();
		\endcode
	   */
		
		time_border = 0;

		this->emulate_intput_warm();
		this->emulate_temperature_changes();
	}
};

/**
* \brief Абстрактный класс регулятора
*
* Предоставляет интерфейс для взаимодействия с регулятором
*/
class Regulator
{
protected:
	double desired_value; ///< содержит желаемое значение, к которому должна стремиться температура объекта

	/**
	* для расчёта управляющего воздействия
	*/
	virtual double count_managing() = 0;

public:
	/**
	* для установки управляющего воздейсвия регулятора
	* \param temperature определяет управляющее воздействия для объекта регулирования
	*/
	virtual void set_state_of_TMO(double temperature) = 0;

	/**
	* для получения значение e(t)
	*/
	virtual double get_difference() = 0;
	/**
	* для получения значение u(t)
	*/
	virtual double get_managing() = 0;

	Regulator(double desired_value) {
	   /**
	   * Конструктор Regulator
	   *
	   * Код:
	    \code
		this->desired_value = desired_value;
	    \endcode
	   */
		this->desired_value = desired_value;
	}
	virtual ~Regulator() {/// виртуальный деструктор
	}
};

/**
* \brief Pегулятор температуры печи 
*
* Унаследован от абстрактного класса регулятора. Содержит в себе отклонение выходной переменной и функцию управляющего воздействия.
*/
class BakeRegulator : public Regulator
{
	double difference[3]; ///< содержит значение e(t), e(t -1), e(t -2)
	double managing[2]; ///< содержит значение u(t), u(t -1)
	double temp_temperature; ///< содержит темепратуру, которая была получена от объекта регулирования

	/// постоянные коэффициенты 
	double K = 9.92; ///< коэффициент передачи
	double Ti = 18.47; ///< постоянная интергрирования
	double Td = 5.12; ///< постоянная дифференцирования
	double step_T = 1.0; ///< шаг квантования времени  

	/// параметры регулирвоания 
	/// расчёт параметра q0
	double count_q0() {	return K * (1 + Td / step_T); }
	/// расчёт параметра q1
	double count_q1() {	return -K * (1 + 2 * (Td / step_T) - (step_T / Ti)); }
	/// расчёт параметра q2
	double count_q2() { return K * Td / step_T; }

	/// расчёт управляющего воздействия
	virtual double count_managing() override {
		return managing[0] + (this->count_q0() * this->difference[2] 
							  + this->count_q1() * this->difference[1]
							  + this->count_q2() * this->difference[0]);
	}

public:
	virtual void set_state_of_TMO(double temperature) override  {
		this->temp_temperature = temperature;

		this->difference[0] = this->difference[1];
		this->difference[1] = this->difference[2];
		this->difference[2] = this->desired_value - temperature;

		this->managing[0] = this->managing[1];
		this->managing[1] = this->count_managing();
	}

	virtual double get_difference() override { return difference[2]; }
	virtual double get_managing() override { return managing[1]; }

	BakeRegulator(double temperature, double desired_value) : Regulator(desired_value) {
		/**
		* Конструктор BakeRegulator
		*
		* Код:
		this->difference[0] = 0;
		this->difference[1] = 0;
		this->difference[2] = desired_value - temperature;
		
		this->managing[0] = 0;
		this->managing[1] = this->count_managing();
		
		this->temp_temperature = 0;
		\endcode
		*/
		
		this->difference[0] = 0;
		this->difference[1] = 0;
		this->difference[2] = desired_value - temperature;
		
		this->managing[0] = 0;
		this->managing[1] = this->count_managing();
	
		this->temp_temperature = 0;
	}
};

/**
* Эмулирует регуляцию объекта управления
* \param TMO объект, который мы регулируем
* \param regulator регулятор, осуществляющий регулирование нашего обхъекта
* \param time_moment момент времени, до которого нам необходимы результаты регулирования
* Функция записывает результаты каждого момента времени в отдельный файл с расширением .csv, где данные хранятся в формате t;y(t);e(t);u(t)\n
*/
void emulate_regulation_of_TMO(TemperatureManipulationObject* TMO, Regulator* regulator, int time_moment) {
	/// определяем файл, который будет хранить в себе результаты регулирования
	std::ofstream work_file("work_data.csv", std::fstream::out);
	for (int i = 1; i <= time_moment; i++) {
		/// производим регулирование
		/// поределяем момент времени, который нам нужно отрегулировать
		TMO->set_time(i);
		/// передаём данные регулятору о его целевом обхекте
		regulator->set_state_of_TMO(TMO->get_temperature(i));
		/// передаём объекту результаты регулятора
		TMO->set_input_warm(regulator->get_managing());

		/// записываем данные о регулировании объекта в файл
		work_file << i << ';'
			<< TMO->get_temperature(i) << ';'
			<< regulator->get_difference() << ';'
			<< regulator->get_managing() << '\n';
	}
	work_file.close();
}

int main() {
	/**
	* \brief Главная функция main
	*
	* Создаём объект класса Regulator и TemperatureManipulationObject и вызываем метод для рассчёта и записи результатов в файл
	*/
	TemperatureManipulationObject* TMO;
	TMO = new Bake(0);

	Regulator* regulator;

	/// определяем момент времени, который нам необходим
	int time_moment;
	std::cout << "Enter the time moment: ";
	std::cin >> time_moment;

	/// определяем желаемое значение, к которому должна стремиться температура регулируемого объекта
	double desired_value;
	std::cout << "Enter the desired value: ";
	std::cin >> desired_value; 

	/// определяем начальные значения для регулятора и объектра его регулирования
	regulator = new BakeRegulator(TMO->get_temperature(0), desired_value);
	regulator->set_state_of_TMO(TMO->get_temperature(0));
	TMO->set_input_warm(regulator->get_managing());

	emulate_regulation_of_TMO(TMO, regulator, time_moment);

	delete regulator;
	delete TMO;

	std::cout << "\nWork is done! Please, wait the graphs!\n";

	/// вызывает программу на Python для построения графиков
	system("python visualisation.py");

	return 0;
}