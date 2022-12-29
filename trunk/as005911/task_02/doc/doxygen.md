# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`abs_model`](#classabs__model) | Абстрактный класс для наследования для наследования конкретными моделями.
`class `[`lin_model`](#classlin__model) | Класс для линейной модели
`class `[`nonlinear_model`](#classnonlinear__model) | Класс для нелинейной модели
`class `[`pid_regulator`](#classpid__regulator) | Класс моделирования регулятора

## class `abs_model`

Абстрактный класс для наследования для наследования конкретными моделями.

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`virtual_model_method`](#classabs__model_1a55df7694eae0dc3247a7fd126841cb40)`(double y_current, double input_warm)` | Виртуальный метод, который будет переопределяться

### Members

#### `public double `[`virtual_model_method`](#classabs__model_1a55df7694eae0dc3247a7fd126841cb40)`(double y_current, double input_warm)` 

Виртуальный метод, который будет переопределяться

п 
#### Parameters
* `y_current` Температура 

* `input_warm` Тепло

## class `lin_model`

```
class lin_model
  : public abs_model
```

Класс для линейной модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`lin_model`](#classlin__model_1a3cf307789f5b1239df424755dc826b1e)`(double a, double b, double y_next)` | 
`public inline virtual double `[`virtual_model_method`](#classlin__model_1a253b1de15e765e30e891fd422010ad78)`(double y_current, double input_warm)` | Переопределённый метод
`private double `[`m_a`](#classlin__model_1a6e96fedb826ca89c49f8b9055348ebee) | Коэффициент
`private double `[`m_b`](#classlin__model_1a31968a15cb8caee9fe7b2f80d514b321) | Коэффициент
`private double `[`m_y_next`](#classlin__model_1a9f8848d6336872d5c51419c15fc12397) | Получаемая нами температура

### Members

#### `public inline  `[`lin_model`](#classlin__model_1a3cf307789f5b1239df424755dc826b1e)`(double a, double b, double y_next)` 

#### `public inline virtual double `[`virtual_model_method`](#classlin__model_1a253b1de15e765e30e891fd422010ad78)`(double y_current, double input_warm)` 

Переопределённый метод

#### `private double `[`m_a`](#classlin__model_1a6e96fedb826ca89c49f8b9055348ebee) 

Коэффициент

#### `private double `[`m_b`](#classlin__model_1a31968a15cb8caee9fe7b2f80d514b321) 

Коэффициент

#### `private double `[`m_y_next`](#classlin__model_1a9f8848d6336872d5c51419c15fc12397) 

Получаемая нами температура

## class `nonlinear_model`

```
class nonlinear_model
  : public abs_model
```

Класс для нелинейной модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`nonlinear_model`](#classnonlinear__model_1ad3df508f9914613f369af8c0ad201b70)`(double a, double b, double c, double d, double y_next)` | 
`public inline virtual double `[`virtual_model_method`](#classnonlinear__model_1a1813b3e8beb8b5b3d2e00a4d46bf7d0b)`(double y_current, double input_warm)` | Переопределённый метод
`private double `[`m_a`](#classnonlinear__model_1a7f4f003a247c9e99725c3958d0a498fc) | Коэффициент
`private double `[`m_b`](#classnonlinear__model_1a94160ed8942e6a4a92ef248f216a2e8b) | Коэффициент
`private double `[`m_c`](#classnonlinear__model_1aba5aaadc5cca7fd671fd546716c6d6e0) | Коэффициент
`private double `[`m_d`](#classnonlinear__model_1a161ebf3eb78528e624fe969eb77523eb) | Коэффициент
`private double `[`m_y_prev`](#classnonlinear__model_1a733b54547f9983b9a429a65a77bf36ea) | Прошлая температура
`private double `[`m_y_next`](#classnonlinear__model_1a667cd250dffb71ab79c0975bd3138523) | Новая температура
`private double `[`m_w_prev`](#classnonlinear__model_1a267d7b8d8c345111f14fc9d7325ee5d7) | Прошлое тепло

### Members

#### `public inline  `[`nonlinear_model`](#classnonlinear__model_1ad3df508f9914613f369af8c0ad201b70)`(double a, double b, double c, double d, double y_next)` 

#### `public inline virtual double `[`virtual_model_method`](#classnonlinear__model_1a1813b3e8beb8b5b3d2e00a4d46bf7d0b)`(double y_current, double input_warm)` 

Переопределённый метод

#### `private double `[`m_a`](#classnonlinear__model_1a7f4f003a247c9e99725c3958d0a498fc) 

Коэффициент

#### `private double `[`m_b`](#classnonlinear__model_1a94160ed8942e6a4a92ef248f216a2e8b) 

Коэффициент

#### `private double `[`m_c`](#classnonlinear__model_1aba5aaadc5cca7fd671fd546716c6d6e0) 

Коэффициент

#### `private double `[`m_d`](#classnonlinear__model_1a161ebf3eb78528e624fe969eb77523eb) 

Коэффициент

#### `private double `[`m_y_prev`](#classnonlinear__model_1a733b54547f9983b9a429a65a77bf36ea) 

Прошлая температура

#### `private double `[`m_y_next`](#classnonlinear__model_1a667cd250dffb71ab79c0975bd3138523) 

Новая температура

#### `private double `[`m_w_prev`](#classnonlinear__model_1a267d7b8d8c345111f14fc9d7325ee5d7) 

Прошлое тепло

## class `pid_regulator`

Класс моделирования регулятора

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`pid_regulator`](#classpid__regulator_1ae2859d3b5de6e53906e223cbc5aaf639)`(double T, double T0, double TD, double K)` | 
`public inline void `[`CalculatePIDRegulator`](#classpid__regulator_1ab73024cee3cd03544ad6054d614bb7e1)`(double need, double start)` | Метод моделирования ПИД-регулятора
`private double `[`m_T`](#classpid__regulator_1a5032bb92a0cab26e7d9b2379f8aa3181) | Постоянная интегрирования
`private double `[`m_T0`](#classpid__regulator_1ae3115258c2d880ec1dcbd926e10d9b17) | Шаг квантования
`private double `[`m_TD`](#classpid__regulator_1a16c82bfc092ce1b04387e0138aa54063) | Постоянная дифференцирования
`private double `[`m_K`](#classpid__regulator_1a98007b933f7731a2d230225dbeb5f0f7) | Коэффициент передачи
`private double `[`m_uk`](#classpid__regulator_1ab306c67f46b61f3e257071e0d39cee05) | Значение управляющего воздействия
`private inline double `[`UKCalculate`](#classpid__regulator_1ab87d9676fbc937f62672e8cef8e6378b)`(double ek, double ek1, double ek2)` | 

### Members

#### `public inline  `[`pid_regulator`](#classpid__regulator_1ae2859d3b5de6e53906e223cbc5aaf639)`(double T, double T0, double TD, double K)` 

#### `public inline void `[`CalculatePIDRegulator`](#classpid__regulator_1ab73024cee3cd03544ad6054d614bb7e1)`(double need, double start)` 

Метод моделирования ПИД-регулятора

#### Parameters
* `need` Значение, которое хотим получить 

* `start` Начальное значение y

#### `private double `[`m_T`](#classpid__regulator_1a5032bb92a0cab26e7d9b2379f8aa3181)

Постоянная интегрирования

#### `private double `[`m_T0`](#classpid__regulator_1ae3115258c2d880ec1dcbd926e10d9b17) 

Шаг квантования

#### `private double `[`m_TD`](#classpid__regulator_1a16c82bfc092ce1b04387e0138aa54063) 

Постоянная дифференцирования

#### `private double `[`m_K`](#classpid__regulator_1a98007b933f7731a2d230225dbeb5f0f7) {#classpid__regulator_1a98007b933f7731a2d230225dbeb5f0f7}

Коэффициент передачи

#### `private double `[`m_uk`](#classpid__regulator_1ab306c67f46b61f3e257071e0d39cee05) 

Значение управляющего воздействия

#### `private inline double `[`UKCalculate`](#classpid__regulator_1ab87d9676fbc937f62672e8cef8e6378b)`(double ek, double ek1, double ek2)` 

Generated by [Moxygen](https://sourcey.com/moxygen)