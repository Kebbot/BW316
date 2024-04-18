#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <cassert>
#include <conio.h>
#include "HeadClass.h"
using namespace std;

template <class T>
void MySort(T Array[], size_t size)
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (Array[j] > Array[j + 1])
				swap(Array[j], Array[j + 1]);
		}
	}
}
template <class T>
void display(T Array[], size_t size)
{
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
	cout << endl;
}
template <class T>
void getValue(string promt, T& value)
{
	cout << promt;
	cin >> value;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Error... Try again" << endl;
		cout << promt;
		cin >> value;
	}
	string endLine;
	getline(cin, endLine);
}

template <class T,int size> //size - параметр non-type в шаблоне класса
class StatArray
{
private:
	//Параметр non-type size определяет размер статического массива
	T m_array[size];
public:
	T* getArray();
	T& operator[](int index)
	{
		return m_array[index];
	}
};
template <class T, int size>
T* StatArray<T, size>::getArray()
{
	return m_array;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	

	const int size = 10;
	StatArray<int, size> intArray;
	for (int i = 0; i < size; i++)
		intArray[i] = i;
	for (int i = size - 1; i >= 0; i--)
	{
		cout << intArray[i] << ' ';
	}cout << endl;

	StatArray<double, size> douArray;
	for (int i = 0; i < size; i++)
		douArray[i] = 5.5 + 0.1 * i;
	for (int i = size - 1; i >= 0; i--)
	{
		cout << douArray[i] << ' ';
	}cout << endl;

	/*cout << "Class Array" << endl << endl;
	Array<int> intArray;
	cout << "int Array initialization:" << endl;
	intArray.display();
	int size = intArray.getSize();
	for (int i = size; i > 0; i--)
	{
		intArray.setItem(size - i, i);
	}
	cout << endl << "int Array after assignment:" << endl;
	intArray.display();
	intArray.sort();
	cout << endl << "int Array after ordering:" << endl;
	intArray.display();
	cout << endl;

	Array<string> strArray;
	cout << "str Array initialization:" << endl;
	strArray.display();
	strArray.setItem(9, "two");
	strArray.setItem(1, "seven");
	strArray.setItem(2, "zero");
	strArray.setItem(3, "four");
	strArray.setItem(4, "one");
	cout << endl << "str Array after assignment:" << endl;
	strArray.display();
	strArray.sort();
	cout << endl << "str Array after ordering:" << endl;
	strArray.display();
	cout << endl;

	cout << "Press any key to exit Program" << endl;*/

	/*cout << "MySort Template" << endl << endl;
	int intArray[]{ 1,3,5,-4,-2,4 };
	int size = sizeof(intArray) / sizeof(int);
	cout << "Original int Array : ";
	display<int>(intArray, size);
	MySort<int>(intArray, size);
	cout << "Sorted int Array : ";
	display<int>(intArray, size);

	char chrArray[]{ 'g','t','f','f','s','s','e','p','n' };
	size = sizeof(chrArray) / sizeof(char);
	cout << "Original char Array : ";
	display<char>(chrArray, size);
	MySort<char>(chrArray, size);
	cout << "Sorted char Array : ";
	display<char>(chrArray, size);

	string strArray[]{ "one","two","three","four","five" };
	size = sizeof(strArray) / sizeof(string);
	cout << "Original char Array : ";
	display<string>(strArray, size);
	MySort<string>(strArray, size);
	cout << "Sorted char Array : ";
	display<string>(strArray, size);*/
	return 0;
}
