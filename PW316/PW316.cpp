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
	int val;
};
class B : public virtual A {};
class C : public virtual A {};
class D : public B, public C 
{
public:
	int Get_val()
	{
		return val;
	}
};*/

class base
{
	char* sp1;
	int size;
public:
	base(const char* S, int s)
	{
		size = s;
		sp1 = new char[size];
		strcpy_s(sp1,size, S);
	}
	virtual ~base()
	{
		cout << "Base" << endl;
		delete[] sp1;
	}
};

class Derived : public base
{
	char* sp2;
	int size2;
public:
	Derived(const char* S1, int s1,
		const char* S2, int s2) : base(S1, s1)
	{
		size2 = s2;
		sp2 = new char[size2];
		strcpy_s(sp2, size2, S2);
	}
	virtual ~Derived()
	{
		cout << "Derived" << endl;
		delete[] sp2;
	}
};

class Something
{
public:
	virtual ~Something() = 0;
};
Something::~Something() {};

void Some()
{
	int a;
	int b;
	try
	{
		
		cout << "\nPut digit a:\n";
		cin >> a;
		cout << "\nPut digit b:\n";
		cin >> b;

		if (b == 0)
			throw "\tZEROOOO!!!\n";
	}
	catch (const char* s)
	{
		cout << "\nError!!! " << s << endl;
	}
	/*catch (...)
	{
		cout << "\nSome Error!!!!!\n";
	}*/
}

void Test(int t)
{
	cout << "\nInside!!\n";
	if (t == 2)
		throw "\nError - is 2\n";
	else if(t==3)
		throw "\nError - is 3\n";
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	cout << "\nStart!!!\n";

	// try - определяет блок кода где может возникнуть ошибка
	//throw - выводит программу из "исключительной" ситуации
	// catch - ловит, анализирует и выдет нужную реакцию

	try
	{
		Test(4);
		Test(2);
	}
	catch (const char* s)
	{
		cout << endl << s << endl;
		
	}
	
	return 0;
}