/**
 * Write a class named `Person` that represents the name and address of a person. Use a `string` to hold each of these elements. Subseqent exercises will incrementally add features to this class. Provide operations in your `Person` class to return the name and address. Should these functions be `const`? Explain your choice.
 */
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