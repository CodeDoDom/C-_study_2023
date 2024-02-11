#include <iostream>
using namespace std;

void SwapByRef2(int& ref1, int& ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;

	SwapByRef2(val1, val2);
	//SwapByRef2(23, 45);	// 참조자는 상수가 될 수 없다. 매개변수의 인자로는 반드시 변수가 등장해야 한다.
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;

	return 0;
}