/**
 * Write a function that returns a dynamically allocated vector of ints. Pass that vector to another function that reads the standard input to give values to the elements. Pass the vector to another function to print the values that were read. Remember to delete the vector at the appropriate time.
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int> *create();
void process(vector<int> *pv);
void print(vector<int> *pv);

int main()
{
    vector<int> *pv = create();
    process(pv);
    print(pv);
}

vector<int> *create()
{
    vector<int> *pv = new vector<int>();
    return pv;
}

void process(vector<int> *pv)
{
    int i;
    cout << "Enter values:\n";
    while (cin >> i)
        pv->push_back(i);
}

void print(vector<int> *pv)
{
    for (const auto &p : *pv)
    {
        cout << p << " ";
    }
    cout << endl;
}