/**
 * Write a program to store each line from a file in a vector<string>
 * now use an istringstream to read each element from the vector a word at a time
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::istringstream;
using std::string;
using std::ifstream;
using std::getline;

int main(int argc, char **argv) {
    string line, word;
    vector<string> transactions;

    ifstream inputFile(argv[1]);
    while (getline(inputFile, line))
    {
        transactions.push_back(line);
    }
    for (const auto &t : transactions){
        istringstream record(t);
        while (record >> word) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}