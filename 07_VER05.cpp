#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LEN 10

enum { MAKE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };

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
	void DepositMoney(int money);
	int WithdrawMoney(int money);
	void ShowAccInfo() const;
	~Account();
};

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
	cout << "������: " << name << endl;
	cout << "���¹�ȣ: " << accID << endl;
	cout << "�ܾ�: " << balance << endl;
}
Account::~Account()
{
	delete[]name;
}

class AccountHandler
{
private:
	Account* accArr[100];
	int accCnt = 0;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowInfo() const;
	~AccountHandler();
};

void AccountHandler::ShowMenu() const
{
	cout << "[ ������� ���� ���α׷� ]" << endl;
	cout << "1. ���°���" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. ��ü�� �ܾ���ȸ" << endl << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount()
{
	char name[NAME_LEN];
	int accID;
	int balance;

	cout << "[���°���]" << endl;
	cout << "������ �Է�: ";
	cin >> name;

	cout << "���¹�ȣ ����: ";
	cin >> accID;

	cout << "�Աݾ�: ";
	cin >> balance;

	accArr[accCnt++] = new Account(name, accID, balance);
	cout << endl;
}

void AccountHandler::Deposit()
{
	int acc;
	int money;

	cout << "[�Ա�]" << endl;
	cout << "�Ա��� ������ ���¹�ȣ �Է�: ";
	cin >> acc;
	cout << endl;

	for (int i = 0; i < accCnt; i++)
	{
		if (accArr[i]->GetAccID() == acc)
		{
			cout << "�Աݾ�: ";
			cin >> money;
			accArr[i]->DepositMoney(money);

			cout << "�ԱݿϷ�" << endl;
			cout << endl;

			accArr[i]->ShowAccInfo();
			cout << endl;

			return;
		}
	}

	cout << "�������� �ʴ� �����Դϴ�." << endl;
	cout << endl;
}

void AccountHandler::Withdraw()
{
	int acc;
	int money;

	cout << "[ ��� ]" << endl;
	cout << "����� ������ ���¹�ȣ �Է�: ";
	cin >> acc;
	cout << endl;

	for (int i = 0; i < accCnt; i++)
	{
		if (accArr[i]->GetAccID() == acc)
		{
			cout << "��ݾ�: ";
			cin >> money;
			if (accArr[i]->WithdrawMoney(money) == 0)
			{
				cout << "�ܾ׺���" << endl;
				cout << endl;
				return;
			}

			cout << "��ݿϷ�" << endl;
			cout << endl;

			accArr[i]->ShowAccInfo();
			cout << endl;

			return;
		}
	}

	cout << "�������� �ʴ� �����Դϴ�." << endl;
	cout << endl;
}

AccountHandler::AccountHandler() :accCnt(0)
{ }

void AccountHandler::ShowInfo() const
{
	cout << "[��ü�� �ܾ���ȸ]" << endl;

	for (int i = 0; i < accCnt; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accCnt; i++)
		delete accArr[i];
}

int main(void)
{
	AccountHandler manager;
	int cmd;

	while (1)
	{
		manager.ShowMenu();
		cout << "�� �� ����� �̿��Ͻðڽ��ϱ�? ";
		cin >> cmd;
		cout << endl;

		switch (cmd)
		{
		case MAKE:	// ���°���
			manager.MakeAccount();
			break;

		case DEPOSIT:	// �Ա�
			manager.Deposit();
			break;

		case WITHDRAW:	// ���
			manager.Withdraw();
			break;

		case SHOW:	// ��ü�� �ܾ���ȸ
			manager.ShowInfo();
			break;

		case EXIT:	// ���α׷� ����
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;

		default: // cmd �Է� ���� ó��
			cout << "�߸��� �Է��Դϴ�. ���Է����ּ���." << endl;
			break;
		}
	}

	return 0;
}