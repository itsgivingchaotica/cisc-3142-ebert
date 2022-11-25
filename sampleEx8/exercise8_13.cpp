/**
 * Rewrite the phone number program from 
 * this section to read from a named file rather than from cin
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istringstream;
using std::ostringstream;
using std::string;
using std::ifstream;
using std::getline;
using std::ostream;
using std::cerr;

struct PersonInfo {
    string name;
    vector<string> phones;
};

constexpr int numLength = 10;

bool valid(const string &num) {
    if (num.size() != numLength)
        return false;
    return true;
}

string format(const string &num)
{
    return num.substr(0, 3) + "-" + num.substr(3,6) + "-" + num.substr(6,10);
}

int main(int argc, char **argv) {

    if (argc < 2) {
        cerr << "No data to process" << endl;
        return -2;
    }
    ifstream inputFile(argv[1]);

    if (!inputFile.is_open())
    {
        cerr << argv[1] << " could not be opened." << endl;
        return -1;
    }
    
    string line, word;
    vector<PersonInfo> people;

    while (getline(inputFile, line)){
        istringstream record(line);
        PersonInfo info;
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &entry : people) {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones){
            if (!valid(nums)){
                badNums << " " << nums;
            } else
            formatted << " " << format(nums);

    }
    if (badNums.str().empty())
        cout << entry.name << " " << formatted.str() << endl;
    else
        cerr << "input error: " << entry.name
        << " invalid number(s) " << badNums.str() << endl;
}
return 0;
}