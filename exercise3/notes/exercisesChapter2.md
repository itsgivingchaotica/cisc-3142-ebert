# *Exercises from Chapter 2*

## *1. Exercise 2.1*

`short` is at least 16 bits and is no longer than `int`. `int` is 16 bits and up to 3 bits and is no longer than `long`. `long` is minimum 32 bits but no longer than `long long`. `long long` is 64 bits and at least as long as `long`. 

signed integrals can represent negative OR positive numbers including zero (range shold be represented equally between positive and negative values), while unsigned integrals represent values greater than zero only (all the bits represent the value)

`float` type is single-precision floating-point of a minimum size of 6 significant values. `double` represents (you guessed it): double-precision floating-point and its minimum size is 10 significant digits

## *2. Exercise 2.2*

You could use `double` or `float` for each. However, if  I were writing the program I would keep rate as `float` because it is not likely to fluctuate throughout the program beyond a lower number of significant values. Principle and payment may accumulate a higher amount needed for `double` type.


## *3. Exercise 2.3*

Given that: `unsigned u = 10, u2 = 42`

`u2 - u` is 32

- 42-10=32

`u - u2` is 4294967264

- 10-42=-32 so 4294967295-32=4294967264, as they are unsigned do not support negative values and represents the typical 32-bit integer size 

Given that `int i = 10, i2 = 42;`

`i2 - i` is 32

- 42-10=32 

`i - i2 ` is -32

- 10-42=-32 as int is signed it supports negative numbers

`i - u` is 0

- 10-10=0, may be signed or unsigned 

`u - i` is 0

- result same as above

## *4. Exercise 2.10*

the first line of code `std::string global_str;` default initialization is empty string. Another global variable: second line `int global_int` is initialized to 0. within `int main(){}` we have `int local_int` which is undefined and `std::string local_str` has the value defined by the `string` class even though it is appears to be fully uninitialized. This would be empty string.

## *5. Exercise 2.12*

(a) `int double = 3.14` is invalid because double is a reserved word and cannot be made of the int type. (c) `int catch-22`  is invalid as `-` may not be used in variable name. (d) `int 1_or_21` is invalid because the variable starts with the number

## *6. Exercise 2.13*

the value of `j` is 100. It is evident `int i = 100;` is contained within the scope of the main. `int i = 42;` is beyond the scope of the main and does not apply to the statement `int j = i;`

## *7. Exercise 2.14*

the value of `j` is 100. It is evident that `int i = 10` is within the scope of the main and hence `int j = i` refers to that and not `int i = 42`

## *8. Exercise 2.17*

the code prints 10 10. `&ri = i` means "ri is a reference bound to i" and we can see that `ri = 10`

## *9. Exercise 2.27*

The initializations in (a) (c) and (f) are illegal. (b) is legal because `p2` will always point to `i2`. (d) `const int *const p3 = &i2;` is legal as `i2` is a `const` pointer represented by `*const p3` to a `const` `int` object. (e) `const int *p1 = &i2` : `i2`  points to the `const` object (g) `i2` is bound to `i`, and `r` is bound to `ic` but neither can change what they are bound to.

## *10. Exercise 2.28*

(a) is illegal since `cp` must initialize. (b) is illegal because `p3` must initialize if it is `const` (c) is illegal because `ic` isn't initialized as a `const` (d) is illegal, because `p3` must initialize as it is `const`. (e) legal, 1p1  is a pointer to a `const int`.
