/**
 * Implement your own version of the word-transformation program
 */
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