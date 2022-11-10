#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::vector;
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::getline;

void readLines(const string& file, vector<string>& svec)
{
    ifstream ifs(file);
    cout << file << endl;
    if (ifs)
    {
        int i = 0;
        string line;
        while (getline(ifs, line))
        {
            svec.push_back(line);
        }
    }
}

int main()
{
    vector<string> svec;
    cout << "something" << endl;
    readLines("/Users/siobhan/cisc-3142-ebert/sampleEx8/notes/tar.txt", svec);
    for (const auto &str : svec)
        cout << str << endl;
    return 0;

}
