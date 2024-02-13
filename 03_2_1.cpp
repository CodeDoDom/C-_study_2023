#include <iostream>
using namespace std;

class Calculator
{
private:
	int add_cnt;
	int min_cnt;
	int mul_cnt;
	int div_cnt;
public:
	void Init();
	double Add(double n1, double n2);
	double Min(double n1, double n2);
	double Multiple(double n1, double n2);
	double Div(double n1, double n2);
	void ShowOpCount();
};

void Calculator::Init()
{
	add_cnt = 0;
	min_cnt = 0;
	mul_cnt = 0;
	div_cnt = 0;
}

double Calculator::Add(double n1, double n2)
{
	add_cnt++;
	return n1 + n2;
}

double Calculator::Min(double n1, double n2)
{
	min_cnt++;
	return n1 - n2;
}

double Calculator::Multiple(double n1, double n2)
{
	mul_cnt++;
	return n1 * n2;
}

double Calculator::Div(double n1, double n2)
{
	div_cnt++;
	return n1 / n2;
}

void Calculator::ShowOpCount()
{
	cout << "[ ¿¬»ê ±â·Ï ]" << endl;
	cout << "µ¡¼À: " << add_cnt << endl;
	cout << "»¬¼À: " << min_cnt << endl;
	cout << "°ö¼À: " << mul_cnt << endl;
	cout << "³ª´°¼À: " << div_cnt << endl;
}

int main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}