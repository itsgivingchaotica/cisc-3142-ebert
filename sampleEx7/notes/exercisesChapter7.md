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




