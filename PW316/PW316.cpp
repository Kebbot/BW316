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


namespace combat
{
	void fire()
	{
		cout << "Выстрел!" << endl;
	}
}
namespace exploration
{
	void fire()
	{
		cout << "Огонь, свет, туда суда" << endl;
	}
}

namespace x
{
	void func1(){}
}
namespace x
{
	void func2() {}
}
namespace //f - предположительное имя пространства
{
	void func2() {}
}



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	combat::fire();
	exploration::fire();
	::func2();
	
	return 0;
}