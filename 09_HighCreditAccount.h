#pragma once
#include "09_NormalAccount.h"

class HighCreditAccount :public NormalAccount
{
private:
	int creditLank;
public:
	HighCreditAccount(char* name, int id, int money, int rate, int credit);

	int ChangeLanktoRate() const;	// 신용 등급별 이율을 계산하기 위해 만듦
	int GetCreditInterest() const;	// 입금 시 추가되는 전체 이자(기본 이자 + 신용 등급별 이자) 계산
	void DepositMoney(int money);
	void ShowAccInfo() const;		// 계좌 정보 출력
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
	return (int)(NormalAccount::GetInterest()	// 기본 이자
		+ (Account::CheckBalance() * (ChangeLanktoRate() / 100.0)));	// 신용 등급별 이자
}

void HighCreditAccount::DepositMoney(int money)
{
	Account::DepositMoney(GetCreditInterest());
	Account::DepositMoney(money);
}

void HighCreditAccount::ShowAccInfo() const
{
	NormalAccount::ShowAccInfo();
	cout << "신용 등급: ";// << creditLank << endl;
	if (creditLank == 1)
		cout << "A" << endl;
	else if (creditLank == 2)
		cout << "B" << endl;
	else
		cout << "C" << endl;
	cout << "신용 등급에 따른 추가 이율: " << ChangeLanktoRate() << "%" << endl;
}
