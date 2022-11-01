# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Bake`](#class_bake) | Объект регулярования - печь
`class `[`BakeRegulator`](#class_bake_regulator) | Pегулятор температуры печи
`class `[`Regulator`](#class_regulator) | Абстрактный класс регулятора
`class `[`TemperatureManipulationObject`](#class_temperature_manipulation_object) | Абстрактный класс объекта регулирования

## class `Bake` {#class_bake}

```
class Bake
  : public TemperatureManipulationObject
```

Объект регулярования - печь

Унаследован от абстрактного класса объекта регулирования. Содержит в себе нелинейную функцию изменения температуры.

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual void `[`set_time`](#class_bake_1a9f6afb06705eb71a52908c411aa87ca5)`(size_t time_moment)` | для установки необходимого для анализа момента времени 
`public inline virtual void `[`set_input_warm`](#class_bake_1a4aed95fd25d9ba223cffe7cd010ce258)`(double managing)` | для установки управляющего воздейсвия регулятора 
`public inline virtual double `[`get_temperature`](#class_bake_1a064b8b2a1d73beb4c3371c2d142cf939)`(size_t time_moment)` | для получения температуры в необходимый момент времени 
`public inline  `[`Bake`](#class_bake_1a17d1b39fe517e2fbee41cb6c1661a2c4)`(size_t time_moment)` | 
`private double `[`nonlin_A`](#class_bake_1a4a9ad8b876c396702cebd06ce3b3db6c) | коэфициенты нелинейной модели изменения температуры
`private double `[`nonlin_B`](#class_bake_1afe654c3d1371bc2af302777dbd7432ee) | коэффициент при y^2(t - 2)
`private double `[`nonlin_C`](#class_bake_1a948e8e7c930590120931100f5b8d9dc4) | коэффициент при u(t)
`private double `[`nonlin_D`](#class_bake_1af145d25ce66f4963c8aeb140681200e5) | коэффициент при sin(u(t - 1))
`private size_t `[`time_border`](#class_bake_1add29c71c70ec5e7947244ba2a58a4f1c) | содержит информацию о последнем моменте времени, при котором работал объект
`private vector< double > `[`temperature_in_nonlinear_model`](#class_bake_1ad4885dadd24a19eea2cbb7811acff9b0) | содержит всё информацию о температуре объекта
`private inline virtual void `[`emulate_intput_warm`](#class_bake_1ab8f069f1a5f1643c1ab8455b5096e796)`()` | для эмуляции входной температуры
`private inline virtual void `[`emulate_temperature_changes`](#class_bake_1ab5d8129531b8cdb0a7192b227ea4d14c)`()` | для эмуляции изменения температуры

### Members

#### `public inline virtual void `[`set_time`](#class_bake_1a9f6afb06705eb71a52908c411aa87ca5)`(size_t time_moment)` {#class_bake_1a9f6afb06705eb71a52908c411aa87ca5}

для установки необходимого для анализа момента времени 
#### Parameters
* `time_moment` определяет момент времи, на котором необходимо отрегулировать объект

#### `public inline virtual void `[`set_input_warm`](#class_bake_1a4aed95fd25d9ba223cffe7cd010ce258)`(double managing)` {#class_bake_1a4aed95fd25d9ba223cffe7cd010ce258}

для установки управляющего воздейсвия регулятора 
#### Parameters
* `managing` определяет управляющее воздействия для объекта регулирования

#### `public inline virtual double `[`get_temperature`](#class_bake_1a064b8b2a1d73beb4c3371c2d142cf939)`(size_t time_moment)` {#class_bake_1a064b8b2a1d73beb4c3371c2d142cf939}

для получения температуры в необходимый момент времени 
#### Parameters
* `time_moment` определяет время, на котором необходимо получить температуру 

#### Returns
температура в определённый момент времени

#### `public inline  `[`Bake`](#class_bake_1a17d1b39fe517e2fbee41cb6c1661a2c4)`(size_t time_moment)` {#class_bake_1a17d1b39fe517e2fbee41cb6c1661a2c4}

#### `private double `[`nonlin_A`](#class_bake_1a4a9ad8b876c396702cebd06ce3b3db6c) {#class_bake_1a4a9ad8b876c396702cebd06ce3b3db6c}

коэфициенты нелинейной модели изменения температуры

коэффициент при y(t - 1)

#### `private double `[`nonlin_B`](#class_bake_1afe654c3d1371bc2af302777dbd7432ee) {#class_bake_1afe654c3d1371bc2af302777dbd7432ee}

коэффициент при y^2(t - 2)

#### `private double `[`nonlin_C`](#class_bake_1a948e8e7c930590120931100f5b8d9dc4) {#class_bake_1a948e8e7c930590120931100f5b8d9dc4}

коэффициент при u(t)

#### `private double `[`nonlin_D`](#class_bake_1af145d25ce66f4963c8aeb140681200e5) {#class_bake_1af145d25ce66f4963c8aeb140681200e5}

коэффициент при sin(u(t - 1))

#### `private size_t `[`time_border`](#class_bake_1add29c71c70ec5e7947244ba2a58a4f1c) {#class_bake_1add29c71c70ec5e7947244ba2a58a4f1c}

содержит информацию о последнем моменте времени, при котором работал объект

#### `private vector< double > `[`temperature_in_nonlinear_model`](#class_bake_1ad4885dadd24a19eea2cbb7811acff9b0) {#class_bake_1ad4885dadd24a19eea2cbb7811acff9b0}

содержит всё информацию о температуре объекта

#### `private inline virtual void `[`emulate_intput_warm`](#class_bake_1ab8f069f1a5f1643c1ab8455b5096e796)`()` {#class_bake_1ab8f069f1a5f1643c1ab8455b5096e796}

для эмуляции входной температуры

#### `private inline virtual void `[`emulate_temperature_changes`](#class_bake_1ab5d8129531b8cdb0a7192b227ea4d14c)`()` {#class_bake_1ab5d8129531b8cdb0a7192b227ea4d14c}

для эмуляции изменения температуры

## class `BakeRegulator` {#class_bake_regulator}

```
class BakeRegulator
  : public Regulator
```

Pегулятор температуры печи

Унаследован от абстрактного класса регулятора. Содержит в себе отклонение выходной переменной и функцию управляющего воздействия.

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual void `[`set_state_of_TMO`](#class_bake_regulator_1a3d394d68ccb147e021a6516a21256c82)`(double temperature)` | для установки управляющего воздейсвия регулятора 
`public inline virtual double `[`get_difference`](#class_bake_regulator_1a24159ac07c57fa5d3de788af88cd59ae)`()` | для получения значение e(t)
`public inline virtual double `[`get_managing`](#class_bake_regulator_1aa67bd5d4a5b3a79b5c20b62aef04d208)`()` | для получения значение u(t)
`public inline  `[`BakeRegulator`](#class_bake_regulator_1a140ecfffe5ff08bf36a052faef52baa1)`(double temperature, double desired_value)` | 
`private double `[`difference`](#class_bake_regulator_1a4696325922b7ab39ea81782bdcb2245d) | содержит значение e(t), e(t -1), e(t -2)
`private double `[`managing`](#class_bake_regulator_1a042cccb0b2738ce8a3b0c7f60a6ae7f1) | содержит значение u(t), u(t -1)
`private double `[`temp_temperature`](#class_bake_regulator_1ab9dca64380844e190c913861ec960e90) | содержит темепратуру, которая была получена от объекта регулирования
`private double `[`K`](#class_bake_regulator_1a8c6b693de645e62e015497a14129e2f9) | постоянные коэффициенты
`private double `[`Ti`](#class_bake_regulator_1a4dcb80d0013213e28faed6d6b73a800f) | постоянная интергрирования
`private double `[`Td`](#class_bake_regulator_1a9f4ae1fd5ab7e18fa50bf42e6ac36bb2) | постоянная дифференцирования
`private double `[`step_T`](#class_bake_regulator_1a88340c769d7bf2722be78320a17fc48f) | шаг квантования времени <br/>
`private inline double `[`count_q0`](#class_bake_regulator_1a6b6d4d88e16959f3429f9adbff9b1c19)`()` | параметры регулирвоания расчёт параметра q0
`private inline double `[`count_q1`](#class_bake_regulator_1aaed1e5fe3636ef78e80e9ca78128fbc0)`()` | расчёт параметра q1
`private inline double `[`count_q2`](#class_bake_regulator_1ab9ce02b6f88c325a17beebf4034d77eb)`()` | расчёт параметра q2
`private inline virtual double `[`count_managing`](#class_bake_regulator_1a92d2005c159d2da6630b66cfc4d85612)`()` | расчёт управляющего воздействия

### Members

#### `public inline virtual void `[`set_state_of_TMO`](#class_bake_regulator_1a3d394d68ccb147e021a6516a21256c82)`(double temperature)` {#class_bake_regulator_1a3d394d68ccb147e021a6516a21256c82}

для установки управляющего воздейсвия регулятора 
#### Parameters
* `temperature` определяет управляющее воздействия для объекта регулирования

#### `public inline virtual double `[`get_difference`](#class_bake_regulator_1a24159ac07c57fa5d3de788af88cd59ae)`()` {#class_bake_regulator_1a24159ac07c57fa5d3de788af88cd59ae}

для получения значение e(t)

#### `public inline virtual double `[`get_managing`](#class_bake_regulator_1aa67bd5d4a5b3a79b5c20b62aef04d208)`()` {#class_bake_regulator_1aa67bd5d4a5b3a79b5c20b62aef04d208}

для получения значение u(t)

#### `public inline  `[`BakeRegulator`](#class_bake_regulator_1a140ecfffe5ff08bf36a052faef52baa1)`(double temperature, double desired_value)` {#class_bake_regulator_1a140ecfffe5ff08bf36a052faef52baa1}

#### `private double `[`difference`](#class_bake_regulator_1a4696325922b7ab39ea81782bdcb2245d) {#class_bake_regulator_1a4696325922b7ab39ea81782bdcb2245d}

содержит значение e(t), e(t -1), e(t -2)

#### `private double `[`managing`](#class_bake_regulator_1a042cccb0b2738ce8a3b0c7f60a6ae7f1) {#class_bake_regulator_1a042cccb0b2738ce8a3b0c7f60a6ae7f1}

содержит значение u(t), u(t -1)

#### `private double `[`temp_temperature`](#class_bake_regulator_1ab9dca64380844e190c913861ec960e90) {#class_bake_regulator_1ab9dca64380844e190c913861ec960e90}

содержит темепратуру, которая была получена от объекта регулирования

#### `private double `[`K`](#class_bake_regulator_1a8c6b693de645e62e015497a14129e2f9) {#class_bake_regulator_1a8c6b693de645e62e015497a14129e2f9}

постоянные коэффициенты

коэффициент передачи

#### `private double `[`Ti`](#class_bake_regulator_1a4dcb80d0013213e28faed6d6b73a800f) {#class_bake_regulator_1a4dcb80d0013213e28faed6d6b73a800f}

постоянная интергрирования

#### `private double `[`Td`](#class_bake_regulator_1a9f4ae1fd5ab7e18fa50bf42e6ac36bb2) {#class_bake_regulator_1a9f4ae1fd5ab7e18fa50bf42e6ac36bb2}

постоянная дифференцирования

#### `private double `[`step_T`](#class_bake_regulator_1a88340c769d7bf2722be78320a17fc48f) {#class_bake_regulator_1a88340c769d7bf2722be78320a17fc48f}

шаг квантования времени <br/>

#### `private inline double `[`count_q0`](#class_bake_regulator_1a6b6d4d88e16959f3429f9adbff9b1c19)`()` {#class_bake_regulator_1a6b6d4d88e16959f3429f9adbff9b1c19}

параметры регулирвоания расчёт параметра q0

#### `private inline double `[`count_q1`](#class_bake_regulator_1aaed1e5fe3636ef78e80e9ca78128fbc0)`()` {#class_bake_regulator_1aaed1e5fe3636ef78e80e9ca78128fbc0}

расчёт параметра q1

#### `private inline double `[`count_q2`](#class_bake_regulator_1ab9ce02b6f88c325a17beebf4034d77eb)`()` {#class_bake_regulator_1ab9ce02b6f88c325a17beebf4034d77eb}

расчёт параметра q2

#### `private inline virtual double `[`count_managing`](#class_bake_regulator_1a92d2005c159d2da6630b66cfc4d85612)`()` {#class_bake_regulator_1a92d2005c159d2da6630b66cfc4d85612}

расчёт управляющего воздействия

## class `Regulator` {#class_regulator}

Абстрактный класс регулятора

Предоставляет интерфейс для взаимодействия с регулятором

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`set_state_of_TMO`](#class_regulator_1aa6cf746d5891f23c162341313408165a)`(double temperature)` | для установки управляющего воздейсвия регулятора 
`public double `[`get_difference`](#class_regulator_1a3d32b0240ab7808ac51c188edfdd4a7b)`()` | для получения значение e(t)
`public double `[`get_managing`](#class_regulator_1ab5e0466ad444cc046f9005c61500b435)`()` | для получения значение u(t)
`public inline  `[`Regulator`](#class_regulator_1a45bd171f0140aab3418ad4dd2e5f8087)`(double desired_value)` | 
`public inline virtual  `[`~Regulator`](#class_regulator_1af26b35487c13a95e6f5698563b7c7b4a)`()` | 
`protected double `[`desired_value`](#class_regulator_1a9cb75433d2ff8b69fcebddab334584d7) | содержит желаемое значение, к которому должна стремиться температура объекта
`protected double `[`count_managing`](#class_regulator_1ae3972aca77b795678352373c6e669d72)`()` | для расчёта управляющего воздействия

### Members

#### `public void `[`set_state_of_TMO`](#class_regulator_1aa6cf746d5891f23c162341313408165a)`(double temperature)` {#class_regulator_1aa6cf746d5891f23c162341313408165a}

для установки управляющего воздейсвия регулятора 
#### Parameters
* `temperature` определяет управляющее воздействия для объекта регулирования

#### `public double `[`get_difference`](#class_regulator_1a3d32b0240ab7808ac51c188edfdd4a7b)`()` {#class_regulator_1a3d32b0240ab7808ac51c188edfdd4a7b}

для получения значение e(t)

#### `public double `[`get_managing`](#class_regulator_1ab5e0466ad444cc046f9005c61500b435)`()` {#class_regulator_1ab5e0466ad444cc046f9005c61500b435}

для получения значение u(t)

#### `public inline  `[`Regulator`](#class_regulator_1a45bd171f0140aab3418ad4dd2e5f8087)`(double desired_value)` {#class_regulator_1a45bd171f0140aab3418ad4dd2e5f8087}

#### `public inline virtual  `[`~Regulator`](#class_regulator_1af26b35487c13a95e6f5698563b7c7b4a)`()` {#class_regulator_1af26b35487c13a95e6f5698563b7c7b4a}

#### `protected double `[`desired_value`](#class_regulator_1a9cb75433d2ff8b69fcebddab334584d7) {#class_regulator_1a9cb75433d2ff8b69fcebddab334584d7}

содержит желаемое значение, к которому должна стремиться температура объекта

#### `protected double `[`count_managing`](#class_regulator_1ae3972aca77b795678352373c6e669d72)`()` {#class_regulator_1ae3972aca77b795678352373c6e669d72}

для расчёта управляющего воздействия

## class `TemperatureManipulationObject` {#class_temperature_manipulation_object}

Абстрактный класс объекта регулирования

Предоставляет интерфейс для взаимодействия с объектом управления

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`set_time`](#class_temperature_manipulation_object_1ab3aca49bfbb6c039b61f3a84ad4287fa)`(size_t time_moment)` | для установки необходимого для анализа момента времени 
`public void `[`set_input_warm`](#class_temperature_manipulation_object_1a728346b63cb3a0d32353a24e49fda697)`(double managing)` | для установки управляющего воздейсвия регулятора 
`public double `[`get_temperature`](#class_temperature_manipulation_object_1af93a08ee40627f4a5ed87e43a6bb6d46)`(size_t time_moment)` | для получения температуры в необходимый момент времени 
`public inline  `[`TemperatureManipulationObject`](#class_temperature_manipulation_object_1ad773c90a4466d8532a896304dae95de1)`(size_t time_moment, double room_temperature)` | 
`public inline virtual  `[`~TemperatureManipulationObject`](#class_temperature_manipulation_object_1ab73dc08b848f0b80e3407d022c48560c)`()` | 
`protected double `[`ROOM_TEMPERATURE`](#class_temperature_manipulation_object_1ae8139179531c0b7323daa19e34001f1b) | содержит начальную температуру печи - принята комнатная температура
`protected size_t `[`time_moment`](#class_temperature_manipulation_object_1a080593cd67c0815fb5201426ab13f0a3) | содержит момент времени, на котором происходит работа оюъекта регулирования
`protected vector< double > `[`input_warm_per_moment`](#class_temperature_manipulation_object_1a1c14d27467090800a1ba5b0dd732dfcd) | содержит всё информацию о входном тепле
`protected void `[`emulate_intput_warm`](#class_temperature_manipulation_object_1a4b5464a5e79b08d41b975fc950963367)`()` | для эмуляции входной температуры
`protected void `[`emulate_temperature_changes`](#class_temperature_manipulation_object_1a8332d06265af14774ff5688a99553a17)`()` | для эмуляции изменения температуры

### Members

#### `public void `[`set_time`](#class_temperature_manipulation_object_1ab3aca49bfbb6c039b61f3a84ad4287fa)`(size_t time_moment)` {#class_temperature_manipulation_object_1ab3aca49bfbb6c039b61f3a84ad4287fa}

для установки необходимого для анализа момента времени 
#### Parameters
* `time_moment` определяет момент времи, на котором необходимо отрегулировать объект

#### `public void `[`set_input_warm`](#class_temperature_manipulation_object_1a728346b63cb3a0d32353a24e49fda697)`(double managing)` {#class_temperature_manipulation_object_1a728346b63cb3a0d32353a24e49fda697}

для установки управляющего воздейсвия регулятора 
#### Parameters
* `managing` определяет управляющее воздействия для объекта регулирования

#### `public double `[`get_temperature`](#class_temperature_manipulation_object_1af93a08ee40627f4a5ed87e43a6bb6d46)`(size_t time_moment)` {#class_temperature_manipulation_object_1af93a08ee40627f4a5ed87e43a6bb6d46}

для получения температуры в необходимый момент времени 
#### Parameters
* `time_moment` определяет время, на котором необходимо получить температуру 

#### Returns
температура в определённый момент времени

#### `public inline  `[`TemperatureManipulationObject`](#class_temperature_manipulation_object_1ad773c90a4466d8532a896304dae95de1)`(size_t time_moment, double room_temperature)` {#class_temperature_manipulation_object_1ad773c90a4466d8532a896304dae95de1}

#### `public inline virtual  `[`~TemperatureManipulationObject`](#class_temperature_manipulation_object_1ab73dc08b848f0b80e3407d022c48560c)`()` {#class_temperature_manipulation_object_1ab73dc08b848f0b80e3407d022c48560c}

#### `protected double `[`ROOM_TEMPERATURE`](#class_temperature_manipulation_object_1ae8139179531c0b7323daa19e34001f1b) {#class_temperature_manipulation_object_1ae8139179531c0b7323daa19e34001f1b}

содержит начальную температуру печи - принята комнатная температура

#### `protected size_t `[`time_moment`](#class_temperature_manipulation_object_1a080593cd67c0815fb5201426ab13f0a3) {#class_temperature_manipulation_object_1a080593cd67c0815fb5201426ab13f0a3}

содержит момент времени, на котором происходит работа оюъекта регулирования

#### `protected vector< double > `[`input_warm_per_moment`](#class_temperature_manipulation_object_1a1c14d27467090800a1ba5b0dd732dfcd) {#class_temperature_manipulation_object_1a1c14d27467090800a1ba5b0dd732dfcd}

содержит всё информацию о входном тепле

#### `protected void `[`emulate_intput_warm`](#class_temperature_manipulation_object_1a4b5464a5e79b08d41b975fc950963367)`()` {#class_temperature_manipulation_object_1a4b5464a5e79b08d41b975fc950963367}

для эмуляции входной температуры

#### `protected void `[`emulate_temperature_changes`](#class_temperature_manipulation_object_1a8332d06265af14774ff5688a99553a17)`()` {#class_temperature_manipulation_object_1a8332d06265af14774ff5688a99553a17}

для эмуляции изменения температуры

Generated by [Moxygen](https://sourcey.com/moxygen)