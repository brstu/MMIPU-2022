# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Model`](#class_model) | Абстрактный класс для моделей
`class `[`LinearModel`](#class_linear_model) | Класс линейной модели
`class `[`NonLinearModel`](#class_non_linear_model) | Класс нелинейной модели
`class `[`Regulator`](#class_regulator) | Класс регулятора

# class `LinearModel` 

```
class LinearModel
  : public Model
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual double `[`Iteration`](#class_linear_model_1acfe75b5c34e6faeec12ed4a3ccf4a7d1)`(double roomTemp,double inputWarm)` | Виртульная функция для моделей

## Members

#### `public inline virtual double `[`Iteration`](#class_linear_model_1acfe75b5c34e6faeec12ed4a3ccf4a7d1)`(double roomTemp,double inputWarm)` 

# class `Model` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`Iteration`](#class_model_1a155b3abcdc80e184498cf9d02c06d837)`(double roomTemp,double inputWarm)` | Формула модели

## Members

#### `public double `[`Iteration`](#class_model_1a155b3abcdc80e184498cf9d02c06d837)`(double roomTemp,double inputWarm)` 

# class `NonLinearModel` 

```
class NonLinearModel
  : public Model
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual double `[`Iteration`](#class_non_linear_model_1a72e3c9e8c655d86027a590bdec4ed421)`(double roomTemp,double inputWarm)` | Формула модели

## Members

#### `public inline virtual double `[`Iteration`](#class_non_linear_model_1a72e3c9e8c655d86027a590bdec4ed421)`(double roomTemp,double inputWarm)` 

# class `Regulator` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline double `[`Regulate`](#class_regulator_1a79545a743f123eb40de30ef1aff76c9e)`(double e,double e1,double e2)` | Подсчитывает u
`public inline void `[`ResetU`](#class_regulator_1a5ae3e75c4fff3ca3f0cfc0828a2edb1f)`()` | Обновляет значение поля u
`public inline void `[`pidRegulator`](#class_regulator_1ac845e11da51183a1c11b455d0bfbcb3a)`(double w,double y0,`[`Model`](#class_model)` * model)` | ПИД-регулятор

## Members

#### `public inline double `[`Regulate`](#class_regulator_1a79545a743f123eb40de30ef1aff76c9e)`(double e,double e1,double e2)` 

#### `public inline void `[`ResetU`](#class_regulator_1a5ae3e75c4fff3ca3f0cfc0828a2edb1f)`()` 

#### `public inline void `[`pidRegulator`](#class_regulator_1ac845e11da51183a1c11b455d0bfbcb3a)`(double w,double y0,`[`Model`](#class_model)` * model)` 
