#include <iostream>
using namespace std;

int main(void)
{
	int num[5];
	int tot = 0;

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "번째 정수 입력: ";
		cin >> num[i];
	}

	for (int i = 0; i < 5; i++)
	{
		tot += num[i];
	}

	cout << "합계: " << tot << endl;

	return 0;
}