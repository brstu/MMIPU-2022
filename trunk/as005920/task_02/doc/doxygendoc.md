# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`nolinefunct`](#class_nolinefunct) | Класс нелинейной модели
`class `[`PIDregulator`](#class_p_i_d) | Абстрактный класс пид-контроллера

## class `nolinefunct` {#class_nolinefunct}

Класс нелинейной модели

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`nolinefunct`](#class_nolinefunct_1a5153eb3009529547aa9925d21d607c87)`()` | 
`public inline double `[`nolinemodel_controller`](#class_nolinefunct_1ac3d73c3e074329581d4eed2748231b1f)`(double in_t, double in_w)` | Метод вычисления температуры для нелинейной температуры
`public inline  `[`~nolinefunct`](#class_nolinefunct_1a071acf01334d3e4b58ed299d9d97488d)`()` | 
`private const double `[`a`](#class_nolinefunct_1a988d7129bb1cd32209cb785d190fbfe8) | Константы нелинейной модели
`private const double `[`b`](#class_nolinefunct_1aba0a3b23f3ec7fc5e0838d769fac2590) | 
`private const double `[`c`](#class_nolinefunct_1ab973684a43214715ca14cfcbee3ed081) | 
`private const double `[`d`](#class_nolinefunct_1a2333d84ea2564f2ef37b73e6040afb4b) | 
`private double `[`c_w`](#class_nolinefunct_1ae08a046343a82c75d1c9b3b1458b86b4) | 
`private double `[`c_t`](#class_nolinefunct_1a2e17095666a61a29ac586ef25b9fc1bc) | 

### Members

#### `public inline  `[`nolinefunct`](#class_nolinefunct_1a5153eb3009529547aa9925d21d607c87)`()` {#class_nolinefunct_1a5153eb3009529547aa9925d21d607c87}

#### `public inline double `[`nolinemodel_controller`](#class_nolinealmodel_1ac3d73c3e074329581d4eed2748231b1f)`(double in_t, double in_w)` {#class_nolinealmodel_1ac3d73c3e074329581d4eed2748231b1f}

Метод вычисления температуры для нелинейной температуры

#### Parameters
* `in_w` Выходное тепло 

* `in_t` Выходная температура

#### `public inline  `[`~Nolinealmodel`](#class_nolinealmodel_1a071acf01334d3e4b58ed299d9d97488d)`()` {#class_nolinealmodel_1a071acf01334d3e4b58ed299d9d97488d}

#### `private const double `[`a`](#class_nolinealmodel_1a988d7129bb1cd32209cb785d190fbfe8) {#class_nolinealmodel_1a988d7129bb1cd32209cb785d190fbfe8}

Константы нелинейной модели

#### Parameters
* `temp` Текущая температура 

* `a` Параметр А 

* `b` Параметр B 

* `c` Параметр С 

* `d` Параметр D

#### `private const double `[`b`](#class_nolinealmodel_1aba0a3b23f3ec7fc5e0838d769fac2590) {#class_nolinealmodel_1aba0a3b23f3ec7fc5e0838d769fac2590}

#### `private const double `[`c`](#class_nolinealmodel_1ab973684a43214715ca14cfcbee3ed081) {#class_nolinealmodel_1ab973684a43214715ca14cfcbee3ed081}

#### `private const double `[`d`](#class_nolinealmodel_1a2333d84ea2564f2ef37b73e6040afb4b) {#class_nolinealmodel_1a2333d84ea2564f2ef37b73e6040afb4b}

#### `private double `[`c_w`](#class_nolinealmodel_1ae08a046343a82c75d1c9b3b1458b86b4) {#class_nolinealmodel_1ae08a046343a82c75d1c9b3b1458b86b4}

#### `private double `[`c_t`](#class_nolinealmodel_1a2e17095666a61a29ac586ef25b9fc1bc) {#class_nolinealmodel_1a2e17095666a61a29ac586ef25b9fc1bc}

## class `PID` {#class_p_i_d}

Абстрактный класс пид-контроллера

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`PID`](#class_p_i_d_1a0311b6f7de348499ce24e53ba353514a)`()` | 
`public inline double `[`contr`](#class_p_i_d_1a47f11bf23f57ad87196f4db73a509268)`(double e, double e1, double e2)` | 
`public inline double `[`PID_regulator`](#class_p_i_d_1a0c1e18b7a301bc825f79c5c9074a2060)`(double w, double y0, `[`Nolinealmodel`](#class_nolinealmodel)` * model)` | 
`public inline  `[`~PID`](#class_p_i_d_1ab7d389fc5b88d881bc25f5dafd360441)`()` | 
`private const double `[`Td`](#class_p_i_d_1a97ed905d61980831d97c9f0ed460d51e) | #### Parameters
`private const double `[`T`](#class_p_i_d_1a4809f5a5c1efd3512929ec10e225b024) | 
`private const double `[`T0`](#class_p_i_d_1a5e747beca09c0aa9826d33c4c3f6db7b) | 
`private const double `[`k`](#class_p_i_d_1af6141c0fb573968bdfb2462c11ed2acc) | 
`private double `[`u`](#class_p_i_d_1a67ade291736a1c89ca44ada3ff5604e0) | 

### Members

#### `public inline  `[`PID`](#class_p_i_d_1a0311b6f7de348499ce24e53ba353514a)`()` {#class_p_i_d_1a0311b6f7de348499ce24e53ba353514a}

#### `public inline double `[`contr`](#class_p_i_d_1a47f11bf23f57ad87196f4db73a509268)`(double e, double e1, double e2)` {#class_p_i_d_1a47f11bf23f57ad87196f4db73a509268}

#### `public inline double `[`PID_regulator`](#class_p_i_d_1a0c1e18b7a301bc825f79c5c9074a2060)`(double w, double y0, `[`Nolinealmodel`](#class_nolinealmodel)` * model)` {#class_p_i_d_1a0c1e18b7a301bc825f79c5c9074a2060}

#### `public inline  `[`~PID`](#class_p_i_d_1ab7d389fc5b88d881bc25f5dafd360441)`()` {#class_p_i_d_1ab7d389fc5b88d881bc25f5dafd360441}

#### `private const double `[`Td`](#class_p_i_d_1a97ed905d61980831d97c9f0ed460d51e) {#class_p_i_d_1a97ed905d61980831d97c9f0ed460d51e}

#### Parameters
* `T` Параметр Т 

* `T0` Параметр Т0 

* `Td` Параметр Td 

* `K` Параметр k

#### `private const double `[`T`](#class_p_i_d_1a4809f5a5c1efd3512929ec10e225b024) {#class_p_i_d_1a4809f5a5c1efd3512929ec10e225b024}

#### `private const double `[`T0`](#class_p_i_d_1a5e747beca09c0aa9826d33c4c3f6db7b) {#class_p_i_d_1a5e747beca09c0aa9826d33c4c3f6db7b}

#### `private const double `[`k`](#class_p_i_d_1af6141c0fb573968bdfb2462c11ed2acc) {#class_p_i_d_1af6141c0fb573968bdfb2462c11ed2acc}

#### `private double `[`u`](#class_p_i_d_1a67ade291736a1c89ca44ada3ff5604e0) {#class_p_i_d_1a67ade291736a1c89ca44ada3ff5604e0}

Generated by [Moxygen](https://sourcey.com/moxygen)