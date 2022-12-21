# * **Exercises from Chapter 7*

## **Exercise 7.1-3**
> Write a version of the transaction-processing program from p. 24 using the `Sales_data` class you defined for exercises on p. 72. Add the `combine` and `isbn` members to the `Sales_data` class you wrote for exercises on p. 76. Revise your transaction-processing program from p. 256 to use these members. Add operations to read and print `Person` objects to the code

```
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::istream;
using std::ostream;

class Sales_data;
istream& read(istream&, Sales_data&);
ostream &print(ostream&, const Sales_data&);
Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

class Sales_data
{
  friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
  friend istream &read(istream&, Sales_data&);
  friend ostream &print(ostream&, const Sales_data&);
  public:
    Sales_data() = default;
    //Sales_data(const string &s) : itemNo(s){ }
    //Sales_data(istream &is) { read(is, *this); }
    Sales_data() : Sales_data("", 0, 0.0f)
    {
      cout << "Sales_data() initialized to null/zero" << endl;
    }
    Sales_data(const string &s) : Sales_data(s, 0, 0.0f)
    {
      cout << "Sales_data(const string &s) initialized" << endl;
    }
    Sales_data(const string &s, unsigned n, double p) : itemNo(s), units_sold(n), revenue(p*n)
    { 
      cout << "Sales_data(const std::string&, unsigned, double)" << endl; 
    }
    Sales_data(istream &is) : Sales_data()
      {
        cout << "Sales_data(istream &is) : Sales_data()\n";
      }
    string isbn() const { return itemNo; }
    Sales_data& combine(const Sales_data &rhs);
 
  private:
    inline double CalcAvgPrice() const;
    string itemNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data total = lhs;
    total.combine(rhs);
    return total;
}

istream &read(istream &is, Sales_data &item)
{
  double price = 0;
  is >> item.itemNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
  os << " ISBN#: " << item.isbn() << "number sold: " << item.units_sold << ", revenue: " << item.revenue << " average price: " << item.CalcAvgPrice(); 
  return os;
}

inline double Sales_data::CalcAvgPrice() const 
{ 
  return units_sold ? revenue/units_sold : 0; 
}

#endif // SALES_DATA_H

#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Sales_data total;
    if (cin >> total.itemNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.itemNo >> trans.units_sold >> trans.revenue)
        {
            if (total.itemNo == trans.itemNo)
            {
                total.combine(trans);
            }
            else
            {
                cout << "Book No: " << total.itemNo << ", units: " << total.units_sold << ", revenue: " << total.revenue << '\n';
                total = trans;
            }
        }
        cout << "Book No: " << total.itemNo << ", units: " << total.units_sold << ", revenue: " << total.revenue << '\n';
    }
    else
    {
        cout << "Data not entered" << '\n';
        return -1;
    }
    cout << endl;
    return 0;
}

```

## **Exercise 7.4-5**
> Write a class named `Person` that represents the name and address of a person. Use a `string` to hold each of these elements. Subseqent exercises will incrementally add features to this class. Provide operations in your `Person` class to return the name and address. Should these functions be `const`? Explain your choice.

```
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Person;
istream &read(istream &, Person &);
ostream &print(ostream &, const Person &);

class Person
{
  friend istream &read(istream &, Person &);
  friend ostream &print(ostream &, const Person &);

public:
  Person() = default;
  Person(const string n, const string a) : name(n), address(a) {}
  explicit Person(istream &is) { read(is, *this); }
  string getName() const { return name; }
  string getAddress() const { return address; }
  // make const, we don't want to read but not write to the data members for the Person that is called
private:
  string name;
  string address;
};

istream &read(istream &is, Person &person)
{
  is >> person.name >> person.address;
  return is;
}

ostream &print(ostream &os, const Person &person) const
{
  os << "Name: " << person.name << ", address: " << person.address;
  return os;
}

#endif
```

## **Exercise 7.8**
> Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?

For `read` the reference must be plain because the object will be modified when calculating revecnue, whereas with `print` the values are simply printed so it should be a `const` reference.

## **Exercise 7.10**
> What does the condition in the following `if` statement do?
`if (read(read(cin,data1), data2)`

Does the same as `if (cin >> data1 >> data2)`

## **Exercise 7.14**
> Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

`Sales_data() : units_sold(0), revenue(0){}`

## **Exercise 7.16**
> What, if any, are the constraints on where and how often an access speciier may appear inside a class definition? What kinds of members should be defined after a `public` specifier? What kinds should be `private`?

There's no constrinats on how often an access specifier appears inside a class defintion. Must keep in mind that each one specifies the access level of the succeeding members. "You should make a function private when you don't need other objects or classes to access the function, when you'll be invoking it from within the class. Stick to the principle of least privilege, only allow access to variables/functions that are absolutely necessary. Anything that doesn't fit this criteria should be private." [private_vs_public] (https://stackoverflow.com/questions/4505938/when-why-to-make-function-private-in-class)

## **Exercise 7.17**
> What, if any, are the differences between using `class` or `struct`

The difference is strictly stylistic, in that the default access level differentiates the two - `public` for `struct` and `private` for `class` unless otherwise specified as `public` in the `class` constructor.

## **Exercise 7.18**
> What is encapsulation? Why is it useful?

Encapsulation allows separation of a class' interface and implementation (`public` vs `private`). Users can access the interface but not the implentation. It can be useful for to hide the values or state of an object and its data members so as to prevent the user to have direct access to them / be able to corrupt the data associated with class objects. In addition, the author is able to make changes to the implemnetation without affecting the code written outside of it, as long as the class behavior is not affected.

## **Exercise 7.19**
> Indicate which members of your `Person` class you would declare as `public` and which you should declare as `private`. Explain your choice

```
class Person
{
    public:
        Person() = default;
        Person(const string n, const string a) : name(n), address(a) { }
        Person(istream &is) { read(is, *this); }
        string getName() const { return name; }
        string getAddress() const { return address; }
    private:
        string name;
        string address;
};
```

We want to include the constructors and accessors as part of the interface and make the `name` and `address` private as part of the implementation. We do not want the actual name and address data to be directly acessible outside of the `class` and avoid inadvertant corruption.

## **Exercise 7.20**
> When are `friend`s useful? Discuss the pros and cons.

A `friend` function is useful in being able to acess all members of the class which are not `public`. For example, the `friend` functions can be used for testing code by first providing proper encapsulation for certain data members and then allowing inspection of the code's behavior. However it may affect maintability outside of these purposes. It makes the code a bit more complicated so it might be reserved for specific access concerns

## **Exercise 7.22**
```
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

class Person;
istream& read(istream&, Person&);
ostream& print(ostream&, const Person&);

class Person
{
    friend istream& read(istream&, Person&);
    friend ostream& print(ostream&, const Person&);
    public:
        Person() = default;
        Person(const string n, const string a) : name(n), address(a) { }
        Person(istream &is) { read(is, *this); }
        string getName() const { return name; }
        string getAddress() const { return address; }
    private:
        string name;
        string address;
};

istream &read(istream &is, Person &person)
{
  is >> person.name >> person.address;
  return is;
}

ostream &print(ostream &os, const Person &person) const
{
  os << "Name: " << person.name << ", address: " << person.address;
  return os;
}

#endif
```
## **Exercise 7.23-24**

> Write your own version of the Screen class. Give your Screen class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.

```
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class Screen{
    public:
        typedef string::size_type pos;

        Screen() = default;
        //initialize contents to hold given number of blanks
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ');
        //screen contents with character
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c);
        char get() const 
            { return contents[cursor]; }
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c)
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
}

inline Screen& Screen::move(pos r, pos c)
{
    //compute row location
    pos row = r * width;
    //move cursor to column within row
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents(row + c);
}
```

## **Exercise 7.25**

> Can `Screen` safely rely on the default versions of copy and assignment?

Yes, as the books states: 

> ..the synthesized versions are unlikely to work correctly for classes that allocate resources that reside outside the class objects themselves. Moreover, the synthesized versions for copy, assignment, and destruction work correctly for classes that have **vector or string members**.

## **Exercise 7.26**

```
//make sure to make declaration private
private:
    inline double CalcAvgPrice() const;
    
inline double Sales_data::CalcAvgPrice() const 
{ 
  return units_sold ? revenue/units_sold : 0; 
}
```
## **Exercise 7.27**

> Add the `move`, `set`, and `display` operations to your version of `Screen`. Test your class by executing the following code: 

```
Screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

```
#ifndef EXERCISE_7_27_H
#define EXERCISE_7_27_H

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::ostream;

class Screen{
    public:
        using pos = string::size_type; 

        Screen() = default;
        //initialize contents to hold given number of blanks
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
        //screen contents with character
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
        char get() const 
            { return contents[cursor]; }
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c);
        Screen &set(char c);
        Screen &set(pos ht, pos wd, char c);
        //display overloaded on whether the object is const or not
        Screen &display(ostream &os) { do_display(os); return *this; }
        const Screen &display(ostream &os) const { do_display(os); return *this; }

    private:
        void do_display(ostream&os) const {os << contents;}
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
        
};

inline Screen& Screen::move(pos r, pos c)
{
    //compute row location
    pos row = r * width;
    //move cursor to column within row
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c)
{
    //set new value at where cursor currently is
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    //set specified location to given value
    contents[r*width + col] = ch;
    return *this;
}

#endif
```

The output is: 

```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
```

## **Exercise 7.28**
> What would happen in the previous exercise if the return type of `move`, `set`, and `display` was `Screen` rather than `Screen&` ?

The character would not be changed because the `set` function would not be able to set a new `char` in place of the one specified as a location. Therefore the `Screen` object would not change

## **Exercise 7.29**
> Revise your Screen class so that move, set, and display functions return Screen and check your prediction from the previous exercise.

The output without `&` is

```
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

## **Exercise 7.30**> 
> It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the `this` pointer to access members.

Even though it can use the member function parameter as the member name within its scope (setters), it is certainly more to read and often redundant in the case of getters.

## **Exercise 7.31**
> Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.

```
#ifndef XY_H
#define XY_H

class Y;

class X 
{
    Y *ptr;
};

class Y 
{
    X obj;
};

#endif
```

## **Exercise 7.32**
> Define your own version of `Screen` and `Window_mgr` in which `clear` is a member of `Window_mgr` and a friend of `Screen`

```
#ifndef EXERCISE_7_32_H
#define EXERCISE_7_32_H

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::ostream;

class Screen;

class Window_mgr 
{
    public:
        //location ID for eaceh screen on the window
        using ScreenIndex = vector<Screen>::size_type;
        //reset the Screen at the given position to all blanks
        void clear(ScreenIndex);

    private:
        vector<Screen> screens; // { Screen(24, 80, ' 'f) } sample input
}

class Screen{
    friend void Window_mgr::clear(ScreenIndex);
    public:
        using pos = string::size_type; 

        Screen() = default;
        //initialize contents to hold given number of blanks
        Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
        //screen contents with character
        Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }
        char get() const 
            { return contents[cursor]; }
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c);
        Screen &set(char c);
        Screen &set(pos ht, pos wd, char c);
        //display overloaded on whether the object is const or not
        Screen &display(ostream &os) { do_display(os); return *this; }
        const Screen &display(ostream &os) const { do_display(os); return *this; }

    private:
        void do_display(ostream&os) const { os << contents << '\n'; }
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;
        
};

void Window_mgr::clear(ScreenIndex i)
{
    //s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    //reset the contents of that Screen we want to clear
    s.contents = string(s.height * s.width, ' ');
}

inline Screen& Screen::move(pos r, pos c)
{
    //compute row location
    pos row = r * width;
    //move cursor to column within row
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c)
{
    //set new value at where cursor currently is
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    //set specified location to given value
    contents[r*width + col] = ch;
    return *this;
}

#endif
```

## **Exercise 7.33**

> What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.

```
pos Screen::size() const
{
    return height * width;
}
```

The error lies in the return type not being specified as `Screen` therefore the code should read `Screen::pos Screen::size() const { return height * width; }` instead

## **Exercise 7.34**
> What would happen if we put the typedef of pos in the Screen class on page 285 as the last line in the class?

There would be an error due to the code `dummy_fcn(pos height);` as type `pos` would be undeclared and therefore unknown

## **Exercise 7.35**
> Explain the following code, indicating which definition of Type or Init_Val is used for each use of those names. Say how you would fix any errors.

```
typedef string Type;
Type Init_Val();

class Exercise
{
public:
    typedef double Type; 
    Type Set_Val(Type);
    Type Init_Val();

private:
    int val;
};

Type Exercise::Set_Val(Type parameter)// Should be Exercise::Type 
{
    val = parameter + Init_Val();
    return val;
}

```

we must also add the following function `init_Val()`:

`Exercise::Type Exercise::init_Val() {...;}`

## **Exercise 7.36**
> The following initializer is in error. Identify and fix the problem.

```
struct X
{
    X(int i, int j): base(i), rem(base % j) { }
    int rem, base;
};
```

`base` cannot be used to initialize `rem`, we must use the parameter supplied `int i` instead

```
struct X
{
    X(int i, int j): base(i), rem(i % j) { }
    int rem, base;
};
```

## **Exercise 7.37**
> Using the version of `Sales_data` from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object: 

```
Sales_data first_item(cin);
int main()
{
    Sales_data next; //use Sales_data(string s = ""); bookNo = "", count = 0, revenue = 0.0
    Sales_data last("9-999-99999-9"); //use Sales_data(string s = ""); bookNo = "9-999-99999-9", count = 0, revenue = 0.0
}
```

## **Exercise 7.38**
> We might want to supply `cin` as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument.

`Sales_data(istream &is = cin);`

## **Exercise 7.39**
> Would it be legal for both the constructor that takes a string and the one that takes an istream& to have default arguments? If not, why not?

Overloading a default constructor in this way will result in ambiguity and a compilation error. If in `main` the following is declared: `Sales_data s;` we run into the problem because our default constructors both take default arguments which are `string` and `istream` so the compiler won't know whether to call the constructor that takes an empty `string` as default or `std::cin`.

## **Exercise 7.40**
> Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions. (a) Book (b) Date (c) Employee (d) Vehicle (e) Object (f) Tree

```
class Book
{
public:
    //default constructor, also takes isbn number
    Book(unsigned isbn = 0U) isbn_(isbn) { }
    Book(unsigned isbn, const string &title, const string &author, const string &genre, const string &pub_date) : isbn_(isbn), title_(title), author_(author), genre_(genre), pub_(pub_date) { }
    private:
        unsigned isbn_;
        string title_;
        string author_;
        string genre_;
        string pub_;
};
```

```
class Date
{
public:
    //default constructors for string and int expressions of date
    Date(int m = 0) : month_(m) { }
    Date(string day_week = "") : day_week_(day_week) { } 
    Date(int month, int day, int year) : month_(month), day_(day), year_(year) { } // 11 7 2022
    Date(string day_week, string m, string dayth, string yr) : day_week_(day_week), mon_(m), dayth_(dayth), yr_(y) { } //Monday, November 7th, 2022
private:
    int month_;
    int day_;
    int year_;
    string day_week_;
    string mon_;
    string dayth_;
    string yr_;
};
```

```
class Employee
{
public:
    Employee(unsigned empl_id = 0U) : empl_(empl_id) { }
    Employee(unsigned empl_id, const string &first_name, string last_name, const string &dob, string phone, string title, string department, double hourly) : empl_(empl_id), first_(first_name), last_(last_name), dob_(dob), phone_(phone), title_(title), department_(department), hourly_(hourly) { }
private:
    unsigned empl_;
    string first_;
    string last_;
    string dob_;
    strinb phone_;
    string title_;
    string department_;
    string hourly_;
};
```

## **Exercise 7.41**
> Rewrite your own version of the Sales_data class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a Sales_data object in every way possible

Can rewrite to include the following constructors:

```
Sales_data() : Sales_data("", 0, 0.0f) //Sales_data sales1;
    {
      cout << "Sales_data() initialized to null/zero" << endl;
    }
Sales_data(const string &s) : Sales_data(s, 0, 0.0f) //Sales_data sales2("0-201-78344-X");
    {
      cout << "Sales_data(const string &s) initialized" << endl;
    }
Sales_data(const string &s, unsigned n, double p) : itemNo(s), units_sold(n), revenue(p*n) //Sales_data sales3("0-201-78345-X", 4, 25.5)
    { 
      cout << "Sales_data(const std::string&, unsigned, double)" << endl;  
    }
Sales_data(istream &is) : Sales_data() //Sales_data sales4(cin);
      {
        cout << "Sales_data(istream &is) : Sales_data()\n";
      }
```

## **Exercise 7.42**
> For the class you wrote for ###Exercise 7.40 in §7.5.1(p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

```
class Book
{
public:
    //default constructor, also takes isbn number
    Book() : Book(0, "", "", "") { }
    Book(unsigned isbn, const string &title, const string &author, const string &genre, const string &pub_date) : isbn_(isbn), title_(title), author_(author), genre_(genre), pub_(pub_date) { }
    Book(istream &is) : Book()
    {
        is >> isbn_ >> title_ >> author_ >> genre_ >> pub_; 
    }
    private:
        unsigned isbn_;
        string title_;
        string author_;
        string genre_;
        string pub_;
};
```

```
class Date
{
public:
    //default constructors for string and int expressions of date
    Date() : Date(0, 0, 0) { }
    Date() : Date ("", "", "", "") { } 
    Date(int month, int day, int year) : month_(month), day_(day), year_(year) { } // 11 7 2022
    Date(string day_week, string m, string dayth, string yr) : day_week_(day_week), mon_(m), dayth_(dayth), yr_(y) { } //Monday, November 7th, 2022
private:
    int month_;
    int day_;
    int year_;
    string day_week_;
    string mon_;
    string dayth_;
    string yr_;
};
```

```
class Employee
{
public:
    Employee() : Employee(0U, "", "", "", "", "", 0.0f) { }
    Employee(unsigned empl_id, const string &first_name, string last_name, const string &dob, string phone, string title, string department, double hourly) : empl_(empl_id), first_(first_name), last_(last_name), dob_(dob), phone_(phone), title_(title), department_(department), hourly_(hourly) { }
private:
    unsigned empl_;
    string first_;
    string last_;
    string dob_;
    strinb phone_;
    string title_;
    string department_;
    string hourly_;
};
```

## **Exercise 7.43**
> Assume we have a class named `NoDefault` that has a constructor that takes an `int` but has no default constructor. Define class `C` that has a member of type `NoDefault` and define the default constructor.

```
class NoDefault 
{
    public:
        NoDefault(int i) { }
};
```

```
class C 
{
    public:
        C() : def_(0) { }
    private:
        NoDefault def_;

}
```

## **Exercise 7.44**
> Is the following declaration legal? If not, why not?
`vector<NoDefault> vec(10);` 

The declaration is illegal because NoDefault has no default constructor. The 10 elements want to be value initialized but cannot be due to the NoDefault type.

## **Exercise 7.45**
> What if we defined the vector in the previous exercise to hold objects of type C?

This would be valid since `C` has a default constructor 

## **Exercise 7.46**
> Which, if any, of the following statements are untrue? Why?
(a) A class must provide at least one constructor. 
(b) A default constructor is a constructor with an empty parameter list. 
(c) If there are no meaningful default values for a class, the class should not provide a default constructor. 
(d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type.

a) Untrue. The compiler can provide default constructor implicitly.
b) Untrue. The parameters themselves can be default.
c) Untrue. Default constructor should be provided by the class. Compiler errors can result.
d) Default initialization of class types cannot occur without default constructors.

## **Exercise 7.47**
> Explain whether the Sales_data constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?

`explicit` is only used on constructors called with one argument. So `explicit` has its limits. However this it is good to call to avoid making an error in calling the wrong overloaded function. Whether to make the constructor `explicit Sales_data(const string &s) : bookNo(s) { }` depends on what is needed by the user. 

## **Exercise 7.48**
> Assuming the Sales_data constructors are not explicit, what operations happen during the following definitions

```
string null_isbn("9-999-99999-9"); 
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```
- `null_isbn` a `string` is initialized as the isbn character string `"9-999-99999-9"`
- `item 1`, is initialized a `Sales_data` object
- `item 2` is initialized after implicit conversion to `string` occurs

## **Exercise 7.49**
> For each of the three following declarations of `combine`, explain what happens if we call `i.combine(s)`, where `i` is a `Sales_data` and `s` is a string: 
(a) `Sales_data &combine(Sales_data);  //ok
(b) `Sales_data &combine(Sales_data&); //error: cannot pass temporary object because combine has a parameter that is a non-const reference`
(c) `Sales_data &combine(const Sales_data&) const; //cannot have trailing const, would not be able to change data members

## **Exercise 7.50**
> Determine whether any of your `Person` class constructors should be `explicit`

`explicit Person(istream &is) { read(is, *this); }` is a good example

## **Exercise 7.51**
> Why do you think `vector` defines its single-argument constructor as `explicit`, but `string` does not?

With `string` we often need to implicitly convert the a `char` to a `string`. Whereas for `vector` it have no meaning outside of being supplied `size`

## **Exercise 7.52**
> Using our first version of `Sales_data` from §2.6.1(p. 72), explain the following initialization. Identify and fix any problems.

`Sales_data item = {"978-0590353403", 25, 15.99};` we cannot use this initialization without `Sales_data` being an aggregate class. If it looked like this then the initialization would work as expected. The members cannot be initialized as well.

```
struct Sales_data
{
    string itemNo;
    unsigned units_sold;
    double revenue;
};
```

## **Exeercise 7.53**
> Define `Debug`

```
#include <iostream>

using std::cout;

class Debug
{
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) { } //hw is hardware
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
    constexpr bool any()
    {
        return hardware || io || other;
    }
    void set_io(bool b)
    {
        io = b;
    }
    void set_hw(bool b)
    {
        hw = b;
    }
    void set_other(bool b)
    {
        other = b;
    }

private:
    bool hw;// hardware errors other than IO errors
    bool io;// IO errors
    bool other;// other errors
};
```

## **Exercise 7.54**
> Should the members of Debug that begin with `set_` be declared as `constexpr`? If not, why not?

The members are not `const` so they cannot be declared `constexpr`

## **Exercise 7.55**
> Is the `Data` class from §7.5.5(p. 298) a literal class? If not, why not?
```
struct Data {
    int ival;
    string s;
}
```

No, because member of `string` type is not a literal

## **Exercise 7.56**
> What is a `static` class member? What are the advantages of `static` members? How do they differ from ordinary members?

Associated with the class, not with individuals objects of class type and therefore exist outside any object. They have no `this` pointer so as functions they cannot be declared as `const` and therefore cannot use `this` in the body of the `static` member. Advantages are that they can be used in ways that non`static` data members cannot. Can have incomplete type as well as same type as class type of which it is a member. Can use as a default argument where non`static` members cannot because its value is part of the object of which it is a member. In addition, if the data is changed, each object can use the new value as it is accessible for all the objects of that type.

## **Exercise 7.57**
> Write your own version of the Account class.

```
#include <iostream>
#include <string>

using std::string;
using std::cout;

class Account 
{
    public:
        Account() = default;
        Account(string name) : owner(name) { }
        Account(string name, double amt) : owner(name), amount(amt) { }
        double balance() const { return amount; }
        void calculate()
        {
            amount += amount * interestRate; 
        }
        static double rate() 
        {
            return interestRate;
        }
        static void rate(double);
    private:
        string owner;
        double amount;
        static double interestRate;
        static double initRate();
};

double Account::interestRate = initRate();

double Account::initRate()
{
    return 0.05; // 5 percent
}

void Account::rate(double newRate)
{
    interestRate = newRate;
}

int main()
{
    cout << "Starting interest rate: " << Account::rate() << '\n';
    double initialBalance = 894785.22;
    Account acct("Williams", initialBalance);
    acct.calculate();
    printf("The initial balance was: %.2f\nBalance after interest: %.2f\nWith interest rate: %.2f\n", initialBalance, acct.balance(), acct.rate());
    //cout << "The initial balance was: " << initialBalance << " , balance after interest: " << acct.balance() << " with interest rate: " << acct.rate() << '\n';
    Account::rate(0.025);
    acct.calculate();
    printf("New balance: %.2f with new interest rate of %.2f", acct.balance(), acct.rate());
    //cout << "New balance: " << acct.balance() << " with interest rate: " << acct.rate() << '\n';

return 0;
}

/**
* Starting interest rate: 0.05
* The initial balance was: 894785.22
* Balance after interest: 939524.48
* With interest rate: 0.05
* New balance: 963012.59 with new interest rate of 0.03%   
*/
```

## **Exercise 7.58**
> Which, if any, of the following static data member declarations and definitions are errors? Explain why.

```
// example.h
class Example
{
public:
    static double rate = 6.5; //rate should be constexpr here
    static const int vecSize = 20;
    static vector<double> vec(vecSize); //definition should be outside of class - get rid of (vecSize)
};

// example.C
#include "example.h"
double Example::rate; //constexpr double
//if we use the member in a context in which the value cannot be substiuted, there must be a definition for that member
//static constexpr int Example::vecSize;
vector<double> Example::vec; //should have an initializer. vector<double> Example::vec(Example::vecSize);
```
