/**
 * Write a program that defines a `multimap` of authors and their works. Use `find` to find an element in the `multimap` and `erase` that element.
 * Using the `multimap` from the previous exercise, write a program to print the list of authors and their works alphabetically.
 */
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
