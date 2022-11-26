#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    //fstream object file
    ifstream file("film.csv.txt");
    ofstream ofs("results.csv.txt",ofstream::out);
    //nested vector to hold all film records
    vector<vector<string>> records;
    string line,word;

    if (file.is_open()){
        //skip first two lines
        getline(file,line);
        getline(file,line);
        //create the nested vector
        while (getline(file, line)) {
            istringstream iss(line);
            vector<string> fields;
            string str;
            while(getline(iss,str,';')){
                fields.push_back(str);
            }
            records.push_back(fields);
        }
    } else {
        cerr << "could not read file" << endl;
    }
    double averageLength;
    double length=0;

    //calculate the average length of time for the films - average running length
    for (const vector<string> fields : records)
    {
        if (fields[1]!="")
        {
            double l = stod(fields[1]);
            length+=l;
        }
    }
    averageLength = (length/records.size());
    ofs << "The average running length of the films is " << averageLength << " minutes\n\n";

    //sort the nested vector by decade
    vector<vector<string>>decadeRecords = records;
    sort(decadeRecords.begin(), decadeRecords.end(), [](const vector<string>& a, const vector<string>& b)
    {
        return a[0] < b[0];
    });
    //determine the average running time of the films by decade. using sorted by year 2d vector
    vector<string> years;
    string prevYear = decadeRecords[0][0].substr(0,3);
    double rLength=0;
    size_t count=0;
    for (const vector<string> decade : decadeRecords)
    {
        //if there is a year, the running length is not null and the field is a film from the previous year
        if (decade[0]!="" && decade[1]!="" && (decade[0].substr(0,3) == prevYear))
        {
            double l = stod(decade[1]);
            rLength+=l;
        }
        if ((decade[0].substr(0,3) != prevYear) && decade[1]!="" && decade[0]!="")
        {
            ofs << prevYear << "0's average film length: " << (rLength/count) << "\n";
            count = 0;
            rLength = 0;
            double l = stod(decade[1]);
            rLength+=l;
        }
        
        prevYear = decade[0].substr(0,3);
        count++;
    }
    ofs << prevYear << "0's average film length: " << (rLength/count) << "\n\n";
    //sort the original record vector by genre
    vector<vector<string>>genreRecords = records;
    sort(genreRecords.begin(), genreRecords.end(), [](const vector<string>& a, const vector<string>& b)
    {
        return a[3] < b[3];
    });
    //find the directors who have received awards in the different genres
    vector<string> directors;
    string prev = genreRecords[0][3];
    size_t awardscount = 0;
    for (const vector<string> genre : genreRecords)
    {
        vector<string>::iterator it;
        string current = genre[3];
        string director = genre[6];
        if (current == prev){
            //if awarded and genre is not blank
            if ((genre[8] == "Yes" || genre[8] == "yes") && (current != "") && 
                ((it = find(directors.begin(), directors.end(), director)) == directors.end() && (director != "")))
            {
                directors.push_back(director);
                awardscount++;  
            }
         }
        else {
            //if a different genre, print number of directors with awards to ouput file
            if (prev != "")
            {
                ofs << "\n" << prev << " genre: " << awardscount << " director(s) have won awards\n\n";
            }
            //print the directors who received awards to output file
            for (const auto& d : directors)
            {
                ofs << d << "\n";
            }
            awardscount = 0;
            //clear the directors vector which keeps track of the directors by genre and begin to refill
            directors.clear();
            if (genre[8] == "Yes" || genre[8] == "yes" && director != "" && current != "")
            {
                    directors.push_back(director);
                    awardscount++;  
            }
        }
        prev = current;
    }
    //close output file
    ofs.close();

    return 0;   
}