#include <iostream>
using namespace std;

int main(void)
{
	int sales;
	int salary;
	int money = 50;
	double percent = 0.12;

	while(1)
	{
		cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		cin >> sales;

		if (sales <= -1)
		{
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		}

		else
		{
			salary = money + sales * percent;
			cout << "�̹� �� �޿�: " << salary << "����\n";
		}
	}

	return 0;
}