#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>
using namespace std;



//annual intrest rate
const float INTEREST = .17;

//monthly fee
const float MONTHLYFEE = 5.00;

//files name.
const string checkBalance0 = "check_balance.txt";  // checking balance file.
const string saveBalance0 = "save_balance.txt";   // saveing balance file
const string depositNum = "depositnum.txt";  //number of deposit file.
const string withdrawNum = "withdrawNum.txt";  // number of withdraws file.
const string monthlyServiceCh = "monthlySerCharge.txt"; // monthly service charge file.
const string end_check_balance = "end_check_balance.txt"; //end of month checking balance
const string end_save_balance = "end_save_balance.txt";  //end of month saving balance
const string total_withdraw = "total_withdraw.txt";  //total withdraw amount
const string total_deposit = "total_deposit.txt"; //total deposit amount

//base class
class BankAccount
{
    protected:
        float checkBalance; // when the author said balance, i am not sure if he meant checking and saving balance, so i decide to be explicit and have both
        float endOfMonthSbalance;  // to store end of month saving balance
        float endOfmonthCbalance;  // to store end of month checking balance
        float savingBalance; //saving balance
        int numberOfWitdraw;  //number of withdraw per month
        int numberOfdeposit;  // number of deposit per month
        float totalWithdraw; // total deposit amount
        float totalDeposit;  // total withdraw amount
        float annualInterestRate;  // annual interest rate, this member variable will read in the const variable INTEREST.
        float monthlyServiceCharge;  // monthly charge service, this member variable willr ead in the const variable MONTHLYFEE.
        fstream file0;   // file stream object


    public:

		//file i/0
		float readFromFile(fstream &file, const string fileName); //read from file

		template <class T>
		void writeToFile(fstream &file, string fileName, T a);  //write to files


        //default constructor
        BankAccount();

        //constructor
        BankAccount(float cb, float sb)  //since the author didnt specify checking or saving balance, i assuming he meant both
        {
        	checkBalance = cb;
        	savingBalance = sb;

		}

   		//destructor
        //~BankAccount(){}

		//get checking and saving balance.
        //accessors
        float getcheckB() const  //inline function. get checking balance
        {
        	return checkBalance;
		}

		float getsaveB() const //inline function. get saving balance
        {
        	return savingBalance;
		}

		int getNumDepo() const //get number of deposit
		{
			return numberOfdeposit;
		}

		int getNumWith() const //get number of withdraw
		{
			return numberOfWitdraw;
		}

		float endofMonthSba() const //get previouse end of month saving balance
		{
			return endOfMonthSbalance;
		}

		float endofMonthCba() const  //get get previouse end of month checking balance
		{
			return endOfmonthCbalance;
		}

		float totalWithdr()  const  //get total withdraw amount
		{
			return totalWithdraw;
		}

		float totalDeposi() const // get total deposit amount
		{
			return totalDeposit;
		}


        //mutators

        //end of month balance
        void endOfmonthBalance()
        {
        	endOfMonthSbalance = savingBalance;
        	endOfmonthCbalance = checkBalance;

		}
        virtual void deposit(float deposistAmount, bool b)   //inline function
        {
        	if (b == true) // flag for deposit to checking acount
        	{
        		checkBalance = checkBalance + deposistAmount;
			}
			else if (b == false) // flag for deoisut to saving acount
			{
				savingBalance = savingBalance + deposistAmount;
			}

			totalDeposit = totalDeposit + deposistAmount; // accumulate total deposits amount.
			numberOfdeposit++; //increment number of deposit by one
			return;
		}

	   virtual void withdraw(float withdrawAmount, bool a)  //inline function
        {
        	if (a == true) // flag for withdraw from checking acount
        	{
        		checkBalance = checkBalance - withdrawAmount;
			}
			else if (a == false) // flag for withdraw from saving acount
			{
				savingBalance = savingBalance - withdrawAmount;
			}

			totalWithdraw = totalWithdraw + withdrawAmount; //accumulate withdraws amount
			numberOfWitdraw++;  //increment number of withdraw by one
			return;
		}
		//caLcInt is not a virtual function because it is not needed, it is the only function that available in BankAccount class.
        void calcInt();    //this calculation done one per month, only available to bank's employee.
        virtual void monthlyProc();  //only available to bank employee.
        void writeToFiles();



};

float BankAccount::readFromFile(fstream &file, const string fileName)
{
	float ans;
	file.open(fileName.c_str(), ios::in);

	if (file.fail())
	{
		cout << "error" << endl;
	}
	else
	{
		file >> ans;

	}

	file.close();
	return ans;
}

template <class T>
void BankAccount::writeToFile(fstream &file, string fileName, T a) //member variable of base class have more than one data type, implement of template class is need.
{

	file.open(fileName.c_str(), ios::out);

	if (file.fail())
	{
		cout << "error" << endl;
	}

	file << a;
	file.close();
	return;
}

BankAccount::BankAccount()  //constructor body, initialize all members when object of BankAccount class is declare.
{
	annualInterestRate = INTEREST;
	checkBalance = readFromFile(file0, checkBalance0); //read from file
	savingBalance = readFromFile(file0, saveBalance0); //read from file
	monthlyServiceCharge = readFromFile(file0, monthlyServiceCh); //read from file
	numberOfdeposit = static_cast<int>(readFromFile(file0, depositNum));  // number of deposit from file. Since read in member function only read float format, type_cast is needed for for different data type.
	numberOfWitdraw = static_cast<int>(readFromFile(file0, withdrawNum));  // number of withdraw from file.
	endOfMonthSbalance = readFromFile(file0,end_save_balance); //read from file
	endOfmonthCbalance = readFromFile(file0,end_check_balance); //read from file
	totalWithdraw = readFromFile(file0, total_withdraw); //read from file
	totalDeposit = readFromFile(file0,total_deposit); //read from file

}

void BankAccount::writeToFiles() // write to files
{
	writeToFile(file0, checkBalance0, checkBalance); // write check balance to file
	writeToFile(file0, saveBalance0, savingBalance); //write saving balance to file
	writeToFile(file0, monthlyServiceCh, monthlyServiceCharge);  //write monthly service charge to file
	writeToFile(file0, withdrawNum, numberOfWitdraw);  // write number of withdraws to file
	writeToFile(file0, end_save_balance, endOfMonthSbalance);  //write end of month saving balance to file
	writeToFile(file0, end_check_balance, endOfmonthCbalance);  //write end of month checking balance to file
	writeToFile(file0, total_withdraw, totalWithdraw);  //write total withdraw amount to file
	writeToFile(file0, total_deposit, totalDeposit);  //write total deposit amount to file
	writeToFile(file0, depositNum, numberOfdeposit);  //write number of deposits to file

	return;
}


//calcInt function is design to update saving balance, because saving balance is the only account benefit the monthly annual interest rate.
void BankAccount::calcInt()
{
	float m; //monthly interest rate
	float i; //monthly interest

	m = (INTEREST/12);  //(annual interest rate / 12)
	i = savingBalance * m; // monthly interest
	savingBalance = savingBalance + i; //saving balance is update.
	return;
}

void BankAccount::monthlyProc()
{
	savingBalance = savingBalance - monthlyServiceCharge;  //I assume he meant subtract monthly  service charge from saving balance.
	calcInt();   // call and invoke calInt funtion.
	numberOfWitdraw = 0;  //reset to zero
	numberOfdeposit = 0; //reset to zero
	monthlyServiceCharge = 0;  //reset to zero
	totalWithdraw = 0;  //reset to zero
	totalDeposit = 0;  //reset to zero

	return;
}
