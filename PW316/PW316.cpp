#include <iostream>
#include <Windows.h>
#include <vector>
#include "HeadClass.h"
using namespace std;

/*class Array
{
	int size;
	int* array;
public:
	explicit Array(int size = 10);
	~Array();
	int getSize() const;
	int getValue(int index) const;
	void setValue(int index, int value);
	void display(int index) const;
};
Array::Array(int size)
{
	Array::size = size;
	array = new int[size];
}
Array::~Array()
{
	delete[] array;
}
int Array::getSize() const
{
	return size;
}
int Array::getValue(int index) const
{
	return array[index];
}
void Array::setValue(int index, int value)
{
	array[index] = value;
}
void Array::display(int index) const
{
	cout << array[index] << " ";
}
void display(const Array& array)
{
	for (int i = 0; i < array.getSize(); i++)
	{
		array.display(i);
	}
	cout << endl;
}*/

class Point
{
private:
	double x;
	double y;
public:
	void display() const;
	void read();
	//Сравнение двух точек
	static bool isEqual(const Point& point1, const Point& point2); 
	//Сложение двух точек
	static Point add(const Point& point1, const Point& point2);
	//Умножение вектора на число
	static Point mult(const Point& point1, double value);
	// Расстояине между двумя точками
	static double distance(const Point& point1, const Point& point2);
	//длинна вектора
	static double length(const Point& point);
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	Point point1(1, 1);
	Point point2;
	Point point3(1, 1);

	if (Point::isEqual(point1, point3))
		cout << "point1 and point3 are equal" << endl;

	cout << "point1: ";
	point1.display();

	cout << "Введите значения точек в формате x,y (12,10): ";
	point2.read();

	cout << "point2: ";
	point2.display();

	cout << "point1 + point2 = ";
	Point::add(point2, point1).display();

	cout << "Расстояние точек ";
	point1.display();
	cout << " и ";
	point2.display();
	cout << " будет ";
	cout << Point::distance(point1, point2) << endl;



	/*cout << "Dynamic integer array" << endl;
	int size = 4;
	Array array(size);
	for (int i = 0; i < size; i++)
	{
		array.setValue(i, size - i);
	}
	display(array);
	cout << "!!!" << endl;
	display(Array(3));

	//Array array10 = 10; //ошибка - так нельзя
	Array array10{ 10 };*/


	return 0;
}
// 3.2 логика использования стандартных символов 
