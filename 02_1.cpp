#include <iostream>
using namespace std;

void AddNum(int &n)
{
	n++;
}

void Change(int& n)
{
	n *= -1;
}

int main(void)
{
	int num = 20;

	AddNum(num);
	cout << "1�� ������Ű�� �Լ�: " << num << endl;

	Change(num);
	cout << "��ȣ�� �ٲٴ� �Լ�: " << num << endl;

	return 0;
}