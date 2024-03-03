#pragma once
#include "09_Account.h"

class AccountHandler
{
private:
	Account* accArr[100];
	int accCnt;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowInfo() const;
	~AccountHandler();
protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};
