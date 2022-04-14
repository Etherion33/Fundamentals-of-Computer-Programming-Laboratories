#include <iostream>

using namespace std;

class Shape
{
protected:
	Shape()
	{
		cout << "It is a base class!" << endl;
	};
public:
	virtual double Area() = 0;
	virtual ~Shape() = 0;
};

class Rectangle: public Shape
{
protected:
	double a, b;
public:
	Rectangle(double x, double y)
		:a(x) , b(y)
	{
		cout << "Rectangle is created a =" << a << " b= " << b << endl;
	}
	double Area()
	{
		return a*b;
	}
	~Rectangle()
	{
		cout << "Rectangle is deleted" << endl;
	}
private:

};


Shape::~Shape()
{
	cout << "Object is deleted" << endl;
}


class Triangle : public Shape
{
protected:
	double a, h;
public:
	Triangle(double x, double y)
		: a(x), h(y)
	{
		cout << "Length of the base = " << a << endl;
		cout << "Length of the height =" << h << endl;
	}
	double Area()
	{
		return (a*h) / 2.0;
	}
	~Triangle()
	{
		cout << "Triangle is deleted" << endl;
	}
};

int main()
{
	Triangle tr(2, 5);
	cout << "\nTriangle area: " << tr.Area() << endl;
	Rectangle rect(5,5);
	cout << "\nRectangle area: "<< rect.Area() << endl;
	Shape *shp = NULL;
	shp = &rect;
	cout <<"\nRectangle area:" << shp->Area() << endl;
	shp = &tr;
	cout << "\nTriangle area:" << shp->Area() << endl;


	system("pause");
	return 0;
}