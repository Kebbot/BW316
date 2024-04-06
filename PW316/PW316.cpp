#include <iostream>
#include <Windows.h>
#include <vector>
#include "HeadClass.h"
using namespace std;

/*class Point
{
	double x;
	double y;
public:
	Point(double x, double y) : x{x}, y{x}{}
	void display() const
	{
		cout << "(" << x << "," << y << ")" <<endl;
	}
	
	Point operator+(const Point& point1)
	{
		return Point(x + point1.x, y + point1.y);
	}
	friend Point operator-(const Point& point1)
	{
		return Point(-point1.x, -point1.y);
	}
	friend ostream& operator<<(ostream& output, const Point& point1)
	{
		output << "(" << point1.x << "," << point1.y << ")";
		return output;
	}
	friend istream& operator>>(istream& input, Point& point1)
	{
		input >> point1.x;
		input >> point1.y;
		return input;
	}
	double getX()const { return x; }
	double getY()const { return y; }
};

Point operator+(const Point& point1, const Point& point2)
{
	return Point(point2.getX() + point1.getX(), point2.getY() + point1.getY());
}*/

class DynArray
{
	int* arr;
	int size;
public:
	DynArray(int sizeP)
		: arr{ new int[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(const DynArray& object)
		: arr{ new int[object.size] }, size{ object.size }
	{
		/* В списке инициализаторов полей класса выше
		выделяем новый блок динамической памяти того же
		размера, что и в копируемом экземпляре класса
		DynArray. Следующим циклом копируем элементы
		из оригинального блока памяти во вновь
		выделенный. */
		for (int i{ 0 }; i < size; ++i)
		{
			arr[i] = object.arr[i];
		};
		std::cout << "DynArr copy constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	DynArray( DynArray&& object) : 
		arr{ object.arr}, size{ object.size}
	{
		object.arr = nullptr;
		object.size = 0;
		cout << "DynArr move constructed for "
			<< size << " elements, for " << this
			<< '\n'; 
	}
	DynArray& operator=(const DynArray& object)
	{
		// проверка на самоприсваивание
		if (!(this == &object))
		{
			/* проверяем на невозможность "переиспользовать"
			блок памяти, выделенный под имеющийся
			массив */
			if (size != object.size)
			{
				/* в случае невозможности "переиспользования"
				необходимо освободить память, УЖЕ
				занимаемую элементами текущего
				динамического массива */
				delete[] arr;
				/* выделяем новый блок памяти согласно
				размеру копируемого массива */
				arr = new int[object.size];
			}
			size = object.size;
			/* Следующим циклом копируем элементы
			из оригинального блока памяти во вновь
			выделенный */
			for (int i = 0; i < size; i++)
			{
				arr[i] = object.arr[i];
			};
			/*int* dest{arr};//указатель на НАчало массива
			int* src{ object.arr }; //указатель на начало object массива 
			int* const end{ arr + size }; //указатель на конец массива
			//выполнять пока "Начало" меньше чем "конец"
			while (dest < end)
			{
				*dest++ = *src++;
				//Копируем значения из object массива в наш массив
			}*/

		}
		std::cout << "DynArr copy assigned for "
			<< size << " elements, for " << this
			<< '\n';
		return *this;
	}
	int getElem(int idx)const { return arr[idx]; }
	void setElem(int idx, int val) { arr[idx] = val; }
	void print()const;
	void randomize();
	~DynArray()
	{
		std::cout << "Try to free memory from DynArray for"
			<< arr << " pointer\n";
		delete[] arr;
		std::cout << "DynArr destructed for " << size
			<< " elements, for " << this << '\n';
	}
};
void DynArray::print()const
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
void DynArray::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}

DynArray arrFactory(int arrSize)
{
	DynArray arr{ arrSize };
	arr.randomize();
	return arr;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	
	DynArray ar1;
	ar1 = arrFactory(10);
	std::cout << "ar1 elements: ";
	ar1.print();
	
	

	return 0;
}
