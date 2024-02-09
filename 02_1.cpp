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
	cout << "1씩 증가시키는 함수: " << num << endl;

	Change(num);
	cout << "부호를 바꾸는 함수: " << num << endl;

	return 0;
}