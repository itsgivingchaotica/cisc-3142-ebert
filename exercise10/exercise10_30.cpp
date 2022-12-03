#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;
// Use stream iterators, `sort`, and `copy` to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.
int main()
{
    istream_iterator<int> isit(cin), is_eof;
    vector<int> ivec(isit, is_eof);
    // sort the input
    sort(ivec.begin(), ivec.end());
    ostream_iterator<int> osit(cout, " ");
    // copy the output to osit
    copy(ivec.begin(), ivec.end(), osit);

    return 0;
}