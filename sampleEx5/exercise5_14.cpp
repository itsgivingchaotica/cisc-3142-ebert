/**
 * Write a program to read `string`s from the standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is `how now now now brown cow cow`, the output should indicate that the word `now` occurred three times.
 */

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