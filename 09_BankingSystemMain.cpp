/*
Banking System Ver 0.7
수행 내용: 파일 분할
*/
#include "09_BankingCommonDec1.h"
#include "09_AccountHandler.h"

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