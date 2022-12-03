/**
 * Write your own version of the word-counting program.
*/

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