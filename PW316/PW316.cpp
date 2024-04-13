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

/*class MedalRow
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
};*/


class Dyn2DArr
{
	int sizeY;
	int sizeX;
public:
	int** data;
	Dyn2DArr(int sizeYP, int sizeXP)
		: sizeY{ sizeYP }, sizeX{ sizeXP },
		data{ new int* [sizeYP] }
	{
		int* dataElements{ new int[sizeY * sizeX] };
		for (int y = 0; y < sizeY; y++)
		{
			data[y] = dataElements + y * sizeX;
		}
	}
	void Print()
	{
		for (int i = 0; i < sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
			{
				cout << data[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	~Dyn2DArr()
	{
		delete[] data[0];
		delete[] data;
	}
};

class Matrix
{
	int sizeY;
	int sizeX;
	int* data;
	int index2D(int y, int x) const {
		return y * sizeX + x;
	}
	int index2D(int y, int x, int sizeXP) const {
		return y * sizeXP + x;
	}
public:
	Matrix(int sizeYP, int sizeXP)
		: sizeY{ sizeYP }, sizeX{ sizeXP },
		data{ new int[sizeYP * sizeXP] } {}
	int operator()(int y, int x) const {
		return *(data + index2D(y, x));
	}
	int& operator()(int y, int x)
	{
		return *(data + index2D(y, x));
	}
	void deleteColumn(int columnPos)
	{
		--sizeX;
		int* newData{ new int[sizeY * sizeX] };
		for (int y{ 0 }; y < sizeY; ++y)
		{
			for (int x{ 0 }; x < sizeX; ++x)
			{
				*(newData + index2D(y, x)) =
					*(data + index2D(y, x + (x >=
						columnPos)));
			}
		}
		delete[] data;
		data = newData;
	}
	void addColumn(int columnPos, int* newCol = nullptr)
	{
		int* newData{ new int[sizeY * (sizeX + 1)] };
		for (int y{ 0 }; y < sizeY; ++y)
		{
			for (int x{ 0 }; x < sizeX; ++x)
			{
				*(newData + index2D(y, x + (x >= columnPos),
					sizeX + 1)) = *(data + index2D(y, x));
			}
			*(newData + index2D(y, columnPos, sizeX + 1)) =
				newCol ? *(newCol + y) : 0;
		}
		delete[] data;
		data = newData;
		++sizeX;
	}
	void deleteRow(int rowPos)
	{
		--sizeY;
		int* newData{ new int[sizeY * sizeX] };
		for (int y{ 0 }; y < sizeY; ++y)
		{
			for (int x{ 0 }; x < sizeX; ++x)
			{
				*(newData + index2D(y, x)) =
					*(data + index2D(y + (y >= rowPos),
						x));
			}
		}
		delete[] data;
		data = newData;
	}
	void addRow(int rowPos, int* newRow = nullptr)
	{
		int* newData{ new int[(sizeY + 1) * sizeX] };
		for (int y{ 0 }; y < sizeY; ++y)
		{
			for (int x{ 0 }; x < sizeX; ++x)
			{
				*(newData + index2D(y + (y >= rowPos), x)) =
					*(data + index2D(y, x));
			}
		}
		for (int x{ 0 }; x < sizeX; ++x)
		{
			*(newData + index2D(rowPos, x)) =
				newRow ? *(newRow + x) : 0;
		}
		delete[] data;
		data = newData;
		++sizeY;
	}
	void print()const
	{
		for (int y{ 0 }; y < sizeY; ++y)
		{
			for (int x{ 0 }; x < sizeX; ++x)
			{
				std::cout << (*this)(y, x) << '\t';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	~Matrix() { delete[] data; }
};

class Counter
{
	int cnt;
public:
	Counter(int start) : cnt{ start } {}
	Counter() : Counter(0) {}
	int operator()() { return cnt++; }
	void resrtTo(int start) { cnt = start; }
};

class PointArr
{
	const int size{ 6 };
	int* arr1; //{ 6, 8, 6, 7, 3}
	int* arr2; //{ 2, 5, 8, 7, 3}
	int* arr3; //сюда уникальные элементы {6,2,5}
	//которых нет в другом массиве (без повторов)
	
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	const int maxCnt{ 5 };
	Counter cnt1{};
	Counter cnt2{100};
	for (int i = 0; i < maxCnt; i++)
	{
		cout <<"cnt1: " << cnt1() << endl;
		cout << "cnt2: " << cnt2() << endl;
	}
	cout << endl;
	cnt1.resrtTo(10);
	cnt2.resrtTo(200);
	for (int i = 0; i < maxCnt; i++)
	{
		cout << "cnt1: " << cnt1() << endl;
		cout << "cnt2: " << cnt2() << endl;
	}
	cout << endl;

	/*Для ввожа в ручную поставьте значение USER_INPUT в 1*/
/*#define USER_INPUT 0;
	int rows{ 3 };
	int columns{ 3 };
	int counter{ 1 };
#if USER_INPUT == 1
	std::cout << "Enter matrix rows count\n";
	std::cin >> rows;
	std::cout << "Enter matrix columns count\n";
	std::cin >> rows;
#endif
	Matrix matrix{ rows, columns };
	for (int y{ 0 }; y < rows; ++y)
	{
		for (int x{ 0 }; x < columns; ++x)
		{
			matrix(y, x) = counter++;
		}
	}
	matrix.print();
	matrix.deleteColumn(2);
	matrix.print();
	int* newColumn{ new int[columns] {11,22,33} };
	matrix.addColumn(0, newColumn);
	matrix.print();
	matrix.deleteRow(2);
	matrix.print();
	int* newRow{ new int[rows] {111,222,333} };
	matrix.addRow(2, newRow);
	matrix.print();
	delete[] newRow;
	delete[] newColumn;*/

	/*int rows{ 3 };
	int colums{ 3 };
	int count{ 1 };
	Dyn2DArr arr2d{ rows,colums };
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colums; j++)
		{
			arr2d.data[i][j] = count++;
		}
	}
	arr2d.Print();*/
	
	return 0;
}
