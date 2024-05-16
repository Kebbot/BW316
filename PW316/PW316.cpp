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

/*class A
{
public:
	virtual void v_function();//описывает некое поведение класса А
};
class B : public A
{
	//Заменяющая функция описывает некое новое поведение класса B
	virtual void v_function(void);
};
class C : public B
{

};

class Weapon
{
	int TypeOfWeapon;
public:
	virtual void Use1(void);//левая кнопка мыши
	virtual void Use2(void);//правая кнопка мыши
};
Weapon* Arms[10];//массив указателей на объекты Weapon*/

class Animal
{
public:
	char Title[30]; //Кличка животного
	Animal(const char* t) { strcpy_s(Title, t); } //Конструктор
	virtual void speak() = 0; //Чисто виртуальная функция
};

class Frog :public Animal
{
public:
	Frog(const char* Title) : Animal(Title) {};
	virtual void speak()
	{
		cout << Title << " Say " << "\'kwa-kwa\'" << endl;
	}
};

class Dog :public Animal
{
public:
	Dog(const char* Title) : Animal(Title) {};
	virtual void speak()
	{
		cout << Title << " Say " << "\'gav-gav\'" << endl;
	}
};
class Cat :public Animal
{
public:
	Cat(const char* Title) : Animal(Title) {};
	virtual void speak()
	{
		cout << Title << " Say " << "\'MMIIIAAAAAAAA-MMIIIAAAAAAAA\'" << endl;
	}
};

class Lion :public Cat
{
public:
	Lion(const char* Title) : Cat(Title) {};
	virtual void speak()
	{
		cout << Title << " Say " << "\'RRRR-RRRRR\'" << endl;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	Animal* animals[4] =
	{
		new Dog("Pich"),
		new Cat("Gav"),
		new Frog("Vasya"),
		new Lion("Pushistick")
	};
	for (int i = 0; i < 4; i++)
	{
		animals[i]->speak();
	}

	/*A object_A;
	B object_B;
	C object_C;

	A* point_To_obj; //Указатель на базовый класс
	point_To_obj = &object_C; //Присваиваем адрес класса потомка, потомка
	point_To_obj = &object_B;//Присваиваем адрес класса потомка
	point_To_obj->v_function();*/

	return 0;
}