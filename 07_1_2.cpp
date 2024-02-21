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
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
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
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl << endl;
	}
};

int main()
{
	MyFriendDetailInfo friend1("�����ϳ�", 22, "���ѹα� ���", "010-1111-2222");
	friend1.ShowMyFriendDetailInfo();

	MyFriendDetailInfo friend2("�Ӽ���", 22, "���� ���", "010-2222-3333");
	friend2.ShowMyFriendDetailInfo();

	return 0;
}