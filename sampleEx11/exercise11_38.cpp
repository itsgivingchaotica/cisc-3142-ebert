/**
 * Rewrite the word-counting and word-transformation programs to use an `unordered_map`
 */
#include <iostream>
#include <unordered_map>
#include <vector>git 

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