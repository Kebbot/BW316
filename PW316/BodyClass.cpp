#include <iostream>
#include "HeadClass.h"
using namespace std;
//Конструкторы и деструктор
Student::Student() 
{ 
	cout << "Конструктор по умолчанию отработал" << this << endl;
	full_name = nullptr;
	marks = nullptr;
	markCount = 0;
}
Student::Student(const char* studentName) { createName(studentName); }
Student::Student(const char* studentName,
	const int studentMarkCount)
{
	createName(studentName); //присвоили имя

	marks = new int[studentMarkCount];
	markCount = studentMarkCount;
	for (int i = 0; i < studentMarkCount; i++)
	{
		marks[i] = 0;
	}
}
Student::Student(const char* studentName,
	const int studentMarkCount,
	const int* studentMarks)
{
	createName(studentName); //присвоили имя

	marks = new int[studentMarkCount];
	markCount = studentMarkCount;
	for (int i = 0; i < studentMarkCount; i++)
	{
		marks[i] = studentMarks[i];
	}
}
//Student::~Student()
//{
//	
//	if(full_name != nullptr)
//	delete[] full_name;
//
//	if (marks != nullptr)
//	delete[] marks;
//	cout << "Отработал деструктор" << this << endl;
//	
//	
//}

//Set'эры
void Student::createName(const char* studentName)
{
	int nameLength = strlen(studentName);
	full_name = new char[nameLength + 1];
	for (int i = 0; i <= nameLength; i++)
	{
		full_name[i] = studentName[i];
	}
}
void Student::setName(const char* studentName)
{
	delete[] full_name;
	createName(studentName);
}
void Student::setMarks(int mark, int index)
{
	if (index < 0 or index >= markCount)
		return;
	if (mark < 1 or mark > 12)
		mark = 0;
	marks[index] = mark;
}

//Обычные методы
double Student::getAver()
{
	double sum = 0;
	for (int i = 0; i < markCount; i++)
	{
		sum += marks[i];
	}
	return sum / markCount;
}

void stopProgram(string message)
{
	cout << message << endl;
	cout << "Press any key to exit Program" << endl;
	exit(1);
}