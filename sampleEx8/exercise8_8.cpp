/**
 * Revise the program from the previous exercise to append its output to its given file.
 * Run the program on the same output file at least twice to ensure that the data is preserved
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
    ofstream outputFile(argv[2], ofstream::app);
    if (!outputFile){
        cerr << "No output file: " << endl;
        return -1;
    }
    processSales(inputFile,outputFile);
   
    return 0;
}
}