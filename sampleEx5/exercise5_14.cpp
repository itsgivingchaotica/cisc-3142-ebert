#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string prevWord, word, repeatWord;
    int cnt = 0;
    int max_repeat_cnt = 0;
    cout << "Enter text to find out max number of repeats :"; 
    while (cin >> word)
    {
        if (word == prevWord)
        {
            ++cnt;
        }
        else
        {
            prevWord = word;
            cnt = 1;
        }

        if (max_repeat_cnt < cnt)
        {
            max_repeat_cnt = cnt;
            repeatWord = prevWord;
        }
    }

    if (max_repeat_cnt <= 1)
    {
        cout << "No words were repeated" << endl;
    }
    else
    {
        cout << "the word " << repeatWord << " occurred " << max_repeat_cnt << " times" << endl;
    }
    return 0;

}