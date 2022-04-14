#include <iostream>
#include <string>
#include <typeinfo>

class Job
{
public:
	virtual void jobInfo() {
		std::cout << "\nSalary: " << m_salary
			<< "\nHours per week:" << m_hoursPerWeek << std::endl;
	}
	virtual  ~Job() {};
protected:
	int m_salary;
	int m_hoursPerWeek;
};

class Baker : public Job
{
public:
	Baker(int salary, int hoursPerWeek, std::string bakeryName, unsigned int breadsPerDay)
	{
		m_salary = salary;
		m_hoursPerWeek = hoursPerWeek;
		m_bakeryName = bakeryName;
		m_breadsPerDay = breadsPerDay;
	}
	void jobInfo()
	{
		Job::jobInfo();
		std::cout << "\nBakery name: " << m_bakeryName
			<< "\nBreads per day: " << m_breadsPerDay << std::endl;
	}
	~Baker() {};
private:
	std::string m_bakeryName;
	unsigned int m_breadsPerDay;
};

class Secretary : public Job
{
public:
	Secretary(int salary, int hoursPerWeek, bool isWorking)
	{
		m_salary = salary;
		m_hoursPerWeek = hoursPerWeek;
		m_isWorking = isWorking;
	}
	void jobInfo()
	{
		Job::jobInfo();
		std::cout << "\nIs working: " << m_isWorking << std::endl;
	}
	~Secretary() {};

private:
	bool m_isWorking;
};

class Policeman : public Job
{
public:
	Policeman(int salary, int hoursPerWeek, int donutsPerDay)
	{
		m_salary = salary;
		m_hoursPerWeek = hoursPerWeek;
		m_donutsPerDay = donutsPerDay;
	}
	void jobInfo()
	{
		Job::jobInfo();
		std::cout << "\nDounts eaten per day: " << m_donutsPerDay << std::endl;
	}
	~Policeman() {};
private:
	int m_donutsPerDay;
};

Job* getJob()
{
	static int jobCounter = 0;
	switch (jobCounter % 3)
	{
	case 0:
	{
		Baker* b = new Baker(2500, 120, "HappyBread", 50);		
		jobCounter++;
		return b;
		break;
	}
	case 1:
	{
		Secretary* s = new Secretary(3000, 180, true);
		jobCounter++;
		return s;
	}
	case 2:
	{
		Policeman* p = new Policeman(2200, 230, 5);
		jobCounter++;
		return p;
	}
	}
}

int main()
{
	Job* ptr = NULL;												//pointer of type Job*
	Baker* ptrB = NULL;												//pointer of type Baker*

	std::cout << "Exercise 6.1:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		ptr = getJob();
		if (ptrB = dynamic_cast<Baker*> (ptr)) ptrB->jobInfo();		//if pointer is Baker* print info about it
	}

	std::cout << "\nExercise 6.2" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		ptr = getJob();
		if (typeid(Baker) == typeid(*ptr))							//same thing but with use of typeid operator
		{
			ptr->jobInfo();
			std::cout << std::endl;
		}
		else {
			std::cout << typeid(*ptr).name();
			std::cout << std::endl;
		}
	}

	if (typeid(Job).before(typeid(Baker)))
	{
		std::cout << "Baker inherits from Job";
	}
	system("pause");

	return 0;
}