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
	Point& operator+=(const Point& ref)
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point& ref)
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
	friend Point operator-(const Point&, const Point&);
	friend bool operator==(const Point&, const Point&);
	friend bool operator!=(const Point&, const Point&);
};

Point operator-(const Point& pos1, const Point& pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point& pos1, const Point& pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}

int main()
{
	Point pos1(10, 20);
	Point pos2(1, 2);
	Point pos3(4, 3);

	Point pos4(5, 5);
	Point pos5(5, 5);
	Point pos6(7, 9);

	Point pos = pos1 - pos2;

	cout << "10_1_1번 답: " << endl;
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos.ShowPosition();
	cout << endl;

	pos1 += pos2;
	pos2 -= pos3;

	cout << "10_1_2번 답: " << endl;
	pos1.ShowPosition();
	pos2.ShowPosition();
	cout << endl;

	cout << "10_1_3번 답: " << endl;
	cout << "== 연산자 오버로딩: " << endl;	// 같으면 참, 다르면 거짓
	pos4.ShowPosition();
	pos5.ShowPosition();
	if (pos4 == pos5)	// [5, 5] == [5, 5]
		cout << "EQUAL" << endl;
	else
		cout << "NOT EQUAL" << endl;
	cout << endl;

	cout << "!= 연산자 오버로딩: " << endl;	// 같으면 거짓, 다르면 참
	pos4.ShowPosition();
	pos6.ShowPosition();
	if (pos4 != pos6)	// [5, 5] != [7, 9]
		cout << "NOT EQUAL" << endl;
	else
		cout << "EQUAL" << endl;

	return 0;
}