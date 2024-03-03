#include "09_BankingCommonDec1.h"
#include "09_AccountHandler.h"
#include "09_Account.h"	// �� �ʿ��Ѱ�?? AccountHandler ����� �̹� ���ԵǾ� �ִµ�?
#include "09_NormalAccount.h"
#include "09_HighCreditAccount.h"

void AccountHandler::ShowMenu() const
{
	cout << "[ ������� ���� ���α׷� ]" << endl;
	cout << "1. ���°���" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. ��ü�� �ܾ���ȸ" << endl << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount()
{
	int choice;

	cout << "[���°���]" << endl;
	while (1)
	{
		cout << "� ������ ���¸� �����Ͻðڽ��ϱ�?(1��. ���뿹�ݰ���, 2��. �ſ�ŷڰ���): ";
		cin >> choice;

		switch (choice)
		{
		case NORMAL:
			MakeNormalAccount();
			return;
		case CREDIT:
			MakeCreditAccount();
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

void AccountHandler::MakeCreditAccount()
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
