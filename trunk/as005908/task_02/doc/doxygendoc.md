# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Country`](#class_country) | 
`class `[`ellipse`](#classellipse) | 
`class `[`factory`](#classfactory) | 
`class `[`figure`](#classfigure) | 
`class `[`line`](#classline) | 
`class `[`NoLineModel`](#class_no_line_model) | Абстрактный класс нелинейной модели
`class `[`nonSpace`](#classnon_space) | 
`class `[`PID_controller`](#class_p_i_d__controller) | Абстрактный класс пид-контроллера
`class `[`PID_Controller`](#class_p_i_d___controller) | 
`class `[`rectangle`](#classrectangle) | 
`class `[`Russia`](#class_russia) | 
`class `[`Shape`](#class_shape) | 
`class `[`text`](#classtext) | 
`class `[`USA`](#class_u_s_a) | 

## class `Country` {#class_country}

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`AddTroop`](#class_country_1aaa05bc0d0881c16f8c1e635091aa3079)`(pattern * troop)` | 
`public `[`Country`](#class_country)` * `[`Clone`](#class_country_1a453ff418a675e77044d9db981250e519)`()` | 
`protected inline  `[`Country`](#class_country_1a4cba457856775a13a17dfcb11a77e224)`()` | 

### Members

#### `public void `[`AddTroop`](#class_country_1aaa05bc0d0881c16f8c1e635091aa3079)`(pattern * troop)` {#class_country_1aaa05bc0d0881c16f8c1e635091aa3079}

#### `public `[`Country`](#class_country)` * `[`Clone`](#class_country_1a453ff418a675e77044d9db981250e519)`()` {#class_country_1a453ff418a675e77044d9db981250e519}

#### `protected inline  `[`Country`](#class_country_1a4cba457856775a13a17dfcb11a77e224)`()` {#class_country_1a4cba457856775a13a17dfcb11a77e224}

## class `ellipse` {#classellipse}

```
class ellipse
  : public Shape
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual void `[`draw`](#classellipse_1ab45b24ed6d243243a7ec3124f420f056)`()` | 
`public inline virtual void `[`set_to_object`](#classellipse_1a38b4f772fc5cb4a85858cc4528bbc1c9)`()` | 
`public inline virtual `[`ellipse`](#classellipse)` * `[`clone`](#classellipse_1a45a6c027d68f6a5a030c64eda11a5bdd)`()` | 

### Members

#### `public inline virtual void `[`draw`](#classellipse_1ab45b24ed6d243243a7ec3124f420f056)`()` {#classellipse_1ab45b24ed6d243243a7ec3124f420f056}

#### `public inline virtual void `[`set_to_object`](#classellipse_1a38b4f772fc5cb4a85858cc4528bbc1c9)`()` {#classellipse_1a38b4f772fc5cb4a85858cc4528bbc1c9}

#### `public inline virtual `[`ellipse`](#classellipse)` * `[`clone`](#classellipse_1a45a6c027d68f6a5a030c64eda11a5bdd)`()` {#classellipse_1a45a6c027d68f6a5a030c64eda11a5bdd}

## class `factory` {#classfactory}

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Shape`](#class_shape)` * `[`Product1`](#classfactory_1a1b0c44077b7914f0bbe765916b756eb3)`()` | 
`public `[`Shape`](#class_shape)` * `[`Product2`](#classfactory_1aae04a93a653f65dc5edd5fa472030993)`()` | 

### Members

#### `public `[`Shape`](#class_shape)` * `[`Product1`](#classfactory_1a1b0c44077b7914f0bbe765916b756eb3)`()` {#classfactory_1a1b0c44077b7914f0bbe765916b756eb3}

#### `public `[`Shape`](#class_shape)` * `[`Product2`](#classfactory_1aae04a93a653f65dc5edd5fa472030993)`()` {#classfactory_1aae04a93a653f65dc5edd5fa472030993}

## class `figure` {#classfigure}

```
class figure
  : public factory
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`private inline virtual `[`Shape`](#class_shape)` * `[`Product1`](#classfigure_1ae889c190d4f565a161f9746bfd185252)`()` | 
`private inline virtual `[`Shape`](#class_shape)` * `[`Product2`](#classfigure_1a8d7e5932c4e6cc1e01983008a295a47f)`()` | 

### Members

#### `private inline virtual `[`Shape`](#class_shape)` * `[`Product1`](#classfigure_1ae889c190d4f565a161f9746bfd185252)`()` {#classfigure_1ae889c190d4f565a161f9746bfd185252}

#### `private inline virtual `[`Shape`](#class_shape)` * `[`Product2`](#classfigure_1a8d7e5932c4e6cc1e01983008a295a47f)`()` {#classfigure_1a8d7e5932c4e6cc1e01983008a295a47f}

## class `line` {#classline}

```
class line
  : public Shape
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`line`](#classline_1a68c308bd5049fc0eebada748a261d132)`(int buff_long_of)` | 
`public inline virtual void `[`draw`](#classline_1ac3edc76a59ee53e240875513073c447c)`()` | 
`public inline virtual void `[`set_to_object`](#classline_1afa85e8bdb94b685bca6de9dffd4b0301)`()` | 
`public inline virtual `[`line`](#classline)` * `[`clone`](#classline_1a9b771d5d782d8282282503e5438700b0)`()` | 
`private int `[`long_of`](#classline_1a57b340d044f687cb637fe7f57189ca43) | 

### Members

#### `public inline  `[`line`](#classline_1a68c308bd5049fc0eebada748a261d132)`(int buff_long_of)` {#classline_1a68c308bd5049fc0eebada748a261d132}

#### `public inline virtual void `[`draw`](#classline_1ac3edc76a59ee53e240875513073c447c)`()` {#classline_1ac3edc76a59ee53e240875513073c447c}

#### `public inline virtual void `[`set_to_object`](#classline_1afa85e8bdb94b685bca6de9dffd4b0301)`()` {#classline_1afa85e8bdb94b685bca6de9dffd4b0301}

#### `public inline virtual `[`line`](#classline)` * `[`clone`](#classline_1a9b771d5d782d8282282503e5438700b0)`()` {#classline_1a9b771d5d782d8282282503e5438700b0}

#### `private int `[`long_of`](#classline_1a57b340d044f687cb637fe7f57189ca43) {#classline_1a57b340d044f687cb637fe7f57189ca43}

## class `NoLineModel` {#class_no_line_model}

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

## class `nonSpace` {#classnon_space}

```
class nonSpace
  : public factory
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`private inline virtual `[`Shape`](#class_shape)` * `[`Product1`](#classnon_space_1a9c065f67b3081b0104e6bd6a1099d270)`()` | 
`private inline virtual `[`Shape`](#class_shape)` * `[`Product2`](#classnon_space_1adfb0eda2f6929c520f56e90fbb62e1ba)`()` | 

### Members

#### `private inline virtual `[`Shape`](#class_shape)` * `[`Product1`](#classnon_space_1a9c065f67b3081b0104e6bd6a1099d270)`()` {#classnon_space_1a9c065f67b3081b0104e6bd6a1099d270}

#### `private inline virtual `[`Shape`](#class_shape)` * `[`Product2`](#classnon_space_1adfb0eda2f6929c520f56e90fbb62e1ba)`()` {#classnon_space_1adfb0eda2f6929c520f56e90fbb62e1ba}

## class `PID_controller` {#class_p_i_d__controller}

Абстрактный класс пид-контроллера

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

### Members

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

## class `rectangle` {#classrectangle}

```
class rectangle
  : public Shape
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`rectangle`](#classrectangle_1ad4051666ee82815412630ee4020c4477)`(int buff_long_of)` | 
`public inline virtual void `[`draw`](#classrectangle_1ad4eed4000cf558c6fd3528573990f6f8)`()` | 
`public inline virtual void `[`set_to_object`](#classrectangle_1ae8e01b7a7764ee535cdfe60acfcc8354)`()` | 
`public inline virtual `[`rectangle`](#classrectangle)` * `[`clone`](#classrectangle_1aaf40ebf401dbf824527559239d3faf3a)`()` | 
`private int `[`long_of`](#classrectangle_1abea7d3297b2361f0d2b9d5bb2143c57f) | 

### Members

#### `public inline  `[`rectangle`](#classrectangle_1ad4051666ee82815412630ee4020c4477)`(int buff_long_of)` {#classrectangle_1ad4051666ee82815412630ee4020c4477}

#### `public inline virtual void `[`draw`](#classrectangle_1ad4eed4000cf558c6fd3528573990f6f8)`()` {#classrectangle_1ad4eed4000cf558c6fd3528573990f6f8}

#### `public inline virtual void `[`set_to_object`](#classrectangle_1ae8e01b7a7764ee535cdfe60acfcc8354)`()` {#classrectangle_1ae8e01b7a7764ee535cdfe60acfcc8354}

#### `public inline virtual `[`rectangle`](#classrectangle)` * `[`clone`](#classrectangle_1aaf40ebf401dbf824527559239d3faf3a)`()` {#classrectangle_1aaf40ebf401dbf824527559239d3faf3a}

#### `private int `[`long_of`](#classrectangle_1abea7d3297b2361f0d2b9d5bb2143c57f) {#classrectangle_1abea7d3297b2361f0d2b9d5bb2143c57f}

## class `Russia` {#class_russia}

```
class Russia
  : public Country
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Russia`](#class_russia_1a8eecf41da9af057c71e04bf8e18d9700)`()` | 
`public inline  `[`Russia`](#class_russia_1a02d11fce79f78f366776a423e4df85c1)`(`[`Russia`](#class_russia)` * other)` | 
`public inline virtual void `[`AddTroop`](#class_russia_1a8eb6b3a705cfdfc4572f98cb948e6380)`(pattern * troop)` | 
`public inline virtual `[`Country`](#class_country)` * `[`Clone`](#class_russia_1a9dc493fafb5117563d9409dc5ebe8cd5)`()` | 

### Members

#### `public inline  `[`Russia`](#class_russia_1a8eecf41da9af057c71e04bf8e18d9700)`()` {#class_russia_1a8eecf41da9af057c71e04bf8e18d9700}

#### `public inline  `[`Russia`](#class_russia_1a02d11fce79f78f366776a423e4df85c1)`(`[`Russia`](#class_russia)` * other)` {#class_russia_1a02d11fce79f78f366776a423e4df85c1}

#### `public inline virtual void `[`AddTroop`](#class_russia_1a8eb6b3a705cfdfc4572f98cb948e6380)`(pattern * troop)` {#class_russia_1a8eb6b3a705cfdfc4572f98cb948e6380}

#### `public inline virtual `[`Country`](#class_country)` * `[`Clone`](#class_russia_1a9dc493fafb5117563d9409dc5ebe8cd5)`()` {#class_russia_1a9dc493fafb5117563d9409dc5ebe8cd5}

## class `Shape` {#class_shape}

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`draw`](#class_shape_1afacc5aad8e37308c3ce8fef768199b05)`()` | 
`public void `[`set_to_object`](#class_shape_1a4f5cbb70beadc864d90d2909abca5537)`()` | 
`public `[`Shape`](#class_shape)` * `[`clone`](#class_shape_1abe4aa6a335cdabe5eb677c662caf1cce)`()` | 

### Members

#### `public void `[`draw`](#class_shape_1afacc5aad8e37308c3ce8fef768199b05)`()` {#class_shape_1afacc5aad8e37308c3ce8fef768199b05}

#### `public void `[`set_to_object`](#class_shape_1a4f5cbb70beadc864d90d2909abca5537)`()` {#class_shape_1a4f5cbb70beadc864d90d2909abca5537}

#### `public `[`Shape`](#class_shape)` * `[`clone`](#class_shape_1abe4aa6a335cdabe5eb677c662caf1cce)`()` {#class_shape_1abe4aa6a335cdabe5eb677c662caf1cce}

## class `text` {#classtext}

```
class text
  : public Shape
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`text`](#classtext_1aad9c90428cab006ed58e606c9567a401)`(std::string buff_set)` | 
`public inline virtual void `[`draw`](#classtext_1a25103b3989e3a8f27a624361a6b2570c)`()` | 
`public inline virtual void `[`set_to_object`](#classtext_1a7fd2bfd54da52391560ad3830f8caf7b)`()` | 
`public inline virtual `[`text`](#classtext)` * `[`clone`](#classtext_1aea34de4bc8c875f2eb26738f08b50d57)`()` | 
`private std::string `[`set`](#classtext_1aca745a1b2c9c5010a1a5285741ef64f3) | 

### Members

#### `public inline  `[`text`](#classtext_1aad9c90428cab006ed58e606c9567a401)`(std::string buff_set)` {#classtext_1aad9c90428cab006ed58e606c9567a401}

#### `public inline virtual void `[`draw`](#classtext_1a25103b3989e3a8f27a624361a6b2570c)`()` {#classtext_1a25103b3989e3a8f27a624361a6b2570c}

#### `public inline virtual void `[`set_to_object`](#classtext_1a7fd2bfd54da52391560ad3830f8caf7b)`()` {#classtext_1a7fd2bfd54da52391560ad3830f8caf7b}

#### `public inline virtual `[`text`](#classtext)` * `[`clone`](#classtext_1aea34de4bc8c875f2eb26738f08b50d57)`()` {#classtext_1aea34de4bc8c875f2eb26738f08b50d57}

#### `private std::string `[`set`](#classtext_1aca745a1b2c9c5010a1a5285741ef64f3) {#classtext_1aca745a1b2c9c5010a1a5285741ef64f3}

## class `USA` {#class_u_s_a}

```
class USA
  : public Country
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`USA`](#class_u_s_a_1a6f84ae5d294198969dd31b471f36e084)`()` | 
`public inline  `[`USA`](#class_u_s_a_1a61614725a9f8020259707f7fd99ea72b)`(`[`USA`](#class_u_s_a)` * other)` | 
`public inline virtual void `[`AddTroop`](#class_u_s_a_1ac55aece84378355584ff7251b55133a3)`(pattern * troop)` | 
`public inline virtual `[`Country`](#class_country)` * `[`Clone`](#class_u_s_a_1af510ec4407e81ae8ed70cdc427e1ed02)`()` | 

### Members

#### `public inline  `[`USA`](#class_u_s_a_1a6f84ae5d294198969dd31b471f36e084)`()` {#class_u_s_a_1a6f84ae5d294198969dd31b471f36e084}

#### `public inline  `[`USA`](#class_u_s_a_1a61614725a9f8020259707f7fd99ea72b)`(`[`USA`](#class_u_s_a)` * other)` {#class_u_s_a_1a61614725a9f8020259707f7fd99ea72b}

#### `public inline virtual void `[`AddTroop`](#class_u_s_a_1ac55aece84378355584ff7251b55133a3)`(pattern * troop)` {#class_u_s_a_1ac55aece84378355584ff7251b55133a3}

#### `public inline virtual `[`Country`](#class_country)` * `[`Clone`](#class_u_s_a_1af510ec4407e81ae8ed70cdc427e1ed02)`()` {#class_u_s_a_1af510ec4407e81ae8ed70cdc427e1ed02}

Generated by [Moxygen](https://sourcey.com/moxygen)