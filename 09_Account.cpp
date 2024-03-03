#include "09_BankingCommonDec1.h"
#include "09_Account.h"

Account::Account(char* _name, int _accID, int _balance)
	:accID(_accID), balance(_balance)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}
Account::Account(const Account& copy)
	:accID(copy.accID), balance(copy.balance)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}
int Account::GetAccID() const
{
	return accID;
}
void Account::DepositMoney(int money)
{
	balance += money;
}
int Account::WithdrawMoney(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}
void Account::ShowAccInfo() const
{
	cout << "°èÁÂÁÖ: " << name << endl;
	cout << "°èÁÂ¹øÈ£: " << accID << endl;
	cout << "ÀÜ¾×: " << balance << endl;
}
int Account::CheckBalance() const	// ÅëÀå ÀÜ°í È®ÀÎ¿ë
{
	return balance;
}
Account::~Account()
{
	delete[]name;
}