/**
 * Use a stack to process parenthesized expressions. 
 * When you see an open parenthesis, note that it was seen. 
 * When you see a close parenthesis after an open parenthesis, 
 * pop elements down to and including the open parenthesis off the estack. 
 * push a value onto the stack to indicate that a parenthesized
 * expression was replaced.
*/
#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::cout;
using std::endl;
using std::stack;

int main()
{
    string input = "(Paranthesis) and ((Parantheses))";
    char replacement = '~';
    size_t seen = 0;
    stack<char> cstack;

    for (auto i : input) {
        cstack.push(i);
        if (i == '(') ++seen;   // open
        if (seen && i == ')') { // pop elements down to the stack
            while (cstack.top() != '(') 
            {
                cstack.pop();
            }
            cstack.pop();      // including the open parenthesis
            cstack.push(replacement); // push a value indicate it was replaced
            --seen;         // close
        }
    }
    string output;
    while (!cstack.empty())
    {
        output.insert(output.begin(),cstack.top());
        cstack.pop();
    }
    cout << output << endl; // "This is # and # over"
    return 0;
}