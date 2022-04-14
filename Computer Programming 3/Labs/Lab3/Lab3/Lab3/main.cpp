#include <iostream>
#include <string>

class Car {
protected:
	std::string m_name;
	int m_enginePower;
	int m_yearProduction;
public:
	virtual void print()
	{
		std::cout << "Car name: " << m_name << "\nEngine power: " << m_enginePower << std::endl;
	}
	void printYearProduction()
	{ 
		std::cout << "Year of production: " << m_yearProduction << std::endl;
	}
	Car() {}
	Car(std::string carName, int carEnginePower, int yearOfProduction)
		: m_name(carName),m_enginePower(carEnginePower),m_yearProduction(yearOfProduction){}
	~Car()
	{
		std::cout << "Deleted Car: " << m_name << std::endl;
	}
};

class Jeep : public Car
{
protected:
	int m_clearance;
public:
	void print()
	{
		std::cout << "Jeep name: " << m_name << "\nClearance: " << m_clearance << std::endl << std::endl;
	}
	Jeep(std::string carName, int carEnginePower, int yearOfProduction, int carClearance)
	{
		m_name = carName;
		m_enginePower = carEnginePower;
		m_yearProduction = yearOfProduction;
		m_clearance = carClearance;
	}
	~Jeep()
	{
		std::cout << "Deleted Jeep: " << m_name << std::endl;
	}
};

class Truck :public Car
{
protected:
	int m_capacity;
	int m_length;
public:
	void print()
	{
		std::cout << "\nTruck name: " << m_name << "\nCapacity: " << m_capacity << std::endl << std::endl;
	}
	Truck(std::string carName, int carEnginePower, int yearOfProduction, int carClearance,int carCapacity, int carLength)
	{
		m_name = carName;
		m_enginePower = carEnginePower;
		m_yearProduction = yearOfProduction;
		m_capacity = carCapacity;
		m_length = carLength;
	}
	~Truck()
	{
		std::cout << "Deleted Truck: " << m_name << std::endl;
	}
};


int main()
{
	Car c1("Maluch", 50, 1960);
	Car c2("Trabant", 65, 1965);

	Jeep j1("Rover", 200, 1999,100000);
	Jeep j2("Hammer", 345, 2003, 250000);

	Truck t1("Man", 600, 2005, 500000,2500, 5);
	//Truck t2("Scania", 550, 2004, 750000, 3000, 8);

	j1.print();
	t1.print();

	Car ** tab = new Car*[5];
	tab[0] = &c1;
	tab[1] = &c2;
	tab[2] = &j1;
	tab[3] = &j2;
	tab[4] = &t1;

	std::cout << "Array contents: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		tab[i]->print();
		tab[i]->printYearProduction();
	}

	delete[] tab;

	system("pause");
	return 0;
}