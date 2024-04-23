#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <cassert>
#include <conio.h>
#include <initializer_list>
#include "HeadClass.h"
using namespace std;



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


//шаблоны с неопределенным количеством параметров
/*double getSum(double x) {
	return x;
}
template <class...Args>
double getSum(double x, Args ... args) {
	return x + getSum(args...);
}

void print() // ничего не делает
{}
template <class First, class... Other>
void print(const First& first,const Other&... other)
{
	cout << first;
	print(other...);
}
template <class... Args>
void println(const Args&... args)
{
	print(args...);
	cout << endl;
}
struct Point
{
	int x;
	int y;
	friend std::ostream& operator<<(std::ostream& output, const Point& p)
	{
		output << "(" << p.x << "," << p.y << ")";
		return output;
	}
};*/

template<class T>
class DynArray
{
	int length;
	T* data;
public:
	DynArray():length(0),data(nullptr){}
	DynArray(int length) : length(length)
	{ data = new T[length]; }
	DynArray(const std::initializer_list<T>& list) : DynArray(list.size())
	{
		int i = 0;
		for (auto& element : list)
		{
			data[i] = element;
			i++;
		}
	}
	~DynArray()
	{
		delete[] data;
	}
	T& operator[](int index) { return data[index]; }
	int getLength() const { return length; }
};

struct Point
{
	int x;
	int y;
	friend std::ostream& operator<<(std::ostream& output, const Point& p)
	{
		output << "(" << p.x << "," << p.y << ")";
		return output;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	// С-стайл строки
	/*char ch{'a'};
	char8_t ch8{ u8'a' }; 
	char16_t ch16{ u'a' };
	char32_t ch32{ U'a' };
	wchar_t chw{ L'a' }; //нестандартный тип*/
	/* минусы
	* 1. Их невозможно сравнивать посредством операторов сравнения (==,<,>)
	* 2. Нельзя присваивать значения одного массива другому
	* 3. Не все функции интуитивно понятны
	*/
	/* плюсы
	* 1. Эффективны по скорости.
	* 2. У них есть большая библиотека функций
	*/

	//string text{"Hello"}; //Инициализация как const char*
	//string text1(8,'a'); //Строка из 8 символов 'a'
	
	//char arr[]{ 'a', 'b', 'c','\0','a','b', 'c' };
	string mass;
	
	getline(cin, mass);
	
	cout << "| " << mass << " |" << endl;
	cout << "| " << mass.find("Арман") << " |" << endl;
	
	
	//typedef basic_string<char> string;
	/*
	* 1. Легко редактировать
	* 2. Защищен от ошибок выхода за пределы массива
	* 3. У них есть большая библиотека функций
	*/

	/*DynArray<int> intarray{1,2,3,4,5,6,7,8,9,12,3,13,135,53,1,54,53};
	for (int i = 0; i < intarray.getLength(); i++)
	{
		cout << intarray[i] << ' ';
	}
	cout << endl;
	
	DynArray<Point> pointArray{ Point{1,1}, Point{2,2}, Point{7,7} };

	for (int i = 0; i < pointArray.getLength(); i++)
	{
		cout << pointArray[i] << ' ';
	}
	cout << endl;

	DynArray<string> strArray{ "one","two","three","chetire"};

	for (int i = 0; i < strArray.getLength(); i++)
	{
		cout << strArray[i] << ' ';
	}
	cout << endl;*/
	/*println("Hello, world");
	println("Hello, world",' ', 
		"Hello, Point", ' ', 
		"Hello, C++", ' ',
		"Hello, OOP for C++");
	println("Pi = ", 3.14, '\n', 2, " * ", 2, " = ", 2 * 2);
	Point point{ 12,2 };
	println("Point: ", point);*/

	/*double sum = getSum(1, 2, 3, 4, 5);
	cout << "sum: " << sum;*/

	/*List<int> intList;
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
	cout << endl;*/

	return 0;
}
