#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* _name, int _age)	:age(_age)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	~MyFriendInfo()
	{
		delete[]name;
	}
	void ShowMyFriendInfo()
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* _name, int _age, const char* _addr, const char* _phone) :MyFriendInfo(_name, _age)
	{
		addr = new char[strlen(_addr) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(addr, _addr);
		strcpy(phone, _phone);
	}
	~MyFriendDetailInfo()
	{
		delete[]addr;
		delete[]phone;
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
};

int main()
{
	MyFriendDetailInfo friend1("윤이하나", 22, "대한민국 어딘가", "010-1111-2222");
	friend1.ShowMyFriendDetailInfo();

	MyFriendDetailInfo friend2("임수영", 22, "우주 어딘가", "010-2222-3333");
	friend2.ShowMyFriendDetailInfo();

	return 0;
}