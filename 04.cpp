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
		cout << "계좌주: " << name << endl;
		cout << "계좌번호: " << accID << endl;
		cout << "잔액: " << balance << endl;
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
		cout << "몇 번 기능을 이용하시겠습니까? ";
		cin >> cmd;
		cout << endl;

		switch (cmd)
		{
		case MAKE:	// 계좌개설
			MakeAccount();
			break;

		case DEPOSIT:	// 입금
			Deposit();
			break;

		case WITHDRAW:	// 출금
			Withdraw();
			break;

		case SHOW:	// 전체고객 잔액조회
			ShowInfo();
			break;

		case EXIT:	// 프로그램 종료
			cout << "프로그램을 종료합니다." << endl;
			return 0;

		default: // cmd 입력 예외 처리
			cout << "잘못된 입력입니다. 재입력해주세요." << endl;
			break;
		}
	}

	return 0;
}

void ShowMenu(void)
{
	cout << "[ 은행계좌 관리 프로그램 ]" << endl;
	cout << "1. 계좌개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 전체고객 잔액조회" << endl << "5. 프로그램 종료" << endl;
}

void MakeAccount(void)
{
	char name[NAME_LEN];
	int accID;
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌주 입력: ";
	cin >> name;

	cout << "계좌번호 생성: ";
	cin >> accID;

	cout << "입금액: ";
	cin >> balance;

	accArr[accCnt++] = new Account(name, accID, balance);
	cout << endl;
}

void Deposit(void)
{
	int acc;
	int money;

	cout << "[입금]" << endl;
	cout << "입금할 계좌의 계좌번호 입력: ";
	cin >> acc;
	cout << endl;

	for (int i = 0; i < accCnt; i++)
	{
		if (accArr[i]->GetAccID() == acc)
		{
			cout << "입금액: ";
			cin >> money;
			accArr[i]->DepositMoney(money);

			cout << "입금완료" << endl;
			cout << endl;

			accArr[i]->ShowAccInfo();
			cout << endl;

			return;
		}
	}

	cout << "존재하지 않는 계좌입니다." << endl;
	cout << endl;
}

void Withdraw(void)
{
	int acc;
	int money;

	cout << "[ 출금 ]" << endl;
	cout << "출금할 계좌의 계좌번호 입력: ";
	cin >> acc;
	cout << endl;

	for (int i = 0; i < accCnt; i++)
	{
		if (accArr[i]->GetAccID() == acc)
		{
			cout << "출금액: ";
			cin >> money;
			if (accArr[i]->WithdrawMoney(money) == 0)
			{
				cout << "잔액부족" << endl;
				cout << endl;
				return;
			}

			cout << "출금완료" << endl;
			cout << endl;

			accArr[i]->ShowAccInfo();
			cout << endl;

			return;
		}
	}

	cout << "존재하지 않는 계좌입니다." << endl;
	cout << endl;
}

void ShowInfo(void)
{
	cout << "[전체고객 잔액조회]" << endl;

	for (int i = 0; i < accCnt; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}