#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 20;

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
	virtual void ShowAccInfo() const;	// ���� �Լ�: ���� �Լ��� ����ϸ� ������ �Լ� ȣ�⿡ ���� ���� �ٸ� Ŭ������ �Լ��� ����� �� ����
	int CheckBalance() const;	// ���� �ܰ� Ȯ�ο�
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
int Account::CheckBalance() const	// ���� �ܰ� Ȯ�ο�
{
	return balance;
}
Account::~Account()
{
	delete[]name;
}

class NormalAccount :public Account
{
private:
	int interestRate;
public:
	NormalAccount(char* name, int id, int money, int rate);

	int GetInterest() const;	// �Ա� �� �߰��Ǵ� �⺻���� ���
	void ShowAccInfo() const;	// ���� ���� ���
};

NormalAccount::NormalAccount(char* name, int id, int money, int rate)
	:Account(name, id, money), interestRate(rate)
{ }

int NormalAccount::GetInterest() const
{
	return (int)(Account::CheckBalance() * (interestRate / 100.0));
}

void NormalAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "����: " << interestRate << "%" << endl;
}

class HighCreditAccount :public NormalAccount
{
private:
	int creditLank;
public:
	HighCreditAccount(char* name, int id, int money, int rate, int credit);

	int ChangeLanktoRate() const;	// �ſ� ��޺� ������ ����ϱ� ���� ����
	int GetCreditInterest() const;	// �Ա� �� �߰��Ǵ� (�⺻ ���� + �ſ� ��޺� ����) ���
	void ShowAccInfo() const;		// ���� ���� ���
};

HighCreditAccount::HighCreditAccount(char* name, int id, int money, int rate, int credit)
	:NormalAccount(name, id, money, rate), creditLank(credit)
{ }

int HighCreditAccount::ChangeLanktoRate() const
{
	if (creditLank == 1)		// A ���
		return 7;
	else if (creditLank == 2)	// B ���
		return 4;
	else						// C ���
		return 2;
}

int HighCreditAccount::GetCreditInterest() const
{
	return (int)(NormalAccount::GetInterest()	// �⺻ ����
		+ (Account::CheckBalance() * (ChangeLanktoRate() / 100.0)));	// �ſ� ��޺� ����
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

class AccountHandler
{
private:
	Account* accArr[100];
	int accCnt;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void MakeNormalAccount();
	void MakeHighCreditAccount();
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
	int choice;

	cout << "[���°���]" << endl;
	while(1)
	{
		cout << "� ������ ���¸� �����Ͻðڽ��ϱ�?(1��. ���뿹�ݰ���, 2��. �ſ�ŷڰ���): ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			MakeNormalAccount();
			return;
		case 2:
			MakeHighCreditAccount();
			return;
		default:
			cout << "�߸��� �Է��Դϴ�. ���Է����ּ���." << endl;
		}
	}
}

void AccountHandler::MakeNormalAccount()
{
	char name[NAME_LEN];
	int accID;
	int balance;
	int rate;
	
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "������ �Է�: ";
	cin >> name;

	cout << "���¹�ȣ ����: ";
	cin >> accID;

	cout << "�Աݾ�: ";
	cin >> balance;

	cout << "����(���� �Է�): ";
	cin >> rate;

	accArr[accCnt++] = new NormalAccount(name, accID, balance, rate);
	cout << endl;
}

void AccountHandler::MakeHighCreditAccount()
{
	char name[NAME_LEN];
	int accID;
	int balance;
	int rate;
	int credit;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "������ �Է�: ";
	cin >> name;

	cout << "���¹�ȣ ����: ";
	cin >> accID;

	cout << "�Աݾ�: ";
	cin >> balance;

	cout << "����: ";
	cin >> rate;

	cout << "�ſ� ���(1. A ���, 2. B ���, 3. C ���): ";
	cin >> credit;

	accArr[accCnt++] = new HighCreditAccount(name, accID, balance, rate, credit);
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
{
	for (int i = 0; i < 100; ++i)
		accArr[i] = nullptr;
}

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