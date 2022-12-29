**_<h1 align = "center">Лабораторная работа №2 «ПИД-регуляторы»</a>_**

<font size = 3>
<p align = "right">
Выполнила: Грицук В.Ю.</p>
<p align = "right">
Проверил: Иванюк Д.С.</p>
</font>

## **Результаты работы программы:**

# Нелинейная

<img src="/img/results_NL.png">

# Линейная

<img src="/img/results_L.png">
  
График линейной функции

<img src="/img/linear.png">
  
График нелинейной функции

<img src="/img/nonlinear.png">

# class `Models`

```
class Models

```

Абстрактный класс для переопределения моделей подсчёта

## Summary

| Member                                                                           | Description             |
| -------------------------------------------------------------------------------- | ----------------------- |
| public double [calculateModel](#class_models_1a681ab22836d9b489b5b797b85a406585) | ф-я для расчёта формулы |

## Methods

#### public double `calculateModel(double init_room, double init_warm)=0` <a id='class_models_1a681ab22836d9b489b5b797b85a406585' href='#class_models_1a681ab22836d9b489b5b797b85a406585'>#</a>

# class `Linear`

```
class Linear
    : public Models

```

Класс линейной модели

## Summary

| Member                                                                                           | Description                          |
| ------------------------------------------------------------------------------------------------ | ------------------------------------ |
| private double [A](#class_linear_1af7d68936e67268f4d3a816cbf2050bbe)                             | конастанта линейной модели           |
| private double [B](#class_linear_1aa223ad945a168cfeb948a69f9e6d0aef)                             | константа линейной модели            |
| public virtual virtual double [calculateModel](#class_linear_1ab892d573b3f19953dfa90649ae1de7f2) | перегруженная ф-я для расчёта модели |

## Attributes

#### private double `A` = 0.335 <a id='class_linear_1af7d68936e67268f4d3a816cbf2050bbe' href='#class_linear_1af7d68936e67268f4d3a816cbf2050bbe'>#</a>

#### private double `B` = 0.671 <a id='class_linear_1aa223ad945a168cfeb948a69f9e6d0aef' href='#class_linear_1aa223ad945a168cfeb948a69f9e6d0aef'>#</a>

## Methods

#### public virtual virtual double `calculateModel(double init_room, double init_warm)` [: calculateModel](class_models.md#class_models_1a681ab22836d9b489b5b797b85a406585) <a id='class_linear_1ab892d573b3f19953dfa90649ae1de7f2' href='#class_linear_1ab892d573b3f19953dfa90649ae1de7f2'>#</a>

| Kind  | Member    | Description                     |
| ----- | --------- | ------------------------------- |
| param | init_room | начальная температура           |
| param | init_warm | значение увеличения температуры |

# class `NonLinear`

```
class NonLinear
    : public Models

```

Класс нелинейной модели

## Summary

| Member                                                                                               | Description                          |
| ---------------------------------------------------------------------------------------------------- | ------------------------------------ |
| private double [A](#class_non_linear_1a35ed414c923d0a51bcc9a48d24e202f6)                             | константа нелинейной модели          |
| private double [B](#class_non_linear_1a5e10f073fce400ad722286c79509dc79)                             | константа нелинейной модели          |
| private double [C](#class_non_linear_1a53f20dce7ed5630ad0f34935f402905b)                             | константа нелинейной модели          |
| private double [D](#class_non_linear_1aef2c6a4c54a3c6918833c5000d41ae47)                             | константа нелинейной модели          |
| private double [tempPr](#class_non_linear_1a13b906d795847353a41781239d98978a)                        | предыдущая температура               |
| private double [warmPr](#class_non_linear_1a9671ad1ca219575a75007103a95289d2)                        | предыдущее увеличение температуры    |
| public virtual virtual double [calculateModel](#class_non_linear_1aa4d74c49c0dfbbf8343226c0c8aab54c) | перегруженная ф-я для расчёта модели |

## Attributes

#### private double `A` = 1.0005 <a id='class_non_linear_1a35ed414c923d0a51bcc9a48d24e202f6' href='#class_non_linear_1a35ed414c923d0a51bcc9a48d24e202f6'>#</a>

#### private double `B` = 0.0035 <a id='class_non_linear_1a5e10f073fce400ad722286c79509dc79' href='#class_non_linear_1a5e10f073fce400ad722286c79509dc79'>#</a>

#### private double `C` = 0.535 <a id='class_non_linear_1a53f20dce7ed5630ad0f34935f402905b' href='#class_non_linear_1a53f20dce7ed5630ad0f34935f402905b'>#</a>

#### private double `D` = 0.535 <a id='class_non_linear_1aef2c6a4c54a3c6918833c5000d41ae47' href='#class_non_linear_1aef2c6a4c54a3c6918833c5000d41ae47'>#</a>

#### private double `tempPr` = 0 <a id='class_non_linear_1a13b906d795847353a41781239d98978a' href='#class_non_linear_1a13b906d795847353a41781239d98978a'>#</a>

#### private double `warmPr` = 0 <a id='class_non_linear_1a9671ad1ca219575a75007103a95289d2' href='#class_non_linear_1a9671ad1ca219575a75007103a95289d2'>#</a>

## Methods

#### public virtual virtual double `calculateModel(double init_temp, double init_warm)` [: calculateModel](class_models.md#class_models_1a681ab22836d9b489b5b797b85a406585) <a id='class_non_linear_1aa4d74c49c0dfbbf8343226c0c8aab54c' href='#class_non_linear_1aa4d74c49c0dfbbf8343226c0c8aab54c'>#</a>

| Kind  | Member    | Description                     |
| ----- | --------- | ------------------------------- |
| param | init_room | начальная температура           |
| param | init_warm | значение увеличения температуры |

# class `PidRegulator`

```
class PidRegulator

```

Класс пид регулятора

## Summary

| Member                                                                          | Description                 |
| ------------------------------------------------------------------------------- | --------------------------- |
| private double [T](#class_pid_regulator_1a4b2b5427a5629828d664efca2db0c609)     | постоянная интеграции       |
| private double [T0](#class_pid_regulator_1af45611f0bf22376c4cb1fb6d3a3bfe54)    | шаг                         |
| private double [TD](#class_pid_regulator_1aa00c0fb773e8112445e9300c9b45f076)    | постоянная разницы значений |
| private double [K](#class_pid_regulator_1aebc558d2cc36af91cd688ea6a7a74f13)     | значение передачи           |
| private double [u](#class_pid_regulator_1ad8321d4804e7b5281d062604944badb4)     | результат работы генератора |
| private double [iters](#class_pid_regulator_1ab490c6f021caf46b878c63e94c0b22ef) | кол-во итераций             |
| public double [reg](#class_pid_regulator_1a7c83b9d1fd99ee817df3433c2c2de93b)    | ф-я подсчёта u              |
| public void [pid](#class_pid_regulator_1abcea2bea3d95ebd929d8e49fe51a7929)      | ф-я работы генератора       |

## Attributes

#### private double `T` = 10 <a id='class_pid_regulator_1a4b2b5427a5629828d664efca2db0c609' href='#class_pid_regulator_1a4b2b5427a5629828d664efca2db0c609'>#</a>

#### private double `T0` = 10 <a id='class_pid_regulator_1af45611f0bf22376c4cb1fb6d3a3bfe54' href='#class_pid_regulator_1af45611f0bf22376c4cb1fb6d3a3bfe54'>#</a>

#### private double `TD` = 50 <a id='class_pid_regulator_1aa00c0fb773e8112445e9300c9b45f076' href='#class_pid_regulator_1aa00c0fb773e8112445e9300c9b45f076'>#</a>

#### private double `K` = 0.1 <a id='class_pid_regulator_1aebc558d2cc36af91cd688ea6a7a74f13' href='#class_pid_regulator_1aebc558d2cc36af91cd688ea6a7a74f13'>#</a>

#### private double `u` = 0 <a id='class_pid_regulator_1ad8321d4804e7b5281d062604944badb4' href='#class_pid_regulator_1ad8321d4804e7b5281d062604944badb4'>#</a>

#### private double `iters` = 100 <a id='class_pid_regulator_1ab490c6f021caf46b878c63e94c0b22ef' href='#class_pid_regulator_1ab490c6f021caf46b878c63e94c0b22ef'>#</a>

## Methods

#### public double `reg(double error, double error1, double error2)` <a id='class_pid_regulator_1a7c83b9d1fd99ee817df3433c2c2de93b' href='#class_pid_regulator_1a7c83b9d1fd99ee817df3433c2c2de93b'>#</a>

| Kind  | Member | Description              |
| ----- | ------ | ------------------------ |
| param | error  | основаня ошибка          |
| param | error1 | предыдущая ошибка        |
| param | error2 | дважды предыдущая ошибка |

#### public void `pid(double warm, double y0, Models *Models)` <a id='class_pid_regulator_1abcea2bea3d95ebd929d8e49fe51a7929' href='#class_pid_regulator_1abcea2bea3d95ebd929d8e49fe51a7929'>#</a>

| Kind  | Member | Description                     |
| ----- | ------ | ------------------------------- |
| param | y0     | начальная температура           |
| param | warm   | значение увеличения температуры |
| param | Models | указатель на абстрактный класс  |
