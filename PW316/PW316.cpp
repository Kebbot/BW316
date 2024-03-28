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
//struct Point
//{
//	int x;
//	int y;
//};

/*class Point
{
	int x{ 100 };
	int y{ 100 };
public:
	Point() : x{ 0 }, y{ 0 } 
	{ cout << "Default point constuctor class\n"; }
	Point(int pX, int pY) : x{ pX }, y{ pY }
	{ cout << "Point parametr constuctor class\n";}
	int getX() { return x; }
	int getY() { return y; }
};

class RectangleP
{
	Point leftUpperCorner;
	int width;
	int height;
public:
	RectangleP() : leftUpperCorner{10,10}, width{0}, height{0}
	{ cout << "Default Rectangle constuctor class\n";}
	RectangleP(int x, int y, int widthP, int heightP) : 
		leftUpperCorner{ x,y }, width{ widthP }, height{ heightP }
	{cout << "Rectangle parametr constuctor class\n";}

};*/

/*
Point(int pX, int pY) : x{px}, y{pY} { Тело_конструктора}
*/

/*class BadOrder
{
	int fieldOne;
	int fieldTwo;
public:
	BadOrder(int param) : fieldTwo{ param },
		fieldOne{ fieldTwo +10 }{}
	void Print()
	{
		cout << "fieldOne = " << fieldOne << endl
			<< "fieldTwo = " << fieldTwo << endl;
	}
};

class GoogOrder
{
	int fieldOne;
	int fieldTwo;
public:
	GoogOrder(int param) : fieldOne{ param + 10}, 
		fieldTwo{ param } {}
	void Print()
	{
		cout << "fieldOne = " << fieldOne << endl
			<< "fieldTwo = " << fieldTwo << endl;
	}
};*/

class Human
{
	char* name;
	int age;
	int socialId;
public:
	Human(const char* nameP, int ageP, int socialIdP) :
		name{ nameP ? new char[strlen(nameP) + 1] : nullptr },
		age{ ageP }, socialId{ socialIdP }
	{
		if (name)
			strcpy_s(name, strlen(nameP) + 1, nameP);
		cout << "Human constructor" << endl;
	}
	Human() : Human{nullptr, 0,0}{}
	Human(const char* nameP) : Human{ nameP, 0,0 } {}
	Human(const char* nameP, int ageP) : Human{ nameP, ageP,0 } {}
	~Human()
	{
		if (name != nullptr)
			delete[] name;
		cout << "Human destructor" << endl;
	}
	void Print()
	{
		if (name)
			cout << "Name: " << name << endl
			<< "Age: " << age << endl
			<< "Social ID: " << socialId << endl;
		else
		{
			cout << "[empty Human]" << endl;
		}
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");

	Human no;
	no.Print();

	Human pers{ "Ivan Ivanov" };
	pers.Print();

	Human pers1{ "Ivan Ivanov", 25 };
	pers1.Print();

	Human pers2{ "Ivan Ivanov", 25, 123456789 };
	pers2.Print();

	/*cout << "BadOrder" << endl;
	BadOrder t1{ 42 };
	t1.Print();
	cout << endl;

	cout << "GoogOrder" << endl;
	GoogOrder t2{ 42 };
	t2.Print();*/

	/*RectangleP rect; //конструктор по умолчанию
	RectangleP rect1{ 42,33,10,5 };
	Point point{ 55,72 };
	cout << point.getX() << endl;
	cout << point.getY() << endl;*/

	/*//унифицированная инициализация
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
	Point point{ 11,-3 }; //экземпляр (объект) структуры*/
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
