/**
 * Write a program to explore how `vector`s grow in the library you use.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::cerr;

int main()
{
    ifstream file("film.csv.txt");
    //nested vector of months / temperatures
    vector<vector<string>> temperatures;
    string line;

    vector<string> fields;
    if (file.is_open())
    {
        getline(file,line);
        while (getline(file,line)){
                fields.push_back(line);
                cout << fields.capacity() << " ";
        }
    } else {
        cerr << "Could not read file" << endl;
    }

    return 0;

    /**
     * The vector's capacity doubles like so:
     * 1 2 4 8 16 32 64 128 256 512 1024 2048 
    */

}


