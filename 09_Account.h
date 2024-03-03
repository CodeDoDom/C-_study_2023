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
	virtual void ShowAccInfo() const;	// ���� �Լ�: ���� �Լ��� ����ϸ� ������ �Լ� ȣ�⿡ ���� ���� �ٸ� Ŭ������ �Լ��� ����� �� ����
	int CheckBalance() const;	// ���� �ܰ� Ȯ�ο�
	~Account();
};