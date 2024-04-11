#include <iostream>
#include <Windows.h>
#include <vector>
#include <cassert>
#include "HeadClass.h"
using namespace std;

/*class DynArray
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
		
		for (int i{ 0 }; i < size; ++i)
		{
			arr[i] = object.arr[i];
		};
		std::cout << "DynArr copy constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	DynArray(DynArray&& object) :
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
			
			if (size != object.size)
			{
				
				delete[] arr;
				
				arr = new int[object.size];
			}
			size = object.size;
			
			for (int i = 0; i < size; i++)
			{
				arr[i] = object.arr[i];
			};
			

		}
		std::cout << "DynArr copy assigned for "
			<< size << " elements, for " << this
			<< '\n';
		return *this;
	}
	int operator[](int idx) const
	{
		//Константная перегрузка, возвращающая элемент по значению
		assert(idx >= 0 and idx < size and "Index is out of range!");
		return arr[idx];
	}
	int& operator[](int idx)
	{
		//Не Константная перегрузка, возвращающая элемент по ссылке
		assert(idx >= 0 and idx < size and "Index is out of range!");
		return arr[idx];
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
}*/

/*// заданные по умолчанию и удаленные методы
class Point
{
	int x;
	int y;
	
public:
	Point() = default;
	Point(int pX, int pY) : x{ pX }, y{ pY } {}
	Point& setX(int pX) { x = pX; return *this; }
	Point& setY(int pY) { y = pY; return *this; }
	/*Point& setX(double pX) = delete;
	Point& setY(double pY) = delete;
	void showPoint() const
	{
		std::cout << '(' << x << ',' << y << ')';
	}
};

int Max(int a, int b) { return a > b ? a : b; }
template <typename T1, typename T2> int Max(T1 a, T2 b) = delete;*/

class MedalRow
{
	char country[4];
	int medals[3];
public:
	static const int GOLD{ 0 };
	static const int SILVER{ 1 };
	static const int BRONZE{ 2 };
	MedalRow(const char* countryP, const int* medalsP)
	{
		strcpy_s(country, 4, countryP ? countryP : "NON");
		for (int i = 0; i < 3; i++)
		{
			medals[i] = medalsP ? medalsP[i] : 0;
		}
	}
	MedalRow() : MedalRow(nullptr, nullptr){}
	MedalRow& setCountry(const char* countryP)
	{
		if (countryP)
			strcpy_s(country, 4, countryP);
		return *this;
	}
	const char* getCountry()const { return country; }
	int& operator[](int idx)
	{
		assert((idx >= 0 and idx < 3) and "Index is out of range!");
		return medals[idx];
	}
	int operator[](int idx) const
	{
		assert((idx >= 0 and idx < 3) and "Index is out of range!");
		return medals[idx];
	}
	void Print() const
	{
		cout << '[' << country << "] - ( ";
		for (int i = 0; i < 3; i++)
		{
			cout << medals[i];
			if (i < 2) { cout << "\t"; }
		}
		cout << ")" << endl;
	}
};

class MedalsTable
{
public:
	static const int maxSize{ 10 };
private:
	MedalRow medalRows[MedalsTable::maxSize];
	int size;
	int findCountry(const char* country) const
	{
		for (int i = 0; i < size; i++)
		{
			if (strcmp(medalRows[i].getCountry(), country) == 0)
				return i;
		}
		return -1;
	}
public:
	MedalsTable() : size{ 0 } {}
	MedalRow& operator[](const char* country)
	{
		int idx{ findCountry(country) };
		if (idx == -1)
		{
			assert(size < MedalsTable::maxSize and "Table is Full!");
			idx = size++;
			medalRows[idx].setCountry(country);
		}
		return medalRows[idx];
	}
	const MedalRow& operator[](const char* country) const
	{
		int idx{ findCountry(country) };
		assert(idx != -1 and "Country not found on const table");

		return medalRows[idx];
	}
	void Print() const
	{
		for (int i = 0; i < size; i++)
		{
			medalRows[i].Print();
		}
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	MedalsTable mt;
	cout << "Medal table #1\n";
	mt["RUS"][MedalRow::GOLD] = 15;
	mt["RUS"][MedalRow::SILVER] = 12;
	mt["KAZ"][MedalRow::GOLD] = 7;
	mt["KAZ"][MedalRow::BRONZE] = 15;
	mt["BEL"][MedalRow::SILVER] = 15;
	mt["BEL"][MedalRow::BRONZE] = 3;
	mt["BEL"][MedalRow::GOLD] = 5;
	mt.Print();

	cout << "Medal table #2\n";
	const MedalsTable mt1{ mt };
	mt1.Print();
	
	return 0;
}
