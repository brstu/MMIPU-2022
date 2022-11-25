# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`nolinemodel`](#classnolinemodel) | Класс нелинейной модели
`class `[`PID_controller`](#class_p_i_d__controller) | Абстрактный класс пид-контроллера
`class `[`Regulator`](#class_regulator) | Абстрактный класс моделей вычисления

## class `nolinemodel` {#classnolinemodel}

```
class nolinemodel
  : public Regulator
```

Класс нелинейной модели

Является подклассом Model

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual double `[`regulator`](#classnolinemodel_1a3329aa139c5047141fac8f5ee62d139e)`(double in_temp, double in_warm)` | Метод вычисления температуры для нелинейной температуры
`private const double `[`a`](#classnolinemodel_1a1cdba1adad1f8bf8e1e9a4e32d0438a8) | Константы нелинейной модели
`private const double `[`b`](#classnolinemodel_1a95571213fbd074fef81fe1fba57338e0) | 
`private const double `[`c`](#classnolinemodel_1a113886922031a3e1a82ce6b5c6d93aec) | 
`private const double `[`d`](#classnolinemodel_1afa476e856370bdca0ddcd93ebc7e40da) | 
`private double `[`c_warm`](#classnolinemodel_1acb45015c726da70ea7d4fb30a64310d0) | 
`private double `[`c_temp`](#classnolinemodel_1a90fa540257c8d3f0b95822a532c53c2c) | 

### Members

#### `public inline virtual double `[`regulator`](#classnolinemodel_1a3329aa139c5047141fac8f5ee62d139e)`(double in_temp, double in_warm)` {#classnolinemodel_1a3329aa139c5047141fac8f5ee62d139e}

Метод вычисления температуры для нелинейной температуры

#### Parameters
* `in_warm` Выходное тепло 

#### Returns
double

#### `private const double `[`a`](#classnolinemodel_1a1cdba1adad1f8bf8e1e9a4e32d0438a8) {#classnolinemodel_1a1cdba1adad1f8bf8e1e9a4e32d0438a8}

Константы нелинейной модели

#### Parameters
* `temp` Текущая температура 

* `a` Параметр А 

* `b` Параметр B 

* `c` Параметр С 

* `d` Параметр D

#### `private const double `[`b`](#classnolinemodel_1a95571213fbd074fef81fe1fba57338e0) {#classnolinemodel_1a95571213fbd074fef81fe1fba57338e0}

#### `private const double `[`c`](#classnolinemodel_1a113886922031a3e1a82ce6b5c6d93aec) {#classnolinemodel_1a113886922031a3e1a82ce6b5c6d93aec}

#### `private const double `[`d`](#classnolinemodel_1afa476e856370bdca0ddcd93ebc7e40da) {#classnolinemodel_1afa476e856370bdca0ddcd93ebc7e40da}

#### `private double `[`c_warm`](#classnolinemodel_1acb45015c726da70ea7d4fb30a64310d0) {#classnolinemodel_1acb45015c726da70ea7d4fb30a64310d0}

#### `private double `[`c_temp`](#classnolinemodel_1a90fa540257c8d3f0b95822a532c53c2c) {#classnolinemodel_1a90fa540257c8d3f0b95822a532c53c2c}

## class `PID_controller` {#class_p_i_d__controller}

Абстрактный класс пид-контроллера

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`controller`](#class_p_i_d__controller_1a8f0fdbda1f69726508eaebe7657d544d)`(double e, double e1, double e2)` | 
`public inline void `[`Reset_U`](#class_p_i_d__controller_1a82f45df3cab5592c644e0010909d60a1)`()` | 
`public inline double `[`PID_contr`](#class_p_i_d__controller_1a50aced8b083a102e1a5b646cdecfc134)`(double w, double y0, `[`Regulator`](#class_regulator)` * model)` | 
`private double `[`u`](#class_p_i_d__controller_1adc1a0d283bf172b3989ceb3f8b94d395) | controller
`private double `[`Td`](#class_p_i_d__controller_1afed0f7047921ed2a07232ce770d9e85a) | 
`private double `[`T`](#class_p_i_d__controller_1a88e6c57a17bf0372d6b4bcd52dae13a8) | 
`private double `[`T0`](#class_p_i_d__controller_1a24fba432394075e763ca8f18ff3285e9) | 
`private double `[`k`](#class_p_i_d__controller_1a75a15b60e8d357b2a4200ebb0387bfb9) | 

### Members

#### `public inline double `[`controller`](#class_p_i_d__controller_1a8f0fdbda1f69726508eaebe7657d544d)`(double e, double e1, double e2)` {#class_p_i_d__controller_1a8f0fdbda1f69726508eaebe7657d544d}

#### `public inline void `[`Reset_U`](#class_p_i_d__controller_1a82f45df3cab5592c644e0010909d60a1)`()` {#class_p_i_d__controller_1a82f45df3cab5592c644e0010909d60a1}

#### `public inline double `[`PID_contr`](#class_p_i_d__controller_1a50aced8b083a102e1a5b646cdecfc134)`(double w, double y0, `[`Regulator`](#class_regulator)` * model)` {#class_p_i_d__controller_1a50aced8b083a102e1a5b646cdecfc134}

#### `private double `[`u`](#class_p_i_d__controller_1adc1a0d283bf172b3989ceb3f8b94d395) {#class_p_i_d__controller_1adc1a0d283bf172b3989ceb3f8b94d395}

controller

#### Parameters
* `T` Параметр Т 

* `T0` Параметр Т0 

* `Td` Параметр Td 

* `K` Параметр k

#### `private double `[`Td`](#class_p_i_d__controller_1afed0f7047921ed2a07232ce770d9e85a) {#class_p_i_d__controller_1afed0f7047921ed2a07232ce770d9e85a}

#### `private double `[`T`](#class_p_i_d__controller_1a88e6c57a17bf0372d6b4bcd52dae13a8) {#class_p_i_d__controller_1a88e6c57a17bf0372d6b4bcd52dae13a8}

#### `private double `[`T0`](#class_p_i_d__controller_1a24fba432394075e763ca8f18ff3285e9) {#class_p_i_d__controller_1a24fba432394075e763ca8f18ff3285e9}

#### `private double `[`k`](#class_p_i_d__controller_1a75a15b60e8d357b2a4200ebb0387bfb9) {#class_p_i_d__controller_1a75a15b60e8d357b2a4200ebb0387bfb9}

## class `Regulator` {#class_regulator}

Абстрактный класс моделей вычисления

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`regulator`](#class_regulator_1a1f38dc31ad584dcfb2bad02f3dd13441)`(double in_temp, double in_warm)` | 

### Members

#### `public double `[`regulator`](#class_regulator_1a1f38dc31ad584dcfb2bad02f3dd13441)`(double in_temp, double in_warm)` {#class_regulator_1a1f38dc31ad584dcfb2bad02f3dd13441}

Generated by [Moxygen](https://sourcey.com/moxygen)