# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`ControlObject`](#class_control_object) | Класс компонента контролируемого объекта
`class `[`Element`](#class_element) | Абстрактный класс элементов системы
`class `[`Feedback`](#class_feedback) | Класс элемента обратной связи
`class `[`LinearCalculator`](#class_linear_calculator) | Класс линейной модели
`class `[`NonlinearCalculator`](#class_nonlinear_calculator) | Класс нелинейной модели
`class `[`Regulator`](#class_regulator) | Класс элемента регулятора
`class `[`TemperatureCalculator`](#class_temperature_calculator) | Абстрактный класс моделей вычисления

# class `ControlObject` 

```
class ControlObject
  : public Element
```  

Класс компонента контролируемого объекта

Является подклассом [Element](#class_element)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`ControlObject`](#class_control_object_1a892cbb2cf005a2b68d0fb2e0ba02bf0e)`(`[`Element`](#class_element)` * next_element,`[`TemperatureCalculator`](#class_temperature_calculator)` * temperature_calculator)` | Construct a new Control Object object.
`public inline virtual double `[`Calculate`](#class_control_object_1a9d6127c6597691c6f76dcbc46cbf5f6c)`(double prev_value)` | Метод вычисления значения
`public inline virtual double `[`GetValue`](#class_control_object_1a515b75ebfc9a0453dd924beae155a58e)`()` | Метод получения внутреннего значения
`public inline  `[`~ControlObject`](#class_control_object_1a28035430b8bfc602dad5fd19b55a767b)`()` | Destroy the Control Object object.

## Members

#### `public inline  `[`ControlObject`](#class_control_object_1a892cbb2cf005a2b68d0fb2e0ba02bf0e)`(`[`Element`](#class_element)` * next_element,`[`TemperatureCalculator`](#class_temperature_calculator)` * temperature_calculator)` 

Construct a new Control Object object.

#### Parameters
* `next_element` Следующий элемент цепи 

* `temperature_calculator` Способ вычисления температуры

#### `public inline virtual double `[`Calculate`](#class_control_object_1a9d6127c6597691c6f76dcbc46cbf5f6c)`(double prev_value)` 

Метод вычисления значения

#### Parameters
* `prev_value` Значение предыдущего элемента 

#### Returns
double

#### `public inline virtual double `[`GetValue`](#class_control_object_1a515b75ebfc9a0453dd924beae155a58e)`()` 

Метод получения внутреннего значения

#### Returns
double

#### `public inline  `[`~ControlObject`](#class_control_object_1a28035430b8bfc602dad5fd19b55a767b)`()` 

Destroy the Control Object object.

# class `Element` 

Абстрактный класс элементов системы

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`Calculate`](#class_element_1a9121a11bb308582291aa30af95b712b0)`(double)` | Абстрактный метод для вычисления значения
`public double `[`GetValue`](#class_element_1a90a763452b3088550f6197587ff7ecfb)`()` | Абстрактный метод для получения внутреннего значения
`protected `[`Element`](#class_element)` * `[`_next_element`](#class_element_1ae053d8b33d16404d2db4b47692b39b47) | 

## Members

#### `public double `[`Calculate`](#class_element_1a9121a11bb308582291aa30af95b712b0)`(double)` 

Абстрактный метод для вычисления значения

#### Returns
double

#### `public double `[`GetValue`](#class_element_1a90a763452b3088550f6197587ff7ecfb)`()` 

Абстрактный метод для получения внутреннего значения

#### Returns
double

#### `protected `[`Element`](#class_element)` * `[`_next_element`](#class_element_1ae053d8b33d16404d2db4b47692b39b47) 

# class `Feedback` 

```
class Feedback
  : public Element
```  

Класс элемента обратной связи

Является подклассом [Element](#class_element)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Feedback`](#class_feedback_1a965fb5868ba37db6e93c329fcb43cad0)`(`[`Element`](#class_element)` * next_element,double expected_value)` | Construct a new [Feedback](#class_feedback) object.
`public inline virtual double `[`Calculate`](#class_feedback_1a2af6e8e068f9dbe62b34ba49f90f5de4)`(double prev_value)` | Метод вычисления значения
`public inline virtual double `[`GetValue`](#class_feedback_1a752bb24e426291125b7fcb0c7be68dff)`()` | Метод получения внутреннего значения
`public inline  `[`~Feedback`](#class_feedback_1aa5037cce52fef7c63980caef4e13532c)`()` | Destroy the [Feedback](#class_feedback) object.

## Members

#### `public inline  `[`Feedback`](#class_feedback_1a965fb5868ba37db6e93c329fcb43cad0)`(`[`Element`](#class_element)` * next_element,double expected_value)` 

Construct a new [Feedback](#class_feedback) object.

#### Parameters
* `next_element` Следующий элемент схемы 

* `expected_value` Ожидаемое значение

#### `public inline virtual double `[`Calculate`](#class_feedback_1a2af6e8e068f9dbe62b34ba49f90f5de4)`(double prev_value)` 

Метод вычисления значения

#### Parameters
* `prev_value` Значение предыдущего элемента 

#### Returns
double

#### `public inline virtual double `[`GetValue`](#class_feedback_1a752bb24e426291125b7fcb0c7be68dff)`()` 

Метод получения внутреннего значения

#### Returns
double

#### `public inline  `[`~Feedback`](#class_feedback_1aa5037cce52fef7c63980caef4e13532c)`()` 

Destroy the [Feedback](#class_feedback) object.

# class `LinearCalculator` 

```
class LinearCalculator
  : public TemperatureCalculator
```  

Класс линейной модели

Является подклассом [TemperatureCalculator](#class_temperature_calculator)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearCalculator`](#class_linear_calculator_1ab79d0cf1f768aa789a213bd3f71c5da3)`(double current_temperature,double a,double b)` | Construct a new Linear Temperature Calculator object.
`public inline virtual double `[`CalculateNextTemperature`](#class_linear_temperature_calculator_1a07cf007c632ad0e157c5b02f0d9ff14f)`(double input_warm)` | Метод вычисления температуры

## Members

#### `public inline  `[`LinearCalculator`](#class_linear_calculator_1ab79d0cf1f768aa789a213bd3f71c5da3)`(double current_temperature,double a,double b)` 

Construct a new Linear Temperature Calculator object.

#### Parameters
* `current_temperature` Текущая температура 

* `a` Параметр А 

* `b` Параметр В

#### `public inline virtual double `[`CalculateNextTemperature`](#class_linear_temperature_calculator_1a07cf007c632ad0e157c5b02f0d9ff14f)`(double input_warm)` 

Метод вычисления температуры

#### Parameters
* `input_warm` Входное тепло 

#### Returns
double

# class `NonlinearCalculator` 

```
class NonlinearCalculator
  : public TemperatureCalculator
```  

Класс нелинейной модели

Является подклассом [TemperatureCalculator](#class_temperature_calculator)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonlinearCalculator`](#class_nonlinear_calculator_1abc05f6c86f8e418cbc86426d9a01a6fa)`(double current_temperature,double a,double b,double c,double d)` | Construct a new Nonlinear Temperature Calculator object.
`public inline virtual double `[`CalculateNextTemperature`](#class_nonlinear_temperature_calculator_1ae6059ee5736fa60a183ee9edcd990fea)`(double input_warm)` | Метод вычисления температуры

## Members

#### `public inline  `[`NonlinearCalculator`](#class_nonlinear_calculator_1abc05f6c86f8e418cbc86426d9a01a6fa)`(double current_temperature,double a,double b,double c,double d)` 

Construct a new Nonlinear Temperature Calculator object.

#### Parameters
* `current_temperature` Текущая температура 

* `a` Параметр А 

* `b` Параметр В 

* `c` Параметр С 

* `d` параметр D

#### `public inline virtual double `[`CalculateNextTemperature`](#class_nonlinear_temperature_calculator_1ae6059ee5736fa60a183ee9edcd990fea)`(double input_warm)` 

Метод вычисления температуры

#### Parameters
* `input_warm` Входное тепло 

#### Returns
double

# class `Regulator` 

```
class Regulator
  : public Element
```  

Класс элемента регулятора

Является подклассом [Element](#class_element)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1a0b41b7135c0583893b0f0b1e6c818807)`(`[`Element`](#class_element)` * next_element,double T,double T0,double TD,double K)` | Construct a new [Regulator](#class_regulator) object.
`public inline virtual double `[`Calculate`](#class_regulator_1a44012226822cccc6add1c679bbab2adc)`(double prev_value)` | Метод вычисления значения
`public inline virtual double `[`GetValue`](#class_regulator_1a2b9a6e663d4920f4de7d57de2693054b)`()` | Метод получения внутреннего значения
`public inline  `[`~Regulator`](#class_regulator_1a692d9247294fdd34942f760d519644a0)`()` | Destroy the [Regulator](#class_regulator) object.

## Members

#### `public inline  `[`Regulator`](#class_regulator_1a0b41b7135c0583893b0f0b1e6c818807)`(`[`Element`](#class_element)` * next_element,double T,double T0,double TD,double K)` 

Construct a new [Regulator](#class_regulator) object.

#### Parameters
* `next_element` Следующий элемент цепи 

* `T` Параметр Т 

* `T0` Параметр Т0 

* `TD` Параметр ТD 

* `K` Параметр K

#### `public inline virtual double `[`Calculate`](#class_regulator_1a44012226822cccc6add1c679bbab2adc)`(double prev_value)` 

Метод вычисления значения

#### Parameters
* `prev_value` Значение предыдущего элемента 

#### Returns
double

#### `public inline virtual double `[`GetValue`](#class_regulator_1a2b9a6e663d4920f4de7d57de2693054b)`()` 

Метод получения внутреннего значения

#### Returns
double

#### `public inline  `[`~Regulator`](#class_regulator_1a692d9247294fdd34942f760d519644a0)`()` 

Destroy the [Regulator](#class_regulator) object.

# class `TemperatureCalculator` 

Абстрактный класс моделей вычисления

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`CalculateNextTemperature`](#class_temperature_calculator_1a29d565e704266b76a331eff8d356b3a2)`(double input_warm)` | Абстрактный метод для вычисления сделующего значения температуры
`protected inline  `[`TemperatureCalculator`](#class_temperature_calculator_1a7c449ee43ca46debae13fd515dcdaec2)`()` | 

## Members

#### `public double `[`CalculateNextTemperature`](#class_temperature_calculator_1a29d565e704266b76a331eff8d356b3a2)`(double input_warm)` 

Абстрактный метод для вычисления сделующего значения температуры

#### `protected inline  `[`TemperatureCalculator`](#class_temperature_calculator_1a7c449ee43ca46debae13fd515dcdaec2)`()` 

Generated by [Moxygen](https://sourcey.com/moxygen)