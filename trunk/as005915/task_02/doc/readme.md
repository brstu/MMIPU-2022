**_<h1 align = "center">Лабораторная работа №2 «ПИД-регуляторы»</a>_**

<font size = 3>
<p align = "right">
Выполнила: Коверец Е.Д.</p>
<p align = "right">
Проверил: Иванюк Д.С.</p>
</font>

## **Результаты работы программы:**

# Не линейная

<img src="/nonlinear.png">

# Линейная

<img src="/linear.png">
  
График линейной функции

<img src="/images/lineargrafic.png">
  
График нелинейной функции

<img src="/images/nonlineargrafic.png">

# class `Main`

```
class Main

```

Abstract class with start values for models and method ovveride.

## Summary

| Member                                                                 | Description     |
| ---------------------------------------------------------------------- | --------------- |
| public double [a](#class_main_1a320607f516ff962abb01c24a35a68db5)      | init linear     |
| public double [b](#class_main_1a721df7982f370c690ca8bd1b7dc4d532)      | init linear     |
| public double [a1](#class_main_1ab0f136596b8b98ecb5549f4f86dae4b1)     | init not linear |
| public double [b1](#class_main_1a2034bebb819cad32b095628aecd4cdcd)     | init not linear |
| public double [c1](#class_main_1ad043ba752e997eb484b236ca3742436e)     | init not linear |
| public double [d1](#class_main_1a3ee58bcc293d891e3ab3f8db368e90f5)     | init not linear |
| public double [method](#class_main_1a0301d67849b55176f1a46b2e169b19a5) | ovveride method |

## Attributes

#### public double `a` = 0.699 <a id='class_main_1a320607f516ff962abb01c24a35a68db5' href='#class_main_1a320607f516ff962abb01c24a35a68db5'>#</a>

#### public double `b` = 0.899 <a id='class_main_1a721df7982f370c690ca8bd1b7dc4d532' href='#class_main_1a721df7982f370c690ca8bd1b7dc4d532'>#</a>

#### public double `a1` = 0.857 <a id='class_main_1ab0f136596b8b98ecb5549f4f86dae4b1' href='#class_main_1ab0f136596b8b98ecb5549f4f86dae4b1'>#</a>

#### public double `b1` = 0.0022 <a id='class_main_1a2034bebb819cad32b095628aecd4cdcd' href='#class_main_1a2034bebb819cad32b095628aecd4cdcd'>#</a>

#### public double `c1` = 0.467 <a id='class_main_1ad043ba752e997eb484b236ca3742436e' href='#class_main_1ad043ba752e997eb484b236ca3742436e'>#</a>

#### public double `d1` = 0.398 <a id='class_main_1a3ee58bcc293d891e3ab3f8db368e90f5' href='#class_main_1a3ee58bcc293d891e3ab3f8db368e90f5'>#</a>

## Methods

#### public double `method(double temp, double warm)=0` <a id='class_main_1a0301d67849b55176f1a46b2e169b19a5' href='#class_main_1a0301d67849b55176f1a46b2e169b19a5'>#</a>

# class `Pid`

```
class Pid

```

Class pid generator q-values and result pid value.

## Summary

| Member                                                                   | Description          |
| ------------------------------------------------------------------------ | -------------------- |
| private double [T](#class_pid_1a60e79cb04369a9bbf77231e409cb5dda)        | Constant integration |
| private double [T0](#class_pid_1a549a24bc48174c5ce86acc4947437408)       | Step                 |
| private double [TD](#class_pid_1ada9c4cadcdcab774cf7b066128f966da)       | Diff constant        |
| private double [K](#class_pid_1aaad27b7121f99c580fdb31957bd24f77)        | Transfer             |
| private double [U](#class_pid_1aadf6584e9bf48e218a045994a548a952)        | Result generator     |
| public double [calculate](#class_pid_1abc81dead46694a568624968a25a40b47) | For find q-values    |
| public void [result](#class_pid_1a7e7d2d706ff5a57480e8f0ad938aec7b)      | call models and gen  |

## Attributes

#### private double `T` = 10 <a id='class_pid_1a60e79cb04369a9bbf77231e409cb5dda' href='#class_pid_1a60e79cb04369a9bbf77231e409cb5dda'>#</a>

#### private double `T0` = 10 <a id='class_pid_1a549a24bc48174c5ce86acc4947437408' href='#class_pid_1a549a24bc48174c5ce86acc4947437408'>#</a>

#### private double `TD` = 50 <a id='class_pid_1ada9c4cadcdcab774cf7b066128f966da' href='#class_pid_1ada9c4cadcdcab774cf7b066128f966da'>#</a>

#### private double `K` = 0.085 <a id='class_pid_1aaad27b7121f99c580fdb31957bd24f77' href='#class_pid_1aaad27b7121f99c580fdb31957bd24f77'>#</a>

#### private double `U` = 0 <a id='class_pid_1aadf6584e9bf48e218a045994a548a952' href='#class_pid_1aadf6584e9bf48e218a045994a548a952'>#</a>

## Methods

#### public double `calculate(double e, double error1, double error2)` <a id='class_pid_1abc81dead46694a568624968a25a40b47' href='#class_pid_1abc81dead46694a568624968a25a40b47'>#</a>

| Kind  | Member | Description     |
| ----- | ------ | --------------- |
| param | e      | main error      |
| param | error1 | prev error      |
| param | error2 | prev prev error |

#### public void `result(int iter, double temp, double warm, Pid *pid, Main *res)` <a id='class_pid_1a7e7d2d706ff5a57480e8f0ad938aec7b' href='#class_pid_1a7e7d2d706ff5a57480e8f0ad938aec7b'>#</a>

| Kind  | Member | Description              |
| ----- | ------ | ------------------------ |
| param | iter   | count of iterations      |
| param | temp   | start temperature        |
| param | warm   | increasing value of temp |
| param | pid    | pointer to Pid class     |
| param | res    | pointer to Res class     |

# class `Linear`

```
class Linear
    : public Main

```

Class linear model.

## Summary

| Member                                                                                   | Description       |
| ---------------------------------------------------------------------------------------- | ----------------- |
| private double [aL](#class_linear_1a5a825550bf5451e499342f87a3294bef)                    | value for a       |
| private double [bL](#class_linear_1abf599a8057b407ec439676a1eaec75f1)                    | value for b       |
| private double [resL](#class_linear_1a70f7f42e1981a4a9bbf5fdae87ce1ea4)                  | value res         |
| public Linear [Linear](#class_linear_1af4b35371ac5e8e4d7e68f7d3ca162e9f)                 | find linear model |
| public virtual virtual double [method](#class_linear_1a80573183336a773d88d3c247f57432d7) | virtual from Main |

## Attributes

#### private double `aL` <a id='class_linear_1a5a825550bf5451e499342f87a3294bef' href='#class_linear_1a5a825550bf5451e499342f87a3294bef'>#</a>

#### private double `bL` <a id='class_linear_1abf599a8057b407ec439676a1eaec75f1' href='#class_linear_1abf599a8057b407ec439676a1eaec75f1'>#</a>

#### private double `resL` <a id='class_linear_1a70f7f42e1981a4a9bbf5fdae87ce1ea4' href='#class_linear_1a70f7f42e1981a4a9bbf5fdae87ce1ea4'>#</a>

## Methods

#### public Linear `Linear()` <a id='class_linear_1af4b35371ac5e8e4d7e68f7d3ca162e9f' href='#class_linear_1af4b35371ac5e8e4d7e68f7d3ca162e9f'>#</a>

#### public virtual virtual double `method(double temp, double warm)` [: method](class_main.md#class_main_1a0301d67849b55176f1a46b2e169b19a5) <a id='class_linear_1a80573183336a773d88d3c247f57432d7' href='#class_linear_1a80573183336a773d88d3c247f57432d7'>#</a>

| Kind  | Member | Description         |
| ----- | ------ | ------------------- |
| param | temp   | start temperature   |
| param | warm   | value of increasing |

# class `NonLinear`

```
class NonLinear
    : public Main

```

Class nonLinear model.

## Summary

| Member                                                                                       | Description    |
| -------------------------------------------------------------------------------------------- | -------------- |
| private double [aNL](#class_non_linear_1ad2415b042d1f8818af70fea064f62a38)                   | value for a1   |
| private double [bNL](#class_non_linear_1a29380d2ab8fa5208ad544116ad074e8a)                   | value for b1   |
| private double [cNL](#class_non_linear_1affb06e69c6803c23fe9cafd2fdb36a41)                   | value for c1   |
| private double [dNL](#class_non_linear_1a7d9ca060f8f8c55a6d5f35c905e828b6)                   | value for d1   |
| private double [lastcalculate](#class_non_linear_1a429c9de0d7d58ed8c68d22e1230c124d)         | value warm     |
| private double [lastTemp](#class_non_linear_1a97f742f40eac5377e6a3c3d3fe78c330)              | value temp     |
| public NonLinear [NonLinear](#class_non_linear_1a3ebf4f32e50b143cd0f62c21e29640ac)           | find NonLinear |
| public virtual virtual double [method](#class_non_linear_1a460bfc85241a88c78dd37f4d95972076) | virtual Main   |

## Attributes

#### private double `aNL` <a id='class_non_linear_1ad2415b042d1f8818af70fea064f62a38' href='#class_non_linear_1ad2415b042d1f8818af70fea064f62a38'>#</a>

#### private double `bNL` <a id='class_non_linear_1a29380d2ab8fa5208ad544116ad074e8a' href='#class_non_linear_1a29380d2ab8fa5208ad544116ad074e8a'>#</a>

#### private double `cNL` <a id='class_non_linear_1affb06e69c6803c23fe9cafd2fdb36a41' href='#class_non_linear_1affb06e69c6803c23fe9cafd2fdb36a41'>#</a>

#### private double `dNL` <a id='class_non_linear_1a7d9ca060f8f8c55a6d5f35c905e828b6' href='#class_non_linear_1a7d9ca060f8f8c55a6d5f35c905e828b6'>#</a>

#### private double `lastcalculate` = 0 <a id='class_non_linear_1a429c9de0d7d58ed8c68d22e1230c124d' href='#class_non_linear_1a429c9de0d7d58ed8c68d22e1230c124d'>#</a>

#### private double `lastTemp` = 0 <a id='class_non_linear_1a97f742f40eac5377e6a3c3d3fe78c330' href='#class_non_linear_1a97f742f40eac5377e6a3c3d3fe78c330'>#</a>

## Methods

#### public NonLinear `NonLinear()` <a id='class_non_linear_1a3ebf4f32e50b143cd0f62c21e29640ac' href='#class_non_linear_1a3ebf4f32e50b143cd0f62c21e29640ac'>#</a>

#### public virtual virtual double `method(double temp, double calculate)` [: method](class_main.md#class_main_1a0301d67849b55176f1a46b2e169b19a5) <a id='class_non_linear_1a460bfc85241a88c78dd37f4d95972076' href='#class_non_linear_1a460bfc85241a88c78dd37f4d95972076'>#</a>

| Kind  | Member | Description         |
| ----- | ------ | ------------------- |
| param | temp   | start temperature   |
| param | warm   | value of increasing |
