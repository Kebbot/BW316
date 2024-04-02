#include <iostream>
#include <Windows.h>
#include <vector>
#include "HeadClass.h"
using namespace std;

/*class Human
{
	char* name;
public:
	Human(){}
	Human(const char* nameP)
	{
		if (nameP) {
			name = new char[strlen(nameP) + 1];
			for (int i = 0; i < strlen(nameP) + 1; i++)
			{
				name[i] = nameP[i];
			}
		}
		else
		{
			name = nullptr;
		}
	}
	Human(const Human& object)
	{
		for (int i = 0; i <= strlen(object.name); i++)
		{
			name[i] = object.name[i];
		}
	}
	
	Human& setName(char* nameP)
	{
		if (nameP != nullptr)
		{
			name = new char[strlen(nameP) + 1];
			strcpy_s(name, strlen(nameP) + 1, nameP);
		}
		return *this;
	}
	char* getName()
	{
		return name;
	}
};

class Flatt
{
	int countHuman;
	Human* human;
public:
	Flatt(int countHumanP, Human* humanP)
	{
		human = new Human[countHumanP];
		countHuman = countHumanP;
		for (int i = 0; i < countHumanP; i++)
		{
			human[i].setName(humanP[i].getName());
		}
	}
	void Print()
	{
		cout << "Flatt is " << this << " human here: ";
		for (int i = 0; i < countHuman; i++)
		{
			cout << human[i].getName() << endl;
		}
		cout << endl << endl;
	}
	char* getHumanName(int idx)
	{
		for (int i = 0; i < countHuman; i++)
		{
			if(idx == i)
			return human[i].getName();
		}
		
	}
	/*~Flatt()
	{
		if (human != nullptr)
			delete[] human;
	}
};

class Home
{
	Flatt* flat;

};
*/

class Account
{
private:
	double sum;
	const double rate;
public:
	Account(double Rate, double Sum) : rate{Rate}
	{
		this->sum = Sum;
	}
	double getRate() const { return rate; }
	double getIncome() { return sum * rate / 100; }
	double getIncome() const { return sum * rate / 100; }
	double getSum()  { return sum; }
	double getSum() const { return sum; }
	double setSum()  { sum += getIncome();  return sum; } //Ошибка
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	Account account1(2, 2000);
	const Account account2(8, 5000);

	account1.getRate();
	account2.getRate();

	account1.getSum();
	account2.getSum();
	
	return 0;
}
// Explicit
