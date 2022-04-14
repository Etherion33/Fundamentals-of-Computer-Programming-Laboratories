#include <iostream>

using namespace std;

class Animal
{
protected:
	void AnimalData() {
		cout << "\nI am an animal" << endl;
	}
public:
	Animal() {};
};

class Bird
{
protected:
	void BirdData()
	{
		cout << "\nI am bird" << endl;
	}
public:
	Bird(){}
};

class Human
{
public:
	Human(){}
	~Human(){}

protected:
	void HumanData() {
		cout << "\nI am human" << endl;
	}
};

class Horse
{
protected:
	void HorseData()
	{
		cout << "\nI am horse" << endl;
	}
public:
	Horse() {}
};

class Centaur : public Human, public Horse
{
public:
	Centaur() {}
public:
	void CentaurData() {
		this->HumanData();
		this->HorseData();
		cout << "\nI am centaur" << endl;
	}
};

class Batman : public Human, public Bird
{
public:
	Batman(){}
	~Batman(){}

public:
	void BatmanData() {
		this->HumanData();
		this->BirdData();
		cout << "\nI am batman!" << endl;
	}
};

class Pegasus: public Horse, public Bird
{
public:
	Pegasus() {}
	~Pegasus(){}

public:
	void PegasusData() {
		this->BirdData();
		this->HorseData();
		cout << "\nI am pegasus" << endl;
	}
};

int main() {

	Centaur c1;
	Batman	b1;
	Pegasus p1;

	c1.CentaurData();
	b1.BatmanData();
	p1.PegasusData();


	system("pause");
	return 0;
}