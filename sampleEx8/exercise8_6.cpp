/**
 * Rewrite the bookstore program to read its transactions from a file. Pass the name of the file as an argument to main
*/
#include <iostream>
#include <string>
#include "Sales_data.cpp"
#include <fstream>

using std::ifstream;

int main(int argc, char **argv)
{
    if (argc < 2) {
        cerr << "No data to process" << endl;
        return -3;
    }
    ifstream inputFile(argv[1]);

    if (!inputFile) {
        cerr << "Cannot open file " << argv[1] << endl;
        return -2;
    }

    Sales_data total;
    if (read(inputFile,total))
    {
        Sales_data trans;
        while (read(inputFile,trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout,total) << endl;
                total = trans; //defalt copy constructor
            }
        }
        print(cout,total) << endl;
    }
    else
    {
        cerr << "Data not entered" << endl;
        return -1;
    }
    return 0;
}