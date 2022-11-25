# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`NoLineModel`](#class_no_line_model) | Класс нелинейной модели
`class `[`PID_contr`](#class_p_i_d__contr) | Абстрактный класс пид-контроллера
`class `[`Reg_controller`](#class_reg__controller) | Абстрактный класс моделей вычисления

## class `NoLineModel` {#class_no_line_model}

```
class NoLineModel
  : public Reg_controller
```

Класс нелинейной модели

Является подклассом Model

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual double `[`reg`](#class_no_line_model_1a701b03b83641bd6a06ba35df07079598)`(double _temp, double _warm)` | Метод вычисления температуры для нелинейной температуры
`private const double `[`a`](#class_no_line_model_1a0d2842b398e76e57273163b626d1f7fe) | Константы нелинейной модели
`private const double `[`b`](#class_no_line_model_1aa9022f7a5d041df05fafb675a02f8960) | 
`private const double `[`c`](#class_no_line_model_1a9cecf0f03caf7e586d8494789a0df1a8) | 
`private const double `[`d`](#class_no_line_model_1a06942f0bf4b6058e68bc9655b48fff06) | 
`private double `[`warm`](#class_no_line_model_1ab92defa16c7d778b6bdf9c2279192df4) | 
`private double `[`t`](#class_no_line_model_1a2b6b94c20a24b89c2654b8297553c6df) | 

### Members

#### `public inline virtual double `[`reg`](#class_no_line_model_1a701b03b83641bd6a06ba35df07079598)`(double _temp, double _warm)` {#class_no_line_model_1a701b03b83641bd6a06ba35df07079598}

Метод вычисления температуры для нелинейной температуры

#### Parameters
* `_warm` Выходное тепло 

#### Returns
double

#### `private const double `[`a`](#class_no_line_model_1a0d2842b398e76e57273163b626d1f7fe) {#class_no_line_model_1a0d2842b398e76e57273163b626d1f7fe}

Константы нелинейной модели

#### Parameters
* `t` Текущая температура 

* `a` Параметр А 

* `b` Параметр B 

* `c` Параметр С 

* `d` Параметр D

#### `private const double `[`b`](#class_no_line_model_1aa9022f7a5d041df05fafb675a02f8960) {#class_no_line_model_1aa9022f7a5d041df05fafb675a02f8960}

#### `private const double `[`c`](#class_no_line_model_1a9cecf0f03caf7e586d8494789a0df1a8) {#class_no_line_model_1a9cecf0f03caf7e586d8494789a0df1a8}

#### `private const double `[`d`](#class_no_line_model_1a06942f0bf4b6058e68bc9655b48fff06) {#class_no_line_model_1a06942f0bf4b6058e68bc9655b48fff06}

#### `private double `[`warm`](#class_no_line_model_1ab92defa16c7d778b6bdf9c2279192df4) {#class_no_line_model_1ab92defa16c7d778b6bdf9c2279192df4}

#### `private double `[`t`](#class_no_line_model_1a2b6b94c20a24b89c2654b8297553c6df) {#class_no_line_model_1a2b6b94c20a24b89c2654b8297553c6df}

## class `PID_contr` {#class_p_i_d__contr}

Абстрактный класс пид-контроллера

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`controller`](#class_p_i_d__contr_1ad78f614dfae7e280c5612fbd857c1af4)`(double e, double e1, double e2)` | 
`public inline void `[`Reset_U`](#class_p_i_d__contr_1a77bb7e2db9da18c0a8d049b031240505)`()` | 
`public inline double `[`PID_controller`](#class_p_i_d__contr_1a42d8afd6f37c34faae4f4b4a94c62adc)`(double w, double y0, `[`Reg_controller`](#class_reg__controller)` * model)` | 
`private double `[`u`](#class_p_i_d__contr_1a6e0a5095185c1a9de60e98c93fdf8d57) | [PID_contr](#class_p_i_d__contr).
`private double `[`Td`](#class_p_i_d__contr_1ad66532155b521da598266b3f3825f671) | 
`private double `[`T`](#class_p_i_d__contr_1ac40ace1422c9328a386e982dde1030d2) | 
`private double `[`T0`](#class_p_i_d__contr_1a2ea5f9cb20a5b149844ea1af57583c50) | 
`private double `[`k`](#class_p_i_d__contr_1ab22921d76ae85ac0d943627d3958d3d4) | 

### Members

#### `public inline double `[`controller`](#class_p_i_d__contr_1ad78f614dfae7e280c5612fbd857c1af4)`(double e, double e1, double e2)` {#class_p_i_d__contr_1ad78f614dfae7e280c5612fbd857c1af4}

#### `public inline void `[`Reset_U`](#class_p_i_d__contr_1a77bb7e2db9da18c0a8d049b031240505)`()` {#class_p_i_d__contr_1a77bb7e2db9da18c0a8d049b031240505}

#### `public inline double `[`PID_controller`](#class_p_i_d__contr_1a42d8afd6f37c34faae4f4b4a94c62adc)`(double w, double y0, `[`Reg_controller`](#class_reg__controller)` * model)` {#class_p_i_d__contr_1a42d8afd6f37c34faae4f4b4a94c62adc}

#### `private double `[`u`](#class_p_i_d__contr_1a6e0a5095185c1a9de60e98c93fdf8d57) {#class_p_i_d__contr_1a6e0a5095185c1a9de60e98c93fdf8d57}

[PID_contr](#class_p_i_d__contr).

#### Parameters
* `T` Параметр Т 

* `T0` Параметр Т0 

* `Td` Параметр Td 

* `K` Параметр k

#### `private double `[`Td`](#class_p_i_d__contr_1ad66532155b521da598266b3f3825f671) {#class_p_i_d__contr_1ad66532155b521da598266b3f3825f671}

#### `private double `[`T`](#class_p_i_d__contr_1ac40ace1422c9328a386e982dde1030d2) {#class_p_i_d__contr_1ac40ace1422c9328a386e982dde1030d2}

#### `private double `[`T0`](#class_p_i_d__contr_1a2ea5f9cb20a5b149844ea1af57583c50) {#class_p_i_d__contr_1a2ea5f9cb20a5b149844ea1af57583c50}

#### `private double `[`k`](#class_p_i_d__contr_1ab22921d76ae85ac0d943627d3958d3d4) {#class_p_i_d__contr_1ab22921d76ae85ac0d943627d3958d3d4}

## class `Reg_controller` {#class_reg__controller}

Абстрактный класс моделей вычисления

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`reg`](#class_reg__controller_1ab0be117114f29911c5b2260c08757354)`(double _temp, double _warm)` | 

### Members

#### `public double `[`reg`](#class_reg__controller_1ab0be117114f29911c5b2260c08757354)`(double _temp, double _warm)` {#class_reg__controller_1ab0be117114f29911c5b2260c08757354}

Generated by [Moxygen](https://sourcey.com/moxygen)