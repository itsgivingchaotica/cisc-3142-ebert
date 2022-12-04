/**
 * Rewrite the word-counting program from p. 421 to use `insert` instead of subscripting. Which program do you think is eaiser to write and read? Explain your reasoning.
 */
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