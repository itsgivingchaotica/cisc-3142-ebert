#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::vector;

shared_ptr<vector<int>> createShared();
void process(shared_ptr<vector<int>> spv);
void print(shared_ptr<vector<int>> spv);

int main()
{
    auto spv = createShared();
    process(spv);
    print(spv);
}

shared_ptr<vector<int>> createShared()
{
    return make_shared<vector<int>>();
}

void process(shared_ptr<vector<int>> spv)
{
    int i;
    cout << "Enter values:\n";
    while (cin >> i)
        spv->push_back(i);
}

void print(shared_ptr<vector<int>> spv)
{
    for (const auto &p : *spv)
    {
        cout << p << " ";
    }
    cout << endl;
}