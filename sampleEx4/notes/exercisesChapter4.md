# **Exercises from Chapter 4**

## **Exercise 4.1**
The value returned by `5 + 10 * 20 / 2` is `105`

## **Exercise 4.2**
a) `*(vec.begin())`

b) `(*(vec.begin())) + 1`

## **Exercise 4.3**
Efficiency is key to good code. It's more important to prioritize efficient code generation than potential problems with how the programmer writes expressions. 

## **Exercise 4.4**
`((12 / 3)*4) + (5 * 15) + ((24 % 4) / 2)`

## **Exercise 4.5**
(a) `-30 * 3 + 21 / 5` : `-90 + 4` = `-86`
(b) `-30 + 3 * 21 / 5` : `-30 + 63 / 5` = `-30 + 12` = `-18`
(c) `30 / 3 * 21 % 5` : `10 * 21 % 5` = `210 % 5` = `0`
(d) `-30 / 3 * 21 % 4` : `-10 * 21 % 4` = `-210 % 4` = `-2`

## **Execise 4.6**
`i % 2 == 0 ? "even" : "odd";`

## **Exercise 4.7**
For each type, there is a range of values which it may represent. If a value is computed and lies outside of the range of the type, unexpected results may occur. For example:

1. `short val = 32767; ++val;` The value wraps around becuase the sign bit was set to 1, the negative value -32768
2. `unsigned int uval = 4294967295; ++uval;` This is the largest value for unsigned it. Wraps around to 0.
3. `unsigned short usval = 0` --usval;` An unsigned value is never negative. This wraps around to the largest value of 65535

## **Exercise 4.8**
Logical AND and OR operators evaluate the left operand before the right. The right operand is evaluated IFF the left operand does not already decide the result. Therefore, for `&&` the right side is evaluated IFF left side is `true`, whereas for `||` IFF left side is `false`. Equality operators have left to right associativity, therefore for an expression like `val == true` and `val` is not a `bool`, `true` is converted to `1`.

## **Exercise 4.9**
For the expression 
```
const char *cp = "Hello World";
if (cp && *cp)
```
the left hand side of `&&` because cp is not a null pointer, it points to data `"Hello world"`and `*cp`on right hand side points to char 'H' therefore the condition evaluates as `true`.

## **Exercise 4.10**
`int val; while (cin >> val && val !=42){}`

## **Exercise 4.11**
`if (a > b && b > c && c > d)`

## **Exercise 4.12**
The right side of the expression `i != j < k` is evaluated first as it takes precedence. Thefore `i != ` 0 or 1 depending on the values of `j` and `k`

## **Exercise 4.13**
We have `int i; double d`
(a) `d = i = 3.5; ` then `i` truncates to 3 and `d` is a `double` so evalutes to `d = 3.0`
(b) `i = d = 3.5;` is equivalent to `i = 3` 

## **Exercise 4.14**
The `if` test `if (42 = i)` is illegal since an lvalue is required as the left operand for assignment. For `if (i = 42)` if the assignment is true then it returns `true`.

## **Exercise 4.15**
In this example, noticed that it's illegal to assign an `*int` to an `int`. Therefore for the assignment to be legal we would need not use `*int`

## **Exercise 4.16**
(a) The equality operator is evaluted prior to the assignment and `getPtr()` would be evaluted first and the result `true` or `false` would be assigned to `i`. Instead write `if ((p = getPtr()) != 0`
(b) We should write `if (i == 1024)` not `if (i = 1024)`

## **Exercise 4.17**
In a prefix increment, the value such as 'val' is incremented and the value of the expression once incremented is now 'val' whereas in a postfix increment 'val' would be incremented but the expression itself is still the original value of 'val'.

## **Exercise 4.18**
If a prefix increment was used, the first element in the vector would be incremented to the next and not be printed. It would also try to dereference past the last element which would cause an error. The behavior of the while loop would thus be off by one element.

## **Exercise 4.19**
(a) `ptr != 0 && *ptr++` : if `ptr` is not a null pointer, then increment the pointer a return the value stored in memory prior to the increment. However if it is dereferenced after the expression it it will cause an error, therefore the expression should be `(*ptr)++`

(b) `ival++ && ival` : `ival` is incremented and original value returned. Returns true if `ival` is non-zero and now the incremented `ival` is also non-zero.

(c) `vec[ival++] <= vec[ival]` is undefined. Could write instead `++ival, vec[ival] <= vec[ival+1]`

## **Exercise 4.20**
for `vector<string>::iterator`
(a) `*iter++;` first de-references value of `iter` then `++iter` 
(b) `(*iter)++;` Since dereferencing `iter` returns a `string`, and that type cannot be incremented, the expression is illegal
(c) `*iter.empty()` is illegal; `iter` is a pointer and has no member named `empty`. The expression should be `(*iter).empty()`
(d) `iter->empty();` equivalent to revised expression above. Checks whether the `string` is empty from the `string` returned by `iter`
(e) `iter++->empty();` Since `->` takes precedence over `++`, this expression checks whether the `string` returned by `iter` is empty then `++iter`

## **Exercise 4.23**
When the following tries to run it fails: `s + s[s.size() -1] == 's'` becuase it tries to add the `string s` to `s[3]` which is a `char` and then `== 's' ` which is invalid. We would need to specify in the following way for the code to run correctly:  `s + ((s[s.size() - 1] == 's') ? "" : s");` 

## **Exercise4.24**
If the conditional operator were left associative, everything on the left hand side of the last `?` would be evaluated first and if grade `<90` then assign `grade <60` which would results in printing `"fail"` and never `"pass"`

## **Exercise 4.25**
`~'q'` is evaluted first so the bit pattern `01110001` is converted from `0000 0000 0000 0000 0000 0000 0111 0001` in 32-bits to `1111 1111 1111 1111 1111 1111 1000 1110` then moved over 6 bit places to the left giving us `1111 1111 1111 1111 1110 0011 1000 0000` which is `-7296` as signed 2's complement.

## **Exercise 4.26**
`unsigned int` is guaranteed to hold 16 bits whereas `unsigned long` holds at least 32 bits therefore since the class has 30 students the `int` type would not be able to hold the bits needed and would thus render the expression undefined.

## **Exercise 4.27**
(a) `ul1 & ul2` = `0011 & 0111` = `0011` = 3
(b) `ul1 | ul2` = `0011 | 0111` = '0111` = 7
(c) `ul1 && ul2` = 1 = `true`
(d) `ul1 || ul2` = 1 = `true`

## **Exercise 4.29**
`cout << sizeof(x) / sizeof(*x) << endl;` we have 10 / 1 = 10
`cout << sizeof(p) / sizeof(*p) << endl;` the size of the pointer divided by the size of the int. 64-bit machine a pointer is 8 bytes and size of int is 4 bytes so 8/4 = 2. 32-bit machine 4/4 = 1

## **Exercise 4.31**
`for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)` using postfix instead of prefix. It's good habit to use prefix over postfix although in this example it doesn't return an invalid or different result.

## **Exercise 4.32**
The for loop creates a pointer `ia` to the first element of `ia` with index `ix` if initially the index and pointer is not pointing past the last element/pointer in the array. Then both are incremented and the for loop continues until the expression returns false.

## **Exercise 4.33**
The expression is equivalent to `((true ? (++x, ++y) : --x), --y )`

## **Exercise 4.34**
(a) `if (fval)` :  `fval` is converted to a boolean, true if not 0
(b) `dval = fval + ival` : `ival` is converted to `float` and then the sum is converted to `double`
(c) `dval + ival * cval` : `cval` is converted to an `int` and then the `int` is converted to a `double` to  add to `dval`

## **Exercise 4.35**
(a) `cval = 'a' + 3;` : 'a' is promoted to `int` to be added to 3 and then the sum is converted to type `char`
(b) `fval = ui - ival * 1.0` : `ival` is converted to `double` as well as unsigned int `ui` and then converted to `float`
(c) `dval = ui * fval` : `ui` converted to `float` and the product converted to `double`
(d) `cval = ival + fval + dval` `int` is converted to `float` and then to `double` and then to `char`

## **Exercise 4.36**
Floating point multiplication: `i *= d;` integral multiplication : `i *= <static_cast<int>(d);`

## **Exercise4.37**
(a) old-style cast : `pv = (void*)ps;` named cast : `pv = static_cast<void*>(const_cast<string*>(ps));`
(b) `i = int(*pc)` is `i = static_cast<int>(*pc);`
(c) `pv = &d;` is `pv = static_cast<void>(&d);`
(d) `pc = (char*) pv;` is `pc = reinterpret_cast<char*>(pv);`

## **Exercise4.38**
`double slope = static_cast<double>(j/i)` (j/i) an `int` by truncation is cast as `double` and assigned to `slope`
