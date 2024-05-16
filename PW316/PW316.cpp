#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <io.h>
#include <sys/locking.h>
#include "BinaryTree.h"
using namespace std;
/*// Глобальный класс (А)
class A
{
public:
	int init(int);
private:
	class B
	{
	public:
		//friend class A; //объявление друга
		B(int val = 0); //Конструктор
		void mf( A&);
		int value;
		static int static_mem;
	};
	//class Ref {
	//	B* pli; //pli - имеет тип A::B*
	//};
	//class B {
	//	Ref* pRef; // pRef - имеет тип A::Ref*
	//};
	//B num; 
	// //Компилятор пока не видит определения 
	// вложенного класса и не может создать объект
	//поэтому можно создавать только ссылки и указатели
};

void A::B::mf( A& i1)
{
	int memb = i1.init(5);
}
A::B::B(int val = 0)
{
	//A::init() - ошибка нестатическое поле класса А должно использоваться через
	//объект или указатель на тип А
	value = val;
}

int A::B::static_mem = 1024;

class B
{
public:
	//Вложенный класс А, Он инкапсулирован внутри области видимости класса В
	class A {};

	A* obj; //Тут используется вложенный класс А
};*/

/*//класс "точка"
class Point {
	//кооординаты
	int X;
	int Y;
public:
	//конструктор
	Point() {
		X = Y = 0;
	}
	//установка координат
	void SetPoint(int iX, int iY) {
		X = iX;
		Y = iY;
	}
	//демонстрация координат
	void Show() {
		cout << "----------------------------\n\n";
		cout << X << "\t" << Y << "\n\n";
		cout << "----------------------------\n\n";
	}
};
//класс фигура
class Figura {
	//агрегация точки
	//(координаты углов)
	Point* obj;
	//количество углов
	int count;
	//цвет фигуры
	int color;
public:
	//конструктор
	Figura() {
		count = color = 0;
		obj = NULL;
	}
	//создание фигуры
	void CreateFigura(int cr, int ct) {
		//если углов меньше трех — это не фигура
		if (ct < 3) exit(0);
		//инициализация цвета и количества углов
		count = ct;
		color = cr;
		//выдделение памяти под массив точек
		obj = new Point[count];
		if (!obj) exit(0);
		//установка координат точек
		int tempX, tempY;
		for (int i = 0; i < count; i++) {
			cout << "Set X\n";
			cin >> tempX;
			cout << "Set Y\n";
			cin >> tempY;
			obj[i].SetPoint(tempX, tempY);
		}
	}
	//показ фигуры
	void ShowFigura() {
		cout << "----------------------------\n\n";
		cout << "Color" << color << "\n\nPoints — "<<count<<"\n\n";
			for (int i = 0; i < count; i++) {
				obj[i].Show();
			}
	}
	//если фигура была очистить память
	~Figura() {
		if (obj != NULL) delete[]obj;
	}
};*/

/*
* class имя_класса : спецификатор_наследования имя_базового_класса
* { описание_класса }
*/

class Flat
{
	int numer_Flat; //номер квартиры 
	int Human_live; // количесво жильцов
	int num_rooms; //кол-во комнат
public:
	Flat()
	{
		numer_Flat = 0;
		Human_live = 0;
		num_rooms = 0;
	}
	Flat(int Inumer_Flat, int IHuman_live, int Inum_rooms)
	{
		numer_Flat = Inumer_Flat;
		Human_live = IHuman_live;
		num_rooms = Inum_rooms;
	}
	void display()
	{
		cout << "Nuber Flatt: " << numer_Flat << endl;
		cout << "Count human: " << Human_live << endl;
		cout << "Count rooms: " << num_rooms << endl;
	}
};

class Home : public Flat
{
	string name_street; // улица
public:
	Home(int Inumer_Flat, 
		int IHuman_live, 
		int Inum_rooms, 
		string Iname_street) : Flat(Inumer_Flat, IHuman_live, Inum_rooms)
	{
		name_street = Iname_street;
	}
	void Print()
	{
		cout << "Street Home: " << name_street << endl;
		display();
	}
};

class Roga
{
protected:
	char color[30];
	int ves;
public:
	Roga()
	{
		strcpy_s(color, "Brown");
		ves = 10;
	}
	Roga(const char* c, int v)
	{
		strcpy_s(color, c);
		ves = v;
	}
};

class Kopyta
{
protected:
	char forma[30];
	int razmer;
public:
	Kopyta()
	{
		strcpy_s(forma, "Big");
		razmer = 10;
	}
	Kopyta(const char* f, int r)
	{
		strcpy_s(forma, f);
		razmer = r;
	}
};

class Los : public Roga, public Kopyta
{
	char name[250];
public:
	Los(const char* n, const char* c, int v, const char* f, int r) :
		Kopyta( f, r), Roga( c, v)
	{
		strcpy_s(name, n);
	}
	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Forma: " << forma << endl;
		cout << "Color: " << color << endl;
		cout << "Ves Rogov: " << ves << endl;
		cout << "Razmer kopyt: " << razmer << endl;
		
	}
};

class Buf : public Roga, public Kopyta
{
	char name[250];
public:
	Buf(const char* n, const char* c, int v, const char* f, int r) :
		Kopyta(f, r), Roga(c, v)
	{
		strcpy_s(name, n);
	}
	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Forma: " << forma << endl;
		cout << "Color: " << color << endl;
		cout << "Ves Rogov: " << ves << endl;
		cout << "Razmer kopyt: " << razmer << endl;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	Los los("Osas", "Purple", 20, "Krug", 15);
	los.Print();
	cout << endl << "_____________________" << endl;
	Buf buf("Pen", "Orange", 40, "Dual", 30);
	buf.Print();
	

	/*Figura f;
	f.CreateFigura(255, 3);
	f.ShowFigura();*/

	/*// Вложенный класс А не видим в данной области видимости
	//Тут у нас используется глобальный класс А
	A* obj2;*/

	return 0;
}