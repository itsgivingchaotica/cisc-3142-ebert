# **Chapter 11 Exercises**

## **Exercise 11.1**
> Describe the differences between a `map` and a `vector`

A `map` is a type of associative container whereas a `vector` is sequential. ***A 'map' is a collection of key-value pairs***. Unlike `vector` or `array`, `map` and other associative arrays' subscripts do not need to be integers. Furthermore, the values in `map`s are found by a key rather than by the value.

## **Exercise 11.2**
> Give an example of when each of `list`, `vector`, `deque`, `map`, and `set` might be most useful.

`list`:
- needing to insert into middle of the container 
- need stability, as elements do not need to be moveable 
- iterators and references never invalidated unless associated element is erased
- moving one or more elements from *middle* of one list to another. 

`vector`: 
- always use vector unless need associative array container of a fixed size
- contiguous memory and don't need pointers
- don't need to insert data besides at the end (`push_back`) or in the middle, but there are other containers best suited for that

`deque`:
- want to insert and delete at both beginning and end (altho is also possible to do so from the middle)
- FIFO data structure
- no iterator invalidation unless insertion occurs in the middle

`map`
- lookup and retrieval by a key 
- `pair` is the template used to hold data elements, a key and its corresponding value
    - e.g. a word and the word counter
- ensures key is unique across entire data structure
- when wanting to avoid duplicating data

`set`
- looking up if a key exists or not
- simple programs like to check if a name is present in the system
- bad checks example

## **Exercise 11.3**
> Write your own version of the word-counting program.

```
#include <iostream>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::cin;
using std::set;


void printCount(map<string,size_t> countMap){
    for (const auto &m : countMap)
        cout << m.first << " occurred " << m.second << ((m.second > 1 ) ? " times " : " time ") << endl;
}

int main()
{
    map<string, size_t> countMap;
    string input, word;
    set<string> exclude = {"and", "And", "The", "the", "a", "an", "or", "but", "But", "Or", "A", "a", "I"};
    
    while (cin >> word)
    {
        if (exclude.find(word) == exclude.end())
            ++countMap[word];
    }
    printCount(countMap);

    return 0;
}
```

## **Exercise 11.4**
> Extend your program to ignore case and punctuation. For example, "example." "example" and "Example" should all increment the same counter.

```
#include <iostream>
#include <map>
#include <set>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::cin;
using std::set;

int main()
{
    /**
     * countMap will hold our words(first) and counts(second), 
     * while exclude will be the set of words to exclude from the word count
     */

    map<string, size_t> countMap;
    set<string> exclude = {"and", "And", "The", "the", "a", "an", "or", "but", "But", "Or", "A", "a", "I"};
    string word;
    
    while (cin >> word)
    {
        if (exclude.find(word) == exclude.end())
        for (auto &w : word){
            if (ispunct(w))
            {
                word.erase(word.find_first_of(w));
            }
            w = tolower(w);
            
            }
        ++countMap[word];
    }
     for (const auto &m : countMap)
        cout << m.first << " occurred " << m.second << ((m.second > 1 ) ? " times " : " time ") << endl;

    /**
     * Siobhan
    * siobhan
    * SIOBHAN
    * siobhan.
    * Siobhan.
    * siobhan occurred 5 times 
    */

    return 0;
}
```

## **Exercise 11.5**
> Explain the difference between a `map` and a `set`. When might you use one or the other?

A `map` stores a key value pair whereas a `set` consists of keys. Use `map` the print frequencies of distinct sorted elements, and `set` for only printing sorted distinct elements.

## **Exercise 11.6**
> Explain the difference between a `set` and a `list`. When might you use one or the other? 

A `list` is an ordered sequence of elements whereas a `set` is an unordered distinct list of elements. Therefore null elements may only be stored once in a `set`. `list` is thus indexed and `set` is not, and instead uses keys. Therefore, in a `list` elements by their position can be accessed.

## **Exercise 11.7**
> Define a `map` for which the key is the family's last name and the value is a `vector` of the children's names. Write code to add new families and to add new children to an existing family.

```
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, vector<string>> families;

    std::string lastName, firstName;

    while ([&]() -> bool
           {
        std::cout << "Please enter last name:\n";

        return cin >> lastName && lastName != "q"; }())

    {
        std::cout << "Enter children's name:\n";
        while (cin >> firstName && firstName != "q")
        {
            // add a new child
            families[lastName].push_back(firstName);
        }
    }

    //! iterate through family map.
    for (auto f : families)
    {
        std::cout << f.first << " family:\n";

        //! iterate through the vector of children.
        for (auto v : f.second)
            cout << v << " ";
        cout << " (" << f.second.size() << " children)\n";
    }

    return 0;
}
```

## **Exercise 11.8**
> Write a program that stores the excluded words in a `vector` instead of in a `set`. What are the advantages to using a `set`?

```
#include <iostream>
#include <map>
#include <vector>

using std::map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    map<string, size_t> word_count;
    vector<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    string word;
    bool excluded;
    while (cin >> word)
    {
        if (word == "q")
        {
            break;
        }
        //we must iterate through the vector to find the value, whereas
        // a set you may find by the key using method find()
        for (auto it = exclude.begin(); it != exclude.end(); ++it)
        {
            if (word == *it)
                excluded = true;
                continue;
        }
        if (!excluded)
                ++word_count[word];
    }
    for (auto w : word_count)
    {
        cout << w.first << ": " << w.second << ((w.second > 1) ? " times" : " time");
        cout << endl;
    }

    return 0;
}
```

## **Exercise 11.9**
> Define a `map` that associates words with a `list` of line numbers on which the word might occur

`map<string,list<size_t>> word_list;`

## **Exercise 11.10**
> Could we define a `map` from `vector<int>::iterator` to `int`? What about from `list<int>::iterator` to `int`. In each case, if not, why?

`map<vector<int>::iterator,int>>` 

`vector<int>::iterator` supports use of certain arithmetic operators whereas `list<int>::iterator` will not. Therefore we cannot define the following `map` from `list<int>::iterator` to `int` 

`map<list<int>>::iterator,int>>` 

The following compiler error results from using this declaration: 

`error: invalid operands to binary expression ('const std::__list_iterator<int, void *>' and 'const std::__list_iterator<int, void *>')`

## **Exercise 11.11**
> Redefine `bookstore` without using `decltype`

`multiset<Sales_data,bool(*)(const Sales_data &lhs, const Sales_data &rhs)> bookstore(compareIsbn)`

where `compareIsbn` returns `lhs.isbn () < rhs.isbn()`

## **Exercise 11.12**
> Write a program to read a sequence of `string`s and `int`s, storing each into a `pair`. Store the `pair`s in a `vector` 

```
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::cout;
using std::endl;

int main()
{
    
    vector<pair<string,int>> pvec;
    ifstream in("pairs.txt");
    string line, word;
    int num;
    if (in.is_open())
    {
        pair<string,int> pair;
        while (in.good())
        {
            while (getline(in,line))
            {
            istringstream iss(line); 
            iss >> word >> num;
            pair = make_pair(word,num);
            pvec.push_back(pair);
            }
        }
    }
    for (auto it = pvec.cbegin(); it != pvec.cend(); ++it)
    {
        cout << (*it).first << " paired with " << ((*it).second) << endl;
    }

    return 0;
}
```

## **Exercise 11.13**
> There are at least three ways to create the `pair`s in the program for the previous exercise. Write three versions of that program, creating the `pair`s in each way. Explain which form you think is easiest to write and understand.

Let's compare the three ways:
```
vector<pair<string,int>> mvec, vvec, evec;
string word = "word";
int num = 1;
pair<string,int> pair;

pair = make_pair(word,num);
mvec.push_back(pair);
vvec.push_back({word,num}); 
evec.emplace_back(word,num); //easiest because we do not need to use make_pair or using { } to create the vector
```

## **Exercise 11.14**
> Extend the `map` of children for their family name that you wrote for the exercises by having the `vector` store a `pair` that holds a child's name and birthday.

```
/**
 * Extend the `map` of children for their family name that you wrote for the exercises by having the `vector` store a `pair` that holds a child's name and birthday.
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::make_pair;
using std::map;
using std::ostream;
using std::pair;
using std::set;
using std::string;
using std::vector;

class Family
{
public:
     using Child = pair<string, string>;
     using Children = vector<Child>;
     using Lineage = map<string, Children>;

     void add(string const &lastName, string const &firstName, string birthday)
     {
          familyData[lastName].push_back(make_pair(firstName, birthday));
     }

     ostream &print(ostream &os) const
     {
          if (familyData.empty())
          {
               return os << "No family data entered. " << endl;
          }
          for (const auto &entry : familyData)
          {
               os << entry.first << " Family:\n";
               for (const auto &child : entry.second)
                    os << child.first << " " << child.second << endl;
               os << endl;
          }
          return os;
     }

private:
     Lineage familyData;
};

int main()
{
     Family families;
     set<string> endit = {"No", "N", "n", "NO", "no"};
     string lastName, child, birthday;
     string response;
     cout << "Enter the family name, child name, birthday: ";
     while (cin >> lastName >> child >> birthday)
     {
          if (lastName == "q" || child == "q" || birthday == "q")
               break;
          families.add(lastName, child, birthday);

          cout << "continue? ";
          cin >> response;
          if (endit.find(response) != endit.end())
          {
               families.print(cout << "\nData collected: " << endl);
          }
          else
          {
               cout << "Enter the family name, child name, birthday: ";
          }
     }
     return 0;
}
```

## **Exercise 11.15**
> What are the `mapped_type`, `key_type`, and `value_type` of a `map` from `int` to `vector<int>`?

`mapped_type` is `vector<int>`
`key_type` is `int`
`value_type` is `pair<const int, vector<int>>

## **Exercise 11.16**
> Using a `map` iterator write an expression that assigns a value to an element.

```
#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

int main()
{
    map<string, string> names;
    string first, last;

    while (cin >> first >> last)
    {
        // iterator = map_name.find(key)
        auto it = names.find(first);
        if (it != names.end())
            it->second = last;
        else
            names.insert({first, last});
    }
    for (auto it = names.cbegin(); it != names.cend(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
```

## **Exercise 11.17**
> Assuming `c` is a `multiset` of `string`s and `v` is a `vector` of `string`s, explain the following calls. Indicate whether each call is legal

```
copy(v,begin(), v.end(), inserter(c, c.end())); //this will copy elements of `v` and insert it into the `multiset`
copy(v.begin(), v.end(), back_inserter(c)); //invalid, cannot use back_inserter on `multiset` container type
copy(c.begin(), c.end(), inserter(v,v.end()) //legal, copies string elements of `c` multiset into vector `v`
copy(c.begin(), c.edn(), back_inserter(v)); //same as last but uses back_inserter instead of inserter
```

## **Exercise 11.18**
> Write the type of `map_it` from the loop on page 430 without using `auto` or `decltype`

Instead of using `auto map_it` one would use `map<string,size_t>::const_iterator map_it`.

## **Exercise 11.19**
> Define a variable that you initialize by calling `begin()` on the `multiset` named `bookstore` from p. 425. Write the variable's type without using `auto` of `decltype`.

```
using boolType = bool(*)(const Sales_data &lhs, const Sales_data &rhs) //store the type returned by the method
multiset<Sales_data, boolType> bookstore(compareIsbn); //Redefine bookstore using boolType
multiset<Sales_data,bool>::const_iterator mit = bookstore.begin(); //variable mit initialized using begin();
```

## **Exercise 11.20**
> Rewrite the word-counting program from p. 421 to use `insert` instead of subscripting. Which program do you think is eaiser to write and read? Explain your reasoning.

```
#include <iostream>
#include <map>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::string;

int main()
{
    /**
     * countMap will hold our words(first) and counts(second),
     * while exclude will be the set of words to exclude from the word count
     */

    map<string, size_t> countMap;
    set<string> exclude = {"and", "the", "a", "an", "or", "but", "i"};
    string word;

    while (cin >> word)
    {
        // make the word case insensitive
        for (auto &w : word)
        {
            //get rid of any punctuation
            if (ispunct(w))
            {
                word.erase(word.find_first_of(w));
            }
            w = tolower(w);
        }
        //if the word isn't common
        if (exclude.find(word) == exclude.end())
        {
            //insert into the map
            auto ret = countMap.insert({word, 1});
            //if the key already exists, increment the counter
            if (!ret.second)
                ++ret.first->second;
        }
        // ++countMap[word];
        //subscript is easier but does not specify whether the insertion was not successful i.e. if the key word was listed
    }
    for (const auto &m : countMap)
        cout << m.first << " occurred " << m.second << ((m.second > 1) ? " times " : " time ") << endl;

    /**
     * Siobhan
     * siobhan
     * SIOBHAN
     * siobhan.
     * Siobhan.
     * siobhan occurred 5 times
     */

    return 0;
}

moon
moon
cow
cow
cow
SIOBHAN
siobhan
Siobhan
an
a
BUT
_______________________
cow occurred 3 times 
moon occurred 2 times 
siobhan occurred 3 times 
```

## **Exercise 11.21**
> Assuming `word_count` is a `map` from `string` to `size_t` and `word` is a `string`, explain the following loop:

```
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
```

does the the same as 
```
while (cin >> word)
auto ret = countMap.insert({word, 1});
if (!ret.second)
    ++ret.first->second;
```

and `++word_count[word];`, if the `word` is already in the `map`, increase the count by 1, else `insert` into `map` but set to 0 then incremented by 1. 

## **Exercise 11.22**
> Given a `map<string, vector<int>> write the types used as an argument and as the return value for the version of `insert` that inserts one element.

```
pair<string,vector<int>> //argument passed to insert function, inserting a pair into map
pair<map<string,vector<int>::iterator, bool> //return value of insert
```

## **Exercise 11.23**
> Rewrite the `map` that stored `vector`s of children's names with a key that is the family last name for the exercises on p. 424 to use a `multimap`

```
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::multimap;
using std::string;
using std::vector;

void addLastName(multimap<string, vector<string>> &families, const string &last);

void addFirstName(multimap<string, vector<string>> &families, const string &last, const string &first);

int main()
{
    multimap<string, vector<string>> families;

    string lastName, firstName;
    while (cin >> firstName >> lastName)
    {
        addLastName(families, lastName);
        addFirstName(families, lastName, firstName);
    }
    //! iterate through family map.
    cout << "\n";
    for (const auto f : families)
    {
        if (f.second.size() != 0)
        {
            cout << f.first << " family:\n";

            //! iterate through the vector of children.
            for (auto v : f.second)
                cout << v << " ";
            cout << " (" << f.second.size() << " children)\n";
        }
    }

    return 0;
}

void addFirstName(multimap<string, vector<string>> &families, const string &last, const string &first)
{
    auto it = families.find(last);
    if (it != families.end())
        it->second.push_back(first);
}

void addLastName(multimap<string, vector<string>> &families, const string &last)
{
    families.insert({last, vector<string>()});
}

Saoirse Ebert
Lindsay Ebert
Venus Williams
Serena Williams
^D
Ebert family:
Saoirse Lindsay  (2 children)
Williams family:
Venus Serena  (2 children)

```

## **Exercise 11.24**
> What does the following program do?

```
map<int, int> m;
m[0]=1; //set the value at key 0 to 1 and adds the key-value pair into the map
```

## **Exercise 11.25**
> Contrast the following program with teh one in the previous exercise:

```
vector<int> v;
v[0]=1; //the value at index 0 is 1;
```

## **Exercise 11.26**
> What type can be used to subscript a map? What type does the subscript operator return? Give a concrete example—that is, define a map and then write the types that can be used to subscript the map and the type that would be returned from the subscript operator.

Use `key_type` to subscript a `map`. 

```
map<string, int> word_count; 
string input = "Input";
int count = word_count[input]; /`mapped_type` is returned, or `int`
```

## **Exercise 11.27**
> What kinds of problems would you use `count` to solve?? When might you use `find` instead?

We can use `count` for containers which allow multiple keys, and `find` when wanting to see if the key is present and what its unique value is. Therefore, `multiset` and `multimap` uses `count` and `set` and `map` uses `find` in meaningful ways, respecitvely.

## **Exercise 11.28**
> Define and initialize a variable to hold the result of calling `find` on a `map` from `string` to `vector` of `int`
```
map<string,vector<int>> amap;
string astring = "astring"
auto found = amap.find(astring);
```

## **Exercise 11.29**
> What do `upper_bound`, `lower_bound`, and `equal_range` return when you pass them a key that is not in the container?

`upper_bound` and `lower_bound` both return off-the-end iterator `c.end()`. `equal_range` will return two iterators which refer to the position where the key can be inserted `make_pair(c.end(), c.end());`

## **Exercise 11.30**
> Explain the meaning of the operand `pos.first->second` used in the output expression of the final program in this section.

`pos.first` is the first iterator in a pair of iterators denoted by `pos` referring to the matching key. So `pos.first->second` would dereference that iterator, a pair of strings, and return the second string. In the example it would print the title of each book written by the author which was the `search_item`.

## **Exercise 11.31/32**
> Write a program that defines a `multimap` of authors and their works. Use `find` to find an element in the `multimap` and `erase` that element.

```
#include <iostream>
#include <map>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::string;

int main()
{
    multimap<string, string> authorMap{{"Fitzgerald", "The Great Gatsby"}, {"Fitzgerald", "Tender is the Night"}, {"Fitzgerald", "This Side of Paradise"}, {"Steinbeck", "The Grapes of Wrath"}, {"Steinbeck", "East of Eden"}, {"Steinbeck", "Of Mice and Men"}, {"Faulkner", "The Sound and the Fury"}, {"Faulkner", "As I Lay Dying"}, {"Faulkner", "Light in August"}};

    string author;

    cout << "Enter an author to remove a book from the reading list: " << endl;
    cin >> author;
    cout << "The first novel found on list by " << author << " will be deleted." << endl;

    auto found = authorMap.find(author);
    if (found != authorMap.end())
    {
        // erase the first element found by key
        authorMap.erase(found);
    }
    else
    {
        cerr << "Author not found on reading list." << endl;
    }

    cout << "Updated reading list: \n"
         << endl;
    for (const auto &a : authorMap)
    {
        cout << a.second << " by " << a.first << "\n";
    }
    cout << endl;
    return 0;
}


Enter an author to remove a book from the reading list: 
Faulkner
The first novel found on list by Faulkner will be deleted.
Updated reading list: 

As I Lay Dying by Faulkner
Light in August by Faulkner
The Great Gatsby by Fitzgerald
Tender is the Night by Fitzgerald
This Side of Paradise by Fitzgerald
The Grapes of Wrath by Steinbeck
East of Eden by Steinbeck
Of Mice and Men by Steinbeck

//The Sound and the Fury was deleted

```

## **Exercise 11.32**
> Using the `multimap` from the previous exercise, write a program to print the list of authors and their works alphabetically.

```
#include <iostream>
#include <map>
#include <vector>
#include <set>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::multiset;
using std::pair;
using std::string;
using std::vector;

void sort(map<string, string> &authorMap);
bool myComparator(pair<string, string> &lhs, pair<string, string> &rhs);

int main()
{
    multimap<string, string> authorMap{{"Fitzgerald", "The Great Gatsby"}, {"Fitzgerald", "Tender is the Night"}, {"Fitzgerald", "This Side of Paradise"}, {"Steinbeck", "The Grapes of Wrath"}, {"Steinbeck", "East of Eden"}, {"Steinbeck", "Of Mice and Men"}, {"Faulkner", "The Sound and the Fury"}, {"Faulkner", "As I Lay Dying"}, {"Faulkner", "Light in August"}};

    string author;
    map<string, multiset<string>> alphabeticalList;

    cout << "Enter an author to remove a book from the reading list: " << endl;
    cin >> author;
    cout << "The first novel found on list by " << author << " will be deleted." << endl;

    auto found = authorMap.find(author);
    if (found != authorMap.end())
    {
        // erase the first element found by key
        authorMap.erase(found);
    }
    else
    {
        cerr << "Author not found on reading list." << endl;
    }
    for (const auto &a : authorMap)
    {
        alphabeticalList[a.second].insert(a.first);
    }
    cout << "Updated reading list: \n"
         << endl;
    for (const auto &al : alphabeticalList)
    {
        cout << al.first << ": ";
        for (const auto &novel : al.second)
        {
            cout << novel << " ";
        }
        cout << endl;
    }

    return 0;
}

```

## **Exercise 11.33**
> Implement your own version of the word-transformation program.

```
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

void word_transform(map<string, string> &smap, const vector<string> &svec);
const string &transform(const string &s, const map<string, string> &m);

int main()
{
    // Initialize map using
    // default constructor
    map<string, string> transMap;

    // Adding key-value pairs
    // using Initializer list
    transMap = {{"brb", "be right back"},
                {"k", "okay"},
                {"y", "why"},
                {"r", "are"},
                {"u", "you"},
                {"pic", "picture"},
                {"thx", "thanks"},
                {"l8r", "later"}};

    vector<string> phrases = {"where", "r", "u", "y", "don't", "u", "send", "me", "a", "pic", "k", "thx", "l8r"};

    word_transform(transMap, phrases);

    // Traverse through the map
    for (auto x : transMap)
    {
        cout << x.first << "->" << x.second << endl;
    }
    return 0;
}

void word_transform(map<string, string> &smap, const vector<string> &svec)
{
    bool firstWord = true;
    for (auto s : svec)
    {
        if (firstWord)
            firstWord = false;
        else
        {
            cout << " ";
        }
        cout << transform(s, smap);
    }
    cout << endl;
}

const string &transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}
```

## **Exercise 11.34**
> What would happen if we used the subscript operator instead of `find` in th `trnasform` function

In this case the following error would result. 

```
error: no viable overloaded operator[] for type 'const map<std::string, std::string>' (aka 'const map<basic_string<char, char_traits<char>, allocator<char>>, basic_string<char, char_traits<char>, allocator<char>>>')
    auto map_it = m[s];
```

This is because the map operator is not `const` whereas `m` is a `const` reference. 

## **Exercise 11.35**
> In `buildMap`, what effect, if any, would there be from rewriting `trans_map[key] = value.substr(1);` as `trans_map.insert({key, value.substr(1)});` ?

Using `[]` the last word which appeared more than once will be put into the `trans_map` whereas using `insert` it will always be the first to be inserted into the `map`

## **Exercise 11.36**
> Our program does no checking on the validity of either input file. In particular, it assumes that the rules in the transformation file are all sensible. What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.

If a line in that file has a key, one space, and then the end of the line, it will cause an error because there is no value associated with the key. There would need to be a second space to initialize the value to an empty string. 

## **Exercise 11.37**
> What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?

Unordered containers are are useful because they are implemented by hash tables and therefore take a lookup and insertion complexity of O(1) rather than O(log n) of ordered containers. 
Ordered containers advantages include all keys being sorted by type and is relatively straightfoward to use compared to implementing an unordered container.

## **Exercise 11.38**
> Rewrite the word-counting and word-transformation programs to use an `unordered_map`

```
#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

void word_transform(unordered_map<string, string> &smap, const vector<string> &svec);
const string &transform(const string &s, const unordered_map<string, string> &m);

int main()
{

    unordered_map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    }

    // Initialize map using
    // default constructor
    unordered_map<string, string> transMap;

    // Adding key-value pairs
    // using Initializer list
    transMap = {{"brb", "be right back"},
                {"k", "okay"},
                {"y", "why"},
                {"r", "are"},
                {"u", "you"},
                {"pic", "picture"},
                {"thx", "thanks"},
                {"l8r", "later"}};

    vector<string> phrases = {"where", "r", "u", "y", "don't", "u", "send", "me", "a", "pic", "k", "thx", "l8r"};

    word_transform(transMap, phrases);

    // Traverse through the map
    for (auto x : transMap)
    {
        cout << x.first << "->" << x.second << endl;
    }
    return 0;
}

void word_transform(unordered_map<string, string> &smap, const vector<string> &svec)
{
    bool firstWord = true;
    for (auto s : svec)
    {
        if (firstWord)
            firstWord = false;
        else
        {
            cout << " ";
        }
        cout << transform(s, smap);
    }
    cout << endl;
}

const string &transform(const string &s, const unordered_map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}
```
