#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::begin;
using std::end;
using std::setprecision;

/** getAverage finds the average spend or sales 
 * ivec : the vector of sales or spend figures
 * return : the average spend or sales
 **/
double getAverage (vector<double> ivec)
{
    float sum;
    for (auto &i : ivec)
    {
        sum += i;
    }
    float avg = sum / ivec.size();

    return avg;
}

/** sumOfSquaresXX finds the SSxx value needed to determine slope, the regression coefficient
 * &xDiff : a reference to the vector of Avg(spend) - spend of each month
 * return : the sum of squares for the variance in X
 **/
double sumOfSquaresXX (vector<double> &xDiff)
{
    double sSxx;
    for (auto xd : xDiff)
    {   
        sSxx += xd*xd;
    }
    return sSxx;
}

/** sumOfSquaresXY finds the SSxy value needed to determine slope, the regression coefficient
 * &xvec : a reference to the vector of spending values for each month
 * &yvec : a reference to the vector of sales for each month
 * return : the sum of squares of the covariance of X and Y
 **/
double sumOfSquaresXY (vector<double> &xvec, vector<double> &yvec)
{
    vector<double> sums(xvec.size());
    double product, sSxy;
    //cout << " Average X - x * AvgY - y: " << endl;
    for (int i = 0; i != xvec.size(); ++i)
    {
        product = xvec[i] * yvec[i];
        //cout << "(" << product << ") " << endl;
        sums.push_back(product);
    }
    for (auto &s : sums)
    {
        sSxy += s;
    }
    return sSxy;
}

/** findDifference finds the difference between average of the elements 
 * across the vector and each element in the vector
 * avg : the average of X or Y - spending or sales
 * dvec : the vector of X or Y values
 * return : a vector of differences to be used later to determine SSxy
 **/
vector<double> findDifference(double avg, vector<double> dvec)
{
    vector<double> diffVec;
    double diff;
    //cout << "The difference is: " << endl;
    for (auto &d : dvec)
    {
        diff = avg - d;
        //cout << diff << endl;
        diffVec.push_back(diff);
    }
    return diffVec;

}

/** getLinearRegression finds the sales based on the equation determined by the program based on spending
 * intercept: AVG(Y) - slope * Avg(X)
 * slope : SSxy / SSxx
 * spend : the initial spend value to plug into x
 * return sales : the projeted sales based on spending
 **/
double getLinearRegression(double intercept, double slope, double spend)
{
    double sales = 0.00;

    sales = intercept + slope * spend;

    return sales;

}

int main()
{
    vector<double> xvec, yvec;
    vector<double> xDiff, yDiff;
    double x, y, avgX, avgY, sSxx, sSxy, slope, intercept;
    //import data spend and sale values
    ifstream input("data.txt");
    while (input >> x >> y)
    {
        xvec.push_back(x);
        yvec.push_back(y);
    }
    //find average of spend and sales values
    avgX = getAverage(xvec);
    avgY = getAverage(yvec);
    //for each month, calculate the Avg(spending) - spend, Avg(sales) - sales 
    //to use later as SSXy to determine slope - the regression coefficient
    xDiff = findDifference(avgX, xvec);
    yDiff = findDifference(avgY, yvec);
    //to find the variance in spending
    sSxx = sumOfSquaresXX(xDiff);
    //SSxy is the covariance of spending and sales
    sSxy = sumOfSquaresXY(xDiff,yDiff);
    //slope is sum of squares covariance of spend and sales divided by sum of sqaures varianceo of spend
    slope = sSxy / sSxx;
    //intercept is the sales average minus the regression coefficient times the spending average
    intercept = avgY - slope * avgX;
    //print the linear regression equation to console
    cout << "Linear regression equation for 12 Month Marketing Budget " <<
    "and Sales is as follows: y = " << intercept << " + " << slope << "*x" << endl;
   
    //USER INPUT
    //plug in how much you project to spend and determine out the projected sales
    double spend;
    cout << "Enter your projected spending for the month: $";
    while (cin >> spend)
    {
        cout << "Projected sales: $";
        printf("%.2f\n", getLinearRegression(intercept,slope,spend));
        cout << "Next projected spending, Ctrl +D to quit: ";
    }

    return 0;
}