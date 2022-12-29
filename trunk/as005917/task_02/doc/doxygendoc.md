# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`mode_model`](#classmode__model) | Интерфейс для модели
`class `[`No_Line_Model`](#class_no___line___model) | Класс нелинейной модели
`class `[`PIDRegulator`](#class_p_i_d_regulator) | 

## class `mode_model` {#classmode__model}

Интерфейс для модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public long double `[`No_Line_Functoin`](#classmode__model_1a544e8ed4789f4798f397370dff3b9c85)`(long double inT, long double inW, long double & a, long double & b, long double & c, long double & d)` | 

### Members

#### `public long double `[`No_Line_Functoin`](#classmode__model_1a544e8ed4789f4798f397370dff3b9c85)`(long double inT, long double inW, long double & a, long double & b, long double & c, long double & d)` {#classmode__model_1a544e8ed4789f4798f397370dff3b9c85}

## class `No_Line_Model` {#class_no___line___model}

```
class No_Line_Model
  : private mode_model
```

Класс нелинейной модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual long double `[`No_Line_Functoin`](#class_no___line___model_1af30a3c40894891ad343167505c598529)`(long double inT, long double inW, long double & a, long double & b, long double & c, long double & d)` | Метод вычисления температуры для нелинейной модели
`private long double * `[`inT_array`](#class_no___line___model_1a4b85366e2e101193aa266b6e9d72ef70) | Массивы
`private long double * `[`inW_array`](#class_no___line___model_1a0454bfc1add0c1c0dfb3829e9d30eba5) | 

### Members

#### `public inline virtual long double `[`No_Line_Functoin`](#class_no___line___model_1af30a3c40894891ad343167505c598529)`(long double inT, long double inW, long double & a, long double & b, long double & c, long double & d)` {#class_no___line___model_1af30a3c40894891ad343167505c598529}

Метод вычисления температуры для нелинейной модели

#### Returns
buf Временная переменная

#### `private long double * `[`inT_array`](#class_no___line___model_1a4b85366e2e101193aa266b6e9d72ef70) {#class_no___line___model_1a4b85366e2e101193aa266b6e9d72ef70}

Массивы

#### Parameters
* `inT_array` Хранит температуру 

* `inW_array` Хранит тепло

#### `private long double * `[`inW_array`](#class_no___line___model_1a0454bfc1add0c1c0dfb3829e9d30eba5) {#class_no___line___model_1a0454bfc1add0c1c0dfb3829e9d30eba5}

## class `PIDRegulator` {#class_p_i_d_regulator}

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`Find_U`](#class_p_i_d_regulator_1ae3592c0463496759ebb7ad4f3c6a698f)`(double e, double e1, double e2)` | Метод вычисления U.
`public inline void `[`Regulator`](#class_p_i_d_regulator_1ab9d89b93672f88c78dd2c05514a1be08)`(double w, double y0, `[`No_Line_Model`](#class_no___line___model)` * nolinemodel, long double & a, long double & b, long double & c, long double & d)` | ПИД-Регулятор
`private long double `[`u`](#class_p_i_d_regulator_1a1320572f36a6de287931998c04c53d27) | Константы контроллера
`private const long double `[`Td`](#class_p_i_d_regulator_1a8b646744b009c4da44a4d4b2bea6f5d1) | 
`private const long double `[`T`](#class_p_i_d_regulator_1aeaa03c95199673109c3ab68e646e1886) | 
`private const long double `[`T0`](#class_p_i_d_regulator_1a37cac0cb89e4b974c5ad5266456cd211) | 
`private const long double `[`k`](#class_p_i_d_regulator_1a70c81a0e78ff6b260d87269b212c8f09) | 

### Members

#### `public inline double `[`Find_U`](#class_p_i_d_regulator_1ae3592c0463496759ebb7ad4f3c6a698f)`(double e, double e1, double e2)` {#class_p_i_d_regulator_1ae3592c0463496759ebb7ad4f3c6a698f}

Метод вычисления U.

#### Returns
U U

#### `public inline void `[`Regulator`](#class_p_i_d_regulator_1ab9d89b93672f88c78dd2c05514a1be08)`(double w, double y0, `[`No_Line_Model`](#class_no___line___model)` * nolinemodel, long double & a, long double & b, long double & c, long double & d)` {#class_p_i_d_regulator_1ab9d89b93672f88c78dd2c05514a1be08}

ПИД-Регулятор

#### `private long double `[`u`](#class_p_i_d_regulator_1a1320572f36a6de287931998c04c53d27) {#class_p_i_d_regulator_1a1320572f36a6de287931998c04c53d27}

Константы контроллера

#### Parameters
* `T` Параметр Т 

* `T0` Параметр Т0 

* `Td` Параметр Td 

* `K` Параметр k

#### `private const long double `[`Td`](#class_p_i_d_regulator_1a8b646744b009c4da44a4d4b2bea6f5d1) {#class_p_i_d_regulator_1a8b646744b009c4da44a4d4b2bea6f5d1}

#### `private const long double `[`T`](#class_p_i_d_regulator_1aeaa03c95199673109c3ab68e646e1886) {#class_p_i_d_regulator_1aeaa03c95199673109c3ab68e646e1886}

#### `private const long double `[`T0`](#class_p_i_d_regulator_1a37cac0cb89e4b974c5ad5266456cd211) {#class_p_i_d_regulator_1a37cac0cb89e4b974c5ad5266456cd211}

#### `private const long double `[`k`](#class_p_i_d_regulator_1a70c81a0e78ff6b260d87269b212c8f09) {#class_p_i_d_regulator_1a70c81a0e78ff6b260d87269b212c8f09}

Generated by [Moxygen](https://sourcey.com/moxygen)