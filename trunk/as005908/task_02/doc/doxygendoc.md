# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`NoLineModel`](#class_no_line_model) | ПИД-регулятор
`class `[`PID_Controller`](#class_p_i_d___controller) | 
`class `[`PID_controller`](#class_p_i_d__controller) | Абстрактный класс пид-контроллера

## class `NoLineModel` {#class_no_line_model}

ПИД-регулятор

@mainpages

Абстрактный класс нелинейной модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`NoLineTemperature`](#class_no_line_model_1af4f8ec333d4197681add19e87246b7cf)`(double temperature, double temperature_1)` | Метод вычисления температуры для нелинейной температуры
`private const double `[`a`](#class_no_line_model_1a0d2842b398e76e57273163b626d1f7fe) | Константы линейной модели
`private const double `[`b`](#class_no_line_model_1aa9022f7a5d041df05fafb675a02f8960) | 
`private const double `[`c`](#class_no_line_model_1a9cecf0f03caf7e586d8494789a0df1a8) | 
`private const double `[`d`](#class_no_line_model_1a06942f0bf4b6058e68bc9655b48fff06) | 

### Members

#### `public inline double `[`NoLineTemperature`](#class_no_line_model_1af4f8ec333d4197681add19e87246b7cf)`(double temperature, double temperature_1)` {#class_no_line_model_1af4f8ec333d4197681add19e87246b7cf}

Метод вычисления температуры для нелинейной температуры

#### Parameters
* `buf` Выходное тепло 

#### Returns
double

#### `private const double `[`a`](#class_no_line_model_1a0d2842b398e76e57273163b626d1f7fe) {#class_no_line_model_1a0d2842b398e76e57273163b626d1f7fe}

Константы линейной модели

#### Parameters
* `a` Параметр А 

* `b` Параметр B 

* `c` Параметр C 

* `d` Параметр D

#### `private const double `[`b`](#class_no_line_model_1aa9022f7a5d041df05fafb675a02f8960) {#class_no_line_model_1aa9022f7a5d041df05fafb675a02f8960}

#### `private const double `[`c`](#class_no_line_model_1a9cecf0f03caf7e586d8494789a0df1a8) {#class_no_line_model_1a9cecf0f03caf7e586d8494789a0df1a8}

#### `private const double `[`d`](#class_no_line_model_1a06942f0bf4b6058e68bc9655b48fff06) {#class_no_line_model_1a06942f0bf4b6058e68bc9655b48fff06}

## class `PID_Controller` {#class_p_i_d___controller}

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`controller`](#class_p_i_d___controller_1abdf1333b58203a8ad01ebde97e0116b0)`(double e, double e1, double e2)` | Метод вычисления u.
`public inline double `[`PID_contr`](#class_p_i_d___controller_1add61a62d94ac007d5639f0ae2a3c9216)`(double w, double y0, `[`NoLineModel`](#class_no_line_model)` * model, int & number)` | 
`private double `[`u`](#class_p_i_d___controller_1af0a89ff557deeff72ebd03c2126e13f3) | controller
`private double `[`Td`](#class_p_i_d___controller_1a2f2fbdf4904c8df3781a004fd2d022e3) | 
`private double `[`T`](#class_p_i_d___controller_1acb69f67db86f6664cd22a6121eac88ac) | 
`private double `[`T0`](#class_p_i_d___controller_1a4c9367895488cc7e58bf039bbc63e11a) | 
`private double `[`k`](#class_p_i_d___controller_1a9a66fb26d22b39eaa6e26d630cc36f16) | 
`private double `[`error`](#class_p_i_d___controller_1ab766aabc41bcccbcca9096511856aa23) | 

### Members

#### `public inline double `[`controller`](#class_p_i_d___controller_1abdf1333b58203a8ad01ebde97e0116b0)`(double e, double e1, double e2)` {#class_p_i_d___controller_1abdf1333b58203a8ad01ebde97e0116b0}

Метод вычисления u.

#### `public inline double `[`PID_contr`](#class_p_i_d___controller_1add61a62d94ac007d5639f0ae2a3c9216)`(double w, double y0, `[`NoLineModel`](#class_no_line_model)` * model, int & number)` {#class_p_i_d___controller_1add61a62d94ac007d5639f0ae2a3c9216}

#### `private double `[`u`](#class_p_i_d___controller_1af0a89ff557deeff72ebd03c2126e13f3) {#class_p_i_d___controller_1af0a89ff557deeff72ebd03c2126e13f3}

controller

#### Parameters
* `T` Параметр Т 

* `T0` Параметр Т0 

* `Td` Параметр Td 

* `K` Параметр k

#### `private double `[`Td`](#class_p_i_d___controller_1a2f2fbdf4904c8df3781a004fd2d022e3) {#class_p_i_d___controller_1a2f2fbdf4904c8df3781a004fd2d022e3}

#### `private double `[`T`](#class_p_i_d___controller_1acb69f67db86f6664cd22a6121eac88ac) {#class_p_i_d___controller_1acb69f67db86f6664cd22a6121eac88ac}

#### `private double `[`T0`](#class_p_i_d___controller_1a4c9367895488cc7e58bf039bbc63e11a) {#class_p_i_d___controller_1a4c9367895488cc7e58bf039bbc63e11a}

#### `private double `[`k`](#class_p_i_d___controller_1a9a66fb26d22b39eaa6e26d630cc36f16) {#class_p_i_d___controller_1a9a66fb26d22b39eaa6e26d630cc36f16}

#### `private double `[`error`](#class_p_i_d___controller_1ab766aabc41bcccbcca9096511856aa23) {#class_p_i_d___controller_1ab766aabc41bcccbcca9096511856aa23}

## class `PID_controller` {#class_p_i_d__controller}

Абстрактный класс пид-контроллера

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

### Members

Generated by [Moxygen](https://sourcey.com/moxygen)