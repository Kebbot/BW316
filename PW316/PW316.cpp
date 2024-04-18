#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <cassert>
#include <conio.h>
#include "HeadClass.h"
using namespace std;

/*template<class T>
struct Point
{
	T x;
	T y;
	void display()
	{
		cout << "(" << x << "," << y << ")";
	}
};
template<class T>
struct ArrayP
{
	vector<T> data;
	void Add(T item)
	{
		data.push_back(item);
	}
	void display()
	{
		for (auto var : data)
			cout << var << " ";
	}
};
template<template<class> class T, class T1>
struct Some
{
	T<T1> data; // создается переменная data,
	// типом которой будет шаблон класса T,
	// принимающий параметр-тип T1
	void Add(T1 item)
	{
		data.Add(item);
	}
	void display()
	{
		data.display();
		cout << endl;
	}
};*/

/*template<class T>
T Max(T t1, T t2)
{
	return(t1 > t2 ? t1 : t2);
}
//Специализация шаблона 
/*template<>
const char* Max<const char*>(const char* t1, const char* t2)
{
	return (strcmp(t1, t2) > 0 ? t1 : t2);
}*/

/*template<class T>
void getValue(string promp, T& value)
{
	cout << promp;
	cin >> value;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Error... try again" << endl;
		cout << promp;
		cin >> value;
	}
	string endLine;
	getline(cin, endLine);
}

template<>
inline void getValue<string>(string promp, string& value)
{
	cout << promp;
	getline(cin, value);
}*/
//Полная специализация шаблонов класса 
// template <> className<dataTypeList> {classDefinition}

template<class T>
class List
{
	vector<T> list;
public:
	void add(T item)
	{
		list.push_back(item);
	}
	void remove(int index)
	{
		list.erase(list.begin() + index);
	}
	auto getMin()
	{
		auto pMin = list.begin();
		for (auto it = list.begin(); it < list.end(); it++)
		{
			if (*it < *pMin)
			{
				*pMin = *it;
			}
		}
		return *pMin;
	}
	auto getMax()
	{
		auto pMax = list.begin();
		for (auto it = list.begin(); it < list.end(); it++)
		{
			if (*it > *pMax)
			{
				*pMax = *it;
			}
		}
		return *pMax;
	}
};

template<>
class List<const char*>
{
	vector<const char*> list;
public:
	void add(const char* item)
	{
		list.push_back(item);
	}
	void remove(int index)
	{
		list.erase(list.begin() + index);
	}
	auto getMin()
	{
		auto pMin = list.begin();
		for (auto it = list.begin(); it < list.end(); it++)
		{
			if (strcmp(*it, *pMin)<0)
			{
				pMin = it;
			}
		}
		return *pMin;
	}
	auto getMax()
	{
		auto pMax = list.begin();
		for (auto it = list.begin(); it < list.end(); it++)
		{
			if (strcmp(*it, *pMax) > 0)
			{
				pMax = it;
			}
		}
		return *pMax;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	List<int> intList;
	intList.add(4);
	intList.add(3);
	intList.add(5);
	intList.add(2);
	cout << "intList min: " << intList.getMin() << endl;
	cout << "intList max: " << intList.getMax() << endl;
	cout << endl;

	List<string> strList;
	strList.add("four");
	strList.add("five");
	strList.add("two");
	strList.add("three");
	cout << "strList min: " << strList.getMin() << endl;
	cout << "strList max: " << strList.getMax() << endl;
	cout << endl;

	List<const char*> txtList;
	txtList.add("four");
	txtList.add("two");
	txtList.add("five");
	txtList.add("three");
	cout << "txtList min: " << txtList.getMin() << endl;
	cout << "txtList max: " << txtList.getMax() << endl;
	cout << endl;



	/*// структура Point с целыми x,y
	Some<Point, int> intPoint;
	intPoint.data.x = 1;
	intPoint.data.y = 2;
	cout << "Some: struct Point with int x, y : ";
	intPoint.display();
	// структура Point с плавающими x,y
	Some<Point, double> doublePoint;
	doublePoint.data.x = 10.01;
	doublePoint.data.y = 0.02;
	cout << "Some: struct Point with double x,y : ";
	doublePoint.display();
	// массив (вектор) целых
	Some<ArrayP, int> intArray;
	intArray.Add(1);
	intArray.Add(3);
	intArray.Add(5);
	cout << "Some: array (vector) with int items: ";
	intArray.display();*/
	return 0;
}
