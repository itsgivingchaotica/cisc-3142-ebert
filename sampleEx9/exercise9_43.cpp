/**
 * Write a function that takes three `string`s: `s`,
 * `oldVal`, and `newVal`. Using iterators, and the `insert`
 * and `erase` functions replace all instances of `oldVal`
 * that appear in s by newVal.
 * Test your function by using it to replace common
 * abbreviations, such as "tho" by "though" and "thru" by "through".
 */

#include <iostream>

using std::cout;
using std::endl;
using std::string;

void replace(string &s, const string &oldVal, const string &newVal)
{
    for (auto iter = s.begin(); iter < s.end() - oldVal.size() + 1; ++iter)
    {
        auto iter2 = oldVal.cbegin();
        for (auto iter3 = iter; iter2 != oldVal.cend(); ++iter2, ++iter3)
        {
            if (*iter3 != *iter2)
                break;
        }
        if (iter2 == oldVal.cend())
        {
            string::size_type pos = iter - s.begin();
            s.erase(pos, oldVal.size());
            s.insert(pos, newVal);
            // Recalculate `it` from `begin()` rather than use `+=` operator, because
            // `it` is invalid by `erase()` and `insert()`
            iter = s.begin() + pos + newVal.size();
        }
    }
}

int main()
{
    string str = "Even tho I tried my best, it felt like there was no way thru the semester";
    replace(str, "tho", "though");
    replace(str, "thru", "through");
    cout << str << endl;

    return 0;
}
