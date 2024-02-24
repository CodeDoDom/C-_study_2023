#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 100;
const int EMPLIST_MAX = 50;

namespace RISK_LEVEL
{
	enum {
		RISK_A = 30, RISK_B = 20, RISK_C = 10
	};
}

class Employee
{
private:
	char name[NAME_LEN];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker :public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		:Employee(name), salary(money)
	{ }
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker :public Employee
{
private:
	int workTime;
	int PayPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		:Employee(name), workTime(0), PayPerHour(pay)
	{ }
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * PayPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker :public PermanentWorker
{
private:
	int salesResult;
	double bounusRatio;
public:
	SalesWorker(const char* name, int money, double ratio)
		:PermanentWorker(name, money), salesResult(0), bounusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay()
			+ (int)(salesResult * bounusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class ForeignSalesWorker :public SalesWorker
{
private:
	int salesResult;
	int riskLevel;
public:
	ForeignSalesWorker(const char* name, int money, double ratio, int lisk)
		:SalesWorker(name, money, ratio), riskLevel(lisk)
	{ }
	int GetRiskPay() const	// ���� ����
	{
		return (int)(SalesWorker::GetPay() * riskLevel / 100.0);
	}
	int GetPay() const
	{
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary: " << SalesWorker::GetPay() << endl;
		cout << "�������: " << GetRiskPay() << endl;
		cout << "����: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[EMPLIST_MAX];
	int empNum;
public:
	EmployeeHandler() :empNum(0)
	{
		for (int i = 0; i < EMPLIST_MAX; ++i)	// ������ ��� �ߴµ� ��� �۵��� ��
			empList[i] = nullptr;
	}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "������ �޿� �ջ�: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	EmployeeHandler handler;

	// �ؿ� ������ ���(8_1�� �������� �߰��� �κ�)
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	//handler.AddEmployee(new PermanentWorker("Kim", 1000));
	//handler.AddEmployee(new PermanentWorker("Park", 1500));

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();
	return 0;
}