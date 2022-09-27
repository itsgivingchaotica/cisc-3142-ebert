//read sequence of words from cin and store values in vector. After you've read in all the words process the vector and change each word to uppercase. Print elements eight words to a line
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
  string str;
  vector<string> svec;

  cout << "Enter a sequence of words separated by enter : " << endl;
  while (getline(cin, str))
  {
      svec.push_back(str);
  }
    
    for (int i = 0; i < svec.size(); ++i)
	   {
	   for (char &c : svec[i])
	     {
	     if(isalpha(c) && !isupper(c))
        //for each character in each string in the vector, move to uppercase
		c = toupper(c);
	     }
        //for every eight word, go to next line
        if (i%8 == 0)
        {
            cout << endl;
        }
        //print each element of the vector separated by a space
        cout << svec[i] << " ";
    }
    return 0;
}
