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
	// 인자를 전달하지 않으면서 함수를 호출할 경우, 두 함수 모두 호출조건을 만족하기 때문에 컴파일 에러가 발생함.
	cout << SimpleFunc(1) << endl;

	return 0;
}