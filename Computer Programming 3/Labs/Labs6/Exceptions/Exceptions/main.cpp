#include <iostream>
#include <string>

using namespace std;

class Shoe
{
public:
	Shoe() {};
	~Shoe() {};
protected:
	string m_Company;
	int m_Size;
};

class Trainers : public Shoe
{
public:
	Trainers(string company, int size, int length) 
	{
		if (size < 35) throw invalid_argument("Trainers are too small!");
		else if (length < 30) throw length_error("Trainers are too short!");
		else
		{
			m_Company = company;
			m_Size = size;
			m_Length = length;
		}
	};
	~Trainers() {};
	void print_info()
	{
		std::cout << "\nCompany: " << m_Company << "\nSize: " << m_Size << "\nLength: " << m_Length << std::endl;
	}
protected:
	int m_Length;
};

class Sandals : public Shoe
{
public:
	Sandals(string company, int size, int year)
	{
		if (size < 23) throw invalid_argument("Sandals are too small!");
		else if (year > 2017) throw "Sandals are not produced yet!";
		else
		{
			m_Company = company;
			m_Size = size;
			m_Year = year;
		}
	}
	void print_info()
	{
		std::cout << "\nCompany: " << m_Company << "\nSize: " << m_Size << "\nYear: " << m_Year << std::endl;
	}
	~Sandals(){}
protected:
	int m_Year;
};


class Heels : public Shoe
{
public:
	Heels(string company, int size, int height)
	{
		if (size > 40) throw invalid_argument("Heels are too big!");
		else if (height == 0) throw "Shoes are not heels.";
		else
		{
			m_Company = company;
			m_Size = size;
			m_Height = height;
		}
	}
	~Heels() {}
	void print_info()
	{
		std::cout << "\nCompany: " << m_Company << "\nSize: " << m_Size << "\nHeight: " << m_Height << std::endl;
	}
protected:
	int m_Height;
};


int main()
{
	try {
		Trainers t("Adidas", 40, 45);
		t.print_info();
		Sandals s("Legionist", 25, 1996);
		s.print_info();
		Heels h("Platforms", 20, 5);
		h.print_info();
		Trainers t2("Nike", 33, 45);
		t2.print_info();
	}
	catch(invalid_argument &e){
		cout << "\nError: " << e.what() << endl;
	}
	catch (length_error &e) {
		cout << "\nError: " << e.what() << endl;
	}
	catch (char * s)
	{
		cout << s << endl;
	}

	system("pause");
	return 0;
}