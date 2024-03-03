#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x, int y)
		:xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
	friend Point operator-(const Point&, const Point&);
};

Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(10, 20);
	Point pos2(1, 2);
	Point pos3 = operator-(pos1, pos2);
	Point pos4 = pos1 - pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();

	return 0;
}