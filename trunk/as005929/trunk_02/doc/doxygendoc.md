# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Abstract_Model`](#class_abstract___model) | Абстрактный класс моделей вычисления
`class `[`NoLinealModel`](#class_no_lineal_model) | Класс нелинейной модели
`class `[`PID`](#class_p_i_d) | Абстрактный класс пид-контроллера

## class `Abstract_Model` {#class_abstract___model}

Абстрактный класс моделей вычисления

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`m`](#class_abstract___model_1ad2acdaabb05418917b6cb4c481032a21)`(double _t, double _w)` | 

### Members

#### `public double `[`m`](#class_abstract___model_1ad2acdaabb05418917b6cb4c481032a21)`(double _t, double _w)` {#class_abstract___model_1ad2acdaabb05418917b6cb4c481032a21}

## class `NoLinealModel` {#class_no_lineal_model}

```
class NoLinealModel
  : public Abstract_Model
```

Класс нелинейной модели

Является подклассом [Abstract_Model](#class_abstract___model)

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual double `[`m`](#class_no_lineal_model_1a893f68dfe2db4f4b9156c42f3b7189b9)`(double _t, double _w)` | Метод вычисления емпературы для нелинейной температуры
`private const double `[`a`](#class_no_lineal_model_1a781bdafeccdd5c7c4839e1ba2741769d) | Константы нелинейной модели
`private const double `[`b`](#class_no_lineal_model_1a7fbf349573200da6af5383cca9918921) | 
`private const double `[`c`](#class_no_lineal_model_1a5bb992dfdbdaf61d9ab4c0e9194a2dec) | 
`private const double `[`d`](#class_no_lineal_model_1a948869fe2f24938aac1aaccbb1db1bed) | 
`private double `[`_w_step_minus1`](#class_no_lineal_model_1a565b4a1a89bbe19fe241e8df439be016) | 
`private double `[`_t_step_minus1`](#class_no_lineal_model_1a736964220469772666fd99a82356095d) | 

### Members

#### `public inline virtual double `[`m`](#class_no_lineal_model_1a893f68dfe2db4f4b9156c42f3b7189b9)`(double _t, double _w)` {#class_no_lineal_model_1a893f68dfe2db4f4b9156c42f3b7189b9}

Метод вычисления емпературы для нелинейной температуры

#### Parameters
* `_w` Выходное тепло 

#### Returns
double

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

#### `private double `[`_w_step_minus1`](#class_no_lineal_model_1a565b4a1a89bbe19fe241e8df439be016) {#class_no_lineal_model_1a565b4a1a89bbe19fe241e8df439be016}

#### `private double `[`_t_step_minus1`](#class_no_lineal_model_1a736964220469772666fd99a82356095d) {#class_no_lineal_model_1a736964220469772666fd99a82356095d}

## class `PID` {#class_p_i_d}

Абстрактный класс пид-контроллера

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`calc`](#class_p_i_d_1a40a4cafcd4eac8e325865bf7a6d656ae)`(double e, double e1, double e2)` | 
`public inline double `[`PID_D`](#class_p_i_d_1a3dced7cd38f13663ae589b5f4ef7f9b4)`(double w, double y0, `[`Abstract_Model`](#class_abstract___model)` * m)` | 
`private double `[`u`](#class_p_i_d_1a67ade291736a1c89ca44ada3ff5604e0) | controller
`private double `[`Td`](#class_p_i_d_1a6d3306e34c941e0a0858c7d9844ad34a) | 
`private double `[`T`](#class_p_i_d_1acf6dff362a7dd74e543ec9c9ec60a3ab) | 
`private double `[`T0`](#class_p_i_d_1af69630823959fdbc57637cbc7e69c9c7) | 
`private double `[`k`](#class_p_i_d_1a8365273557bc3611df0f3b7c18bfc739) | 

### Members

#### `public inline double `[`calc`](#class_p_i_d_1a40a4cafcd4eac8e325865bf7a6d656ae)`(double e, double e1, double e2)` {#class_p_i_d_1a40a4cafcd4eac8e325865bf7a6d656ae}

#### `public inline double `[`PID_D`](#class_p_i_d_1a3dced7cd38f13663ae589b5f4ef7f9b4)`(double w, double y0, `[`Abstract_Model`](#class_abstract___model)` * m)` {#class_p_i_d_1a3dced7cd38f13663ae589b5f4ef7f9b4}

#### `private double `[`u`](#class_p_i_d_1a67ade291736a1c89ca44ada3ff5604e0) {#class_p_i_d_1a67ade291736a1c89ca44ada3ff5604e0}

controller

#### Parameters
* `T` Параметр Т 

* `T0` Параметр Т0 

* `Td` Параметр Td 

* `K` Параметр k

#### `private double `[`Td`](#class_p_i_d_1a6d3306e34c941e0a0858c7d9844ad34a) {#class_p_i_d_1a6d3306e34c941e0a0858c7d9844ad34a}

#### `private double `[`T`](#class_p_i_d_1acf6dff362a7dd74e543ec9c9ec60a3ab) {#class_p_i_d_1acf6dff362a7dd74e543ec9c9ec60a3ab}

#### `private double `[`T0`](#class_p_i_d_1af69630823959fdbc57637cbc7e69c9c7) {#class_p_i_d_1af69630823959fdbc57637cbc7e69c9c7}

#### `private double `[`k`](#class_p_i_d_1a8365273557bc3611df0f3b7c18bfc739) {#class_p_i_d_1a8365273557bc3611df0f3b7c18bfc739}

Generated by [Moxygen](https://sourcey.com/moxygen)