#include <iostream>
using namespace std;

#define NAME_LEN 10

typedef struct info
{
	int accID;
	char name[NAME_LEN];
	int balance;
} Info;

Info accArr[100];
int accCnt = 0;

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
		case 1:	// ���°���
			MakeAccount();
			break;

		case 2:	// �Ա�
			Deposit();
			break;

		case 3:	// ���
			Withdraw();
			break;

		case 4:	// ��ü�� �ܾ���ȸ
			ShowInfo();
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

	cout << "[���°���]" << endl;
	cout << "������ �Է�: ";
	//cin >> name;
	//strcpy_s(clients[cliNum].name, name);
	cin >> accArr[accCnt].name;

	cout << "���¹�ȣ ����: ";
	//cin >> id;
	//clients[cliNum].accID = id;
	cin >> accArr[accCnt].accID;

	cout << "�Աݾ�: ";
	//cin >> money;
	//clients[cliNum].balance = money;
	cin >> accArr[accCnt].balance;
	cout << endl;

	cout << "������: " << accArr[accCnt].name << endl;
	cout << "���¹�ȣ: " << accArr[accCnt].accID << endl;	
	cout << "�ܰ�: "<< accArr[accCnt].balance << endl;
	cout << endl;
	
	accCnt++;
}

void Deposit(void)
{
	int acc, money;

	cout << "[�Ա�]" << endl;
	cout << "�Ա��� ������ ���¹�ȣ �Է�: ";
	cin >> acc;
	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		if (accArr[i].accID == acc)
		{
			cout << "������: " << accArr[i].name << endl;
			cout << "���¹�ȣ: " << accArr[i].accID << endl;

			cout << "�Ա��� �ݾ� �Է�: ";
			cin >> money;
			cout << endl;

			accArr[i].balance += money;

			cout << "�Ա� �Ϸ�" << endl << "�ܰ�: " << accArr[i].balance << endl;
			cout << endl;

			return;
		}
	}

	cout << "�������� �ʴ� �����Դϴ�." << endl;
	cout << endl;
}

void Withdraw(void)
{
	int acc, money;

	cout << "[���]" << endl;
	cout << "����� ������ ���¹�ȣ �Է�: ";
	cin >> acc;
	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		if (accArr[i].accID == acc)
		{
			cout << "������: " << accArr[i].name << endl;
			cout << "���¹�ȣ: " << accArr[i].accID << endl;

			cout << "����� �ݾ� �Է�: ";
			cin >> money;
			cout << endl;

			if (accArr[i].balance <= 0 || accArr[i].balance < money)
			{
				cout << "�ܾ׺���" << endl;
				cout << endl;
				return;
			}

			accArr[i].balance -= money;

			cout << "��� �Ϸ�" << endl << "�ܾ�: " << accArr[i].balance << endl;
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
		cout << "������: " << accArr[i].name << endl;
		cout << "���¹�ȣ: " << accArr[i].accID << endl;
		cout << "�ܾ�: " << accArr[i].balance << endl;
		cout << endl;
	}
}