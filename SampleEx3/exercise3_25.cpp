//rewrite grade clustering program using iterators instead of subscripts
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	vector<int> scores(11, 0);
	unsigned grade;
    cout << "Enter the grades for the class here: \n";
	while (cin >> grade)
	{
	  if(grade <= 100)
	  {
	    ++(*(scores.begin() + grade / 10));
	  }
	}

    cout << "The grades in clusters of ten: ";
	for(const auto &score : scores)
	{
		cout << score << " ";
	}
	cout << endl;

	return 0;
}
