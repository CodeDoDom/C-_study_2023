#include <iostream>
using namespace std;

int main(void)
{
	int num;

	cout << "숫자 입력: ";
	cin >> num;

	for (int i = 0; i < 9; i++)
		cout << num << " x " << i + 1 << " = " << num * (i + 1) << endl;

	return 0;
}