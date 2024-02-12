#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void SrandNum(void);

int main(void)
{
	srand((unsigned int)time(NULL));

	SrandNum();

	return 0;
}
void SrandNum(void)
{
	int num;

	for (int i = 0; i < 5; i++)
	{
		num = rand() % 100;
		cout << num << endl;
	}
}