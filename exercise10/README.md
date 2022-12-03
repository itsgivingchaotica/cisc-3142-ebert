# **Exercise 10**
The sample run can be found at GitHub Actions using workflow exercise10.yaml

Alternatively you may run `make exercise10` within the exercise folder.

```
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>

using std::back_inserter;
using std::cerr;
using std::cout;
using std::endl;
using std::find;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::stod;
using std::stoi;
using std::string;
using std::transform;
using std::vector;

void findRunningTimes(vector<vector<string>> records, ofstream &ofs);
vector<vector<string>> makeNested(vector<vector<string>> &records, ifstream &file);
bool myComparator(const vector<string> &a, const vector<string> &b);
void listbyPopularity(vector<vector<string>> popularity, ofstream &ofs);
void printVector(const vector<int> ivec, ofstream &ofs);
void makeGenreVectors(const vector<vector<string>> &records, vector<int> &genreFilm, const string &input);
void findFirst(const string &findActor, vector<vector<string>> dvec, ofstream &ofs);

int main()
{
    ifstream file("film.csv.txt");
    // print the results to an output file
    ofstream ofs("results.txt", ofstream::out);
    vector<vector<string>> records;
    int allrunningtimes;
    // store the csv file in a nested vector
    if (file.is_open())
    {
        records = makeNested(records, file);
    }
    else
    {
        cerr << "could not read file" << endl;
    }
    ofs.flush();
    // use accumulate to sum the total length of movies
    // the algorithm is inside call to function findRunningTimes
    ofs << "a) Use accumulate to sum the total length of movies\n";
    findRunningTimes(records, ofs);
    // sort by popularity descending order
    ofs << "b) Use sort to rank movies in descending order by popularity\n";
    vector<vector<string>> popularity = records;
    sort(popularity.begin(), popularity.end(), myComparator);
    listbyPopularity(popularity, ofs);
    // use find to find the top film by the actor by popularity
    ofs << "c) Use find to find the first occurrence of an actor from the ranked movies\n";
    string actorToFind("Brando, Marlon");
    findFirst(actorToFind, popularity, ofs);
    // extract from the data two vectors: Action and Comedy
    // Use unique to find the unique years these movies were released
    ofs << "d) Extract from the data two vectors: Action and Comedy. Use unique to find the unique years these movies were released and print. Use equal to compare the two unique lists";
    vector<int> action, comedy;
    makeGenreVectors(records, action, "Action");
    makeGenreVectors(records, comedy, "Comedy");
    sort(action.begin(), action.end());
    sort(comedy.begin(), comedy.end());
    action.erase(unique(action.begin(), action.end()), action.end());
    comedy.erase(unique(comedy.begin(), comedy.end()), comedy.end());
    sort(action.begin(), action.end());
    sort(comedy.begin(), comedy.end());
    ofs << "\nYears action films were released: ";
    printVector(action, ofs);
    ofs << "\n\nYears comedy films were released: ";
    printVector(comedy, ofs);
    // use equal to compare the two unique lists
    int action_years = action.size();
    int comedy_years = comedy.size();
    if (equal((action).begin(), action.end(), comedy.begin()))
    {
        ofs << "\n\nAction and comedy have the same number of years released " << action_years << " = " << comedy_years << "\n";
    }
    else
    {
        ofs << "\n\nAction and comedy do not have the same number of years released. Action: " << action_years << ", Comedy: " << comedy_years << "\n";
    }
    ofs.flush();

    return 0;
}

void findRunningTimes(vector<vector<string>> records, ofstream &ofs)
{
    vector<int> runtimes;
    int allRunTimes;
    for (const vector<string> fields : records)
    {
        if (fields[1] != "")
        {
            int time = stoi(fields[1]);
            runtimes.push_back(time);
        }
    }
    // here using accumulate algorithm
    allRunTimes = accumulate(runtimes.begin(), runtimes.end(), 0);

    ofs << "The total running length of all movies is: " << allRunTimes << " minutes\n\n";
    ofs.flush();
}

vector<vector<string>> makeNested(vector<vector<string>> &records, ifstream &file)
{
    string line;
    getline(file, line);
    getline(file, line);
    // create the nested vector
    while (getline(file, line))
    {
        istringstream iss(line);
        vector<string> fields;
        string str;
        while (getline(iss, str, ';'))
        {
            fields.push_back(str);
        }
        records.push_back(fields);
    }
    return records;
}

bool myComparator(const vector<string> &a, const vector<string> &b)
{
    if (a[7].size() == b[7].size())
        return a[7] > b[7];
    else
        return a[7].size() > b[7].size();
}

void listbyPopularity(vector<vector<string>> popularity, ofstream &ofs)
{
    size_t counter = 0;
    ofs << "Films listed by popularity: \n";
    for (const vector<string> fields : popularity)
    {
        if (fields[7] != "")
        {
            ++counter;
            ofs << counter << ". " << fields[2] << ", " << fields[7] << "\n";
        }
    }
    ofs << "\n";
    ofs.flush();
}

void printVector(const vector<int> ivec, ofstream &ofs)
{
    for (auto i : ivec)
    {
        ofs << i << " ";
    }
    ofs.flush();
}

void makeGenreVectors(const vector<vector<string>> &records, vector<int> &genreFilm, const string &input)
{
    for (vector<string> fields : records)
    {
        string genre = fields[3];
        string year = fields[0];
        if (year != " ")
        {
            if (genre == input && year != "")
            {
                genreFilm.push_back(stoi(year));
            }
        }
    }
}

void findFirst(const string &findActor, vector<vector<string>> dvec, ofstream &ofs)
{
    vector<string>::iterator searched;
    vector<string> actors;
    for (const vector<string> fields : dvec)
    {
        string actor = fields[4];
        actors.push_back(actor);
    }
    searched = find(actors.begin(), actors.end(), findActor);

    int position = searched - actors.begin();
    vector<string> fields = dvec[0];
    ofs << "\nThe first film entry starring " << findActor << " from popularity list: \n";
    for (int j = 0; j < fields.size(); ++j)
    {
        ofs << dvec[position][j] << " ";
    }
    ofs << "\n";
    ofs.flush();
}
```

# **Redo Midterm Question**

```
#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

// count the word with the most repeated occurrences in a vector
int main()
{
    set<string> aset;
    vector<string> svec = {"how", "now", "now", "now", "brown", "how", "cow"};
    int currCount, maxCount;
    string currWord, maxWord;
    for (auto it = svec.begin(); it != svec.end(); ++it)
    {
        aset.insert(*it);
    }
    for (auto a : aset)
    {
        currWord = a;
        // using count algorithm
        currCount = count(svec.begin(), svec.end(), a);
        if (currCount > maxCount)
        {
            maxCount = currCount;
            maxWord = currWord;
        }
    }
    cout << maxWord << " had the most repetitions: " << maxCount;

    return 0;
}
```

# **Additional Practice**

> Exercise 10.14: Write a lambda that takes two `ints` and returns its sum

```
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    auto add = [](int a, int b)
    {
        return a + b;
    };
    int a, b;
    cin >> a >> b;
    cout << "The sum of " << a << " + " << b << " using lambda function is : " << add(a, b) << endl;
    return 0;
}
```

> Exercise 10.30: Use stream iterators, `sort`, and `copy` to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.

```
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
```

