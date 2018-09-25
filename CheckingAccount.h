
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "BankAccount.h"
class CheckingAccount : public BankAccount
//class CheckingAccount
{
    public:
        //Constructor
        CheckingAccount() : BankAccount()
        {
            checkBalance = 0;
            monthlyServiceCharge = 0;
            numberOfWitDraw = 0;}
        //Destructor
        virtual ~CheckingAccount();
        //withDraw function
        void withDraw(float, bool);
        //monthlyProc function
        void monthlyProc();

    protected:
    private:
        //Temporary variable for now
        int checkBalance;
        int monthlyServiceCharge;
        //int withDrawCounter; // Needs to be static??
        int numberOfWitDraw;
};

#endif // CHECKINGACCOUNT_H
