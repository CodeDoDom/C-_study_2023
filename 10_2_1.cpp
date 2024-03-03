#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
	Point operator-(const Point& pos1)
	{
		Point pos(-pos1.xpos, -pos1.ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(10, 20);
	Point pos2()

	return 0;
}