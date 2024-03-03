#pragma once
#include "09_NormalAccount.h"

class HighCreditAccount :public NormalAccount
{
private:
	int creditLank;
public:
	HighCreditAccount(char* name, int id, int money, int rate, int credit);

	int ChangeLanktoRate() const;	// �ſ� ��޺� ������ ����ϱ� ���� ����
	int GetCreditInterest() const;	// �Ա� �� �߰��Ǵ� ��ü ����(�⺻ ���� + �ſ� ��޺� ����) ���
	void DepositMoney(int money);
	void ShowAccInfo() const;		// ���� ���� ���
};

HighCreditAccount::HighCreditAccount(char* name, int id, int money, int rate, int credit)
	:NormalAccount(name, id, money, rate), creditLank(credit)
{ }

int HighCreditAccount::ChangeLanktoRate() const
{
	switch (creditLank)
	{
	case LANK_A:
		return 7;
	case LANK_B:
		return 4;
	case LANK_C:
		return 2;
	default:
		return 0;
	}
}

int HighCreditAccount::GetCreditInterest() const
{
	return (int)(NormalAccount::GetInterest()	// �⺻ ����
		+ (Account::CheckBalance() * (ChangeLanktoRate() / 100.0)));	// �ſ� ��޺� ����
}

void HighCreditAccount::DepositMoney(int money)
{
	Account::DepositMoney(GetCreditInterest());
	Account::DepositMoney(money);
}

void HighCreditAccount::ShowAccInfo() const
{
	NormalAccount::ShowAccInfo();
	cout << "�ſ� ���: ";// << creditLank << endl;
	if (creditLank == 1)
		cout << "A" << endl;
	else if (creditLank == 2)
		cout << "B" << endl;
	else
		cout << "C" << endl;
	cout << "�ſ� ��޿� ���� �߰� ����: " << ChangeLanktoRate() << "%" << endl;
}
