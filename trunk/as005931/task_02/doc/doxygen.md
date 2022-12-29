# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AbstraktnayaModel`](#class_abstraktnaya_model) | Абстрактный модель, которая будет наследоваться другими моделями.
`class `[`LineynayaModel`](#class_lineynaya_model) | Класс для линейной модели
`class `[`NelineynayaModel`](#class_nelineynaya_model) | Класс для нелинейной модели
`class `[`PidRegulator`](#class_pid_regulator) | Класс моделирования регулятора

## class `AbstraktnayaModel` {#class_abstraktnaya_model}

Абстрактный модель, которая будет наследоваться другими моделями.

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`virtual_model_method`](#class_abstraktnaya_model_1a63edb33e0b0ee85adcc8d0a39f01eb65)`(double curY, double warmInp)` | Виртуальный метод

### Members

#### `public double `[`virtual_model_method`](#class_abstraktnaya_model_1a63edb33e0b0ee85adcc8d0a39f01eb65)`(double curY, double warmInp)` {#class_abstraktnaya_model_1a63edb33e0b0ee85adcc8d0a39f01eb65}

Виртуальный метод

#### Parameters
* `curY` Температура 

* `warmInp` Тепло

## class `LineynayaModel` {#class_lineynaya_model}

```
class LineynayaModel
  : public AbstraktnayaModel
```

Класс для линейной модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LineynayaModel`](#class_lineynaya_model_1a3f396cd6e7b83b53d60af3cd7c3b675e)`(double a, double b, double nextY)` | 
`public inline virtual double `[`virtual_model_method`](#class_lineynaya_model_1a75388a64416a95dbc454a697082026df)`(double curY, double warmInp)` | Переопределённый метод
`private double `[`a_`](#class_lineynaya_model_1a0865c33d179a20310ad1a957856e284c) | Коэффициент
`private double `[`b_`](#class_lineynaya_model_1a2bd1368f22df29cf17b4372f85a2d74a) | Коэффициент
`private double `[`nextY_`](#class_lineynaya_model_1ae60d2d156315c5273ee0f8199a2c7144) | Получаемая нами температура

### Members

#### `public inline  `[`LineynayaModel`](#class_lineynaya_model_1a3f396cd6e7b83b53d60af3cd7c3b675e)`(double a, double b, double nextY)` {#class_lineynaya_model_1a3f396cd6e7b83b53d60af3cd7c3b675e}

#### `public inline virtual double `[`virtual_model_method`](#class_lineynaya_model_1a75388a64416a95dbc454a697082026df)`(double curY, double warmInp)` {#class_lineynaya_model_1a75388a64416a95dbc454a697082026df}

Переопределённый метод

#### `private double `[`a_`](#class_lineynaya_model_1a0865c33d179a20310ad1a957856e284c) {#class_lineynaya_model_1a0865c33d179a20310ad1a957856e284c}

Коэффициент

#### `private double `[`b_`](#class_lineynaya_model_1a2bd1368f22df29cf17b4372f85a2d74a) {#class_lineynaya_model_1a2bd1368f22df29cf17b4372f85a2d74a}

Коэффициент

#### `private double `[`nextY_`](#class_lineynaya_model_1ae60d2d156315c5273ee0f8199a2c7144) {#class_lineynaya_model_1ae60d2d156315c5273ee0f8199a2c7144}

Получаемая нами температура

## class `NelineynayaModel` {#class_nelineynaya_model}

```
class NelineynayaModel
  : public AbstraktnayaModel
```

Класс для нелинейной модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NelineynayaModel`](#class_nelineynaya_model_1aeba89b8438e702f4bac67ebf3603add2)`(double a, double b, double c, double d, double nextY)` | 
`public inline virtual double `[`virtual_model_method`](#class_nelineynaya_model_1adb36a72dcc034186fe7439eebab904b0)`(double curY, double warmInp)` | Переопределённый метод
`private double `[`a_`](#class_nelineynaya_model_1affa51416a46f83cd759225d6489790a1) | Коэффициент
`private double `[`b_`](#class_nelineynaya_model_1a706cba786cc352009892aba8d1cbfd2b) | Коэффициент
`private double `[`c_`](#class_nelineynaya_model_1a7a855b735245a3209ff8e65cd7cb2990) | Коэффициент
`private double `[`d_`](#class_nelineynaya_model_1aae7febd16e95f72b1de0fa1aecef6547) | Коэффициент
`private double `[`prevY_`](#class_nelineynaya_model_1a572f12b56f923eb74762c7baa37305c4) | Прошлая температура
`private double `[`nextY_`](#class_nelineynaya_model_1a43067e3bb7f80a86c10f57a91c5118cc) | Новая температура
`private double `[`prevW_`](#class_nelineynaya_model_1a30811c1e77370fe28ab9e77e67d05bca) | Прошлое тепло

### Members

#### `public inline  `[`NelineynayaModel`](#class_nelineynaya_model_1aeba89b8438e702f4bac67ebf3603add2)`(double a, double b, double c, double d, double nextY)` {#class_nelineynaya_model_1aeba89b8438e702f4bac67ebf3603add2}

#### `public inline virtual double `[`virtual_model_method`](#class_nelineynaya_model_1adb36a72dcc034186fe7439eebab904b0)`(double curY, double warmInp)` {#class_nelineynaya_model_1adb36a72dcc034186fe7439eebab904b0}

Переопределённый метод

#### `private double `[`a_`](#class_nelineynaya_model_1affa51416a46f83cd759225d6489790a1) {#class_nelineynaya_model_1affa51416a46f83cd759225d6489790a1}

Коэффициент

#### `private double `[`b_`](#class_nelineynaya_model_1a706cba786cc352009892aba8d1cbfd2b) {#class_nelineynaya_model_1a706cba786cc352009892aba8d1cbfd2b}

Коэффициент

#### `private double `[`c_`](#class_nelineynaya_model_1a7a855b735245a3209ff8e65cd7cb2990) {#class_nelineynaya_model_1a7a855b735245a3209ff8e65cd7cb2990}

Коэффициент

#### `private double `[`d_`](#class_nelineynaya_model_1aae7febd16e95f72b1de0fa1aecef6547) {#class_nelineynaya_model_1aae7febd16e95f72b1de0fa1aecef6547}

Коэффициент

#### `private double `[`prevY_`](#class_nelineynaya_model_1a572f12b56f923eb74762c7baa37305c4) {#class_nelineynaya_model_1a572f12b56f923eb74762c7baa37305c4}

Прошлая температура

#### `private double `[`nextY_`](#class_nelineynaya_model_1a43067e3bb7f80a86c10f57a91c5118cc) {#class_nelineynaya_model_1a43067e3bb7f80a86c10f57a91c5118cc}

Новая температура

#### `private double `[`prevW_`](#class_nelineynaya_model_1a30811c1e77370fe28ab9e77e67d05bca) {#class_nelineynaya_model_1a30811c1e77370fe28ab9e77e67d05bca}

Прошлое тепло

## class `PidRegulator` {#class_pid_regulator}

Класс моделирования регулятора

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`PidRegulator`](#class_pid_regulator_1ac19f257de0c8bc7f6227a27270b9206d)`(double T, double T0, double TD, double K)` | 
`public inline void `[`CalculatePIDRegulator`](#class_pid_regulator_1abd3dc3d8666875d29e6d484230481678)`(double w, double n)` | Метод моделирования ПИД-регулятора
`private double `[`T_`](#class_pid_regulator_1abd288e71c13e1e7676b51f53f8d1676b) | Постоянная интегрирования
`private double `[`T0_`](#class_pid_regulator_1a39749f6ef6098fa6247be3a207d74e5f) | Шаг квантования
`private double `[`TD_`](#class_pid_regulator_1aa7e39fbe574d3454b9bb16b9902b4063) | Постоянная дифференцирования
`private double `[`K_`](#class_pid_regulator_1a6ec4303baf14132b5313229dde8eaa98) | Коэффициент передачи
`private double `[`uk_`](#class_pid_regulator_1af470392ec404bdc0d20bfc833f459037) | Значение управляющего воздействия
`private inline double `[`UKCalculate`](#class_pid_regulator_1ab1f657770c718f2f49dc9d47154a4062)`(double ek, double ek1, double ek2)` | 

### Members

#### `public inline  `[`PidRegulator`](#class_pid_regulator_1ac19f257de0c8bc7f6227a27270b9206d)`(double T, double T0, double TD, double K)` {#class_pid_regulator_1ac19f257de0c8bc7f6227a27270b9206d}

#### `public inline void `[`CalculatePIDRegulator`](#class_pid_regulator_1abd3dc3d8666875d29e6d484230481678)`(double w, double n)` {#class_pid_regulator_1abd3dc3d8666875d29e6d484230481678}

Метод моделирования ПИД-регулятора

#### Parameters
* `w` Значение, которое хотим получить 

* `n` Начальное значение y

#### `private double `[`T_`](#class_pid_regulator_1abd288e71c13e1e7676b51f53f8d1676b) {#class_pid_regulator_1abd288e71c13e1e7676b51f53f8d1676b}

Постоянная интегрирования

#### `private double `[`T0_`](#class_pid_regulator_1a39749f6ef6098fa6247be3a207d74e5f) {#class_pid_regulator_1a39749f6ef6098fa6247be3a207d74e5f}

Шаг квантования

#### `private double `[`TD_`](#class_pid_regulator_1aa7e39fbe574d3454b9bb16b9902b4063) {#class_pid_regulator_1aa7e39fbe574d3454b9bb16b9902b4063}

Постоянная дифференцирования

#### `private double `[`K_`](#class_pid_regulator_1a6ec4303baf14132b5313229dde8eaa98) {#class_pid_regulator_1a6ec4303baf14132b5313229dde8eaa98}

Коэффициент передачи

#### `private double `[`uk_`](#class_pid_regulator_1af470392ec404bdc0d20bfc833f459037) {#class_pid_regulator_1af470392ec404bdc0d20bfc833f459037}

Значение управляющего воздействия

#### `private inline double `[`UKCalculate`](#class_pid_regulator_1ab1f657770c718f2f49dc9d47154a4062)`(double ek, double ek1, double ek2)` {#class_pid_regulator_1ab1f657770c718f2f49dc9d47154a4062}

Generated by [Moxygen](https://sourcey.com/moxygen)