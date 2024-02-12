#include <iostream>
#include <cstring>
using namespace std;

void Solution1(void);
void Solution2(void);

int main(void)
{
	Solution1();
	Solution2();

	return 0;
}

void Solution1(void)
{
	char str1[50] = "Hello! ";
	char str2[50] = "Good Bye! ";
	char str3[50];

	cout << strlen(str1) << endl;
	cout << strlen(str2) << endl;
	strcpy_s(str3, str1);
	strcat_s(str3, str2);
	cout << str3 << endl;

	if (!strcmp(str1, str2))
		cout << "�� ���ڿ��� �����ϴ�." << endl;
	else
		cout << "�� ���ڿ��� �ٸ��ϴ�." << endl;

	cout << endl;
}

void Solution2(void)
{
	char str1[50] = "Apple ";
	char str2[50] = "Apple ";
	//char str2[50] = "Pie Good 123 ";
	char str3[50];

	cout << "str1�� ����: " << strlen(str1) << endl;
	cout << "str2�� ����: " << strlen(str2) << endl;
	strcpy_s(str3, str1);
	cout << "strcpy �� str3: " << str3 << endl;
	strcat_s(str3, str2);
	cout << "strcat �� str3: " << str3 << endl;

	if (strcmp(str1, str3) == 0)
		cout << "str1�� str3�� ���ڿ��� �����ϴ�." << endl;
	else
		cout << "str1�� str3�� ���ڿ��� �ٸ��ϴ�." << endl;

	cout << endl;
}