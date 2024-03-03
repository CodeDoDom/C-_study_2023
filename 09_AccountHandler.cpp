#include "09_BankingCommonDec1.h"
#include "09_AccountHandler.h"
#include "09_Account.h"	// 꼭 필요한가?? AccountHandler 헤더에 이미 포함되어 있는데?
#include "09_NormalAccount.h"
#include "09_HighCreditAccount.h"

void AccountHandler::ShowMenu() const
{
	cout << "[ 은행계좌 관리 프로그램 ]" << endl;
	cout << "1. 계좌개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 전체고객 잔액조회" << endl << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount()
{
	int choice;

	cout << "[계좌개설]" << endl;
	while (1)
	{
		cout << "어떤 종류의 계좌를 개설하시겠습니까?(1번. 보통예금계좌, 2번. 신용신뢰계좌): ";
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

void AccountHandler::MakeCreditAccount()
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
