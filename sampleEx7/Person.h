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