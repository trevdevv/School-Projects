#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::~CheckingAccount()
{
    //dtor
}

//******************************************************
// monthlyProc() function will add a monthly fee of
// $5 plus $0.10 per withdrawl to the base class variable
// that holds the monthly service charge
//*******************************************************
void CheckingAccount::monthlyProc()
{
    // I will add a monthly fee of $5 plus .10 times the withdrawl
    // variable to the baeclass member monthlyServiceCharge
    // So i need to know how many times ive withdrawn
    monthlyServiceCharge = (5+(.10*numberOfWitDraw));
}

//******************************************************
// widthDraw() function will have one arguement of desired
// withdralwl amount . it will  1st determine if the
// deseried withdrawl amount will not cause balance < 0
// If it does $15 will be decuted from base calss member
// of the balance variable
//******************************************************

void CheckingAccount::withDraw(float withDrawAmount, bool a)
        {
            //If statement to determine if whatever is being withdrawn
            // will cause balance to go less than 0
            if(checkBalance < 0)
            {
                //Let user know that the withdrawl cannot be made
                // since balance is less than 0
                cout << "Error. Balance is less than 0\n";
                // let user know $15 will be deducted
                cout << "$15 will be dedecuted from balance\n";
                //I will access the base class variable of balance & subtract $15 from it
                checkBalance -= 15;

            }
        }

