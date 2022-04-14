#include <iostream>

template <class T>
class Point
{
public:
	Point() {}
	Point(T f_x,T f_y)
		: m_x(f_x), m_y(f_y) {}
	~Point() {};
	T getX() { return m_x; }
	T getY() { return m_y; }
	void setX(T f_x) { m_x = f_x; }
	void setY(T f_y) { m_y = f_y; }
	void print();
	Point& operator=(Point &p);
	Point& operator+=(Point p) {
		m_x += p.m_x;
		m_y += p.m_y;
		return *this;
	}
private:
	T m_x, m_y;
};

template<class T>
Point<T>& Point<T>::operator=(Point<T> &p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	return *this;
};

template <>
void Point<int>::print()
{
	std::cout << "(" << m_x << "," << m_y << ")" << std::endl;
}


template <>
void Point<double>::print()
{
	std::cout << std::scientific << "(" << m_x << "," << m_y << ")" << std::endl;
}

template <class T>
Point<T> add(Point<T> a, Point<T> b) {
	Point<T> result = a;
	result += b;
	return result;
};

template <class T,int size> 
class Base
{
protected:
	T m_data[size];
public:
	Base() {}
	T& operator [](int i)
	{
		return m_data[i];
	}
};

template<class T,int size>
class Array : public Base<T,size>
{
public:
	Array() {}
};

template<int size>
class Array<Point<double>, size> : public Base<Point<double>,size>
{
public:
	Array() {}
	void printArray()
	{
		for (int i = 0; i < size; i++)
		{
			m_data[i].print();
		}
	}
};

int main()
{
	std::cout << "\n3.1" << std::endl;
	Point<int> a(0, 0);
	Point<int> b(2, 2);
	Point<int> c = add(a, b);
	c.print();

	Point<double> d(0.5, 0.6);
	Point<double> e(0.5, 0.4);
	Point<double> f = add(d, e);
	f.print();
	
	std::cout << "\n3.2" << std::endl;
	Array <Point<int>, 3> tab;
	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
	for (int i = 0; i < 3; i++)
	{
		tab[i].print();
	}

	std::cout << "\n3.3" << std::endl;
	Array < Point<double>, 3> tabD;
	tabD[0] = d;
	tabD[1] = e;
	tabD[2] = f;
	tabD.printArray();
	system("pause");
	return 0;
}