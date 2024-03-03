/*
Banking System Ver 0.7
���� ����: ���� ����
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