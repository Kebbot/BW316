#include <iostream>
#include <Windows.h>
#include <vector>
#include "HeadClass.h"
using namespace std;

/*
* class имя_класса
	{
		список_элементов_класса;
	};

	class - это ключевое слово, по которому компилятор понимает, что дальше должно быть описание класса
	имя_класса - это идентификатор,
*/

/* Конструктор
Имя_класса(список_параметров / нет)
{
	список_операторов / инструкции
}
*/

/* Деструктор
~Имя_класса()
{
	список_операторов 
}
*/
struct Point
{
	int x;
	int y;
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	//унифицированная инициализация
	int size{ 33 }; //простая переменная
	const float tmp{ 36.6 }; //константа
	int mass[3]{ 5,5,5 }; //одномерный массив
	int mass[3][3]{
		{5,5,5},
		{5,5,5},
		{5,5,5}
	}; //двумерный массив
	int* dataP{ nullptr }; //указатель
	char* str{ new char[14] {"hello, world!"} }; //указатель в стиле C
	int& ref{ size }; //ссылка
	Point point{ 11,-3 }; //экземпляр (объект) структуры
	/*int size = 5;
	vector<Student> student
	{
		{"Student 1", 5,new int[5] {12,12,9,5,10}},
		{"Student 2", 5,new int[5] {11,11,8,5,11}},
		{"Student 3", 5,new int[5] {12,12,9,5,10}},
		{"Student 4", 5,new int[5] {11,11,8,5,11}},
		{"Student 5", 5,new int[5] {12,12,9,5,10}},
	};
	for (int i = 0; i < size; i++)
	{
		double aver = student[i].getAver();
		cout << "Средний бал " << student[i].getName()
			<< " : " << aver << endl;
	}*/
	/*Student* student = new Student[size]
	{
		{"Student 1", 5,new int[5] {12,12,9,5,10}},
		{"Student 2", 5,new int[5] {11,11,8,5,11}},
		{"Student 3", 5,new int[5] {12,12,9,5,10}},
		{"Student 4", 5,new int[5] {11,11,8,5,11}},
		{"Student 5", 5,new int[5] {12,12,9,5,10}},
		
	};
	double sum = 0;
	for (Student* stud = student; stud < student + size; stud++)
	{
		double aver = stud->getAver();
		cout << "Средний бал " << stud->getName()
			<< " : " << aver << endl;
		sum += aver;
	}
	cout << "Средний бал по группе: " << sum / size << endl;
	delete[] student;*/

	/*Student student("Нуптуллин А.С", size,
		new int[size]{10,10,9,12,8});

	Student udent;
	cout << "Средний бал студента " << student.getName()
		<< " : " << student.getAver() << endl;*/
	
}

/*
1. Инкапсуляция - Ограничение доступа к перменным и методам класса
2. Наследование - Отношения между классами (роддительский - дочерний)
3. Полиморфизм - Одинаковые имена (методов) в разных классах
*/

/* Модификаторы доступа
* public - публичный доступ везде в программе
* private - доступ только в классе
* protected - достув в классе и в дочерних классах
*/

// след тема : Поняте аксессора, инспектора, модификатора
/*
set - методы = модификатор / мутатор
get - методы = Инспекторы / Аксессоры
*/
