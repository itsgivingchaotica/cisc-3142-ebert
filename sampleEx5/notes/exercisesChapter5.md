# **Exercises from Chapter 5**

## **Exercise 5.1**
> What is a null statement? When might you use a null statement?

An empty statement `;` We can use a null statement when it is required to have a statement but it is not needed for the logic of the program to check out. For example, if we want to read in values until we find the value we need in a while loop, a null statement can be used to exit the loop.

## **Exercise 5.2**
> What is a block? When might you use a block?

A compound statement surrounded by a pair of curly braces `{}` ; a scope. Used when a single statement is required but the program needs more than one. For example, in a while loop we may need to not only add a value to a sum but also incremenet the value to continue adding values to the sum until the while loop is broken.

## **Execise 5.3**
> Use the comma operator (p. 157) to rewrite the `while` loop from p. 11 so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.

```
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int sum = 0, val = 1;
    /*
    use comma operator to rewrite while loop so
    that it no longer requires a block
    */
    while (val <= 10 && (sum += val, ++val))
        ;
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;
    // diminishes readability of the code

    return 0;
}
```

## **Exercise 5.4**
> Explain each of the following examples, and correct any problems you detect.

(a) `while (string::iterator iter != s.end() { / * ... * / }` is invalid because iter does not point to anything, to fix this we may declare `string::iterator iter = s.begin(); then use the while statement accordingly `while (iter != s.end() { / * ... * / }`

(b) `while (bool status = find(word)) { / * ... * / } if (!status) { / * ... * / }` is invalid because `status` was declared only  in the while statment and can only be used within the scope of that block. To use in the if statement we would need to declare `bool status;` prior to the `while` loop and `if` statement. `bool status; while ((status = find(word))) { / * ... * / } if (!status) { / * ... * / }`

## **Exercise 5.5**
> Using an `if-else` statement, write your own version fo the program to generate the letter grade from a numeric grade

```
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int grade;
    string letterGrade;
    const vector<string> letterScores = {"F", "D", "C", "B", "A", "A++"};
    vector<int> numericScores;
    vector<string> finalScores;
    cout << "Enter the grades (Ctrl+D to complete): " << endl;
    //create vector of numeric scores
    while (cin >> grade)
    {
        numericScores.push_back(grade);
    }
    //assign the proper letter grade based on the numeric scores
    for (auto &n : numericScores)
    {
        if (n < 60)
            letterGrade = letterScores[0];
        else 
        {
            letterGrade = letterScores[(n - 50) / 10];
            if (n != 100)
            {
                if (n % 10 > 7)
                {
                    letterGrade += '+';
                } else if (n % 10 < 3) {
                    letterGrade += '-';
                }
            }
        }
        finalScores.push_back(letterGrade);
    }   
    //print the final letter grade scores
    for (auto f : finalScores)
        cout << f << " ";

    cout << endl;
    return 0;
}      

```

## **Exercise 5.6**
> Rewrite your grading program to use the conditional operator in place of the `if-else` statement

```
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int grade;
    string letterGrade;
    const vector<string> letterScores = {"F", "D", "C", "B", "A", "A++"};
    vector<int> numericScores;
    vector<string> finalScores;
    cout << "Enter the grades (Ctrl+D to complete): " << endl;
    //create vector of numeric scores
    while (cin >> grade)
    {
        numericScores.push_back(grade);
    }
    //assign the proper letter grade based on the numeric scores
    for (auto &n : numericScores)
    {
        //rewrite using conditonal operator
        letterGrade = (n < 60) ? letterScores[0] : letterScores[(n - 50) / 10];
        letterGrade += (n != 100 && n % 10 > 7) ? "+" : (n != 100 && n % 10 < 3) ? "-" : "";
        finalScores.push_back(letterGrade);
    }   
    //print the final letter grade scores
    for (auto f : finalScores)
        cout << f << " ";

    cout << endl;
    return 0;
}     
```

## **Exercise 5.7**
> Correct the errors in each of the following code fragments:

(a) 
```
if (ival1 != ival2)
    ival1 = ival2
else ival1 = ival2 = 0;
```

Rewrite:
```
if (ival1 != ival2)
    ival1 = ival2; //adding missing semicolon
else
    ival1 = ival2 = 0;
```
    
(b)
```
if (ival < minval)
    minval = ival;
    occurs = 1;
```

Rewrite: 
```
if (ival < minval)
{ //use block to add more than one line of code for if statement
    minval = ival; 
    occurs = 1;
}
```

(c) 
```
if (int ival = get_value())
    cout << "ival = " << ival << endl;
```
Need to add the following `else` to make an if-else statement
```
else if (!ival)
    cout << "ival = 0" << endl;
```

(d)
```
if (ival = 0)
    ival = get_value(); 
```

if statement uses assignment not equals, should be
```
if (ival == 0) // if ival equals 0
    ival = get_value();
```

## **Exercise 5.8**
> What is a "dangling `else`"? How are `else` clauses resolved in C++?

When there is more `if` branches than `else` branches it results in dangling `else`, we can resolve this in C++ by making sure to specify that each `else` matches with the previous unmatched `if` closest to it.

## **Exercise 5.9-12**
> Write a program using a series of `if` statements to count the number of vowels in text read from `cin`. The modify the program so that it counts both 'a' and 'A' as part of `aCnt` and so forth Modify so that it also counts the number of blank spaces, tabs, and newlines read as well as the number of occurrences of the following two-character sequences: `ff`, `fl` and `fi`

```
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::noskipws;
using std::string;

int main()
{

    unsigned aCtr = 0, eCtr = 0, iCtr = 0, oCtr = 0, uCtr = 0, spaceCtr = 0,
             tabCtr = 0, newLineCtr = 0, ffCtr = 0, flCtr = 0, fiCtr = 0;
    char ch, prev = '\0';
    cout << "Enter text: ";

    while (cin >> noskipws >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCtr;
            break;
        case 'e':
        case 'E':
            ++eCtr;
            break;
        case 'i':
            if (prev == 'f')
            {
                ++fiCtr;
            }
        case 'I':
            ++iCtr;
            break;
        case 'o':
        case 'O':
            ++oCtr;
            break;
        case 'u':
        case 'U':
            ++uCtr;
            break;
        case ' ':
            ++spaceCtr;
            break;
        case '\t':
            ++tabCtr;
            break;
        case '\n':
            ++newLineCtr;
            break;
        case 'f':
            if (prev == 'f')
            {
                ++ffCtr;
            }
            break;
        case 'l':
            if (prev == 'f')
            {
                ++flCtr;
            }
            break;
        }
        prev = ch;
    }
    cout << "A/a counted: " << aCtr << endl;
    cout << "E/e counted: " << eCtr << endl;
    cout << "I/i counted: " << iCtr << endl;
    cout << "O/o counted: " << oCtr << endl;
    cout << "U/u counted: " << uCtr << endl;
    cout << "ff counted: " << ffCtr << endl;
    cout << "fi counted: " << fiCtr << endl;
    cout << "fl counted: " << flCtr << endl;
    cout << "Tabs counted: " << tabCtr << endl;
    cout << "Spaces counted: " << spaceCtr << endl;
    cout << "New lines counted: " << newLineCtr << endl;

    return 0;
}
```


## **Exercise 5.13**
> Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.

(a)
```
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch){
    case 'a' : aCnt++;
    case 'b' : eCnt++;
    default: iouCnt++;
}
```
Missing `break;` for each `case`

```
switch (ch){
    case 'a' : aCnt++; break;
    case 'b' : eCnt++; break;
    default: iouCnt++; break;
} 
```

(b)
```
unsigned index = some_value();
switch (index){
    case 1:
        int ix = get_value();
        ivec[ix] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ix] = index;
}
```
We need to declare `int ix` before the `case`s in order to use `ix = ivec.size() -1;` under the `default` case.

(c)
```
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit){
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
}
```
`case` cannot work that way. Must be `case 1 : case 3 : case 5 : case 7 : case 9 :` etc.

(d)
```
unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt){
    case ival :
        bufsize = ival * sizeof(int);
        break;
    case jval :
        bufsize = jval * sizeof(int);
        break;
    case kval :
        bufsize = kval * sizeof(int);
        break;
}
```
We cannot use a nonconst case label. Use `const unsigned ival = 512, jval = 1024, kval = 4096;` 

## **Exercise 5.14**
> Write a program to read `string`s from the standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is `how now now now brown cow cow`, the output should indicate that the word `now` occurred three times.

```
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string prevWord, word, repeatWord;
    int cnt = 0;
    int max_repeat_cnt = 0;
    cout << "Enter text to find out max number of repeats :"; 
    while (cin >> word)
    {
        if (word == prevWord)
        {
            ++cnt;
        }
        else
        {
            prevWord = word;
            cnt = 1;
        }

        if (max_repeat_cnt < cnt)
        {
            max_repeat_cnt = cnt;
            repeatWord = prevWord;
        }
    }

    if (max_repeat_cnt <= 1)
    {
        cout << "No words were repeated" << endl;
    }
    else
    {
        cout << "the word " << repeatWord << " occurred " << max_repeat_cnt << " times" << endl;
    }
    return 0;

}
```

## **Exercise 5.15**
> Explain each of the following loops. Correct any problems you detect.

(a) 
```
for (int ix = 0; ix != sz; ++ix)
if (ix != sz) //unnecessary, was already included in the for header as a conditional
    // ...
```
This for loop starts from the  `int` value `ix = 0` (the init statement) and the conditional allows the loop to repeat until `ix` goes to the size of "something" and increments `ix` to continue the loop. Second `if` completely unnecessary

(b)
```
int ix;
for (ix != sz; ++ix)
{ / * . . . * / }
```
This would be valid if the init statement `int ix` included outside of the loop was initialized.

(c)
```
for (int ix = 0; ix != sz; ++ix; ++sz)
{ / * . . . * / }
```
This would result in an endless for loop if `sz != 0` prior to the for heading being read, if the statement did not increment `ix` or decrement `sz` within its block of code.

## **Exercise 5.16**
There are situations in which using a `while` loop makes more sense, as in when you don't know how many iterations you need. It's also great for incorporating user input, file input, and when incrementing values within the block statement is nontraditional.

```
string word;
while (cin >> word)
{
    //do something
}
//vs
for (string word; cin >> word)
{
    //do something
}
```

we can also use the variable `word` beyond the scope of the while loop to perform other tasks needed by the program

For loops are great when you know the number of times the loop should execute, and work well with arrays, vectors, etc.

```
vector<int> ivec = {0, 1, 2, 3, 4, 5}; 

for (auto it = ivec.begin(); it != ivec.end(); ++it)
{
    //do something such as print in this case
}
//vs
auto it2 = ivec.begin();
while (it2 != ivec.end())
{
    ++it2;
    //do something
}
```

## **Exercise 5.17**
> Given two `vector`s of `int`s, write a program to determine whether one `vector` is a prefix of the other. For `vector`s of unequal length, compare the number of elements of the smaller `vector`. For example, given the `vector`s containing `0, 1, 1, 2` and `0, 1, 1, 2, 3, 5, 8`, respectively your program should return true.

```
#include <iostream>
#include <vector>
#include <sstream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::getline;

void inputVector(vector<int> &v)
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    int input;
    while (ss >> input){
        v.push_back(input);
    }
}

bool isPrefix(const vector<int> &v1, const vector<int> &v2)
{
    auto it1 = v1.cbegin(), it2 = v2.cbegin();
    for (; it1 != v1.cend() && it2 != v2.cend(); ++it1, ++it2)
        if (*it1 != *it2)
            break;
        return it1 == v1.cend() || it2 == v2.cend();
}

int main()
{
    vector<int> v1, v2;
    cout << "To begin comparing two vectors to determine if one is a prefix of the other: " << endl;
    inputVector(v1);
    cout << "Enter the second vector: " << endl;
    inputVector(v2);
    cout << "The vector ";
    const vector<int> &rhs = v1.size() < v2.size () ? v1 : v2;
     const vector<int> &lhs = rhs == v1 ? v2 : v1;
    for (auto r : rhs)
    {
        cout << r << " ";
    }
    cout << " is prefix of vector ";
    for (auto l : lhs)
    {
        cout << l << ", ";
    }
    cout << " :";

    cout << (isPrefix(v1, v2) ? "true" : "false")  << endl;
    return 0;
}

```

## **Exercise 5.18**
> Explain each of the following loops. Correct any problems you detect

(a)
```
do 
    int v1, v2;
    cout << "Please enter two numbers to sum: "";
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
while (cin);
```
missing curly braces `{} beginning after `do` and before `while`

(b)
```
do {
    // . . . 
    } while (int ival = get_response());
```
illegal, Cannot define variables inside condition. declare `int ival` prior to do while loop

(c)
```
do {
    int ival = get_response();
} while (ival);
```
ival not declared and is out of scope. insert `int ival = get_response();` prior to the do while loop

## **Exercise 5.19**
> Write a program that uses a `do while` loop to repetitively request two `string`s from the user and report which `string` is less than the other.

```
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    string ans, str1, str2;

    do
    {
        cout << "Input two strings: ";
        cin >> str1 >> str2;
        if (str1 == str2)
        {
            cout << str1 << " is equal to " << str2;
        }
        cout << (str1 <= str2 ? str1 : str2) << " is smaller\n";
        cout << "Go again? (y/n): ";
        cin >> ans;
    }
    while (ans == "y");
    return 0;
}
```

## **Exercise 5.20**
> Write a program to read a sequence of `string`s from the standard input until either the same word occurs twice in succession or all the words have been read. Use a `while` loop to read the text one word at a time. Use the `break` statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.

```
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string str;
    string prev;
    cout << "Enter words to check (Ctrl+D to end): " << endl;
    bool repeat = false;
    //while user inputs words
    while (cin >> str)
    {
        //if the word was last word entered
        if (str == prev)
        {
            //repeated! end loop
            repeat = true;
            break;
        }
        else{
            //assign the current word to be compared to the next
            prev = str;
        }
    }
    //if loop breaks and finds the word was repeated print message
    if (repeat)
    {
        cout << "STOP! " << str << " was repeated in succession." << endl;
    }
    //if break never happened, print this message
    else
    {
        cout << "No word was repeated." << endl;
    }

    return 0;
}
```

## **Exercise 5.21**
> Revise the program from p. 191 so that it looks only for duplicated words that start with an uppercase letter.

```
#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string str;
    string prev;
    cout << "Enter words to check (Uppercase sensitive! Ctrl+D to end): " << endl;
    bool repeat = false;
    //while user inputs words
    while (cin >> str)
    {
        //if the word was last word entered and first char was uppercase 
        if (str == prev && isupper(prev[0]))
        {
            //repeated! end loop
            repeat = true;
            break;
        }
        else{
            //assign the current word to be compared to the next
            prev = str;
        }
    }
    //if loop breaks and finds the word was repeated with uppercase print message
    if (repeat)
    {
        cout << "STOP! " << str << " was repeated in succession." << endl;
    }
    //if break never happened, print this message
    else
    {
        cout << "No word was repeated that had Uppercase first character." << endl;
    }

    return 0;
}
```

## **Exercise 5.22**
> The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.
```
begin:
    int sz = get_size();
    if (sz <=0)
    {
        goto begin;
    }
```
Simply use a while loop
```
int sz;
while ((sz = get_size()) <= 0);
```
## **Exercise 5.23/24**
> Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second. Revise your program to throw an exception if the second number is zero. 

```
##include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

int main()
{
    int int1, int2;
    cout << "Enter two integers (bigger first): " << endl;
    cin >> int1 >> int2;
    if (int2 == 0)
    {
        throw runtime_error("Second integer cannot be 0");
    }
    double divide = int1/int2;
    cout << int1 << " divided by " << int2 << " is: " << int1/int2 << endl;
    return 0;
}
```

## **Exercise 5.25**
> Revise your program from the previous exercise to use a `try` block to `catch` the exception. The `catch` clause should print a message to the user and ask them to supply a new number and repeat the code inside the `try`

```
#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

int main()
{
    int int1, int2;
    cout << "Enter two integers (bigger first, enter between ints): ";
    while (cin >> int1 >> int2)
    {
        try
        {
            if (int2 == 0)
            {
                throw runtime_error("Second integer cannot be 0");
            }
            double divide = int1/int2;
            cout << int1 << " divided by " << int2 << " is: " << int1/int2 << endl;
        } catch (runtime_error err)
            {
            cout << err.what() << "\n" << "Try again. Enter two integers: " ;
            }
    }
    return 0;
}
```
