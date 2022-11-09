#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using std::string;

class Account 
{
    public:
        Account() = default;
        Account(string name) : owner(name) { }
        Account(string name, double amt) : owner(name), amount(amt) { }
        double balance() const { return amount; }
        void calculate()
        {
            amount += amount * interestRate; 
        }
        static double rate() 
        {
            return interestRate;
        }
        static void rate(double);
    private:
        string owner;
        double amount;
        static double interestRate;
        static double initRate();
};

double Account::interestRate = initRate();

double Account::initRate()
{
    return 0.05; // 5 percent
}

void Account::rate(double newRate)
{
    interestRate = newRate;
}


#endif