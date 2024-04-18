#pragma once
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
class Student
{
	char* full_name;
	int markCount;
	int* marks;
public:
	
	//Set'эры
	void createName(const char* studentName);
	void setName(const char* studentName);
	void setMarks(int mark, int index);

	//Get'эры
	const char* getName() { return full_name; }
	int getMarks(int index) { return marks[index]; }

	//Конструкторы и деструктор

	Student(); // конструктор по умолчанию
	Student(const char* studentName);
	Student(const char* studentName,
		const int studentMarkCount);
	Student(const char* studentName,
		const int studentMarkCount,
		const int* studentMarks);
	/*~Student();*/ // деструктор
	//Обычные методы
	double getAver();
};
void stopProgram(string message);

template<class T> //<class T = int, int size = 10>
//Array<int,10> intArray 
class Array
{
	static const size_t size{ 5 };
	T arr[size];
public:
	Array();
	int getSize() const { return size; }
	T getItem(size_t index) const;
	void setItem(size_t index, T value);
	void display();
	void sort();
};
// Поля класса Array
template <class T>
Array<T>::Array() {
	for (int i = 0; i < size; i++)
	{
		arr[i] = T();
	}
}
template <class T>
T Array<T>::getItem(size_t index) const {
	if (index >= 0 && index < size)
		return arr[index];
	else
		stopProgram("Index is out of range!");
}
template <class T>
void Array<T>::setItem(size_t index, T value) {
	if (index >= 0 && index < size)
		arr[index] = value;
	else
		stopProgram("Index is out of range!");
}
template <class T>
void Array<T>::display() {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
template <class T>
void Array<T>::sort()
{
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}
