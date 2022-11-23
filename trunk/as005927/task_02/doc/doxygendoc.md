# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Linear`](#class_linear) | 
`class `[`NonLinear`](#class_non_linear) | 
`class `[`Regulator`](#class_regulator) | 

## class `Linear` {#class_linear}

```
class Linear
  : public Regulator
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Linear`](#class_linear_1af4b35371ac5e8e4d7e68f7d3ca162e9f)`()` | 
`public inline  `[`~Linear`](#class_linear_1a6abe6c2b55a1e1c3e838aaf82e77e627)`()` | 
`private double * `[`y`](#class_linear_1a7180d081b7565c06b6b5f952b9639020) | 
`private double `[`q0`](#class_linear_1a69a3e6cdd1f1fc44813ebb96a952a388) | 
`private double `[`q1`](#class_linear_1a570a77cc5f3357212406e1ac26419a36) | 
`private double `[`q2`](#class_linear_1a90a279d25fa9c514343e841d25f773ca) | 

### Members

#### `public inline  `[`Linear`](#class_linear_1af4b35371ac5e8e4d7e68f7d3ca162e9f)`()` {#class_linear_1af4b35371ac5e8e4d7e68f7d3ca162e9f}

#### `public inline  `[`~Linear`](#class_linear_1a6abe6c2b55a1e1c3e838aaf82e77e627)`()` {#class_linear_1a6abe6c2b55a1e1c3e838aaf82e77e627}

#### `private double * `[`y`](#class_linear_1a7180d081b7565c06b6b5f952b9639020) {#class_linear_1a7180d081b7565c06b6b5f952b9639020}

#### `private double `[`q0`](#class_linear_1a69a3e6cdd1f1fc44813ebb96a952a388) {#class_linear_1a69a3e6cdd1f1fc44813ebb96a952a388}

#### `private double `[`q1`](#class_linear_1a570a77cc5f3357212406e1ac26419a36) {#class_linear_1a570a77cc5f3357212406e1ac26419a36}

#### `private double `[`q2`](#class_linear_1a90a279d25fa9c514343e841d25f773ca) {#class_linear_1a90a279d25fa9c514343e841d25f773ca}

## class `NonLinear` {#class_non_linear}

```
class NonLinear
  : public Regulator
```

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLinear`](#class_non_linear_1a3ebf4f32e50b143cd0f62c21e29640ac)`()` | 
`public inline  `[`~NonLinear`](#class_non_linear_1aa43b52e56692b108bfda6c55835e115a)`()` | 
`private double * `[`y`](#class_non_linear_1a59430b6e01e2b32cd3d6ba21eca12678) | 
`private double `[`q0`](#class_non_linear_1a44bf1c404369af4d985448048fdeb5d2) | 
`private double `[`q1`](#class_non_linear_1afa419fbd25996aa536c4d1679f806ef3) | 
`private double `[`q2`](#class_non_linear_1adb838c8bedfeee667def9fd4dc95271c) | 

### Members

#### `public inline  `[`NonLinear`](#class_non_linear_1a3ebf4f32e50b143cd0f62c21e29640ac)`()` {#class_non_linear_1a3ebf4f32e50b143cd0f62c21e29640ac}

#### `public inline  `[`~NonLinear`](#class_non_linear_1aa43b52e56692b108bfda6c55835e115a)`()` {#class_non_linear_1aa43b52e56692b108bfda6c55835e115a}

#### `private double * `[`y`](#class_non_linear_1a59430b6e01e2b32cd3d6ba21eca12678) {#class_non_linear_1a59430b6e01e2b32cd3d6ba21eca12678}

#### `private double `[`q0`](#class_non_linear_1a44bf1c404369af4d985448048fdeb5d2) {#class_non_linear_1a44bf1c404369af4d985448048fdeb5d2}

#### `private double `[`q1`](#class_non_linear_1afa419fbd25996aa536c4d1679f806ef3) {#class_non_linear_1afa419fbd25996aa536c4d1679f806ef3}

#### `private double `[`q2`](#class_non_linear_1adb838c8bedfeee667def9fd4dc95271c) {#class_non_linear_1adb838c8bedfeee667def9fd4dc95271c}

## class `Regulator` {#class_regulator}

### Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`protected const double `[`k`](#class_regulator_1aed3a807e299f580a0ee59254177fbc00) | 
`protected const double `[`t`](#class_regulator_1aa684a835cf95bed436220685604f5654) | 
`protected const double `[`t_d`](#class_regulator_1a4dc1f81907fccef6a7d53f10efc2183e) | 
`protected const double `[`t_0`](#class_regulator_1a2a181dce3449581abdfc0d0130994034) | 
`protected const double `[`a`](#class_regulator_1af996e58cd124b4535b79124e30833d70) | 
`protected const double `[`b`](#class_regulator_1a6612225adb1b227f85074d51cff7e0f0) | 
`protected const double `[`y_0`](#class_regulator_1a1b0b89c2571ef8e94b7f8310dc51ee88) | 
`protected const double `[`c`](#class_regulator_1a672db286a13f98b82200dc301342530a) | 
`protected const double `[`d`](#class_regulator_1aa54bdbf04f35af62dfc10875d2795f16) | 
`protected const double `[`w_t`](#class_regulator_1ada676f5f8f7108339be89b93dfad51a4) | 
`protected const int `[`j`](#class_regulator_1ada9e9ebc43b00e4f265cb1376ea06264) | 
`protected double `[`e`](#class_regulator_1ae012dd6bb784303503f74a47b87dd856) | 
`protected double `[`prev_e`](#class_regulator_1a0585d426ead2809ac1db81af5a877334) | 
`protected double `[`prev2_e`](#class_regulator_1a47f64fd9474717d49bcc85fc2d6cd563) | 
`protected double `[`u`](#class_regulator_1a9ae220cad26cd2f24031fb9a0c9f4afa) | 
`protected double `[`d_u`](#class_regulator_1aa67ccc024852d990ca76940e8f3405de) | 
`protected double `[`prev_u`](#class_regulator_1a0aa6aa81997a745f4f231b54a34556bf) | 

### Members

#### `protected const double `[`k`](#class_regulator_1aed3a807e299f580a0ee59254177fbc00) {#class_regulator_1aed3a807e299f580a0ee59254177fbc00}

#### `protected const double `[`t`](#class_regulator_1aa684a835cf95bed436220685604f5654) {#class_regulator_1aa684a835cf95bed436220685604f5654}

#### `protected const double `[`t_d`](#class_regulator_1a4dc1f81907fccef6a7d53f10efc2183e) {#class_regulator_1a4dc1f81907fccef6a7d53f10efc2183e}

#### `protected const double `[`t_0`](#class_regulator_1a2a181dce3449581abdfc0d0130994034) {#class_regulator_1a2a181dce3449581abdfc0d0130994034}

#### `protected const double `[`a`](#class_regulator_1af996e58cd124b4535b79124e30833d70) {#class_regulator_1af996e58cd124b4535b79124e30833d70}

#### `protected const double `[`b`](#class_regulator_1a6612225adb1b227f85074d51cff7e0f0) {#class_regulator_1a6612225adb1b227f85074d51cff7e0f0}

#### `protected const double `[`y_0`](#class_regulator_1a1b0b89c2571ef8e94b7f8310dc51ee88) {#class_regulator_1a1b0b89c2571ef8e94b7f8310dc51ee88}

#### `protected const double `[`c`](#class_regulator_1a672db286a13f98b82200dc301342530a) {#class_regulator_1a672db286a13f98b82200dc301342530a}

#### `protected const double `[`d`](#class_regulator_1aa54bdbf04f35af62dfc10875d2795f16) {#class_regulator_1aa54bdbf04f35af62dfc10875d2795f16}

#### `protected const double `[`w_t`](#class_regulator_1ada676f5f8f7108339be89b93dfad51a4) {#class_regulator_1ada676f5f8f7108339be89b93dfad51a4}

#### `protected const int `[`j`](#class_regulator_1ada9e9ebc43b00e4f265cb1376ea06264) {#class_regulator_1ada9e9ebc43b00e4f265cb1376ea06264}

#### `protected double `[`e`](#class_regulator_1ae012dd6bb784303503f74a47b87dd856) {#class_regulator_1ae012dd6bb784303503f74a47b87dd856}

#### `protected double `[`prev_e`](#class_regulator_1a0585d426ead2809ac1db81af5a877334) {#class_regulator_1a0585d426ead2809ac1db81af5a877334}

#### `protected double `[`prev2_e`](#class_regulator_1a47f64fd9474717d49bcc85fc2d6cd563) {#class_regulator_1a47f64fd9474717d49bcc85fc2d6cd563}

#### `protected double `[`u`](#class_regulator_1a9ae220cad26cd2f24031fb9a0c9f4afa) {#class_regulator_1a9ae220cad26cd2f24031fb9a0c9f4afa}

#### `protected double `[`d_u`](#class_regulator_1aa67ccc024852d990ca76940e8f3405de) {#class_regulator_1aa67ccc024852d990ca76940e8f3405de}

#### `protected double `[`prev_u`](#class_regulator_1a0aa6aa81997a745f4f231b54a34556bf) {#class_regulator_1a0aa6aa81997a745f4f231b54a34556bf}

Generated by [Moxygen](https://sourcey.com/moxygen)