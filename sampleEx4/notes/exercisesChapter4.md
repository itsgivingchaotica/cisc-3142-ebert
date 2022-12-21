# **Exercises from Chapter 4**

## **Exercise 4.1**
> What is the value returned by 5 + 10 * 20/2?

The value returned by `5 + 10 * 20 / 2` is `105`

## **Exercise 4.2**
> Using Table on p. 166, paranthesize the following expression to indicate the order in which the operands are grouped
a) `*(vec.begin())`

b) `(*(vec.begin())) + 1`

## **Exercise 4.3**
> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?
Efficiency is key to good code. It's more important to prioritize efficient code generation than potential problems with how the programmer writes expressions. 

## **Exercise 4.4**
> Paranthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parantheses) and printing its result.
`((12 / 3)*4) + (5 * 15) + ((24 % 4) / 2)`

## **Exercise 4.5**
> Determine the result of the following expressions
(a) `-30 * 3 + 21 / 5` : `-90 + 4` = `-86`
(b) `-30 + 3 * 21 / 5` : `-30 + 63 / 5` = `-30 + 12` = `-18`
(c) `30 / 3 * 21 % 5` : `10 * 21 % 5` = `210 % 5` = `0`
(d) `-30 / 3 * 21 % 4` : `-10 * 21 % 4` = `-210 % 4` = `-2`

## **Execise 4.6**
> Write an expression to determine whether an `int` value is even or odd
`i % 2 == 0 ? "even" : "odd";`

## **Exercise 4.7**
> What does overflow mean? Show three expressions that will overflow/
For each type, there is a range of values which it may represent. If a value is computed and lies outside of the range of the type, unexpected results may occur. For example:

1. `short val = 32767; ++val;` The value wraps around becuase the sign bit was set to 1, the negative value -32768
2. `unsigned int uval = 4294967295; ++uval;` This is the largest value for unsigned it. Wraps around to 0.
3. `unsigned short usval = 0` --usval;` An unsigned value is never negative. This wraps around to the largest value of 65535

## **Exercise 4.8**
> Explain when operands are evaluated in the logical `AND` logical `OR` and equality operators
Logical AND and OR operators evaluate the left operand before the right. The right operand is evaluated IFF the left operand does not already decide the result. Therefore, for `&&` the right side is evaluated IFF left side is `true`, whereas for `||` IFF left side is `false`. Equality operators have left to right associativity, therefore for an expression like `val == true` and `val` is not a `bool`, `true` is converted to `1`.

## **Exercise 4.9**
> Explain the behavior of the condition in the following `if`:
For the expression 
```
const char *cp = "Hello World";
if (cp && *cp)
```
the left hand side of `&&` because cp is not a null pointer, it points to data `"Hello world"`and `*cp`on right hand side points to char 'H' therefore the condition evaluates as `true`.

## **Exercise 4.10**
> Write the condition for a `while` loop that would read `int`s from the standard input and stop when the value read is equal to 42.
`int val; while (cin >> val && val !=42){}`

## **Exercise 4.11**
> Write an expression that tests four values, `a`, `b`, `b`, and `d`, and ensures that `a` is greater than `b` which is greater than `c` which is greater than `d`
`if (a > b && b > c && c > d)`

## **Exercise 4.12**
> Assuming `i`, `j`, and `k` are all `int`s, explain what `i != j < k` means.
The right side of the expression `i != j < k` is evaluated first as it takes precedence. Thefore `i != ` 0 or 1 depending on the values of `j` and `k`

## **Exercise 4.13**
> What are the values of `i` and `d` after each assignment?
We have `int i; double d`
(a) `d = i = 3.5; ` then `i` truncates to 3 and `d` is a `double` so evalutes to `d = 3.0`
(b) `i = d = 3.5;` is equivalent to `i = 3` 

## **Exercise 4.14**
> Explain what happens in each of the `if` tests
The `if` test `if (42 = i)` is illegal since an lvalue is required as the left operand for assignment. For `if (i = 42)` we also must use `==` not `=` for `if` statement.

## **Exercise 4.15**
> The following assingment is illegal. Why? How would you correct it?
```
double dval; int ival; int *pi;
dval = ival = pi = 0;
```
In this example, notice that it's illegal to assign an `*int` to an `int`. Therefore for the assignment to be legal we would need not use `*int`

## **Exercise 4.16**
> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expression as you think they should be.
(a) `if (p = getPtr() != 0)` The equality operator is evaluted prior to the assignment and `getPtr()` would be evaluted first and the result `true` or `false` would be assigned to `i`. Instead write `if ((p = getPtr()) != 0`
(b) We should write `if (i == 1024)` not `if (i = 1024)`

## **Exercise 4.17**
> Explain the difference between prefix and postfix increment. 
In a prefix increment, the value such as 'val' is incremented and the value of the expression once incremented is now 'val' whereas in a postfix increment 'val' would be incremented but the expression itself is still the original value of 'val'.

## **Exercise 4.18**
> What would happen if the `while` loop on pg. 148 that prints the elements from a `vector` used the prefix increment operator?
If a prefix increment was used, the first element in the vector would be incremented to the next and not be printed. It would also try to dereference past the last element which would cause an error. The behavior of the while loop would thus be off by one element.

## **Exercise 4.19**
> Given that `ptr` points to an `int`, that `vec` is a `vector<int>` and that `ival` is an `int`, explain the behavior of each of these expressions. Which if any are likely to be incorrect? Why? How might each be corrected?
(a) `ptr != 0 && *ptr++` : if `ptr` is not a null pointer, then it would return the value stored in memory prior to the increment. Checks if `ptr` is null and checks the pointer value. However this is likely not to give the result needed. Instead write `(*ptr)++` to dereference the correct value.

(b) `ival++ && ival` : `ival` is incremented and original value returned. Returns true if `ival` is non-zero and now the incremented `ival` is also non-zero.

(c) `vec[ival++] <= vec[ival]` is undefined. Could write instead `++ival; vec[ival] <= vec[ival+1]`

## **Exercise 4.20**
> Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those aren't legal are in error
(a) `*iter++;` first de-references value of `iter` then `++iter` 
(b) `(*iter)++;` Since dereferencing `iter` returns a `string`, and that type cannot be incremented, the expression is illegal
(c) `*iter.empty()` is illegal; `iter` is a pointer and has no member named `empty`. The expression should be `(*iter).empty()`
(d) `iter->empty();` equivalent to revised expression above. Checks whether the `string` is empty from the `string` returned by `iter`
(e) `iter++->empty();` Since `->` takes precedence over `++`, this expression checks whether the `string` returned by `iter` is empty then `++iter`

## **Exercise 4.21**
> Write a program to use a conditional operator to find the elements in a `vector<int>` that have odd value and double the value of each such element.

```
#include <iostream>
#include <vector>

using std::vector;
using std::cout;

int main()
{
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //if odd value double the value
    cout << "The odd values in the vector doubled: ";
    for (auto &it : ivec) it = (it % 2) ? (it * 2) : it;
    for (auto it : ivec)
        cout << it << " ";
    return 0;
}

```

## **Exercise 4.22**
> Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more `if` statements. Which version do you think is eaisier to understand and why?

```
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int grade;
    
    cout << "Enter the grades to print high pass, pass, fail as as well as low pass, Ctrl-D to complete: ";
    //use conditional operator, much easier
    while (cin >> grade)
    {
    cout << ((grade > 90) ? "high pass" : (grade < 60) ? "fail" : (grade > 75) ? "pass" : "low pass") << endl;
        //using if statements, the criteria becomes more complicated for printing the result
        if (grade > 90){
            cout << "high pass" << endl;
            continue;
        }
        if (grade < 60)
            cout << "fail" << endl;
        if (grade > 75 && grade <=90)
            cout << "pass" << endl;
        else if (grade >=60 && grade <75)
            cout << "low pass" << endl;
    }
    
    return 0;
}
```

## **Exercise 4.23**
> The following expression fails to compile due to operator precedence. Using table on p. 166, explain why it fails. How would you fix it?
```
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s";
```
When the following tries to run it fails: `s + s[s.size() -1] == 's'` becuase it tries to add the `string s` to `s[3]` which is a `char` and then `== 's' ` which is invalid. We would need to specify in the following way for the code to run correctly:  `s + ((s[s.size() - 1] == 's') ? "" : s");` 

## **Exercise 4.24**
> Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator wold be evaluted if the operator were left associative

If the conditional operator were left associative, everything on the left hand side of the last `?` would be evaluated first and if grade `<90` then assign `grade <60` which would results in printing `"fail"` and never `"pass"`

## **Exercise 4.25**
> What is the value of `~'q' << 6` on a machine with 32-bit `int`s and 8 bit `char`s, that uses Latin-1 character set in which `q` has the bit pattern `01110001`?

`~'q'` is evaluted first so the bit pattern `01110001` is converted from `0000 0000 0000 0000 0000 0000 0111 0001` in 32-bits to `1111 1111 1111 1111 1111 1111 1000 1110` then moved over 6 bit places to the left giving us `1111 1111 1111 1111 1110 0011 1000 0000` which is `-7296` as signed 2's complement.

## **Exercise 4.26**
> In our grading example in this section, what would happen if we used `unsigned int` as the type for `quiz1`?

`unsigned int` is guaranteed to hold 16 bits whereas `unsigned long` holds at least 32 bits therefore since the class has 30 students the `int` type would not be able to hold the bits needed and would thus render the expression undefined.

## **Exercise 4.27**
> What is the reslt of each of these expressions?

`unisnged long ul1 = 3, ul2 = 7;`

(a) `ul1 & ul2` = `0011 & 0111` = `0011` = 3
(b) `ul1 | ul2` = `0011 | 0111` = '0111` = 7
(c) `ul1 && ul2` = 1 = `true`
(d) `ul1 || ul2` = 1 = `true`

## **Exercise 4.29**
> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
`int x[10]; int *p = x;`

`cout << sizeof(x) / sizeof(*x) << endl;` we have 10 / 1 = 10
`cout << sizeof(p) / sizeof(*p) << endl;` the size of the pointer divided by the size of the int. 64-bit machine a pointer is 8 bytes and size of int is 4 bytes so 8/4 = 2. 32-bit machine 4/4 = 1

## **Exercise 4.31**
> The program in this section used the prefix increment and decremenet operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions?

`for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)` using postfix instead of prefix. It's good habit to use prefix over postfix although in this example it doesn't return an invalid or different result.

## **Exercise 4.32**
> Explain the following loop.

```
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr) { / * ... * / }
```
The for loop creates a pointer `ptr` to the first element of `ia` with index `ix` if initially the index and pointer is not pointing past the last element/pointer in the array. Then both are incremented and the for loop continues until the expression returns false.

## **Exercise 4.33**
> Using table on p. 166 explain wha the following expression does

The expression is equivalent to `((true ? (++x, ++y) : --x), --y )`

## **Exercise 4.34**
> Given the variable definitions in this section, explain what conversions take place in the following expressions:

(a) `if (fval)` :  `fval` is converted to a boolean, true if not 0
(b) `dval = fval + ival` : `ival` is converted to `float` and then the sum is converted to `double`
(c) `dval + ival * cval` : `cval` is converted to an `int` and then the `int` is added to the `dval` and converted back to `double`.

## **Exercise 4.35**
> Given the following definitions,
```
char cval;
int ival;
unsigned int ui;
float fval;
double dval;
```

(a) `cval = 'a' + 3;` : 'a' is promoted to `int` to be added to 3 and then the sum is converted to type `char`
(b) `fval = ui - ival * 1.0` : `ival` is converted to `double` as well as unsigned int `ui` and then converted to `float`
(c) `dval = ui * fval` : `ui` converted to `float` and the product converted to `double`
(d) `cval = ival + fval + dval` `int` is converted to `float` and then to `double` and then to `char`

## **Exercise 4.36**
> Assuming `i` is an `int` and `d` is a `double` write the expression `i *= d` so that it does integral, rather than floating point, multiplication.

Floating point multiplication: `i *= d;` integral multiplication : `i *= <static_cast<int>(d);`

## **Exercise 4.37**
> Rewrite each of the following old-style casts to use a named cast
`int i; double d; const string *ps; char *pc; void *pv;`

(a) old-style cast : `pv = (void*)ps;` named cast : `pv = static_cast<void*>(const_cast<string*>(ps));`
(b) `i = int(*pc)` is `i = static_cast<int>(*pc);`
(c) `pv = &d;` is `pv = static_cast<void>(&d);`
(d) `pc = (char*) pv;` is `pc = reinterpret_cast<char*>(pv);`

## **Exercise 4.38**
> Explain the following expression: `double slope = static_cast<double>(j/i);`

`double slope = static_cast<double>(j/i)` (j/i) an `int` by truncation is cast as `double` and assigned to `slope`
