# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AbstrModel`](#class_abstr_model) | Класс, который необходим классам, рассчитывающим линейную и нелинейную модель
`class `[`LinearModel`](#class_linear_model) | Класс, который служит для реализации линейной модели
`class `[`NonLinearModel`](#class_non_linear_model) | Класс, который служит для реализации нелинейной модели
`class `[`Regulator`](#class_regulator) | Класс регулятора

## class `AbstrModel` {#class_abstr_model}

Класс, который необходим классам, рассчитывающим линейную и нелинейную модель

Абстрактный класс, который предоставляет виртуальную функцию уравнения calculateModel и от которого наследуются классы [LinearModel](#class_linear_model) и [NonLinearModel](#class_non_linear_model)

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`calculateModel`](#class_abstr_model_1acfab24a843dd017565c12aa96fd12f64)`(double yCurrent, double inputWarm)` | Виртуальная функция, переопределенная в дочерних классах [LinearModel](#class_linear_model) и [NonLinearModel](#class_non_linear_model).

### Members

#### `public double `[`calculateModel`](#class_abstr_model_1acfab24a843dd017565c12aa96fd12f64)`(double yCurrent, double inputWarm)` {#class_abstr_model_1acfab24a843dd017565c12aa96fd12f64}

Виртуальная функция, переопределенная в дочерних классах [LinearModel](#class_linear_model) и [NonLinearModel](#class_non_linear_model).

Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели. 
#### Parameters
* `yCurrent` Температура помещения 

* `inputWarm` Входящее тепло

## class `LinearModel` {#class_linear_model}

```
class LinearModel
  : public AbstrModel
```

Класс, который служит для реализации линейной модели

Дочерний класс от [AbstrModel](#class_abstr_model), который реализует линейную модель через переопределённую функцию calculateModel

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearModel`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a, double b, double yNext)` | 
`public inline virtual double `[`calculateModel`](#class_linear_model_1a0d8fba6c6f1d6d9eb23f7a33e20f1d7e)`(double yCurrent, double inputWarm)` | Переопределённый метод для рассчёта линейной модели
`private double `[`a_`](#class_linear_model_1a205297fcccc324c557d933c1860b8e09) | Коэффициент
`private double `[`b_`](#class_linear_model_1a4432d8cc276c900820e8b0331a2f47eb) | Коэффициент
`private double `[`yNext_`](#class_linear_model_1aaa8fc78bd709ff36444e869d02b9a5fd) | Получаемая нами температура

### Members

#### `public inline  `[`LinearModel`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a, double b, double yNext)` {#class_linear_model_1aa21922a3dd7e060f69855043075d1db5}

#### `public inline virtual double `[`calculateModel`](#class_linear_model_1a0d8fba6c6f1d6d9eb23f7a33e20f1d7e)`(double yCurrent, double inputWarm)` {#class_linear_model_1a0d8fba6c6f1d6d9eb23f7a33e20f1d7e}

Переопределённый метод для рассчёта линейной модели

Код: 
```cpp
[yNext_](#class_linear_model_1aaa8fc78bd709ff36444e869d02b9a5fd) = [a_](#class_linear_model_1a205297fcccc324c557d933c1860b8e09) * yCurrent + [b_](#class_linear_model_1a4432d8cc276c900820e8b0331a2f47eb) * inputWarm;
return [yNext_](#class_linear_model_1aaa8fc78bd709ff36444e869d02b9a5fd);
```

#### `private double `[`a_`](#class_linear_model_1a205297fcccc324c557d933c1860b8e09) {#class_linear_model_1a205297fcccc324c557d933c1860b8e09}

Коэффициент

#### `private double `[`b_`](#class_linear_model_1a4432d8cc276c900820e8b0331a2f47eb) {#class_linear_model_1a4432d8cc276c900820e8b0331a2f47eb}

Коэффициент

#### `private double `[`yNext_`](#class_linear_model_1aaa8fc78bd709ff36444e869d02b9a5fd) {#class_linear_model_1aaa8fc78bd709ff36444e869d02b9a5fd}

Получаемая нами температура

## class `NonLinearModel` {#class_non_linear_model}

```
class NonLinearModel
  : public AbstractModel
```

Класс, который служит для реализации нелинейной модели

Дочерний класс от [AbstractModel](#class_abstr_model), который реализует нелинейную модель через переопределённую функцию calculateModel

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLinearModel`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a, double b, double c, double d, double yNext)` | 
`public inline virtual double `[`calculateModel`](#class_non_linear_model_1ac48d7e25a35fcc57b8288de331865025)`(double yCurrent, double inputWarm)` | Переопределённый метод для рассчёта нелинейной модели
`private double `[`a_`](#class_non_linear_model_1a3a4e17cf0449be48722a76906bfb8ff0) | Коэффициент
`private double `[`b_`](#class_non_linear_model_1a133e6a1778689e2fcd6a763ec458d17f) | Коэффициент
`private double `[`c_`](#class_non_linear_model_1abd42e0081e783bf9e2ebcecefc20c0d2) | Коэффициент
`private double `[`d_`](#class_non_linear_model_1ac274c3c2f138d46fda853e2aede8ab71) | Коэффициент
`private double `[`yPrev_`](#class_non_linear_model_1afe1af036af8c183964e497d3699cd02e) | Предыдущая температура
`private double `[`yNext_`](#class_non_linear_model_1a82b055714af87823aa31182e54743326) | Получаемая нами температура
`private double `[`wPrev_`](#class_non_linear_model_1ae752d321cd1965ce40d36f3493573fe4) | Предыдущее тепло

### Members

#### `public inline  `[`NonLinearModel`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a, double b, double c, double d, double yNext)` {#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518}

#### `public inline virtual double `[`calculateModel`](#class_non_linear_model_1ac48d7e25a35fcc57b8288de331865025)`(double yCurrent, double inputWarm)` {#class_non_linear_model_1ac48d7e25a35fcc57b8288de331865025}

Переопределённый метод для рассчёта нелинейной модели

Код: 
```cpp
[yNext_](#class_non_linear_model_1a82b055714af87823aa31182e54743326) = [a_](#class_non_linear_model_1a3a4e17cf0449be48722a76906bfb8ff0) * yCurrent - [b_](#class_non_linear_model_1a133e6a1778689e2fcd6a763ec458d17f) * pow([yPrev_](#class_non_linear_model_1afe1af036af8c183964e497d3699cd02e), 2) + [c_](#class_non_linear_model_1abd42e0081e783bf9e2ebcecefc20c0d2) * inputWarm + [d_](#class_non_linear_model_1ac274c3c2f138d46fda853e2aede8ab71) * sin([wPrev_](#class_non_linear_model_1ae752d321cd1965ce40d36f3493573fe4));
[yPrev_](#class_non_linear_model_1afe1af036af8c183964e497d3699cd02e) = [yNext_](#class_non_linear_model_1a82b055714af87823aa31182e54743326);
[wPrev_](#class_non_linear_model_1ae752d321cd1965ce40d36f3493573fe4) = inputWarm;
return [yNext_](#class_non_linear_model_1a82b055714af87823aa31182e54743326);
```

#### `private double `[`a_`](#class_non_linear_model_1a3a4e17cf0449be48722a76906bfb8ff0) {#class_non_linear_model_1a3a4e17cf0449be48722a76906bfb8ff0}

Коэффициент

#### `private double `[`b_`](#class_non_linear_model_1a133e6a1778689e2fcd6a763ec458d17f) {#class_non_linear_model_1a133e6a1778689e2fcd6a763ec458d17f}

Коэффициент

#### `private double `[`c_`](#class_non_linear_model_1abd42e0081e783bf9e2ebcecefc20c0d2) {#class_non_linear_model_1abd42e0081e783bf9e2ebcecefc20c0d2}

Коэффициент

#### `private double `[`d_`](#class_non_linear_model_1ac274c3c2f138d46fda853e2aede8ab71) {#class_non_linear_model_1ac274c3c2f138d46fda853e2aede8ab71}

Коэффициент

#### `private double `[`yPrev_`](#class_non_linear_model_1afe1af036af8c183964e497d3699cd02e) {#class_non_linear_model_1afe1af036af8c183964e497d3699cd02e}

Предыдущая температура

#### `private double `[`yNext_`](#class_non_linear_model_1a82b055714af87823aa31182e54743326) {#class_non_linear_model_1a82b055714af87823aa31182e54743326}

Получаемая нами температура

#### `private double `[`wPrev_`](#class_non_linear_model_1ae752d321cd1965ce40d36f3493573fe4) {#class_non_linear_model_1ae752d321cd1965ce40d36f3493573fe4}

Предыдущее тепло

## class `Regulator` {#class_regulator}

Класс регулятора

Отдельный класс, в котором мы моделируем регулятор

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T, double T0, double TD, double K)` | 
`public inline void `[`PIDRegulatorCalculateAndWrite`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need, double start)` | 
`private double `[`T_`](#class_regulator_1a264985dc9d7a23c2a69b6f5139c6f7b1) | Постоянная интегрирования
`private double `[`T0_`](#class_regulator_1ab0cd6139c39fc51d825db7ceadbd0fa9) | Шаг для квантования
`private double `[`TD_`](#class_regulator_1a2022617c1e51d9eeb4bf87b6402ebf31) | Постоянная дифференцирования
`private double `[`K_`](#class_regulator_1acdadaa85e40fa79d87010fa5753ac9be) | Коэффициент передачи
`private double `[`uk_`](#class_regulator_1a521f8577d1d9b9cb62951a8dd56d1a5c) | Текущее значение управляющего воздействия
`private inline double `[`calculateUk`](#class_regulator_1a50b1c9bc3b00f482d4fb1b39f8466b59)`(double ek, double ek1, double ek2)` | 

### Members

#### `public inline  `[`Regulator`](#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T, double T0, double TD, double K)` {#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0}

#### `public inline void `[`PIDRegulatorCalculateAndWrite`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need, double start)` {#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b}

#### `private double `[`T_`](#class_regulator_1a264985dc9d7a23c2a69b6f5139c6f7b1) {#class_regulator_1a264985dc9d7a23c2a69b6f5139c6f7b1}

Постоянная интегрирования

#### `private double `[`T0_`](#class_regulator_1ab0cd6139c39fc51d825db7ceadbd0fa9) {#class_regulator_1ab0cd6139c39fc51d825db7ceadbd0fa9}

Шаг для квантования

#### `private double `[`TD_`](#class_regulator_1a2022617c1e51d9eeb4bf87b6402ebf31) {#class_regulator_1a2022617c1e51d9eeb4bf87b6402ebf31}

Постоянная дифференцирования

#### `private double `[`K_`](#class_regulator_1acdadaa85e40fa79d87010fa5753ac9be) {#class_regulator_1acdadaa85e40fa79d87010fa5753ac9be}

Коэффициент передачи

#### `private double `[`uk_`](#class_regulator_1a521f8577d1d9b9cb62951a8dd56d1a5c) {#class_regulator_1a521f8577d1d9b9cb62951a8dd56d1a5c}

Текущее значение управляющего воздействия

#### `private inline double `[`calculateUk`](#class_regulator_1a50b1c9bc3b00f482d4fb1b39f8466b59)`(double ek, double ek1, double ek2)` {#class_regulator_1a50b1c9bc3b00f482d4fb1b39f8466b59}

Generated by [Moxygen](https://sourcey.com/moxygen)