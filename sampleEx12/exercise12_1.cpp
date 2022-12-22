#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::shared_ptr;
using std::string;
using std::vector;

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }
    // add and remove elements
    void push_back(const string &t)
    {
        data->push_back(t);
    }
    void pop_back();
    string &front() const;
    string &back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};
// default constructor allocates an empty vector
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
// constructor passes its parameter to the corresponding vector constructor, which initializes the vector's elements by copying the values in the list
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

void test(const StrBlob &sb)
{
    try
    {
        // sb.push_back("abc");
        // sb.push_back("def");
        std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
        // sb.pop_back();
        // std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
        // sb.pop_back();
        // std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    }
    catch (out_of_range err)
    {
        cerr << err.what() << " out of range " << endl;
    }
    catch (exception err)
    {
        cerr << err.what() << endl;
    }
}

void test(StrBlob &sb)
{
    try
    {
        sb.push_back("one");
        sb.push_back("two");
        std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
        sb.pop_back();
        std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
        sb.pop_back();
        std::cout << "front: " << sb.front() << " back: " << sb.back() << std::endl;
    }
    catch (out_of_range err)
    {
        std::cerr << err.what() << " out of range" << std::endl;
    }
    catch (exception err)
    {
        std::cerr << err.what() << std::endl;
    }
}

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }
    cout << b1.size();

    StrBlob sb1;
    StrBlob sb2{"Hello", "World"};
    const StrBlob csb1;
    const StrBlob csb2{"This", "Blob"};

    test(sb1);
    cout << endl;
    test(sb2);
    cout << endl;
    test(csb1);
    cout << endl;
    test(csb2);
    cout << endl;

    return 0;
}