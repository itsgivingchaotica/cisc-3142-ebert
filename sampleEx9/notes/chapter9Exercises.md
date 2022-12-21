# **Chapter 9 Exercises**

## **Exercise 9.1**
> Which is the most appropriate—a vector, a deque, or a list—for the following program tasks?Explain the rationale for your choice.If there is no reason to prefer one or another container, explain why not.
- (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem.
- (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
- (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

- (a) Because it is required we insert the words alphabetically into the container, if we were not to use associative container such as `set`, we would use `list`
- (b) This is a FIFO structure. Use `queue`.
- (c) `vector` works for this problem. It is not needed to insert or delete at front or back so we have no reason to use `dequeue` or `queue`. `sort` is well tailored to `vector`

## **Exercise 9.2**
> Define a `list` that holds elements that are `deque`s that hold `int`s

`list<deque<int>> ldqi`

## **Exercise 9.3**
> What are the constraints on the iterators that form iterator ranges?

The iterator range refers to an element or one past the last element in the same container. We can only use iterator operations on the following container types:
- `string`
- `vector`
- `deque` and `queue`
- `array`
- `forward_list` does not support decrement `--` operator

## **Exercise 9.4**
> Write a function that takes a pair of iterators to a `vector<int>` and an int value. Look for that value in the range and return a bool indicating whether it was found.

```
bool valuePresent(vector<int>::iterator itb, vector<int>::iterator ite, int val)
{
    for (auto it = itb; it != ite; ++it)
    {
        if (*it == val)
        {
            return true;
        }
    }
    return false;
}
```

## **Exercise 9.5**
> Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.

```
vector<int>:: iterator findValue(vector<int>::iterator itbegin, vector<int>::iterator itend, int val)
{
    for (auto it = itbegin; it != itend; ++it)
    {
        if (*it == val)
        {
            //returns value associated with it
            return it;
        }
    }
    //handles case where element is not found, returns 0
    return itend;
}
```

## **Exercise 9.6**
> What is wrong with the following program? How might you correct it?

```
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) //list iterator does not support iterator operators such as <, unlike list container itself
```

Instead use following line of code: `while (iter != iter2)`

## **Exercise 9.7**
> What type should be used as the index into a vector of ints?

`vector<int>::size_type`

## **Exercise 9.8**
> What type should be used to read elements in a list of strings? To write them?

`list<string>::iterator` or `list<string>::const_iterator` can be used to read elements in a `list` of `string`s
`list<string>::iterator` may be used to write elements

## **Exercise 9.9**
> What is the difference between the `begin` and `cbegin` functions?
`begin` is a function which returns an `iterator` pointing to the first element in the CONTAINER
`cbegin` is a function which returns a `const_iterator` pointing to the first element in the sequence

## **Exercise 9.10**
> What are the types of the following four objects?
```
vector<int> v1; //
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin(); //it1 is type vector<int>::iterator and it2 is type vector<int>::const_iterator 
auto it3 = v1.cbegin(), it4 = v2.cbegin(); //both are type vector<int>::const_iterator 
```

## **Exercise 9.11**
> Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.

```
vector<int> vec; //default = 0
vector<int> vec(5); //5 elements initialized to zero
vector<int> vec(5,8); //5 elements initialized to 8
vector<int> vec = {2, 9, 44, 8, 0} //5 elements initialized to 2, 9, 44, 8, 0
vector<int> vec1(vec2); //copy of elements of vec2 into vec1
vector<int> vec1(vec2.begin(), vec2.end()) //copy of elements of vec2 into vec1
```

## **Exercise 9.12**
> Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

Whereas the constructor that takes a container to copy cannot be of a different container / element type, the constructor that takes two iterators may copy those elements into a container comprising of the same or different type. For example, for: `list<int> nums = {1, 2, 3, 4, 5}`, the following are invalid:  `vector<int> nums_(nums);` and `list<double> nums_(nums);` However the following are valid: `list<double> nums_(nums.begin(), nums.end());` and `vector<int> nums_(nums.begin(), nums.end());` and we can also copy less elements into the container if need be: `list<double> nums_(++nums.begin(), --nums.end());`

## **Exercise 9.13**
> How would you initialize a `vector<double>` from a `list<int>`? From a `vector<int>`? Write code to check your answers.

```
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    list<int> nums = {1, 2, 3, 4, 5};
    vector<int> ivec = {6, 7, 8, 9, 10};
    cout << "Integer list: ";
    for (const auto &n : nums)
    {
        cout << n;
    }
    cout << endl;

    cout << "Integer vector: ";
    for (const auto &i : ivec)
    {
        cout << i;
    }
    cout << endl;

    vector<double> dvec(nums.begin(), nums.end());
    cout << "Double vector from Integer List: ";
    for (const auto &d : dvec)
    {
        cout << d;
    }
    cout << endl;

    vector<double> dvec2(ivec.begin(), ivec.end());
    cout << "Double vector from Integer vector: ";
    for (const auto &d2 : dvec2)
    {
        cout << d2;
    }
    cout << endl;

    return 0;
}
```

## **Exercise 9.14**
> Write a program to assign the elements from a `list` of `char*` pointers to C-style character `string`s. 

We need to use `const char*` for C-style `string`, hence we have the following program to showcase this:

```
#include <iostream>
#include <list>
#include <vector>

using std::string;
using std::vector;
using std::list;
using std::cout;
using std::endl;

int main(){
    list<string> sl = {"Every", "dog", "has", "his", "day"};
    cout << "List of char* pointers: ";
    for (const auto &s : sl)
    {
        cout << s << " ";
    }
    cout << endl;
    vector<const char*> csl = {"Just", "kidding"};
    sl.assign(csl.cbegin(), csl.cend());
    cout << "Assign list of char* pointers to vector of strings: ";
    for (const auto &c : csl)
    {
        cout << c << " ";
    }
    return 0;
}
```

## **Exercise 9.15**
> Write a program to determine whether two `vector<int>`s are equal.

```
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {1, 3, 5, 7, 9};
    vector<int> v3 = {1, 3, 5, 7, 9, 11};
    cout << "Vector 1: ";
    for (const auto &a : v1)
    {
        cout << a << " ";
    }
    cout << endl;
    cout << "Vector 2: ";
    for (const auto &b : v2)
    {
        cout << b << " ";
    }
    cout << endl;
    cout << "Vector 3: ";
    for (const auto &c : v3)
    {
        cout << c << " ";
    }
    cout << endl;

    if (v1 == v2)
    {
        cout << "Vectors 1 and 2 are equal" << endl;
    }
    else{
        cout << "Vectors 1 and 2 are not equal" << endl;
    }

    if (v1 == v3)
    {
        cout << "Vectors 1 and 3 are equal" << endl;
    }
    else{
        cout << "Vectors 1 and 3 are not equal" << endl;
    }
    return 0;
}
```

## **Exercise 9.16**
> Repeat the previous program, but compare elements in a `list<int>` to a `vector<int>`.

```
#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::cout;
using std::endl;
using std::list;

int main() {
    list<int> list = {1, 3, 5, 7, 9};
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {1, 3, 5, 7, 9, 11};
    cout << "Integer List: ";
    for (const auto &l : list)
    {
        cout << l << " ";
    }
    cout << endl;
    cout << "Vector 1: ";
    for (const auto &a : v1)
    {
        cout << a << " ";
    }
    cout << endl;
    cout << "Vector 2: ";
    for (const auto &b : v2)
    {
        cout << b << " ";
    }
    cout << endl;

    if (vector<int>(list.begin(),list.end()) == v1)
    {
        cout << "List and Vector 1 are equal" << endl;
    }
    else{
        cout << "List  and Vector 1 are not equal" << endl;
    }

    if (vector<int>(list.begin(),list.end()) == v2)
    {
        cout << "List and Vector 2 are equal" << endl;
    }
    else{
        cout << "List and Vector 2 are not equal" << endl;
    }
    return 0;
}
```

## **Exercise 9.17**
> Assuming `c1` and `c2` are containers, what (if any) constraints does the following usage place on the types of c1 and c2? : `if (c1 < c2)`

`c1` and `c2` must be of the same type container in this case, which is able to handle relational operators. They must be of the same `value_type` as well. Unordered associative containers will make an error in this case, i.e. `unordered_set` , `unordered_multiset`, `unordered_map`, and `unordered_multimap`.

## **Exercise 9.18**
> Write a program to read a sequence of `string`s from the standard input into a `deque`. Use iterators to write a loop to print the elements in the deque. 

```
#include <iostream>
#include <deque>
#include <vector>

using std::string;
using std::deque;
using std::cin;
using std::cout;

int main() 
{
    deque<string> dq;
    string word;
    //Ctrl+D to exit
    while (cin >> word)
    {
        dq.push_back(word);
    }
    for (auto it = dq.cbegin(); it != dq.cend(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}
```

## **Exercise 9.19**
> Rewrite the program from the previous exercise to use a  `list`. List the changes you needed to make

```
#include <iostream>
#include <list> //insead of <deque>

using std::string;
using std::cin;
using std::cout;
using std::list; //instead of std::deque

int main() 
{
    //just use list instead of deque
    list<string> list;
    string word;
    //Ctrl+D to exit
    while (cin >> word)
    {
        list.push_back(word);
    }
    for (auto it = list.cbegin(); it != list.cend(); ++it)
    {
        cout << *it << " ";
    }
    return 0;
}
```

## **Exercise 9.20**
> Write a program to copy elements from a  `list<int>` into two `deque`s. The even-valued elements should go into one `deque` and the odds one into the other

```
#include <iostream>
#include <list>
#include <deque>

using std::list;
using std::deque;
using std::cout;
using std::endl;

int main() 
{
    list<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> odd;
    deque<int> even;

    for (auto it = list.cbegin(); it != list.cend(); ++it)
    {
        if (*it % 2 == 0)
            even.push_back(*it);
        else
            odd.push_back(*it);
    }
    cout << "Even integers: ";
    for (auto it = even.cbegin(); it != even.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\nOdd integers: ";
    for (auto it = odd.cbegin(); it != odd.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
```

## **Exercise 9.21**
> Explain how the loop from page 345 that used the return from `insert` to add elements to a list would work if we inserted into a vector instead.

These two would work exactly the same, which is the point using `insert` is that for `vector` is performing the same as `push_front` does for `list` (as well as `insert`) using an `iterator` as the element to `insert` the new elements.

## **Exercise 9.22**
> Assuming `iv` is a `vector` of `int`s, what is wrong with the following program? How might you correct the problem(s)?

```
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid) //iter will never == mid. We don't have an increment
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val); //mid will not longer be true mid
```

To fix the code I did the following:

```
int midway = iv.size()/2
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + midway
while (iter!= mid)
    if(*iter == some_val){
        iv.insert(iter, 2*some_val)
        ++iter;
        ++midway;
        mid = iv.begin() + midway;
        continue;
    }
    ++iter;
}
```

## **Exercise 9.23**
> In the first program in this section on page 346, what would the values of val, val2, val3, and val4 be if c.size() is 1?

They would all be the values of the one element in `c`. 

```
if (!c.empty()) {
    auto val = *c.begin(), val2 = c.front();
    auto last = c.end();
    auto val3 = *(--last); //because last refers to one past the last element
    auto val4 = c.back();
}
```

"begin() returns an iterator that can be used to iterate through the collection, while front() just returns a reference to the first element of the collection." [The difference between front() and begin()] (https://stackoverflow.com/questions/9303110/the-difference-between-front-and-begin)

## **Exercise 9.24**
> Write a program that fetches the first element in a  `vector` using `at`, the subscript operator,`front` and `begin`. Test your program on an empty vector.

```
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() 
{
    vector<int> ivec = {1, 2, 3};
    cout << "ivec.at(0): " << ivec.at(0) << "\nivec[0]: " << ivec[0] 
    << "\n*ivec.begin(): " << *ivec.begin() << "\nivec.front(): " << ivec.front() << endl;
    vector<int> ivec2;
    
    //these next ones would all fail
    //cout << "ivec2.at(0): " << ivec2.at(0); //terminating with uncaught exception of type std::out_of_range: vector
    //cout << "\nivec2[0]: " << ivec2[0];//segmentation fault
    //cout << "\n*ivec2.begin(): " << *ivec2.begin(); //segmentation fault
    //cout << "\nivec2.front()" << ivec2.front(); //segmentation fault
    cout << endl;

    return 0;
}
```
## **Exercise 9.25**
> In the program on page 349 that erased a range of elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?

`elem1 = slist.erase(elem1,elem2);` 

If `elem1` and `elem2` are equal, nothing is erased. If `elem2` is off-the-end everything from the list to the end would be erased. If they are both off-the-end iterators, nothing would be erased.

## **Exercise 9.26**
> Using the following definition of `ia`, copy `ia` into a `vector` and into a `list`. Use the single-iterator form of `erase` to remove the elements with odd values from your `list` and the even values from your `vector`

```
#include <iostream>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() 
{
    int ia[] = {0, 1, 1 ,2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec(begin(ia), end(ia));
    list<int> lst(ivec.begin(), ivec.end());
    //delee all odd integers from list
    while (it != lst.end())
    {
        if (*it % 2 == 0)
            ++it;
        else
            it = lst.erase(it);
    }
    auto it2 = ivec.begin();
    //erase even integers from vector
    while (it2 != ivec.end())
    {
        if (*it2 % 2 == 0)
            it2 = ivec.erase(it2);
        else
            ++it2;
    }
    for (auto i : ivec)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto l : lst)
    {
        cout << l << " ";
    }
    cout << endl;
    return 0;
}
```

## **Exercise 9.27**
> Write a program to find and remove the odd-valued elements in a `forward_list<int>`.

```
#include <iostream>
#include <forward_list>

using std::forward_list;
using std::cout;
using std::endl;

int main(){
forward_list<int> flst = {1, 2, 3, 4, 5, 6, 7, 8, 9};
auto prev = flst.before_begin();
auto curr = flst.begin();
while (curr != flst.end())
{
    if (*curr % 2 == 0){
        prev = curr;
        ++curr;
    } else 
        curr = flst.erase_after(prev);
}
for (auto it = flst.cbegin(); it != flst.cend(); ++it)
{
    cout << *it << " ";
}
cout << endl;

return 0;
}
```

## **Exercise 9.28**
> Write a function that takes a `forward_list<string>` and two additional `string` arguments. The function should find the first `string` and insert the second immediately following the first. If the first `string` is not found, then insert the second `string` at the end of the list.

```
#include <iostream>
#include <forward_list>

using std::forward_list;
using std::cout;
using std::endl;
using std::string;

void insertAfter(forward_list<string> &flst, const string &first, const string &second)
{
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    //flst.end() hangs off
    while (curr != flst.end()) 
    {
        if (*curr == first)
        {
            cout << "inserting";
            flst.insert_after(curr,second);
            return;
        } else {
            prev = curr;
            ++curr;
        }
    }
    //if first not found, insert after the last element
    flst.insert_after(prev,second);
    return;
}

int main()
{
    forward_list<string> flst = {"here", "we", "go","again"};
    for (auto it = flst.cbegin(); it != flst.cend(); ++it)
    {
        cout << *it << " ";
    }
    insertAfter(flst,"we","A");
    for (auto it2 = flst.cbegin(); it2 != flst.cend(); ++it2)
    {
        cout << *it2 << " ";
    }
    insertAfter(flst,"never","B");
    for (auto it3 = flst.cbegin(); it3 != flst.cend(); ++it3)
    {
        cout << *it3 << " ";
    }
    cout << endl;
    return 0;
}
```

## **Exercise 9.29**
> Given that `vec` holds 25 elements, what does `vec.resize(100)` do? What is we next wrote `vec.resize(10)`?

`vec.resize(100)` would add 75 elements value initialized to the back of the list. `vec.resize(10)` would then erase 90 elements from the back of the list. The first 10 elements would remain.

## **Exercise 9.30**
> What, if any, restrictions does using the version of `resize` that takes a single argument place on the element type?

from the book: "If the container holds elements of a class type and `resize` adds elements, we must supply an initializer or the element type must have a default constructor"

## **Exercise 9.31**
> The program on page 354 to remove even-valued elements and duplicate odd ones will not work on a `list` or `forward_list`. Why? Revise the program so that it works on these types as well.

Both `list` and `forward_list` do not allow iterator operations so we must advance the iterators in a different way. Instead of `iter += 2;` must use `++iter; ++iter;` or `advance(iter,2)`. In addition, for `forward_list` we can only use `erase_after()` and `insert_after()` so it would be necessary to initialize an iterator `prev = flst.before_begin()` and include `advance(prev,2)` to follow the `iter`. 

```
#include <iostream>
#include <list>
#include <forward_list>

using std::list;
using std::forward_list;
using std::cout;
using std::endl;
using std::advance;

int main()
{
    list<int> ilst = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    forward_list<int> flst(ilst.begin(), ilst.end());
    auto iter = ilst.begin();
    auto iter2 = flst.begin();
    auto prev = flst.before_begin();
    while (iter != ilst.end())
    {
        if (*iter % 2){
            iter = ilst.insert(iter, *iter);
            //iter += 2; //list doesn't support iterator arithmetic
            ++iter; //or advance(iter,2);
            ++iter;
        } else {
            iter = ilst.erase(iter);
        }
    }
    while (iter2 != flst.end())
    {
        if (*iter2 %2){
            iter2 = flst.insert_after(prev, *iter2);
            //advance both the current iterator and the previous
            advance(iter2,2);
            advance(prev,2);
        }
        else {
            //use erase_after(previous iterator)
            iter2 = flst.erase_after(prev);
        }
    }
    for (auto it = ilst.cbegin(); it !=ilst.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it2 = flst.cbegin(); it2 != flst.cend(); ++it2)
    {
        cout << *it2 << " ";
    }
    cout << endl;
    return 0;
}
```

## **Exercise 9.32**
> In the program on page 354 would it be legal to write the call to `insert` as follows? If not, why not? `iter = vi.insert(iter, *iter++)`

The statement is illegal as the order of evaluation of arguments is unspecified. `iter` can be the incremented value specified `*iter++` or something else. 

## **Exercise 9.33**
> In the final example in this section what would happen if we did not assign the result of `insert` to `begin`? Write a program that omits this assignment to see if your expectation was correct.

As seen in this example, the program would crash because the iterator is invalid after `insert()`. `iterator`s, pointers, and references to a `vector` or `string` are invalid if the container was reallocated:

```
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = v.begin();
    while (begin != v.end()) {
        ++begin;
        //segmentation fault
        /*begin = */ v.insert(begin, 42);
        ++begin;
    }

    for (auto i : v) cout << i << " ";

    return 0;
}
```

## **Exercise 9.34**
> Assuming vi is a container of ints that includes even and odd values, predict the behavior of the following loop. After you've analyzed this loop, write a program to test whether your expectations were correct.
```
iter = vi.begin();
    while (iter != vi.end()){
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        ++iter;
    }
```

First of all, the while loop body should be a block. After this, once an odd value is inserted, it will keep inserting because iter will always be odd. It would only work on containers only having even values. The line of code printing the contents of the container to the console will never be compiled because the program never exits the first while loop.
    
```
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vi{2, 3, 4};
    //vector<int> vi = {2, 4};

    auto iter = vi.begin();
    while (iter != vi.end())
    {  
        if (*iter % 2){
            iter = vi.insert(iter, *iter);
            cout << "infinite" << " ";
        }
        ++iter;
    }
  
    //the following will never compile because 
    //the program is stuck in an inifinite loop
    for (auto it = vi.cbegin(); it != vi.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

  return 0;
}
```

## **Exercise 9.35**
> Explain the difference between a `vector`'s `capacity` and `size`

"The `size` of a container such as a `vector` is the number of elements it already holds; its `capacity` is how many elements it can hold before more space must be allocated"

## **Exercise 9.36**
> Can a container have a `capacity` less than its `size`?

No, a container must have `capacity` at least equalling its `size`

## **Exercise 9.37**
> Why don't `list` or `array` have a `capacity` member?
An `array` is fixed in `size` so there is no `capacity` member. A `list` does not support random access and does not store its elements contiguously and is stored separately in memory.

## **Exercise 9.38**
> Write a program to explore how `vector`s grow in the library you use.

```
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::cerr;

int main()
{
    ifstream file("film.csv.txt");
    //nested vector of months / temperatures
    vector<vector<string>> temperatures;
    string line;

    vector<string> fields;
    if (file.is_open())
    {
        getline(file,line);
        while (getline(file,line)){
                fields.push_back(line);
                cout << fields.capacity() << " ";
        }
    } else {
        cerr << "Could not read file" << endl;
    }

    return 0;

    /**
     * The vector's capacity doubles like so:
     * 1 2 4 8 16 32 64 128 256 512 1024 2048 
    */

}
```

## **Exercise 9.39**
> Explain what the following program fragment does:
```
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size() + svec.size()/2)
```

Each time a new string is inserted into the vector, the vector is resized with an additional 1/2 of the new `size` of `svec`, with elements initialized to default filling `svec`. Therefore, `svec`'s would not change `capacity` until `size` > 1048.

## **Exercise 9.40**
> If the program in the previous exercise reads 256 words, what is its likely `capacity` after it is `resized`? What if it reads 512? 1,000? 1,048?

For reading in 256, 512, and 1,000, the `capacity` remains 1024. If 1048 words are read in, the `capacity` would be *at least* 1048 but most likely 2048.

## **Exercise 9.41**
> Write a program that initializes a `string` from a `vector<char>`

```
#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<char> cvec = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    string phrase(cvec.begin(),cvec.end());

    for (auto it = phrase.begin(); it != phrase.end(); ++it)
    {
        cout << *it; 
    }
    return 0;
}
```

## **Exercise 9.42**
> Given that you want to read a character at a time into a `string`, and you know that you need to read at least 100 characters, how might you improve the performance of your program?

Add `phrase.reserve(100);` to optimize performance so that reallocation doesn't occur during the reading of `const *char`s into the string.

## **Exercise 9.43**
> Write a function that takes three `string`s: `s`, `oldVal`, and `newVal`. Using iterators, and the `insert` and `erase` functions replace all instances of `oldVal` that appear in s by newVal. Test your function by using it to replace common abbreviations, such as "tho" by "though" and "thru" by "through".

```
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::string;

void replace(string &s, const string& oldVal, const string& newVal)
{ 
    for (auto iter = s.begin(); iter < s.end() - oldVal.size() + 1; ++iter) 
    {
        auto iter2 = oldVal.cbegin();
        for (auto iter3 = iter; iter2 != oldVal.cend(); ++iter2, ++iter3){
            if (*iter3 != *iter2)
            break;
        }
        if (iter2 == oldVal.cend()) 
        {
            string::size_type pos = iter - s.begin();
            s.erase(pos, oldVal.size());
            s.insert(pos, newVal);
            // Recalculate `it` from `begin()` rather than use `+=` operator, because
            // `it` is invalid by `erase()` and `insert()`
            iter = s.begin() + pos + newVal.size();
        } 
    }
}

int main() 
{   
    string str = "Even tho I tried my best, it felt like there was no way thru the semester";
    replace(str, "tho", "though");
    replace(str, "thru", "through");
    cout << str << endl;

    return 0;    
}
```

## **Exercise 9.44**
> Rewrite the previous function using an `index` and `replace`

```
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void replace(string &s, const string &oldVal, const string &newVal)
{
    //for each element in the string
    for (string::size_type index = 0; index != s.size(); ++index)
    {
        //if the word matches the old value
        if (s.substr(index, oldVal.size()) == oldVal)
        {
            //replace the old value with the new value
            s.replace(index, oldVal.size(), newVal);
            /**
             * increment the index past the word inserted
            * we continue through the string until all 
            * of the oldVals are replaced by the newVals
            */
            index += newVal.size() -1;
        }
    }
}

int main() 
{   
    string str = "Even tho I tried my best, it felt like there was no way thru the semester";
    replace(str, "tho", "though");
    replace(str, "thru", "through");
    cout << str << endl;

    return 0;
}
```

## **Exercise 9.45**
> Write a function that takes a `string` representing a name and two other `string`s representing a prefix, such as "Mr." or "Ms." and a suffix, such as "Jr." or "III". Using the iterators and the `insert` and `append` functions, generate and return a new `string` with the suffix and prefix added to the given name.

```
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

string prefixSuffix(const string& name, const string& prefix, const string& suffix)
{
    auto iter = name;
    iter.insert(iter.begin(),prefix.begin(),prefix.end());
    iter.append(suffix);

    return iter;
}

int main()
{
    string name, prefix, suffix;

    while (cin)
    {
        getline(cin,name);
        getline(cin,prefix);
        getline(cin,suffix);
        cout << prefixSuffix(name,prefix,suffix) << endl;
    }
    return 0;
}
```

## **Exercise 9.46**
> Rewrite the previous exercise using a position and length to manage the strings. This time use only the insert function

```
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

string prefixSuffix(const string& name, const string& prefix, const string& suffix)
{
    string title(name);
    //0 as index
    title.insert(0, prefix);
    title.insert(title.length(), suffix);
    return title;
}

int main()
{
    string name, prefix, suffix;

    while (cin)
    {
        getline(cin,name);
        getline(cin,prefix);
        getline(cin,suffix);
        cout << prefixSuffix(name,prefix,suffix) << endl;
    }
    return 0;
}
```

## **Exercise 9.47**
> Write a program that finds each numeric character and then each alphabetic character in the `string` "ab2c3d7R4E6". Write two versions of the program. The first should use `find_first_of` and the second `find_first_not_of`

```
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string nums{"0123456789"};
    string alphas{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string str{"ab2c3d7R4E6"};
    string::size_type pos = 0;

    cout << str << endl;

    cout << "Listing the numeric characters: ";
    while ((pos = str.find_first_of(nums, pos)) != string::npos){
        cout << str[pos] << " ";
        ++pos;
    }
    cout << endl;
    cout << "Listing the alphabetical characters: ";
    pos = 0;
    while ((pos = str.find_first_of(alphas, pos)) != string::npos){
        cout << str[pos] << " ";
        ++pos;
    }
    cout << endl;

    return 0;
}
```

## **Exercise 9.48**
> Given the definitions of `name` and `numbers` on page 365, what does `numbers.find(name)` return?
`string numbers("0123456789"), name("rd2d");`

`numbers.find(name)` wold return `string::npos` as the `string` `r2d2` does not occur anywhere in `numbers`

## **Exercise 9.49**
> A letter has an ascender if, as with `d` or `f` part of the letter extends above the middle of the line. A letter has a descender if, as with `p` or `g`, part of the letter extends below the line. Write a program that reads a file containing words and reports the longest word that containers neither ascenders nor descenders.

```
#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int main() 
{
    string nonscenders("aceimnorsuvwxz.");

    ifstream in("words.txt");

    if (in.is_open())
    {
        string longest_word, word;
        while (in >> word){
            if (word.find_first_not_of(nonscenders) == string::npos && word.size() > longest_word.size())
                longest_word = word;
        }
        cout << "The longest word without ascenders or descenders in the file is: " << longest_word << endl;
    }

    return 0;
}
```

## **Exercise 9.50**
> Write a program to process a `vector<string>` whose elements represent integral values. Produce the sum of all the elements in that `vector`. Change the program so that it sums of `string`s that represent floating point values.

```
#include <iostream>
#include <vector>

using std::vector;
using std::stoi;
using std::string;
using std::cout;
using std::endl;

int intSum(vector<string> svec)
{
    int sum;
    for (auto it = svec.begin(); it !=svec.end(); ++it)
    {
        sum+=stoi(*it);
    }
    return sum;
}

float floatSum(vector<string> svec)
{
    float sum;
    for (auto it = svec.begin(); it !=svec.end(); ++it)
    {
        sum+=stof(*it);
    }
    return sum;
}

int main()
{
    vector<string> svec = {"1", "2", "3.5", "4", "5.8"};
    int isum;
    float fsum;
    isum = intSum(svec);
    fsum = floatSum(svec);
    cout << "Sum of all vector string elements" << endl;
    cout << "To Integer: " << isum
    << "\nTo Floating Point: " << fsum << endl;
    return 0;
}
```

## **Exercise 9.51**
> Write a class that has three `unsigned` members representing year, month, and day. Write a constructor that takes a `string` representing a date. Your constructor should handle a variety of date formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900 and so on

```
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::stoi;
using std::isdigit;
using std::cerr;
using std::endl;
using std::cout;

class Date {
public:
    explicit Date(const string& str = "");
    unsigned year = 2000;
    unsigned month = 11;
    unsigned day = 16;
    void Print();

private:
    vector<string> months{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    unsigned findMonth(const std::string& str);
};

Date::Date(const std::string& str)
{
    if (str.empty()) return;
    string delimiters{" ,/"};
    auto first_delim = str.find_first_of(delimiters);
    if (first_delim == string::npos)
        cerr << "wrong format" << endl;
    month = findMonth(str.substr(0, first_delim));
    auto second_delim = str.find_first_of(delimiters, first_delim + 1);
    auto day_len = second_delim - first_delim - 1;
    day = stoi(str.substr(first_delim + 1, day_len));
    year = stoi(str.substr(second_delim + 1));
}

void Date::Print()
{
    cout << month << "-" << day << "-" << year << "\n";
}

unsigned Date::findMonth(const string& s)
{
    if (s.empty()) 
        return 0;
    if (isdigit(s[0])) 
        return stoi(s);
    for (size_t i = 0; i != 12; ++i) {
        if (s.find(months[i]) != string::npos) return i + 1;
    }
    return 0; //  not found
}

int main()
{
    vector<string> svec = {"January 1, 2001", "1/1/2001", "Jan 1, 2001"};
    Date date;
    date.Print();
    for (auto it = svec.begin(); it != svec.end(); ++it)
    {
        auto date = Date(*it);
        date.Print();
    }
    return 0;
}
```

## **Exercise 9.52**
> Use a stack to process parenthesized expressions. When you see an open parenthesis, note that it was seen. When you see a close parenthesis after an open parenthesis, pop elements down to and including the open parenthesis off thestack. push a value onto the stack to indicate that a parenthesized. expression was replaced.

```
#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::cout;
using std::endl;
using std::stack;

int main()
{
    string input = "(Paranthesis) and ((Parantheses))";
    char replacement = '~';
    size_t seen = 0;
    stack<char> cstack;

    for (auto i : input) {
        cstack.push(i);
        if (i == '(') ++seen;   // open
        if (seen && i == ')') { // pop elements down to the stack
            while (cstack.top() != '(') 
            {
                cstack.pop();
            }
            cstack.pop();      // including the open parenthesis
            cstack.push(replacement); // push a value indicate it was replaced
            --seen;         // close
        }
    }
    string output;
    while (!cstack.empty())
    {
        output.insert(output.begin(),cstack.top());
        cstack.pop();
    }
    cout << output << endl; // "This is # and # over"
    return 0;
}
```

























