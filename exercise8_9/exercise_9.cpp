#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::string;
using std::istringstream;
using std::cout;
using std::cerr;
using std::endl;

int main(){
    ifstream file("weather.csv.txt");
    ofstream ofs("weatherData.txt", ofstream::out);
    //nested vector of months / temperatures
    vector<vector<string>> temperatures;
    string line;

    if (file.is_open())
    {
        getline(file,line);
        while (getline(file,line)){
            istringstream iss(line);
            vector<string> fields;
            string str;
            while (getline(iss,str,',')){
                fields.push_back(str);
            }
            temperatures.push_back(fields);
        }
    } else {
        cerr << "Could not read file" << endl;
    }
    ofs << "The following temperatures were recorded: \n";
    for (const vector<string> fields : temperatures) {
        for (const auto &f : fields)
        {
            ofs << f << " ";
        }
        ofs << "\n";
    }
    double simpleSum = 0.0;
    double simpleAverage;
    double movingSum = 0.0;
    double movingAverage;
    double weightedMovingSum = 0.0;
    double weightedMovingAverage;
    int month=0;
    //calculate the simple average across all months
    for (const vector<string> fields : temperatures)
    {
        double simple = stod(fields[1]);
        simpleSum+=simple;
    }
    simpleAverage = (simpleSum/temperatures.size());
    ofs << "\nThe simple average across all months is: " << simpleAverage << " degrees Fahrenheit\n\n";
    //now calculatd the moving average
    ofs << "Moving averages across 3 months: \n";
    //must iterate up until the month third from the end 
    for (int i = 0; i <= temperatures.size()-3; ++i)
    {
        //iterate for 3 months
        for (int j = i; j < i+3; ++j)
        {
            movingSum+=stod(temperatures[j][1]);
            month++;
        }
        //calculate the moving average for the 3 months
        movingAverage = movingSum/3;
        ofs << temperatures[month-1][0] << ": " << movingAverage << "\n";
        //set sum back to zero and begin 2 months back to start
        //the moving average for the next month
        movingSum=0;
        month = month-2;
    }
    //now calculated the weighted moving average
    month = 0;
    ofs << "\nWeighted moving average across 3 months: \n";
    for (int k = 0; k <= temperatures.size()-3; ++k)
    {
        int weight = 0;
        for (int l = k; l < k+3; ++l)
        {
            //for each month, we weight the temperature
            ++weight;
            weightedMovingSum+=stod(temperatures[l][1])*weight;
            ++month;
            
        }

        weightedMovingAverage = weightedMovingSum/(weight+(weight-1)+(weight-2));
        ofs << temperatures[month-1][0] << ": " << weightedMovingAverage << "\n";
        //reset for next month weight moving average
        weightedMovingSum=0;
        month = month-2;
    }
    ofs.close();
    return 0;
}