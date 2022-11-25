/**
 * Rewrite the program, moving the definition of record outside the while,
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istringstream;
using std::string;
using std::ifstream;
using std::getline;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    while (getline(cin, line) && line.length()>0){
        PersonInfo info;
        record.clear(); //need this as after reading line, stream state is "end-of-file"
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people) {
        cout << entry.name << "'s phone numbers: ";
        for (const auto &nums : entry.phones) 
            cout << nums << " ";
        cout << endl;
    }

    return 0;
}