#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	/*void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}*/
	Point(int x, int y) :xpos(x), ypos(y)
	{
		// empty
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	int radius;
	Point center;
public:
	/*void InitCircle(int x, int y, int r)
	{
		center.Init(x, y);
		radius = r;
	}*/
	Circle(int x, int y, int r) :center(x, y)
	{
		radius = r;
	}
	void ShowCircle() const
	{
		cout << "¹ÝÁö¸§: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inner;
	Circle outter;
public:
	/*void Init(int x1, int y1, int r1, int x2, int y2, int r2)
	{
		inner.InitCircle(x1, y1, r1);
		outter.InitCircle(x2, y2, r2);
	}*/
	Ring(int inX, int inY, int inR, int outX, int outY, int outR) :inner(inX, inY, inR), outter(outX, outY, outR)
	{
		// empty
	}
	void ShowRingInfo() const
	{
		cout << "[ Inner Circle Info ]" << endl;
		inner.ShowCircle();
		cout << "[ Outter Circle Info ]" << endl;
		outter.ShowCircle();
	}
};

int main(void)
{
	//Ring ring;
	//ring.Init(1, 1, 4, 2, 2, 9);
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}