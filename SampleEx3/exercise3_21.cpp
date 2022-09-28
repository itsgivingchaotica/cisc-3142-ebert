//redo exercises 3_16, 3_17, 3_20
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::vector;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4 {10};
    vector<int> v5 {10, 42};
    vector<string> v6 {10};
    vector<string> v7 {10, "hi"};
   
    
    //print size and contents of vectors from exercise 3_13
    cout << "v1: size " << v1.size() << ", contents is: ";
    for (auto it = v1.cbegin(); it !=v1.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << ((v1.cbegin() == v1.cend()) ? "empty\n" : "\n");
    
    cout << "v2: size " << v2.size() << ", contents is: ";
    for (auto it2 = v2.cbegin(); it2 !=v2.cend(); ++it2)
    {
        cout << *it2 << " ";
    }
    cout << ((v2.cbegin() == v2.cend()) ? "empty\n" : "\n");
    
    cout << "v3: size " << v3.size() << ", contents is: ";
    for (auto it3 = v3.cbegin(); it3 !=v3.cend(); ++it3)
    {
        cout << *it3 << " ";
    }
    cout << ((v3.cbegin() == v3.cend()) ? "empty\n" : "\n");
    
    cout << "v4: size " << v4.size() << ", contents is: ";
    for (auto it4 = v4.begin(); it4 !=v4.cend(); ++it4)
    {
        cout << *it4 << " ";
    }
    cout << ((v4.cbegin() == v4.cend()) ? "empty\n" : "\n");
    
    cout << "v5: size " << v5.size() << ", contents is: ";
    for (auto it5 = v5.begin(); it5 !=v5.cend(); ++it5)
    {
        cout << *it5 << " ";
    }
    cout << ((v5.cbegin() == v5.cend()) ? "empty\n" : "\n");
    
    cout << "v6: size " << v6.size() << ", contents is: ";
    for (auto it6 = v6.begin(); it6 !=v6.cend(); ++it6)
    {
        cout << *it6 << " ";
    }
    cout << ((v6.cbegin() == v6.cend()) ? "empty\n" : "\n");
    
    cout << "v7: size " << v7.size() << ", contents is: ";
    for (auto it7 = v7.begin(); it7 !=v7.cend(); ++it7)
    {
        cout << *it7 << " ";
    }
    cout << ((v7.cbegin() == v7.cend()) ? "empty\n" : "\n");
    
    /*
     read sequence of words from cin and store values in vector. After you've read in all the words process the vector and change each word to uppercase. Print elements eight words to a line
   */
    
     string str;
     vector<string> svec;
     
     cout << "Enter a sequence of words separated by enter : " << endl;
     while (getline(cin,str))
     {
     svec.push_back(str);
     }
     int word_ctr = 0;
     for (auto it = svec.begin(); it != svec.end(); ++it)
     {
        //put the characters in word of svec into another
        for (char &c : svec[word_ctr])
         {
             //cout << " Next word: " << svec[word_ctr] << " ";
             if(isalpha(c) && !isupper(c))
                 //for each character in each string in the vector, move to uppercase
                 c = toupper(c);
         }
         ++word_ctr;
         
     //for every eight word, go to next line
     if (word_ctr%8 == 0)
     {
     cout << endl;
     }
     //print each element of the vector separated by a space
     cout << *it << " " ;
     }
    cout << endl;

    return 0;
}
