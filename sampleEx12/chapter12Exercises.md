# **Chapter 12: Dynamic Memory Exercises**

## **Exercise 12.1**

> How many elements do `b1` and `b2` have at the end of this code?

`b1` has 4 elements as it shares the same elements with `b2`. Then once an element is pushed back into `b2` they both have 4 elements. Once leaving the scope in which `b2` was declared initialized, `b2` is destroyed but the elements associated with it are not. Hence, `b1` retains 4 elements at the end of the code.

## **Exercise 12.2**

> Write your own version of the `StrBlob` including `const` versions of `front` and `back`.

```
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

using std::cout;
using std::endl;
using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::shared_ptr;
using std::string;
using std::vector;

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }
    // add and remove elements
    void push_back(const string &t)
    {
        data->push_back(t);
    }
    void pop_back();
    string &front() const;
    string &back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
// default constructor allocates an empty vector
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
// constructor passes its parameter to the corresponding vector constructor, which initializes the vector's elements by copying the values in the list
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
```

## **Exercise 12.3**

> Does this class need `const` versions of `push_back` and `pop_back`?

It seems the only reason you would need the `const` version of both functions would be when you would want to change the size and contents of the object `StrBlob` when it is `const`. However, this would be illogical as defining `StrBlob` as `const` would be to keep our program from changing the value held. So there isn't a point in adding `const` to either.

## **Exercise 12.4**

> In our `check` function we didn't check whether `i` was greater than zero. Why is it okay to omit that check?

`i` was defined being of `size_type` which can never be less than 0 as it is unsigned.

## **Exercise 12.5**

> We did not make the constructor that takes an `initializer_list` `explicit`. Discuss the pros and cons of this design choice.
> Pros: a `StrBlob` object can be initialized to default,

Received this error using `explicit` with the sample program:

```
error: chosen constructor is explicit in copy-initialization
StrBlob b2 = {"a", "an", "the"};
```

Because we didn't use `explicit` we are able to use copy-intialization as well as direct initialization. Using `explicit` would limit to direct initialization only. We could not initialize a `StrBlob` object `b3` like so: `b3 = b2`. However we sacrifice unwanted implicit type conversions.

## **Exercise 12.6**

> Write a function that returns a dynamically allocated vector of ints. Pass that vector to another function that reads the standard input to give values to the elements. Pass the vector to another function to print the values that were read. Remember to delete the vector at the appropriate time.

```
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> *create();
void process(vector<int> *pv);
void print(vector<int> *pv);

int main()
{
    vector<int> *pv = create();
    process(pv);
    print(pv);
}

vector<int> *create()
{
    vector<int> *pv = new vector<int>();
    return pv;
}

void process(vector<int> *pv)
{
    int i;
    cout << "Enter values:\n";
    while (cin >> i)
        pv->push_back(i);
}

void print(vector<int> *pv)
{
    for (const auto &p : *pv)
    {
        cout << p << " ";
    }
    cout << endl;
}
```

## **Exercise 12.7**

> Redo the previous exercise, this time using `shared_ptr`

```
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::vector;

shared_ptr<vector<int>> createShared();
void process(shared_ptr<vector<int>> spv);
void print(shared_ptr<vector<int>> spv);

int main()
{
    auto spv = createShared();
    process(spv);
    print(spv);
}

shared_ptr<vector<int>> createShared()
{
    return make_shared<vector<int>>();
}

void process(shared_ptr<vector<int>> spv)
{
    int i;
    cout << "Enter values:\n";
    while (cin >> i)
        spv->push_back(i);
}

void print(shared_ptr<vector<int>> spv)
{
    for (const auto &p : *spv)
    {
        cout << p << " ";
    }
    cout << endl;
}
```

## **Exercise 12.8**

> Explain what if anything is wrong with the following function.

```
bool b(){ //return type should be bool
    int* p = new int;
    // ...
    return p; //memory leakage because function is not (int *)
}
```

## **Exercise 12.9**

> Explain what happens in the following code:

```
//object to which q points has value of 42
int *q = new int(42);
//object to white r points has value of 100
int *r = new int(100);
//r now points to the same memory as q, but the memory which r originally pointed is leaked. It was not freed and no pointer points to it
r = q;
//make two shared pointers to different objects in memory
auto q2 = make_shared<int>(42);
auto r2 = make_shared<int>(100);
//r2 reference count decreases, the memory is freed as no other shared_ptr points to it. r2 and q2 now point to the same memory, the reference count of both pointers increases to 2.
r2 = q2
```

## **Exercise 12.10**

> Explain whether the following call to the `process` function defined on page 464 is correct. If not, how would you correct the call?

```
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

The parameter to `process` is passed by value, so the argument to `process` is copied in. Copying the `shared_ptr` means that the reference count would be incremeneted. At the end of the function, `ptr` goes out of scope and is destroyed. However, the memory is not deleted as the counter cannot go down to 0. So after process the reference count for p stays at 1

## **Exercise 12.11**

> What would happen if we called `process` as follows? `process (shared_ptr<int>(p.get()));`

After `process` executes the memory is freed which `ptr` was pointing. It will thus free memory of `p`. Any use of `p` afterward will be undefined

## **Exercise 12.12**

> Using the declarations of `p` and `sp` explain each of the following calls to `process`. If the call is legal, explain what it does. If the call is illega, explain why:

```
void process(shared_ptr<int> ptr) { / ... / };
auto p = new int();
auto sp = make_shared<int>();
a) process(sp) //legal, processes sp
b) process(new int()); //a plain pointer cannot convert to a small pointer
c) process(p) //same as above, illegal
d) process(shared_ptr<int>(p))
//legal, but with issues mixing smart pointers with plain pointers
```

## **Exercise 12.13**

> What happens if we execute the following code?

```
auto sp = make_shared<int>();
auto p = sp.get();
delete p;

malloc: *** error for object 0x14e606798: pointer being freed was not allocated
```

The

## **Exercise 12.14**

>
