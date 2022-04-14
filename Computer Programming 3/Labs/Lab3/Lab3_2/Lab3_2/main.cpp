#include <iostream>
#include <string>

using namespace std;

class Car
{
protected:
	std::string name;
	int enginePower;
	int yearOfProduction;
public:
	Car() {}
	Car(std::string n, int e, int y)
	{
		name = n;
		enginePower = e;
		yearOfProduction = y;
	}
	virtual void print() {
		cout << "Car name: " << name << "\n Engine Power: " << enginePower << endl;
	}
	void printYear()
	{
		cout << "Car name: " << name << "\n Year of production: " << yearOfProduction << endl;

	}
	~Car() {}
};
class Jeep : public Car
{
protected:
	int clearence;
public:
	void print()
	{
		cout << "Jeep name: " << name << "\n Clearence: " << clearence << endl;
	}
	Jeep(string n, int e, int y, int c)
	{
		name = n;
		enginePower = e;
		yearOfProduction = y;
		clearence = c;
	}
	~Jeep() {}
};

class Truck : public Car
{
protected:
	int capacity;
	int length;
public:
	void print()
	{
		cout << "Truck name: " << name << "\n Capacity: " << capacity << endl;
	}
	void printLength()
	{
		cout << "Car name: " << name << "\n Length: " << length << endl;

	}
	Truck(string n, int e, int y, int c, int l)
	{
		name = n;
		enginePower = e;
		yearOfProduction = y;
		capacity = c;
		length = l;
	}
	~Truck() {}
};


int main()
{
	Car c1("Maluch", 50, 1975);
	Car c2("Trabant", 75, 1978);

	Jeep j1("Rover", 250, 2003, 25);
	Jeep j2("Hammer", 400, 2005, 30);

	Truck t1("Man", 700, 2004, 5000, 11);

	j1.print();
	t1.print();



	Car **tab = new Car*[5];
	tab[0] = &c1;
	tab[1] = &c2;
	tab[2] = &j1;
	tab[3] = &j2;
	tab[4] = &t1;

	for (int i = 0; i < 5; i++)
	{
		tab[i]->print();
		tab[i]->printYear();
	}

	delete[] tab;
	system("pause");

}