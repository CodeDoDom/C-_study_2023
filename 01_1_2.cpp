#include <iostream>
using namespace std;

int main(void)
{
	char name[50];
	char phone[10];

	cout << "이름: ";
	cin >> name;

	cout << "전화번호: ";
	cin >> phone;

	cout << "입력된 이름: " << name << endl;
	cout << "입력된 전화번호: " << phone << endl;

	return 0;
}