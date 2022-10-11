#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

void print(const int* i)
{
        cout << "Printing as void print(const int* i):" << endl;
    cout << *i << endl;
}

void print(const int *beg, const int *end)
{
    cout << "Printing as void print(const int *beg, const int *end):" << endl;
    while (beg != end)
    cout << *beg++ << endl;
}

void print(const int intarr[], size_t size)
{
    cout << "Printing as void print(const int intarr[], size_t size):" << endl;
    for (size_t i = 0; i != size; ++i)
    {
        cout << intarr[i] << endl;
    }
}
void print (int (&intarr)[2])
{
    cout << "Printing as void print (int (&intarr)):" << endl;
    for (auto e : intarr)
    {
        cout << e << endl;
    }
}
int main()
{
    int i = 0, j[2] = {0 ,1};
    cout << "Printing i=0" << endl;
    print(&i);
    cout << "Printing j[2] = {0 ,1}" << endl;
    print(j); //only prints element at first pointer
    print(begin(j), end(j));
    print(j, end(j) - begin(j));

    return 0;
}