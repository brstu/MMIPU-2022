# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Function`](#class_function) | Абстрактный класс моделей вычисления
`class `[`LinealFunction`](#class_lineal_function) | Класс линейной модели
`class `[`LineFunction`](#class_line_function) | 
`class `[`NoLinealFunction`](#class_no_lineal_function) | Класс нелинейной модели
`class `[`NoLineFunction`](#class_no_line_function) | 
`class `[`PID`](#class_p_i_d) | Абстрактный класс пид-контроллера

## class `Function` {#class_function}

Абстрактный класс моделей вычисления

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`function`](#class_function_1a6a2a2d11060d5f23b7365ef072ba61fc)`(double wh_t, double wh_w)` | 

### Members

#### `public double `[`function`](#class_function_1a6a2a2d11060d5f23b7365ef072ba61fc)`(double wh_t, double wh_w)` {#class_function_1a6a2a2d11060d5f23b7365ef072ba61fc}

## class `LinealFunction` {#class_lineal_function}

Класс линейной модели

Является подклассом [Function](#class_function)

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

### Members

## class `LineFunction` {#class_line_function}

```
class LineFunction
  : public Function
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual double `[`function`](#class_line_function_1a41c6e1477d7d2c9b37e563ac107a8240)`(double wh_t, double wh_w)` | 
`private const double `[`a`](#class_line_function_1a119e69859b5f1b9b53350fed3ac71d90) | Константы линейной модели
`private const double `[`b`](#class_line_function_1a12884adbb63e2e93ccd84e1e49e93a29) | 

### Members

#### `public inline virtual double `[`function`](#class_line_function_1a41c6e1477d7d2c9b37e563ac107a8240)`(double wh_t, double wh_w)` {#class_line_function_1a41c6e1477d7d2c9b37e563ac107a8240}

#### `private const double `[`a`](#class_line_function_1a119e69859b5f1b9b53350fed3ac71d90) {#class_line_function_1a119e69859b5f1b9b53350fed3ac71d90}

Константы линейной модели

#### Parameters
* `a` Параметр А 

* `b` Параметр B

#### `private const double `[`b`](#class_line_function_1a12884adbb63e2e93ccd84e1e49e93a29) {#class_line_function_1a12884adbb63e2e93ccd84e1e49e93a29}

## class `NoLinealFunction` {#class_no_lineal_function}

Класс нелинейной модели

Является подклассом [Function](#class_function)

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

### Members

## class `NoLineFunction` {#class_no_line_function}

```
class NoLineFunction
  : public Function
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual double `[`function`](#class_no_line_function_1a8b6c2b1bc66d78cf3eb3e0a435174cc0)`(double wh_t, double wh_w)` | 
`private const double `[`a`](#class_no_line_function_1a6938293c174c8a7b7221b5a33815b7a6) | Константы нелинейной модели
`private const double `[`b`](#class_no_line_function_1ac1d3f73445034bd633b30f7561af3af7) | 
`private const double `[`c`](#class_no_line_function_1a570192ea802e9198d9bf6f301a9978db) | 
`private const double `[`d`](#class_no_line_function_1a7f2583fafd259d949ff15485830db94c) | 
`private double `[`wh_w_1`](#class_no_line_function_1a5b4d9ba272b420dce7d3724d3f20b5a1) | 
`private double `[`wh_t_1`](#class_no_line_function_1a58ada416d9e690e9664ffedaea750ac0) | 

### Members

#### `public inline virtual double `[`function`](#class_no_line_function_1a8b6c2b1bc66d78cf3eb3e0a435174cc0)`(double wh_t, double wh_w)` {#class_no_line_function_1a8b6c2b1bc66d78cf3eb3e0a435174cc0}

#### `private const double `[`a`](#class_no_line_function_1a6938293c174c8a7b7221b5a33815b7a6) {#class_no_line_function_1a6938293c174c8a7b7221b5a33815b7a6}

Константы нелинейной модели

#### Parameters
* `a` Параметр А 

* `b` Параметр B 

* `c` Параметр С 

* `d` Параметр D

#### `private const double `[`b`](#class_no_line_function_1ac1d3f73445034bd633b30f7561af3af7) {#class_no_line_function_1ac1d3f73445034bd633b30f7561af3af7}

#### `private const double `[`c`](#class_no_line_function_1a570192ea802e9198d9bf6f301a9978db) {#class_no_line_function_1a570192ea802e9198d9bf6f301a9978db}

#### `private const double `[`d`](#class_no_line_function_1a7f2583fafd259d949ff15485830db94c) {#class_no_line_function_1a7f2583fafd259d949ff15485830db94c}

#### `private double `[`wh_w_1`](#class_no_line_function_1a5b4d9ba272b420dce7d3724d3f20b5a1) {#class_no_line_function_1a5b4d9ba272b420dce7d3724d3f20b5a1}

#### `private double `[`wh_t_1`](#class_no_line_function_1a58ada416d9e690e9664ffedaea750ac0) {#class_no_line_function_1a58ada416d9e690e9664ffedaea750ac0}

## class `PID` {#class_p_i_d}

Абстрактный класс пид-контроллера

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`controller`](#class_p_i_d_1ac7e4f6e6ed356758c2157bcc4e942cd9)`(double e, double e1, double e2)` | 
`public inline double `[`PID_contr`](#class_p_i_d_1a7c5728df1f55ca2e0d3fd1a8abb6ab07)`(double w, double y0, `[`Function`](#class_function)` * model)` | 
`private double `[`u`](#class_p_i_d_1a67ade291736a1c89ca44ada3ff5604e0) | controller
`private double `[`Td`](#class_p_i_d_1a6d3306e34c941e0a0858c7d9844ad34a) | 
`private double `[`T`](#class_p_i_d_1acf6dff362a7dd74e543ec9c9ec60a3ab) | 
`private double `[`T0`](#class_p_i_d_1af69630823959fdbc57637cbc7e69c9c7) | 
`private double `[`k`](#class_p_i_d_1a8365273557bc3611df0f3b7c18bfc739) | 

### Members

#### `public inline double `[`controller`](#class_p_i_d_1ac7e4f6e6ed356758c2157bcc4e942cd9)`(double e, double e1, double e2)` {#class_p_i_d_1ac7e4f6e6ed356758c2157bcc4e942cd9}

#### `public inline double `[`PID_contr`](#class_p_i_d_1a7c5728df1f55ca2e0d3fd1a8abb6ab07)`(double w, double y0, `[`Function`](#class_function)` * model)` {#class_p_i_d_1a7c5728df1f55ca2e0d3fd1a8abb6ab07}

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