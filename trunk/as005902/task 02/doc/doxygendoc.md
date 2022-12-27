# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Lin`](#class_lin) | `Линейная система`
`class `[`NonLin`](#class_non_lin) | `Нелинейная система`
`class `[`System`](#class_system) | `Родительский класс для линейной и нелинейной систем`

## class `Lin` {#class_lin}

```
class Lin
  : public System
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual void `[`Calculation`](#class_lin_1a3a9cb216556174360887d907291bdad8)`()` | `Виртуальная функция для расчёта необходимой информации`

### Members

#### `public inline virtual void `[`Calculation`](#class_lin_1a3a9cb216556174360887d907291bdad8)`()` {#class_lin_1a3a9cb216556174360887d907291bdad8}

## class `NonLin` {#class_non_lin}

```
class NonLin
  : public System
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline virtual void `[`Calculation`](#class_non_lin_1a8df312b9545900240f9fe816ea8169ca)`()` | 

### Members

#### `public inline virtual void `[`Calculation`](#class_non_lin_1a8df312b9545900240f9fe816ea8169ca)`()` {#class_non_lin_1a8df312b9545900240f9fe816ea8169ca}

## class `System` {#class_system}

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`Calculation`](#class_system_1a74ddf37602136a67d11d6f80368f828d)`()` | 
`protected const double `[`k`](#class_system_1a77f463be00a12443d795dd5faf656865) | 
`protected const double `[`t`](#class_system_1a33ec7e51ce08a05736ac52c2a5f276a9) | 
`protected const double `[`td`](#class_system_1a744836e8c40d7b0cb6c718dab51d160b) | 
`protected const double `[`t_0`](#class_system_1aa6e4720fd435e1ceca54dde533622358) | 
`protected const double `[`a`](#class_system_1a3dc3ed15b90f1bd306ecf3180ee34b7e) | 
`protected const double `[`b`](#class_system_1a2b65e8b6bde0ec03cc717afcd069fb3d) | 
`protected const double `[`y_0`](#class_system_1a369cbeabe2625a67e304c7ab0005708a) | 
`protected const double `[`c`](#class_system_1abdba38c20f537e9a488e6c00d4ed56ca) | 
`protected const double `[`d`](#class_system_1a94b2754f58262d1cc8cb66caeea5488c) | 
`protected const double `[`wt`](#class_system_1ab011098b4c35ca378fc858082bc420d6) | 
`protected const int `[`j`](#class_system_1a4de4ad7f6264ac96629c110f0a81b220) | 
`protected double `[`e`](#class_system_1afbf8ac9ef3c9b85c52add5e15b2a4dfe) | 
`protected double `[`e_prev`](#class_system_1a49fcf42ae4fa8f455bafa61a01ace50e) | 
`protected double `[`e_2prev`](#class_system_1adee2b4a764a75e2f4e550b1e53a3847f) | 
`protected double `[`u`](#class_system_1aefd6e7ce6bc19f7bc3e54f187e7b34fd) | 
`protected double `[`du`](#class_system_1a50cb36fd7da7599882751f07a87ee69c) | 
`protected double `[`u_prev`](#class_system_1aef672eddfa8bb4be524fd4e4c424c0a9) | 
`protected double `[`q0`](#class_system_1ac0fd0d3712d573667c0d390c4ca309c3) | 
`protected double `[`q1`](#class_system_1a97b29b9db43813886107ef2e0bd295c8) | 
`protected double `[`q2`](#class_system_1ac5f90adbb8f458bb9162fe0189bc96d6) | 

### Members

#### `public void `[`Calculation`](#class_system_1a74ddf37602136a67d11d6f80368f828d)`()` {#class_system_1a74ddf37602136a67d11d6f80368f828d}

#### `protected const double `[`k`](#class_system_1a77f463be00a12443d795dd5faf656865) {#class_system_1a77f463be00a12443d795dd5faf656865}

#### `protected const double `[`t`](#class_system_1a33ec7e51ce08a05736ac52c2a5f276a9) {#class_system_1a33ec7e51ce08a05736ac52c2a5f276a9}

#### `protected const double `[`td`](#class_system_1a744836e8c40d7b0cb6c718dab51d160b) {#class_system_1a744836e8c40d7b0cb6c718dab51d160b}

#### `protected const double `[`t_0`](#class_system_1aa6e4720fd435e1ceca54dde533622358) {#class_system_1aa6e4720fd435e1ceca54dde533622358}

#### `protected const double `[`a`](#class_system_1a3dc3ed15b90f1bd306ecf3180ee34b7e) {#class_system_1a3dc3ed15b90f1bd306ecf3180ee34b7e}

#### `protected const double `[`b`](#class_system_1a2b65e8b6bde0ec03cc717afcd069fb3d) {#class_system_1a2b65e8b6bde0ec03cc717afcd069fb3d}

#### `protected const double `[`y_0`](#class_system_1a369cbeabe2625a67e304c7ab0005708a) {#class_system_1a369cbeabe2625a67e304c7ab0005708a}

#### `protected const double `[`c`](#class_system_1abdba38c20f537e9a488e6c00d4ed56ca) {#class_system_1abdba38c20f537e9a488e6c00d4ed56ca}

#### `protected const double `[`d`](#class_system_1a94b2754f58262d1cc8cb66caeea5488c) {#class_system_1a94b2754f58262d1cc8cb66caeea5488c}

#### `protected const double `[`wt`](#class_system_1ab011098b4c35ca378fc858082bc420d6) {#class_system_1ab011098b4c35ca378fc858082bc420d6}

#### `protected const int `[`j`](#class_system_1a4de4ad7f6264ac96629c110f0a81b220) {#class_system_1a4de4ad7f6264ac96629c110f0a81b220}

#### `protected double `[`e`](#class_system_1afbf8ac9ef3c9b85c52add5e15b2a4dfe) {#class_system_1afbf8ac9ef3c9b85c52add5e15b2a4dfe}

#### `protected double `[`e_prev`](#class_system_1a49fcf42ae4fa8f455bafa61a01ace50e) {#class_system_1a49fcf42ae4fa8f455bafa61a01ace50e}

#### `protected double `[`e_2prev`](#class_system_1adee2b4a764a75e2f4e550b1e53a3847f) {#class_system_1adee2b4a764a75e2f4e550b1e53a3847f}

#### `protected double `[`u`](#class_system_1aefd6e7ce6bc19f7bc3e54f187e7b34fd) {#class_system_1aefd6e7ce6bc19f7bc3e54f187e7b34fd}

#### `protected double `[`du`](#class_system_1a50cb36fd7da7599882751f07a87ee69c) {#class_system_1a50cb36fd7da7599882751f07a87ee69c}

#### `protected double `[`u_prev`](#class_system_1aef672eddfa8bb4be524fd4e4c424c0a9) {#class_system_1aef672eddfa8bb4be524fd4e4c424c0a9}

#### `protected double `[`q0`](#class_system_1ac0fd0d3712d573667c0d390c4ca309c3) {#class_system_1ac0fd0d3712d573667c0d390c4ca309c3}

#### `protected double `[`q1`](#class_system_1a97b29b9db43813886107ef2e0bd295c8) {#class_system_1a97b29b9db43813886107ef2e0bd295c8}

#### `protected double `[`q2`](#class_system_1ac5f90adbb8f458bb9162fe0189bc96d6) {#class_system_1ac5f90adbb8f458bb9162fe0189bc96d6}

Generated by [Moxygen](https://sourcey.com/moxygen)