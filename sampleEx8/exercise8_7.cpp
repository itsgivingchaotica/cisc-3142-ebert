/**
 * Rewrite the bookstore program to read its transactions from a file. Pass the name of the file as an argument to main
*/
#include <fstream>
#include <string>
#include "Sales_data.cpp"

using namespace std;

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
    if (argc >= 3) {
    ofstream outputFile(argv[2]);
    if (!outputFile){
        cerr << "No output file: " << endl;
        return -1;
    }
    processSales(inputFile,outputFile);
   
    return 0;
}
}