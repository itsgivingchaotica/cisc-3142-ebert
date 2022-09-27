# **Exercises from Chapter 3**

## **Exercise 3.3**
In the 'string' input operator (cin), whitespace characters are not allowed as the '>>' operator skips leading whitespace characters. However, 'getline' function reads in the entire line including all whitespaces until user hits return

## **Exercise 3.7**
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
As we can see from comparing the three approaches that range for is the most elegant way to iteratitevely change the string to all X's. The while loop adds an extra line of code to account for `++i`

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
This program is not valid 
```
//string is initialized to the empty string
string s;
cout << s[0] <<endl;
```
In this case `s[0]` is undefined as `s` is initialized to the empty string therefore there is no value at index 0.

## **Exercise 3.11**
The following is legal :
```
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```
c is of the type const char&. This is only legal until it is attempted to change the value of c. 

## **Exercise 3.12**
(a) `vector<vector<int>> ivec;` is legal. ivec is an empty vector whose elements are int vectors
(b) `vector<string> svec = ivec;` is not legal. ivec holds `ints`s not `string`s
(c) `vector<string> svec(10, "null");` is legal. svec has ten with value "null"

## **Exercise 3.13**
(a) `vector<int> v1;` v1 holds objects of of type int and is initially empty
(b) `vector<int> v2(10);` v2 can hold 10 elements of int type and is initialized to 0
(c) `vector<int> v3(10, 42);` v3 has ten int elements of value 42
(d) `vector<int> v4{10};` v4 has one int element of value 10
(e) `vector<int> v5{10, 42};` v5 has two int elements of the values 10 and 42
(f) `vector<string> v6{10}; v6 has 10 elements of which are all empty strings
(g) `vector<string> v7{10, "hi"};` has ten string elements and they are all "hi"

## **Exercise 3.18**
The following is not legal:
```
vector<int> ivec;
ivec[0] = 42;
```
`ivec` cannot be subscripted as it is an empty vector. instead we can use `ivec.push_back(42);`

## **Exercise3.19**
1. `vector<int> v1(10, 42);`
2. `vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
3. ```
    vector<int> v3(10);
    for (auto &i: ivec)
    {
        i = 42;
    }
    ```
Option 1 is the simplest way to add multiple identical elements to a vector in this way



