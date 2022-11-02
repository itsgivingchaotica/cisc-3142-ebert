# **Exercises from Chapter 3**

## **Exercise 3.1**
> Rewrite the exercises from 1.4.1 and 2.6.2 with appropriate `using` declarations
[Exercise 3.1](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_1.cpp)

## **Exercise 3.2**
> Write a program to read the standard input a line at a time. Modify your program to read a word at a time.
[Exercise 3.2.A](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_2_1.cpp)
[Exercise3.2.B](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_2_2.cpp)

## **Exercise 3.3**
>Explain how whitespace characters are handled in the `string` input operator and in the `getline` function

In the 'string' input operator `cin`, whitespace characters are not allowed as the `>>` operator skips leading whitespace characters. However, the `getline` function reads in the entire line including all whitespaces until user hits return

## **Exercise 3.4**
> Write a program to read two `string`s and report whether the `strings` are equal. If not, report which of the two is larger.

[Exercise 3.4](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_4.cpp)

## **Exercise 3.5**
> Write a program to read `string`s from the standard input, concatenating what is read into one large `string`. Print the concatenated `string`/ Next, change the program to separate adjacent input `string`s by a space.

[Exercise 3.5](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_5.cpp)

## **Exercise 3.6**
> Use a range for to change all the characters in a `string` to `X`

[Exercise 3.6](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_6.cpp)

## **Exercise 3.7**
> What would happen if you define the loop control variable in the previous exercise as type `char`? Predict the results and then change your program to use a`char` to see if you were right

If we change the for loop control variable to char then the characters will not be changed

```
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
  string str;
  cout << "Enter the string: " << endl;
  cin >> str;
  if(!str.empty())
    {
  //changed from auto &c : str
  for (char c : str)
    c = 'X';
  cout << str << endl;
}
  return 0;
}
```

## **Exercise3.8**
> Rewrite the program in the first exercise, first using a `while` loop and again using a traditional `for` loop. Which of the three approaches do you prefer and why?

As we can see from comparing the three approaches that range for is the most elegant way to iteratively change the string to all X's. The while loop adds an extra line of code to account for `++i`

```
while (i != str1.size()) {
      str1[i] = 'X';
      ++i;
    }
```

A traditional for loop has a more complicated for statement

```
for (i = 0; i < str2.size(); ++i)
```

whereas the range for does not require a counter to iterate through every character in the string as it uses reference to each

```
for (auto &c: str)
```

## **Exercise 3.9**
> What does the following program do? Is it valid? If not, why not?

```
//string is initialized to the empty string
string s;
cout << s[0] <<endl;
```

Invalid. In this case `s[0]` is undefined as `s` is initialized to the empty string therefore there is no value at index 0.

## **Exercise 3.10**
> Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.

[Exercise 3.10](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_10.cpp)

## **Exercise 3.11**
> Is the following range `for` legal? If so, whatis the type of `c`?
```
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```
Legal. `c` is of the type `const char&`. This is only legal until it is attempted to change the value of c. 

## **Exercise 3.12**
> Which, if any, of the following `vector` definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.

(a) `vector<vector<int>> ivec;` is legal. `ivec` is an empty `vector` whose elements are `vector`s of type `int`
(b) `vector<string> svec = ivec;` is not legal. `ivec` holds `ints`s not `string`s
(c) `vector<string> svec(10, "null");` is legal. `svec` has ten elements set to `"null"`

## **Exercise 3.13**
> How many elements are there in each of the following vectors? What are the values of the elements?

(a) `vector<int> v1;` `v1` holds objects of type `int` and is initially empty
(b) `vector<int> v2(10);` `v2` can hold 10 elements of `int` type and is initialized to 0
(c) `vector<int> v3(10, 42);` `v3` has ten `int` elements that have the value 42
(d) `vector<int> v4{10};` `v4` has one `int` element of value 10
(e) `vector<int> v5{10, 42};` `v5` has two `int` elements of the values 10 and 42
(f) `vector<string> v6{10}; `v6` has 10 elements of which are all empty `string`s
(g) `vector<string> v7{10, "hi"};` has ten `string` elements and they are all "hi"

## **Exercise 3.14**
> Write a program to read a sequence of `int`s from `cin` and store those values in a `vector`

[Exercise 3.14](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_14.cpp)

## **Exercise 3.15**
> Repeat the previous program but read `string`s this time

[Exercise 3.15](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_15.cpp)

## **Exercise 3.16**
> Write a program to print the size and contents of the `vector`s from exercise 3.13. 

[Exercise 3.16](https://github.com/itsgivingchaotica/cisc-3142-ebert/blob/main/SampleEx3/exercise3_16.cpp)


## **Exercise 3.18**
> 
The following is not legal:
```
vector<int> ivec;
ivec[0] = 42;
```
`ivec` cannot be subscripted as it is an empty vector. instead we can use `ivec.push_back(42);`

## **Exercise3.19**
1. `vector<int> v1(10, 42);`
2. `vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
3. 
```
vector<int> v3(10);
for (auto &i: ivec)
{
    i = 42;
}
```
Option 1 is the simplest way to add multiple identical elements to a vector in this way

## **Exercise 3.26**
`mid = (beg+end) / 2` can result in overflow specifically when we take `beg+end` whereas `mid = beg + (end - beg) / 2` has no overflow as we subtract `beg` from `end` thereby preventing possible overflow.

## **Exercise 3.27**
(a) `int ia[buf_size];` is illegal because `buf_size` is not `const unsigned` i.e. as a dimension it must be a constant expression.
(b) `int ia[4*7-14]` is equivalent to `int[14]` and is indeed a legal expression `int` in this case is obviously `const`
(c) `int ia[txt_size()]` is legal *only if* the return type of `txt_size()` is `const`
(d) `char st[11] = "fundamental";`is illegal because the number of initializers `char`s in exceed the specified size of the dimension of `st` due to the null terminator unaccounted for. 

## **Exercise 3.28**
1. `string sa[10];` has 10 `string` elements - all empty.
2. `int ia[10];` has 10 `int` elements all automatically initialized to 0.
3. `int main(){string sa2[10]}`  has 10 `string` elements - all empty.
4. `int main(){int ia2[10]}` has 10 uninitialized `int` elements.

## **Exercise 3.29**
There are several drawbacks to using an arrays rather than vectors. 
- An array's length cannot be changed after it is declared. The dimension is fixed, whereas a vector's length may be changed whenever needed. Therefore dynamic creation of arrays is impossible
- Within a block, an array is not initialized whereas a vector will be initialized
- Multiple data types / objects can not be stored and elements can not be deleted

## **Exercise 3.30**
We can see that the size of the array is 10 elements with index values [0,9] therefore when `ix` goes to 10, it is out of range of the array's dimensions

## **Exercise 3.33**
If `scores` was uninitialized then the values would be undefined

## **Exercise 3.34**
The code `p1 =+ p2 - p1;` is another form for `p1 = p1 + (p2 - p1)` by order of operations we have `p2 - p1` which results in returning a `ptrdiff_t` type. If p2 points to an element just past the end of an array and p1 refers to the beginning of the array this will become illegal as 'p1' not be pointing to any element of the array, not even the element one past the end of it.



