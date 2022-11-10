#include <iostream>

using std::cout;
using std::endl;

int counter = 0;
int myMethod(int i)
{
    return i%2;
}

int main()
{
    int *p = &counter; //0 counter=0 is the address of pointer p;
    int count = *p; //0 p is address of count
    int &x = counter; //0 x is a reference to counter
    while (x<5)
    {
        counter +=1;
        cout << "Counter is: " << counter << endl; //0 to 1
        int newCount = count++;
        cout << "Count increased to: " << newCount << endl; 
        count = counter + myMethod(x);
        cout << "Counter: " << counter << " + myMethod(x): " << myMethod(x) << "New count: " << count << endl;
        x++;
        cout << "increment x to : " << x << endl;
        cout << "_____" << endl;
    }
    cout << count << " " << counter << endl;

    return 0;
}