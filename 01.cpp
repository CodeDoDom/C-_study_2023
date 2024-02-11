#include <iostream>
using namespace std;

#define NAME_LEN 10

typedef struct info
{
	int accID;
	char name[NAME_LEN];
	int balance;
} Info;

Info clients[100];
int cliNum = 0;

void ShowMenu(void);
void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void ShowInfo(void);

int main(void)
{
	int cmd;
	
	while(1)
	{
		ShowMenu();
		cin >> cmd;
		cout << endl;

		switch (cmd)
		{
		case 1:	// 계좌개설
			MakeAccount();
			break;

		case 2:	// 입금
			Deposit();
			break;

		case 3:	// 출금
			Withdraw();
			break;

		case 4:	// 전체고객 잔액조회
			ShowInfo();
			break;

		case 5:	// 프로그램 종료
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
	cout << "몇 번 기능을 이용하시겠습니까? ";
}

void MakeAccount(void)
{
	//int id, money;
	//char name[NAME_LEN];

	cout << "[계좌개설]" << endl;
	cout << "계좌주 입력: ";
	//cin >> name;
	//strcpy_s(clients[cliNum].name, name);
	cin >> clients[cliNum].name;

	cout << "계좌번호 생성: ";
	//cin >> id;
	//clients[cliNum].accID = id;
	cin >> clients[cliNum].accID;

	cout << "입금액: ";
	//cin >> money;
	//clients[cliNum].balance = money;
	cin >> clients[cliNum].balance;
	cout << endl;

	cout << "계좌주: " << clients[cliNum].name << endl;
	cout << "계좌번호: " << clients[cliNum].accID << endl;	
	cout << "잔고: "<< clients[cliNum].balance << endl;
	cout << endl;
	
	cliNum++;
}

void Deposit(void)
{
	int acc, money;

	cout << "[입금]" << endl;
	cout << "입금할 계좌의 계좌번호 입력: ";
	cin >> acc;
	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		if (clients[i].accID == acc)
		{
			cout << "계좌주: " << clients[i].name << endl;
			cout << "계좌번호: " << clients[i].accID << endl;

			cout << "입금할 금액 입력: ";
			cin >> money;
			cout << endl;

			clients[i].balance += money;

			cout << "입금 완료" << endl << "잔고: " << clients[i].balance << endl;
			cout << endl;

			return;
		}
	}

	cout << "존재하지 않는 계좌입니다." << endl;
	cout << endl;
}

void Withdraw(void)
{
	int acc, money;

	cout << "[출금]" << endl;
	cout << "출금할 계좌의 계좌번호 입력: ";
	cin >> acc;
	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		if (clients[i].accID == acc)
		{
			cout << "계좌주: " << clients[i].name << endl;
			cout << "계좌번호: " << clients[i].accID << endl;

			cout << "출금할 금액 입력: ";
			cin >> money;
			cout << endl;

			if (clients[i].balance <= 0 || clients[i].balance < money)
			{
				cout << "잔액부족" << endl;
				cout << endl;
				return;
			}

			clients[i].balance -= money;

			cout << "출금 완료" << endl << "잔액: " << clients[i].balance << endl;
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

	for (int i = 0; i < cliNum; i++)
	{
		cout << "계좌주: " << clients[i].name << endl;
		cout << "계좌번호: " << clients[i].accID << endl;
		cout << "잔액: " << clients[i].balance << endl;
		cout << endl;
	}
}