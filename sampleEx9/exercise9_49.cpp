/**
 * A letter has an ascender if, as with `d` or `f` part of 
 * the letter extends above the middle of the line.
 * A letter has a descender if, as with `p` or `g`, 
 * part of the letter extends below the line. 
 * Write a program that reads a file containing words 
 * and reports the longest word that contains
 * neither ascenders nor descenders.
*/

#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

int main() 
{
    string nonscenders("aceimnorsuvwxz.");

    ifstream in("words.txt");

    if (in.is_open())
    {
        string longest_word, word;
        while (in >> word){
            if (word.find_first_not_of(nonscenders) == string::npos && word.size() > longest_word.size())
                longest_word = word;
        }
        cout << "The longest word without ascenders or descenders in the file is: " << longest_word << endl;
    }

    return 0;
}