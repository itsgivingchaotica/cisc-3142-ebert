/**
 * Write a class that has three `unsigned` members representing year, 
 * month, and day. Write a constructor that takes a `string` representing a date. 
 * Your constructor should handle a variety of date formats, such as January 1, 1900, 
 * 1/1/1900, Jan 1, 1900 and so on
*/
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::stoi;
using std::isdigit;
using std::cerr;
using std::endl;
using std::cout;

class Date {
public:
    explicit Date(const string& str = "");
    unsigned year = 2000;
    unsigned month = 11;
    unsigned day = 16;
    void Print();

private:
    vector<string> months{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    unsigned findMonth(const std::string& str);
};

Date::Date(const std::string& str)
{
    if (str.empty()) return;
    std::string delimiters{" ,/"};
    auto first_delim = str.find_first_of(delimiters);
    if (first_delim == string::npos)
        cerr << "wrong format" << endl;
    month = findMonth(str.substr(0, first_delim));
    auto second_delim = str.find_first_of(delimiters, first_delim + 1);
    auto day_len = second_delim - first_delim - 1;
    day = stoi(str.substr(first_delim + 1, day_len));
    year = stoi(str.substr(second_delim + 1));
}

void Date::Print()
{
    cout << month << "-" << day << "-" << year << "\n";
}

unsigned Date::findMonth(const string& s)
{
    if (s.empty()) 
        return 0;
    if (isdigit(s[0])) 
        return stoi(s);
    for (size_t i = 0; i != 12; ++i) {
        if (s.find(months[i]) != string::npos) return i + 1;
    }
    return 0; //  not found
}

int main()
{
    vector<string> svec = {"January 1, 2001", "1/1/2001", "Jan 1, 2001"};
    Date date;
    date.Print();
    for (auto it = svec.begin(); it != svec.end(); ++it)
    {
        auto date = Date(*it);
        date.Print();
    }
    return 0;
}