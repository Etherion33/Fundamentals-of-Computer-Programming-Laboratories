#include <iostream>

using namespace std;


class Employee
{
protected:
	string Name;
	string Phone_Number;
	string Job;
public:
	~Employee() { cout << "Employee is fired" << endl; }
	virtual void doJob() = 0;
	virtual void takeBreak() = 0;
	virtual void finishWork() = 0;
};


/* Programmer*/
class Programmer : public Employee
{
public:
	Programmer(string vName, string vPhone, string vJob)
	{
		Name = vName;
		Phone_Number = vPhone;
		Job = vJob;
	}
	void doJob()
	{
		cout << "Programmer is working" << endl;
	}
	void takeBreak()
	{
		cout << "Programmer is taking break" << endl;
	}
	void finishWork()
	{
		cout << "Programmer finished work" << endl;
	}
};



/*Tester*/
class Tester : public Employee
{
public:
	Tester(string vName, string vPhone, string vJob)
	{
		Name = vName;
		Phone_Number = vPhone;
		Job = vJob;
	}
	void doJob()
	{
		cout << "Tester is working" << endl;
	}
	void takeBreak()
	{
		cout << "Tester is taking break" << endl;
	}
	void finishWork()
	{
		cout << "Tester finished work" << endl;
	}
};



/*Secretary*/
class Secretary : public Employee
{
public:
	Secretary(string vName, string vPhone, string vJob)
	{
		Name = vName;
		Phone_Number = vPhone;
		Job = vJob;
	}
	void doJob()
	{
		cout << "Secretary is working" << endl;
	}
	void takeBreak()
	{
		cout << "Secretary is taking break" << endl;
	}
	void finishWork()
	{
		cout << "Secretary finished work" << endl;
	}
};


int main()
{
	Programmer prog1("Bill","555222333", "Programmer");
	Tester test1("Johnny","32444425235", "Tester");
	Secretary sec1("Madeline", "88888888", "Secretary");
	
	prog1.doJob();
	test1.doJob();
	sec1.doJob();

	Employee* emp1 = NULL;
	emp1 = &prog1;
	prog1.takeBreak();
	emp1 = &test1;
	emp1->takeBreak();
	emp1 = &sec1;
	emp1->takeBreak();

	Employee** tab = new Employee*[3];
	tab[0] = &prog1;
	tab[1] = &test1;
	tab[2] = &sec1;

	for (int i = 0; i <3; i++)
	{
		tab[i]->finishWork();

	}

	delete[] tab;

	system("pause");
	return 0;
}