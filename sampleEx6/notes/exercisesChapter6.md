# **Chapter 6 Exercises**

## **Exercise 6.1**
> What is the difference between a parameter and an argument?
Arguments initialize the function's parameters. When a the function is called, the actual data passed into the parameters are the arguments. 

## **Exercise 6.2**
> Indicate which of the following functions are in error and why. Suggest how you might correct the problems

(a) 
```
int f(){
    string s;
    //...
    return s;
}
```
The return types dont match. Should return an `int`

(b) `f2(int i) { / * ... * / }` Missing type, should be `int f2(int i) { }`
(c) `int calc(int v1, int v1) { / * ... */ }``int v1` passed as same parameters. Either rename the second `v2` or get rid of it, depending on the method's parameters
(d) `double square(double x) return x * x;` Missing curly braces, should enclose `{ return x * x }`

## **Exercise 6.6**
> Explain the differences between a parameter, a local variable, and a local static variable. Give an example of a function in which each might be useful.
A parameter includes local variables declared by function, destroyed when function terminates and are defined in the scope of the function's body. 
A local variable is initialized inside the scope of the block and is destroyed for when the function is called again. 
A local static variable's lifetime continues across calls to the function. For example, keeping a record / running count of a sum
```
int running_count(int val) //val is a parameter
{
    static int sum = 0; //sum is a static variable
    return sum += val;
} 
int main()
{
    int num;
    vector<int> ivec;
    while (cin >> num)
    {
        ivec.push_back(num);
    }
    for (auto i : ivec) //i is a local variable
    {
        cout << running_count(i) << " ";
    }
    cout << endl;
    return 0;
}
```
## **Exercise 6.7**
> Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again
```
size_t count_up()
{
    static size_t ctr = 0;
    return ++ctr;
}
int main()
{
    for (size_t i = 0; i != 20; ++i)
        cout << count_up() <<endl;
    return 0;
}
```

## **Exercise 6.13**
> Assuming `T` is the name of a type, explain the difference bretween a function declared as `void f(T)` and `void f(T&)`

`void f(T)` passes arguments by *value* whereas `void f(T&)` passes arguments by *reference*

## **Exercise 6.14**
> Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

A parameter should be of reference type when we want to change the values associated with the arguments. For larger data structures it also helps performance. However, we should not use when want simply to utilize the arguments in our method and not change them in `main` and the data structure is quite small.

## **Exercise 6.15**
> Explain the rationale for the type of each of find_char’s parameters In particular, why is s a reference to const but occurs is a plain reference? Why are these parameters references, but the char parameter c is not? What would happen if we made s a plain reference? What if we made occurs a reference to const?

`s` is a reference to `const` because the function only needs to read those values, not change them. Whereas the function `find_char` needs to write to `occurs`. Because `c` is a literal and only used for a conditional statement within the body of the function, so it must be passed by value. If we made `s` a plain reference it would not be able to be read as a string literal, only a string object. If `occurs` was a reference to const there would be an error when processing `++occurs` in that it can only be read and not incremented.

## **Exercise 6.16**
> The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function. `bool is_empty(string& s) { return s.empty(); }

`s` should be a reference to a const object. If it isn't then it can only read in string objects. Use as parameter `const string &s` instead

## **Exercise 6.18**
> Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does. (a) A function named compare that returns a bool and has two parameters that are references to a class named matrix. (b) A function named change_val that returns a vector iterator and takes two parameters: One is an int and the other is an iterator for a vector.

(a)
`bool compare(const matrix &m1, const matrix &m2)`

(b)
`vector<int>::iterator change_val(int val, vector<int>::iterator &it)`

## **Exercise 6.19**
> Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why. 
```
double calc(double); 
int count(const string &, char); 
int sum(vector::iterator, vector::iterator, int); 
vector vec(10); 
```
(a) `calc(23.4, 55.1);`
Illegal. the `calc` funtion only has one parameter

(b) `count("abcda", 'a');`
Legal

(c) `calc(66);`
Legal

(d) `sum(vec.begin(), vec.end(), 3.8);`
Legal

## **Exercise 6.20**
> When should reference parameters be references to const? What happens if we make a parameter a plain reference when it could be a reference to const?

We need to be referencing const when we don't want to change the values associated with the paramters. If we make a parameter a plain reference the value could be changed and rewritten as different value/set of values due to what occurs within the body of the function. 

## **Exercise 6.21**
> Write a function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points. What type should you use for the pointer?

```
int largestInt(const int val, const int *ptr)
{
    return((val> *ptr) ? val : *ptr);
}
```
Make sure to use `const` for pointer because we aren't changing the value associated with it.

## **Exercise 6.24**
> Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.
```
void print(const int ia[10])
{
    for(size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```
This method only works when it is called with an array of 10 elements as its argument. It will not work correctly otherwise. Therefore, it would be wiser to explicitly pass a size parameter. We can do so by taking `end(int) - begin(int)` and passing this as the argument representing the function's size parameter

## **Exercises 6.25/26**
> Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting string.
```
int main(int argc, char *argv[])
{
    string str;
    for (int i = 0; i < argc; ++i)
    {
        str += argv[i];
       str += " ";
    }
    cout << str << endl;
    return 0;
}
```

## **Exercise 6.28**
> In the second version of error_msg that has an ErrCode parameter, what is the type of elem in the for loop?

`const string&` because the list is of `string` type so each element will be of type `string` as well, which must always be `const` values. 

## **Exercise 6.29**
> When you use an initializer_list in a range `for` would you ever use a reference as the loop control variable? If so, why? If not, why not?

You would use a reference as the loop control variable if you also want to modify the elements in the range using reference to a const and if it is of `string` type. It's not always necessary for types that don't use much storage to copy their values i.e. `int` `float` `double` etc.

## **Exercise 6.30**
> Compile the version of `str_subrange` as presented on page 223 to see what your compiler does with the indicated errors.

`g++: error: return-statement with no value, in function returning ‘bool’`

## **Exercise 6.31**
> When is it valid to return a reference? A reference to const?

As long as the reference is not to a local object, it may be returned as such. Furthermore, if it is not needed for the reference returned to be an lvalue, a reference to `const` as the `return` type can be made

## **Exercise 6.32**
> Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.

```
int &get(int *arry, int index)
{
    return arry[index];
}
int main()
{
    int ia[10];
    for(int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```
The function is legal. It assigns the element of the array at the index value to that of i value in the for loop.

## **Exercise 6.34**
> What would happen if the stopping condition in factorial were `if(val != 0)`

The function would process up until `val == 0` if the argument passed is positive. If the argument was negative it would result in an endless recursive loop

## **Exercise 6.35**
> In a call to `factorial`, why did we pass `val - 1` rather than `val--` ?

The compiler warns of a segmentation fault. A stack overflow occurs because `val--` would endlessly decrement without end

## **Exercise 6.36**
> Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias. 

`string (&func(string(&arr)[10]))[10]`

## **Exercise 6.37**
> Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?

Using type alias:
`using Array = string[10]; Array &func(string(&arr)[10]);`

Using `declypte`:
`string arr[10]; declypte(arr) &func(string(&arr)[10])`

Using trailing return:
`auto func(string(&arr)[10]) -> string(&) [10]`
We can see above that because the return type comes *after* the parameter list, returning a pointer pointing to an array of ten strings

## **Exercise 6.38**
> Revise the arrPtr function on to return a reference to the array.
```
auto arrPtr(int i) -> int(&)[5]
{
    return(i % 2) ? odd : even;
}
```




