#pragma once
#include "09_Account.h"

class NormalAccount :public Account
{
private:
	int interestRate;
public:
	NormalAccount(char* name, int id, int money, int rate);

	int GetInterest() const;	// �Ա� �� �߰��Ǵ� �⺻���� ���
	void DepositMoney(int money);
	void ShowAccInfo() const;	// ���� ���� ���
};

NormalAccount::NormalAccount(char* name, int id, int money, int rate)
	:Account(name, id, money), interestRate(rate)
{ }

int NormalAccount::GetInterest() const
{
	return (int)(Account::CheckBalance() * (interestRate / 100.0));
}

void NormalAccount::DepositMoney(int money)
{
	Account::DepositMoney(GetInterest());
	Account::DepositMoney(money);
}

void NormalAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "����: " << interestRate << "%" << endl;
}
