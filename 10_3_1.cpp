#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Point {
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend std::istream& operator>>(std::istream& is, Point& pos)
	{
		is >> pos.xpos >> pos.ypos;
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os, const Point& pos)
	{
		os << "[" << pos.xpos << ", " << pos.ypos << "]" << '\n';
		return os;
	}

private:
	int xpos;
	int ypos;
};

int main()
{
	Point pos1;
	std::cout << "x, y 좌표 순으로 입력: ";
	std::cin >> pos1;
	std::cout << pos1;

	Point pos2;
	std::cout << "x, y 좌표 순으로 입력: ";
	std::cin >> pos2;
	std::cout << pos2;
}