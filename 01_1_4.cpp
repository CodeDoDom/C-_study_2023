#include <iostream>
using namespace std;

int main(void)
{
	int sales;
	int salary;
	int money = 50;
	double percent = 0.12;

	while(1)
	{
		cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		cin >> sales;

		if (sales <= -1)
		{
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}

		else
		{
			salary = money + sales * percent;
			cout << "이번 달 급여: " << salary << "만원\n";
		}
	}

	return 0;
}