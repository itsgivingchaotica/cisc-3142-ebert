#include <iostream>
#include "Account.h"

using std::cout;

int main()
{
    cout << "Starting interest rate: " << Account::rate() << '\n';
    double initialBalance = 894785.22;
    Account acct("Williams", initialBalance);
    acct.calculate();
    printf("The initial balance was: %.2f\nBalance after interest: %.2f\nWith interest rate: %.2f\n", initialBalance, acct.balance(), acct.rate());
    //cout << "The initial balance was: " << initialBalance << " , balance after interest: " << acct.balance() << " with interest rate: " << acct.rate() << '\n';
    Account::rate(0.025);
    acct.calculate();
    printf("New balance: %.2f with new interest rate of %.2f", acct.balance(), acct.rate());
    //cout << "New balance: " << acct.balance() << " with interest rate: " << acct.rate() << '\n';

return 0;
}
/**
 * 
*/