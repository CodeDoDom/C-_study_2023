#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LEN 10

void ShowMenu(void);
void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void ShowInfo(void);

enum {MAKE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT};

class Account
{
private:
	char* name;
	int accID;
	int balance;
public:
	Account(char* _name, int _accID, int _balance)
		:accID(_accID), balance(_balance)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	int GetAccID()
	{
		return accID;
	}
	void DepositMoney(int money)
	{
		balance += money;
	}
	int WithdrawMoney(int money)
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}
	void ShowAccInfo() const
	{
		cout << "������: " << name << endl;
		cout << "���¹�ȣ: " << accID << endl;
		cout << "�ܾ�: " << balance << endl;
	}
	~Account()
	{
		delete[]name;
	}
};

Account* accArr[100];
int accCnt = 0;

int main(void)
{
	int cmd;

	while (1)
	{
		ShowMenu();
		cout << "�� �� ����� �̿��Ͻðڽ��ϱ�? ";
		cin >> cmd;
		cout << endl;

		switch (cmd)
		{
		case MAKE:	// ���°���
			MakeAccount();
			break;

		case DEPOSIT:	// �Ա�
			Deposit();
			break;

		case WITHDRAW:	// ���
			Withdraw();
			break;

		case SHOW:	// ��ü�� �ܾ���ȸ
			ShowInfo();
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

void ShowMenu(void)
{
	cout << "[ ������� ���� ���α׷� ]" << endl;
	cout << "1. ���°���" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. ��ü�� �ܾ���ȸ" << endl << "5. ���α׷� ����" << endl;
}

void MakeAccount(void)
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

void Deposit(void)
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

void Withdraw(void)
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

void ShowInfo(void)
{
	cout << "[��ü�� �ܾ���ȸ]" << endl;

	for (int i = 0; i < accCnt; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}