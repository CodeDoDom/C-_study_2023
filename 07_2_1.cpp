#include <iostream>
using namespace std;

class Rectangle	// ���簢��
{
private:
	int width;
	int height;
public:
	Rectangle(int w, int h) :width(w), height(h)
	{ }
	void ShowAreaInfo()
	{
		cout << "����: " << width * height << endl;
	}
};

class Square : public Rectangle	// ���簢��
{
public:
	Square(int side) :Rectangle(side, side)
	{ }
};

int main(void)
{
	Rectangle rec(3, 4);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}