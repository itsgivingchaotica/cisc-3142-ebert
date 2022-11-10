# ***Chapter 8 Exercises***

## **Exercise 8.1**
> Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.

```
using std::istream;
using std::cout;
using std::endl;
using std::string;

istream& print(istream &is)
{
    int in;
    while (is >> in)
        cout << in << endl;
    is.clear(); //makes valid 
    return is;
}
```

## **Exercise 8.2**
> Test your function by calling it, passing cin as an argument.

```
#include <iostream>
#include <string>

using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;

istream& printIO(istream &is)
{
    int in;
    while (is >> in)
        cout << "print: " << in << endl; //will print if the value is an integer, if not will fail
    is.clear(); //makes valid 
    return is;
}

int main()
{
   istream& is = printIO(cin);
    if (!is.rdstate())
        cout << "Input error, is.rdstate() is " << is.rdstate() << endl; //0 for fail
    return 0;
}

/** 
 * 12898
print: 12898
100
print: 100
Hello
Input error, is.rdstate() is 0
*/
```

## **Exercise 8.3**
> What causes the following while to terminate? `while (cin >> i) /*  ...    */`

if `cin` is in error then the `while` loop will terminate. `badbit` indicates that a stream is corrupted. `failbit` indicates that an IO operation failed. `eofbit` indicates that a stream hit end-of-file.



