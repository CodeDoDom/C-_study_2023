#include <iostream>
using namespace std;

int main(void)
{
	char name[50];
	char phone[10];

	cout << "�̸�: ";
	cin >> name;

	cout << "��ȭ��ȣ: ";
	cin >> phone;

	cout << "�Էµ� �̸�: " << name << endl;
	cout << "�Էµ� ��ȭ��ȣ: " << phone << endl;

	return 0;
}