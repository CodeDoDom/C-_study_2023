#pragma once

class Account
{
private:
	char* name;
	int accID;
	int balance;
public:
	Account(char* _name, int _accID, int _balance);
	Account(const Account& copy);

	int GetAccID() const;
	virtual void DepositMoney(int money);
	int WithdrawMoney(int money);
	virtual void ShowAccInfo() const;	// 가상 함수: 가상 함수를 사용하면 동일한 함수 호출에 대해 서로 다른 클래스의 함수가 실행될 수 있음
	int CheckBalance() const;	// 통장 잔고 확인용
	~Account();
};