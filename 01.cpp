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
		case 1:	// ���°���
			MakeAccount();
			break;

		case 2:	// �Ա�
			Deposit();
			break;

		case 3:	// ���
			cout << "��� ����� �����ϼ̽��ϴ�." << endl;
			break;

		case 4:	// ��ü�� �ܾ���ȸ
			cout << "��ü�� �ܾ���ȸ ����� �����ϼ̽��ϴ�." << endl;
			break;

		case 5:	// ���α׷� ����
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
	cout << "�� �� ����� �̿��Ͻðڽ��ϱ�? ";
}

void MakeAccount(void)
{
	//int id, money;
	//char name[NAME_LEN];

	cout << "���°��� ����� �����ϼ̽��ϴ�." << endl;
	cout << "���Ӱ� ������ ������ ������ �Է�: ";
	//cin >> name;
	//strcpy_s(clients[cliNum].name, name);
	cin >> clients[cliNum].name;

	cout << "���¹�ȣ ����: ";
	//cin >> id;
	//clients[cliNum].accID = id;
	cin >> clients[cliNum].accID;

	cout << "�Աݾ�: ";
	//cin >> money;
	//clients[cliNum].balance = money;
	cin >> clients[cliNum].balance;

	cout << "������: " << clients[cliNum].name << endl;
	cout << "���¹�ȣ: " << clients[cliNum].accID << endl;	
	cout << "�ܰ�: "<< clients[cliNum].balance << endl;
	cout << endl;
	
	cliNum++;
}

void Deposit(void)
{
	int acc, money;

	cout << "�Ա� ����� �����ϼ̽��ϴ�." << endl;
	cout << "�Ա��� ������ ���¹�ȣ �Է�: ";
	cin >> acc;
	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		if (clients[i].accID == acc)
		{
			cout << "������: " << clients[i].name << endl;
			cout << "���¹�ȣ: " << clients[i].accID << endl;

			cout << "�Ա��� �ݾ� �Է�: ";
			cin >> money;
			cout << endl;

			clients[i].balance += money;

			cout << "�Ա� �Ϸ�" << endl << "�ܰ�: " << clients[i].balance << endl;
			cout << endl;

			return;
		}
	}

	cout << "�������� �ʴ� �����Դϴ�." << endl;
	cout << endl;
}