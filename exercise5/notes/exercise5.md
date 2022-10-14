#**Exercise 5**

## *Exercises from the textbook:*
## **Exercise 4.5**
> Determine the result of the following expression.

(a) `-30 * 3 + 21 / 5` : `-90 + 4` = `-86`
(b) `-30 + 3 * 21 / 5` : `-30 + 63 / 5` = `-30 + 12` = `-18`
(c) `30 / 3 * 21 % 5` : `10 * 21 % 5` = `210 % 5` = `0`
(d) `-30 / 3 * 21 % 4` : `-10 * 21 % 4` = `-210 % 4` = `-2`

## **Exercise 4.17**
> Explain the difference between prefix and postfix increment

In a prefix increment, the value such as 'val' is incremented and the value of the expression once incremented is now 'val' whereas in a postfix increment 'val' would be incremented but the expression itself is still the original value of 'val'.

## **Exercise 4.34**
> Given the variable definitions in this section, explain what conversions take place in the following expressions:

(a) `if (fval)` :  `fval` is converted to a boolean, true if not 0
(b) `dval = fval + ival` : `ival` is converted to `float` and then the sum is converted to `double`
(c) `dval + ival * cval` : `cval` is converted to an `int` and then the `int` is converted to a `double` to  add to `dval`

## *Practice Problems*
> Sum of Digits: Calculate the sum of digits of a number. The program prompts the user to enter the number. For example: Enter number: 7865 The output should be 7+8+6+5=26.

[Sum of Digits](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/exercise5/sum_of_digits.cpp)

> Prime Numbers: Write a program tha finds and prints all the prime numbers between 3 and 100. 

[Prime Numbers](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/exercise5/prime_numbers.cpp)

> Linear Regression: Write a program tha reads a file containing a pair of numbers in each line (representing x y coordinates) at the end of reading this file compute the linear regression for this set of numbers. Please use the linear regression formulas [here](https://www.dropbox.com/s/qfjnz1oujoo8i8e/Linear%20Regression%20Example.docx?dl=0)

[Linear Regression](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/exercise5/linear_regression.cpp)

The sample data was pulled from [Learn from Marketing: Data Mining + Marketing in Plain English](https://www.learnbymarketing.com/tutorials/linear-regression-by-hand-in-excel/)
