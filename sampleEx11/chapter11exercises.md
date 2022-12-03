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
#include <vector>
#include <map>
#include <set>

using std::vector;
using std::map;
using std::string;
using std::set;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

void printFamilies(map<string, vector<string>> families)
{
for (auto it = families.begin(); it != families.end(); ++it)
        {
            vector<string> dropChildren = (*it).second;
            cout << "The " << (*it).first << " family has " << dropChildren.size() << " children: ";
            for (unsigned i = 0; i < dropChildren.size(); i++)
            {
                cout << dropChildren[i] << " ";
            }
            cout << endl;
        }
}

int main()
{
    map<string, vector<string>> families;
    set<string> endit = {"No", "N", "n", "NO","no"};
    string lastName;
    string response;
    cout << "Enter the family name: ";
    while (cin >> lastName){
    cout << "Enter the children's names, 'q' to end family line: ";
    string child;
    vector<string> children;
    while (cin >> child)
    {
        if (child == "q")
            break;
        children.push_back(child);
    }
    families[lastName] = children; 
   
    cout << "continue? ";
    cin >> response;
    if (endit.find(response) != endit.end())
    {
        printFamilies(families);
    }
    cout << "Enter the family name: ";
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



