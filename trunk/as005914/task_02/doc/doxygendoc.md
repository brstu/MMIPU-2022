# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AXCF`](#class_a_x_c_f) | Абстрактный класс пид-контроллера
`class `[`NoLinealFunct`](#class_no_lineal_funct) | Класс нелинейной модели

## class `AXCF` {#class_a_x_c_f}

Абстрактный класс пид-контроллера

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`AXCF_contr`](#class_a_x_c_f_1a9d697f8422af9dc9dc241662d7b363c9)`(double e, double e1, double e2)` | 
`public inline double `[`PID_contr`](#class_a_x_c_f_1a17a6fa058a3bac5b68278accfb44915e)`(double w, double y0, `[`NoLinealFunct`](#class_no_lineal_funct)` * nlfunct)` | 
`protected double `[`u`](#class_a_x_c_f_1af80156920386790c48072aa8385d9506) | AXCF_contr.
`protected double `[`_Td`](#class_a_x_c_f_1a2be63212bd907953724468d86932b052) | 
`protected double `[`_T`](#class_a_x_c_f_1a1e2bbf5e0590e076a825fbf678f36fb5) | 
`protected double `[`_T0`](#class_a_x_c_f_1ad836aada6441b140d0db1c48bdb8ab78) | 
`protected double `[`k`](#class_a_x_c_f_1a76f5a13d8e6756faeb1639625ee38420) | 

### Members

#### `public inline double `[`AXCF_contr`](#class_a_x_c_f_1a9d697f8422af9dc9dc241662d7b363c9)`(double e, double e1, double e2)` {#class_a_x_c_f_1a9d697f8422af9dc9dc241662d7b363c9}

#### `public inline double `[`PID_contr`](#class_a_x_c_f_1a17a6fa058a3bac5b68278accfb44915e)`(double w, double y0, `[`NoLinealFunct`](#class_no_lineal_funct)` * nlfunct)` {#class_a_x_c_f_1a17a6fa058a3bac5b68278accfb44915e}

#### `protected double `[`u`](#class_a_x_c_f_1af80156920386790c48072aa8385d9506) {#class_a_x_c_f_1af80156920386790c48072aa8385d9506}

AXCF_contr.

#### Parameters
* `T` Параметр Т 

* `T0` Параметр Т0 

* `Td` Параметр Td 

* `K` Параметр k

#### `protected double `[`_Td`](#class_a_x_c_f_1a2be63212bd907953724468d86932b052) {#class_a_x_c_f_1a2be63212bd907953724468d86932b052}

#### `protected double `[`_T`](#class_a_x_c_f_1a1e2bbf5e0590e076a825fbf678f36fb5) {#class_a_x_c_f_1a1e2bbf5e0590e076a825fbf678f36fb5}

#### `protected double `[`_T0`](#class_a_x_c_f_1ad836aada6441b140d0db1c48bdb8ab78) {#class_a_x_c_f_1ad836aada6441b140d0db1c48bdb8ab78}

#### `protected double `[`k`](#class_a_x_c_f_1a76f5a13d8e6756faeb1639625ee38420) {#class_a_x_c_f_1a76f5a13d8e6756faeb1639625ee38420}

## class `NoLinealFunct` {#class_no_lineal_funct}

Класс нелинейной модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`funct`](#class_no_lineal_funct_1a14bdfe7cf0318b5e9f6937fc8f99990a)`(double i_t, double i_w)` | Метод вычисления температуры для нелинейной температуры
`protected const double `[`a`](#class_no_lineal_funct_1a762ac02430f5e9e429ad2fcf1b971b6a) | Константы нелинейной модели
`protected const double `[`b`](#class_no_lineal_funct_1a048e6cac4653b61a85227c528c7e3254) | 
`protected const double `[`c`](#class_no_lineal_funct_1aab8d43dc2126e07ccf2597c2702c2ec8) | 
`protected const double `[`d`](#class_no_lineal_funct_1affddebec86f3b4764cf915e56f16c50f) | 
`protected double `[`i_w_minus1`](#class_no_lineal_funct_1ac2801d9362fa5035abd305a37a3ab0c1) | 
`protected double `[`i_t_minus1`](#class_no_lineal_funct_1af0229045c4ef14cb5ad5aea6791f0a19) | 

### Members

#### `public inline double `[`funct`](#class_no_lineal_funct_1a14bdfe7cf0318b5e9f6937fc8f99990a)`(double i_t, double i_w)` {#class_no_lineal_funct_1a14bdfe7cf0318b5e9f6937fc8f99990a}

Метод вычисления температуры для нелинейной температуры

#### Parameters
* `i_w` Выходное тепло 

#### Returns
double

#### `protected const double `[`a`](#class_no_lineal_funct_1a762ac02430f5e9e429ad2fcf1b971b6a) {#class_no_lineal_funct_1a762ac02430f5e9e429ad2fcf1b971b6a}

Константы нелинейной модели

#### Parameters
* `temp` Текущая температура 

* `a` Параметр А 

* `b` Параметр B 

* `c` Параметр С 

* `d` Параметр D

#### `protected const double `[`b`](#class_no_lineal_funct_1a048e6cac4653b61a85227c528c7e3254) {#class_no_lineal_funct_1a048e6cac4653b61a85227c528c7e3254}

#### `protected const double `[`c`](#class_no_lineal_funct_1aab8d43dc2126e07ccf2597c2702c2ec8) {#class_no_lineal_funct_1aab8d43dc2126e07ccf2597c2702c2ec8}

#### `protected const double `[`d`](#class_no_lineal_funct_1affddebec86f3b4764cf915e56f16c50f) {#class_no_lineal_funct_1affddebec86f3b4764cf915e56f16c50f}

#### `protected double `[`i_w_minus1`](#class_no_lineal_funct_1ac2801d9362fa5035abd305a37a3ab0c1) {#class_no_lineal_funct_1ac2801d9362fa5035abd305a37a3ab0c1}

#### `protected double `[`i_t_minus1`](#class_no_lineal_funct_1af0229045c4ef14cb5ad5aea6791f0a19) {#class_no_lineal_funct_1af0229045c4ef14cb5ad5aea6791f0a19}

Generated by [Moxygen](https://sourcey.com/moxygen)