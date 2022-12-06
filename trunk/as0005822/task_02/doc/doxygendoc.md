# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Control`](#class_control) | Абстрактный класс моделей вычисления
`class `[`LinaelModel`](#class_linael_model) | Класс линейной модели
`class `[`LinealModel`](#class_lineal_model) | 
`class `[`NoLinealModel`](#class_no_lineal_model) | Класс нелинейной модели
`class `[`PID_controller`](#class_p_i_d__controller) | Абстрактный класс пид-контроллера

## class `Control` {#class_control}

Абстрактный класс моделей вычисления

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`Model`](#class_control_1aa5ed70c41e9aea2dd143b867e226e25b)`(vector< double > & symbol, double t)` | 

### Members

#### `public double `[`Model`](#class_control_1aa5ed70c41e9aea2dd143b867e226e25b)`(vector< double > & symbol, double t)` {#class_control_1aa5ed70c41e9aea2dd143b867e226e25b}

## class `LinaelModel` {#class_linael_model}

Класс линейной модели

Является подклассом [Control](#class_control)

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

### Members

## class `LinealModel` {#class_lineal_model}

```
class LinealModel
  : public Control
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual double `[`Model`](#class_lineal_model_1aac6f104b2ffb5eb2bde11772ef4dbaa8)`(vector< double > & symbol_line, double input_warm)` | 
`private const double `[`a`](#class_lineal_model_1a549525777be0ae7d627a4d3c5eec5651) | Константы линейной модели
`private const double `[`b`](#class_lineal_model_1a94dbe04a3421b42c76a25caeac91e385) | 

### Members

#### `public inline virtual double `[`Model`](#class_lineal_model_1aac6f104b2ffb5eb2bde11772ef4dbaa8)`(vector< double > & symbol_line, double input_warm)` {#class_lineal_model_1aac6f104b2ffb5eb2bde11772ef4dbaa8}

#### `private const double `[`a`](#class_lineal_model_1a549525777be0ae7d627a4d3c5eec5651) {#class_lineal_model_1a549525777be0ae7d627a4d3c5eec5651}

Константы линейной модели

#### Parameters
* `temp` Текущая температура 

* `a` Параметр А 

* `b` Параметр B

#### `private const double `[`b`](#class_lineal_model_1a94dbe04a3421b42c76a25caeac91e385) {#class_lineal_model_1a94dbe04a3421b42c76a25caeac91e385}

## class `NoLinealModel` {#class_no_lineal_model}

```
class NoLinealModel
  : public Control
```

Класс нелинейной модели

Является подклассом [Control](#class_control)

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual double `[`Model`](#class_no_lineal_model_1a71e0afa60020bcd112fe523d30df10c6)`(vector< double > & symbol_noline, double input_warm)` | Метод вычисления емпературы для нелинейной температуры
`private const double `[`a`](#class_no_lineal_model_1a781bdafeccdd5c7c4839e1ba2741769d) | Константы нелинейной модели
`private const double `[`b`](#class_no_lineal_model_1a7fbf349573200da6af5383cca9918921) | 
`private const double `[`c`](#class_no_lineal_model_1a5bb992dfdbdaf61d9ab4c0e9194a2dec) | 
`private const double `[`d`](#class_no_lineal_model_1a948869fe2f24938aac1aaccbb1db1bed) | 

### Members

#### `public inline virtual double `[`Model`](#class_no_lineal_model_1a71e0afa60020bcd112fe523d30df10c6)`(vector< double > & symbol_noline, double input_warm)` {#class_no_lineal_model_1a71e0afa60020bcd112fe523d30df10c6}

Метод вычисления емпературы для нелинейной температуры

#### Parameters
* `input_warm` Выходное тепло 

#### Returns
temp

#### `private const double `[`a`](#class_no_lineal_model_1a781bdafeccdd5c7c4839e1ba2741769d) {#class_no_lineal_model_1a781bdafeccdd5c7c4839e1ba2741769d}

Константы нелинейной модели

#### Parameters
* `temp` Текущая температура 

* `a` Параметр А 

* `b` Параметр B 

* `c` Параметр С 

* `d` Параметр D

#### `private const double `[`b`](#class_no_lineal_model_1a7fbf349573200da6af5383cca9918921) {#class_no_lineal_model_1a7fbf349573200da6af5383cca9918921}

#### `private const double `[`c`](#class_no_lineal_model_1a5bb992dfdbdaf61d9ab4c0e9194a2dec) {#class_no_lineal_model_1a5bb992dfdbdaf61d9ab4c0e9194a2dec}

#### `private const double `[`d`](#class_no_lineal_model_1a948869fe2f24938aac1aaccbb1db1bed) {#class_no_lineal_model_1a948869fe2f24938aac1aaccbb1db1bed}

## class `PID_controller` {#class_p_i_d__controller}

Абстрактный класс пид-контроллера

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`controller`](#class_p_i_d__controller_1a8f0fdbda1f69726508eaebe7657d544d)`(double e, double e1, double e2)` | 
`public inline void `[`Reset_U`](#class_p_i_d__controller_1a82f45df3cab5592c644e0010909d60a1)`()` | 
`public inline double `[`PID_contr`](#class_p_i_d__controller_1aac9e943f23930590a72a26deb346e7a3)`(double w, double y0, `[`Control`](#class_control)` * control, vector< double > symbol)` | 
`private double `[`u`](#class_p_i_d__controller_1adc1a0d283bf172b3989ceb3f8b94d395) | controller
`private double `[`Td`](#class_p_i_d__controller_1afed0f7047921ed2a07232ce770d9e85a) | 
`private double `[`T`](#class_p_i_d__controller_1a88e6c57a17bf0372d6b4bcd52dae13a8) | 
`private double `[`T0`](#class_p_i_d__controller_1a24fba432394075e763ca8f18ff3285e9) | 
`private double `[`k`](#class_p_i_d__controller_1a75a15b60e8d357b2a4200ebb0387bfb9) | 

### Members

#### `public inline double `[`controller`](#class_p_i_d__controller_1a8f0fdbda1f69726508eaebe7657d544d)`(double e, double e1, double e2)` {#class_p_i_d__controller_1a8f0fdbda1f69726508eaebe7657d544d}

#### `public inline void `[`Reset_U`](#class_p_i_d__controller_1a82f45df3cab5592c644e0010909d60a1)`()` {#class_p_i_d__controller_1a82f45df3cab5592c644e0010909d60a1}

#### `public inline double `[`PID_contr`](#class_p_i_d__controller_1aac9e943f23930590a72a26deb346e7a3)`(double w, double y0, `[`Control`](#class_control)` * control, vector< double > symbol)` {#class_p_i_d__controller_1aac9e943f23930590a72a26deb346e7a3}

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

Generated by [Moxygen](https://sourcey.com/moxygen)