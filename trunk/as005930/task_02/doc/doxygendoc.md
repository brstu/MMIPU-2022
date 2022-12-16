# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`NonLinearModel`](#class_non_linear_model) | Конкретный класс модели изменения температуры
`class `[`PID_Object`](#class_p_i_d___object) | Абстрактный класс объекта для ПИД-регулирования
`class `[`Regulator`](#class_regulator) | Конкретный класс регулятора
`class `[`Rocket`](#class_rocket) | Конкретный класс рокеты в качестве объекта ПИД-регулирования

## class `NonLinearModel` {#class_non_linear_model}

Конкретный класс модели изменения температуры

Предоставляет функцию изменения температуры по нелинейной модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`count_temperature`](#class_non_linear_model_1adb30a1b71080db77bb7d49903efc549f)`(double T1, double T2, double W1, double W2)` | функция для расчёта температуры по нелинейной модели 
`private double `[`A`](#class_non_linear_model_1a2ab536d8ee22296ff34dbe785d1e69de) | 
`private double `[`B`](#class_non_linear_model_1a564e0d8466ff91584ee99582695b309b) | 
`private double `[`C`](#class_non_linear_model_1a011fd75f3fc6c727acf0cc19d1107c55) | 
`private double `[`D`](#class_non_linear_model_1aabced1ca52ba4da400902ad6c7ff0e95) | коэффициенты нелинейной модели

### Members

#### `public inline double `[`count_temperature`](#class_non_linear_model_1adb30a1b71080db77bb7d49903efc549f)`(double T1, double T2, double W1, double W2)` {#class_non_linear_model_1adb30a1b71080db77bb7d49903efc549f}

функция для расчёта температуры по нелинейной модели 
#### Parameters
* `T1` температура на прошлом моменте времени 

* `T2` температура на позапрошлом моменте времени 

* `W1` тепло на прошлом моменте времени 

* `W2` тепло на позапрошлом моменте времени 

#### Returns
параметр вещественного типа, определяющий температуру в настоящий момент времени

#### `private double `[`A`](#class_non_linear_model_1a2ab536d8ee22296ff34dbe785d1e69de) {#class_non_linear_model_1a2ab536d8ee22296ff34dbe785d1e69de}

#### `private double `[`B`](#class_non_linear_model_1a564e0d8466ff91584ee99582695b309b) {#class_non_linear_model_1a564e0d8466ff91584ee99582695b309b}

#### `private double `[`C`](#class_non_linear_model_1a011fd75f3fc6c727acf0cc19d1107c55) {#class_non_linear_model_1a011fd75f3fc6c727acf0cc19d1107c55}

#### `private double `[`D`](#class_non_linear_model_1aabced1ca52ba4da400902ad6c7ff0e95) {#class_non_linear_model_1aabced1ca52ba4da400902ad6c7ff0e95}

коэффициенты нелинейной модели

## class `PID_Object` {#class_p_i_d___object}

Абстрактный класс объекта для ПИД-регулирования

Предоставляет интерфейс для работы с объектом, подлежащего регулированию

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`count_y_t`](#class_p_i_d___object_1acd183a6f03e0d4a0ec5691dc54b38185)`()` | для расчёта температуры в настоящий момент времени
`public void `[`set_w_t`](#class_p_i_d___object_1a7d576c81606360275005801f3ab4b8b8)`(double u_t)` | для установление управляющего воздействия регулятора 
`public double `[`get_y_t`](#class_p_i_d___object_1a5f10c094717b8e4c524bfef760a6a261)`()` | для получения температуры в настоящий момент времени 
`public inline  `[`~PID_Object`](#class_p_i_d___object_1aa80034978cf8136281cfeb754ace5ed6)`()` | виртуальный деструктор абстрактного класса объекта, подлежащего регулированию

### Members

#### `public void `[`count_y_t`](#class_p_i_d___object_1acd183a6f03e0d4a0ec5691dc54b38185)`()` {#class_p_i_d___object_1acd183a6f03e0d4a0ec5691dc54b38185}

для расчёта температуры в настоящий момент времени

#### `public void `[`set_w_t`](#class_p_i_d___object_1a7d576c81606360275005801f3ab4b8b8)`(double u_t)` {#class_p_i_d___object_1a7d576c81606360275005801f3ab4b8b8}

для установление управляющего воздействия регулятора 
#### Parameters
* `u_t` определяет управляющее воздействие регулятора

#### `public double `[`get_y_t`](#class_p_i_d___object_1a5f10c094717b8e4c524bfef760a6a261)`()` {#class_p_i_d___object_1a5f10c094717b8e4c524bfef760a6a261}

для получения температуры в настоящий момент времени 
#### Returns
параметр вещественного типа, определяющий температуру в настоящий момент времени

#### `public inline  `[`~PID_Object`](#class_p_i_d___object_1aa80034978cf8136281cfeb754ace5ed6)`()` {#class_p_i_d___object_1aa80034978cf8136281cfeb754ace5ed6}

виртуальный деструктор абстрактного класса объекта, подлежащего регулированию

## class `Regulator` {#class_regulator}

Конкретный класс регулятора

Для расчёта e(t) - разницы между текущим и желаемым значением температуры и u(t) - управляющего воздействия

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline void `[`set_y_t`](#class_regulator_1afc646366237f7e07c26e848a54f2d52c)`(double y)` | для расчёта параметров регулятора с поступлением нового значения температуры
`public inline double `[`get_e_t`](#class_regulator_1a3e0257bb58b1e4d27e5a409fbbaab847)`()` | для возврата разницы между желаемым значением и текущей температурой
`public inline double `[`get_u_t`](#class_regulator_1ae0ecfebf98612c50f9e190233ab308e1)`()` | для возврата управляющего воздействия
`public inline  `[`Regulator`](#class_regulator_1ae16af2e64fe5ed0e3c94eb3d7991dc26)`(double temperature, double target_value)` | Конструктор объекта регулирования 
`private double `[`target_value`](#class_regulator_1a2c0e9bd894256e31068d0786661bb51c) | желаемое значение
`private double `[`e_t`](#class_regulator_1a5c1c018fa837d3c8f05a823e5654fdfe) | массив, содержащий разницу целевой температуры и температуры в настоящий, прошлый и позапрошлый моменты времени
`private double `[`u_t`](#class_regulator_1a1d622bd985e141a2d642142d015dfb26) | массив, содержащий управляющее воздействие в настоящий и прошлый моменты времени
`private double `[`temp_temperature`](#class_regulator_1ac039c2cffdc7b47af3fa98edcf787d6e) | для хранения переданной в регулятор температуры
`private double `[`K`](#class_regulator_1adc5f649054e71e71782b3241042ed8b6) | коэффициент передачи
`private double `[`Ti`](#class_regulator_1ac264a5c12ad37ecaf44b75927d7b2f9f) | постоянная интегрирования
`private double `[`Td`](#class_regulator_1a7f3b0d46792663b37a9db6f947c0af25) | постоянная дифференцирования
`private double `[`T0`](#class_regulator_1a932272706482e866663e337f74a3d0ef) | временной шаг
`private double `[`q0`](#class_regulator_1af962577f426e804580711d3c773a3ad5) | хранит значение параметра q0
`private double `[`q1`](#class_regulator_1a53aed74ac6e57619ac3d9b64f5443b24) | хранит значение параметра q1
`private double `[`q2`](#class_regulator_1afa9c8e09f13b3c076e31da1dddce044d) | хранит значение параметра q2
`private inline double `[`count_u_t`](#class_regulator_1adf649605e9c180a72f86456f7fe2db5b)`()` | для расчёта управляющего воздействия

### Members

#### `public inline void `[`set_y_t`](#class_regulator_1afc646366237f7e07c26e848a54f2d52c)`(double y)` {#class_regulator_1afc646366237f7e07c26e848a54f2d52c}

для расчёта параметров регулятора с поступлением нового значения температуры

#### `public inline double `[`get_e_t`](#class_regulator_1a3e0257bb58b1e4d27e5a409fbbaab847)`()` {#class_regulator_1a3e0257bb58b1e4d27e5a409fbbaab847}

для возврата разницы между желаемым значением и текущей температурой

#### `public inline double `[`get_u_t`](#class_regulator_1ae0ecfebf98612c50f9e190233ab308e1)`()` {#class_regulator_1ae0ecfebf98612c50f9e190233ab308e1}

для возврата управляющего воздействия

#### `public inline  `[`Regulator`](#class_regulator_1ae16af2e64fe5ed0e3c94eb3d7991dc26)`(double temperature, double target_value)` {#class_regulator_1ae16af2e64fe5ed0e3c94eb3d7991dc26}

Конструктор объекта регулирования 
#### Parameters
* `t_0` начальная температура объекта 

* `w_0` начальное тепло, поступающее объекту

#### `private double `[`target_value`](#class_regulator_1a2c0e9bd894256e31068d0786661bb51c) {#class_regulator_1a2c0e9bd894256e31068d0786661bb51c}

желаемое значение

#### `private double `[`e_t`](#class_regulator_1a5c1c018fa837d3c8f05a823e5654fdfe) {#class_regulator_1a5c1c018fa837d3c8f05a823e5654fdfe}

массив, содержащий разницу целевой температуры и температуры в настоящий, прошлый и позапрошлый моменты времени

#### `private double `[`u_t`](#class_regulator_1a1d622bd985e141a2d642142d015dfb26) {#class_regulator_1a1d622bd985e141a2d642142d015dfb26}

массив, содержащий управляющее воздействие в настоящий и прошлый моменты времени

#### `private double `[`temp_temperature`](#class_regulator_1ac039c2cffdc7b47af3fa98edcf787d6e) {#class_regulator_1ac039c2cffdc7b47af3fa98edcf787d6e}

для хранения переданной в регулятор температуры

#### `private double `[`K`](#class_regulator_1adc5f649054e71e71782b3241042ed8b6) {#class_regulator_1adc5f649054e71e71782b3241042ed8b6}

коэффициент передачи

#### `private double `[`Ti`](#class_regulator_1ac264a5c12ad37ecaf44b75927d7b2f9f) {#class_regulator_1ac264a5c12ad37ecaf44b75927d7b2f9f}

постоянная интегрирования

#### `private double `[`Td`](#class_regulator_1a7f3b0d46792663b37a9db6f947c0af25) {#class_regulator_1a7f3b0d46792663b37a9db6f947c0af25}

постоянная дифференцирования

#### `private double `[`T0`](#class_regulator_1a932272706482e866663e337f74a3d0ef) {#class_regulator_1a932272706482e866663e337f74a3d0ef}

временной шаг

#### `private double `[`q0`](#class_regulator_1af962577f426e804580711d3c773a3ad5) {#class_regulator_1af962577f426e804580711d3c773a3ad5}

хранит значение параметра q0

#### `private double `[`q1`](#class_regulator_1a53aed74ac6e57619ac3d9b64f5443b24) {#class_regulator_1a53aed74ac6e57619ac3d9b64f5443b24}

хранит значение параметра q1

#### `private double `[`q2`](#class_regulator_1afa9c8e09f13b3c076e31da1dddce044d) {#class_regulator_1afa9c8e09f13b3c076e31da1dddce044d}

хранит значение параметра q2

#### `private inline double `[`count_u_t`](#class_regulator_1adf649605e9c180a72f86456f7fe2db5b)`()` {#class_regulator_1adf649605e9c180a72f86456f7fe2db5b}

для расчёта управляющего воздействия

## class `Rocket` {#class_rocket}

```
class Rocket
  : public PID_Object
```

Конкретный класс рокеты в качестве объекта ПИД-регулирования

Релизует интерфейс от родительского класса для работы с рокетой, подлежащей регулированию

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual void `[`count_y_t`](#class_rocket_1a8a389fd4b2ec65e4fed5c937323eed9b)`()` | для расчёта температуры в настоящий момент времени
`public inline virtual void `[`set_w_t`](#class_rocket_1ae4535c181905af23a0748aae3557b08e)`(double u_t)` | для установление управляющего воздействия регулятора 
`public inline virtual double `[`get_y_t`](#class_rocket_1a25680f13366f02f4086c4b29075597fc)`()` | для получения температуры в настоящий момент времени 
`public inline  `[`Rocket`](#class_rocket_1adb587f7d9c9abc521dd46af70639438d)`(double t_0, double w_0)` | Конструктор объекта регулирования 
`private `[`NonLinearModel`](#class_non_linear_model)` `[`NLM`](#class_rocket_1af33b57cde126b2610f9498ad823f927b) | агрегированная переменная нелинейной модели изменения температуры
`private double `[`y_t`](#class_rocket_1a0cadb9f0d4e09bb7c3e5e334dbc73fee) | массив для хранения значений температуры в настоящий, прошлый и позапрошлый моменты времени
`private double `[`w_t`](#class_rocket_1a9d6c74e85c9ba6747f7e6a6d77a1f6fb) | массив для хранения значений тепла в настоящий и прошлый моменты времени

### Members

#### `public inline virtual void `[`count_y_t`](#class_rocket_1a8a389fd4b2ec65e4fed5c937323eed9b)`()` {#class_rocket_1a8a389fd4b2ec65e4fed5c937323eed9b}

для расчёта температуры в настоящий момент времени

#### `public inline virtual void `[`set_w_t`](#class_rocket_1ae4535c181905af23a0748aae3557b08e)`(double u_t)` {#class_rocket_1ae4535c181905af23a0748aae3557b08e}

для установление управляющего воздействия регулятора 
#### Parameters
* `u_t` определяет управляющее воздействие регулятора

#### `public inline virtual double `[`get_y_t`](#class_rocket_1a25680f13366f02f4086c4b29075597fc)`()` {#class_rocket_1a25680f13366f02f4086c4b29075597fc}

для получения температуры в настоящий момент времени 
#### Returns
параметр вещественного типа, определяющий температуру в настоящий момент времени

#### `public inline  `[`Rocket`](#class_rocket_1adb587f7d9c9abc521dd46af70639438d)`(double t_0, double w_0)` {#class_rocket_1adb587f7d9c9abc521dd46af70639438d}

Конструктор объекта регулирования 
#### Parameters
* `t_0` начальная температура объекта 

* `w_0` начальное тепло, поступающее объекту

#### `private `[`NonLinearModel`](#class_non_linear_model)` `[`NLM`](#class_rocket_1af33b57cde126b2610f9498ad823f927b) {#class_rocket_1af33b57cde126b2610f9498ad823f927b}

агрегированная переменная нелинейной модели изменения температуры

#### `private double `[`y_t`](#class_rocket_1a0cadb9f0d4e09bb7c3e5e334dbc73fee) {#class_rocket_1a0cadb9f0d4e09bb7c3e5e334dbc73fee}

массив для хранения значений температуры в настоящий, прошлый и позапрошлый моменты времени

#### `private double `[`w_t`](#class_rocket_1a9d6c74e85c9ba6747f7e6a6d77a1f6fb) {#class_rocket_1a9d6c74e85c9ba6747f7e6a6d77a1f6fb}

массив для хранения значений тепла в настоящий и прошлый моменты времени

Generated by [Moxygen](https://sourcey.com/moxygen)