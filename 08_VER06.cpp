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
	virtual void ShowAccInfo() const;	// 가상 함수: 가상 함수를 사용하면 동일한 함수 호출에 대해 서로 다른 클래스의 함수가 실행될 수 있음
	int CheckBalance() const;	// 통장 잔고 확인용
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
	cout << "계좌주: " << name << endl;
	cout << "계좌번호: " << accID << endl;
	cout << "잔액: " << balance << endl;
}
int Account::CheckBalance() const	// 통장 잔고 확인용
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

	int GetInterest() const;	// 입금 시 추가되는 기본이자 계산
	void ShowAccInfo() const;	// 계좌 정보 출력
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
	cout << "이율: " << interestRate << "%" << endl;
}

class HighCreditAccount :public NormalAccount
{
private:
	int creditLank;
public:
	HighCreditAccount(char* name, int id, int money, int rate, int credit);

	int ChangeLanktoRate() const;	// 신용 등급별 이율을 계산하기 위해 만듦
	int GetCreditInterest() const;	// 입금 시 추가되는 (기본 이자 + 신용 등급별 이자) 계산
	void ShowAccInfo() const;		// 계좌 정보 출력
};

HighCreditAccount::HighCreditAccount(char* name, int id, int money, int rate, int credit)
	:NormalAccount(name, id, money, rate), creditLank(credit)
{ }

int HighCreditAccount::ChangeLanktoRate() const
{
	if (creditLank == 1)		// A 등급
		return 7;
	else if (creditLank == 2)	// B 등급
		return 4;
	else						// C 등급
		return 2;
}

int HighCreditAccount::GetCreditInterest() const
{
	return (int)(NormalAccount::GetInterest()	// 기본 이자
		+ (Account::CheckBalance() * (ChangeLanktoRate() / 100.0)));	// 신용 등급별 이자
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
	cout << "[ 은행계좌 관리 프로그램 ]" << endl;
	cout << "1. 계좌개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 전체고객 잔액조회" << endl << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount()
{
	int choice;

	cout << "[계좌개설]" << endl;
	while(1)
	{
		cout << "어떤 종류의 계좌를 개설하시겠습니까?(1번. 보통예금계좌, 2번. 신용신뢰계좌): ";
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
			cout << "잘못된 입력입니다. 재입력해주세요." << endl;
		}
	}
}

void AccountHandler::MakeNormalAccount()
{
	char name[NAME_LEN];
	int accID;
	int balance;
	int rate;
	
	cout << "[보통예금계좌 생성]" << endl;
	cout << "계좌주 입력: ";
	cin >> name;

	cout << "계좌번호 생성: ";
	cin >> accID;

	cout << "입금액: ";
	cin >> balance;

	cout << "이율(정수 입력): ";
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

	cout << "[신용신뢰계좌 생성]" << endl;
	cout << "계좌주 입력: ";
	cin >> name;

	cout << "계좌번호 생성: ";
	cin >> accID;

	cout << "입금액: ";
	cin >> balance;

	cout << "이율: ";
	cin >> rate;

	cout << "신용 등급(1. A 등급, 2. B 등급, 3. C 등급): ";
	cin >> credit;

	accArr[accCnt++] = new HighCreditAccount(name, accID, balance, rate, credit);
	cout << endl;
}

void AccountHandler::Deposit()
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

void AccountHandler::Withdraw()
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

AccountHandler::AccountHandler() :accCnt(0)
{
	for (int i = 0; i < 100; ++i)
		accArr[i] = nullptr;
}

void AccountHandler::ShowInfo() const
{
	cout << "[전체고객 잔액조회]" << endl;

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
		cout << "몇 번 기능을 이용하시겠습니까? ";
		cin >> cmd;
		cout << endl;

		switch (cmd)
		{
		case MAKE:	// 계좌개설
			manager.MakeAccount();
			break;

		case DEPOSIT:	// 입금
			manager.Deposit();
			break;

		case WITHDRAW:	// 출금
			manager.Withdraw();
			break;

		case SHOW:	// 전체고객 잔액조회
			manager.ShowInfo();
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