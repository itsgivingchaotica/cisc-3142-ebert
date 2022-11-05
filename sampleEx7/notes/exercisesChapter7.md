# * **Exercises from Chapter 7*

## **Exercise 7.8**
> Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter asa reference to `const`?

For `read` the reference must be plain because the object will be modified, whereas with `print` the values are simply printed so it can be a `const` reference.

## **Exercise 7.10**
> What does the condition in the following `if` statement do?
`if (read(read(cin,data1), data2)`

Does the same as `if (cin >> data1 >> data2)`

## **Exercise 7.14**
> Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

`Sales_data() : units_sold(0), revenue(0){}`

## **Exercise 7.16**
> What, if any, are the constraints on where and how often an access speciier may appear inside a class definition? What kinds of members should be defined after a `public` specifier? What kinds should be `private`?

There's no constrinats on how often an access specifier appears inside a class defintion. Must keep in mind that each one specifies the acess level of the succeeding members. Any constructors / member functions that are part of the class interface will be under `public` whereas those data members and functions that are part of implementation will be listed under `private`

## **Exercise 7.17**
> What, if any, are the differences between using `class` or `struct`

The difference is strictly stylistic, in that the default access level differentiates the two

## **Exercise 7.18**
> What is encapsulation? Why is it useful?

Encapsulation allows separation of a class' interface and implementation (`public` vs `private`). Users can access the intercace but not the implentation. It can be useful for to hide the values or state of an object and its data members so as to prevent the user to have direct access to them / be able to corrupt the data associated with class objects. In addition, the author is able to make changes to the implemnetation without affecting the code written outside of it, as long as the class behavior is not affected.

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
