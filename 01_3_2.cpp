#include <iostream>
using namespace std;

int SimpleFunc(int a = 10)
{
	return a + 1;
}

int SimpleFunc(void)
{
	return 10;
}

int main(void)
{
	cout << SimpleFunc() << endl;
	// ���ڸ� �������� �����鼭 �Լ��� ȣ���� ���, �� �Լ� ��� ȣ�������� �����ϱ� ������ ������ ������ �߻���.
	cout << SimpleFunc(1) << endl;

	return 0;
}