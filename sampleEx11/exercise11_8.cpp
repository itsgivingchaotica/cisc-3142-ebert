/**
 * Write a program that stores the excluded words in a `vector` 
 * instead of in a `set`. What are the advantages to using a `set`?
*/

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