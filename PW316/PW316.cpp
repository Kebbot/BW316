#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Point
{
	Point(double x, double y): x{x}, y{y}{}
	double x;
	double y;
};

class Human
{
	string name;
	int age;
public:
	Human(string name, int age):name{name},age{age}{}
	string getName() const { return name; }
	int getAge() const { return age; }
	void setName(string humanName) { name = humanName; }
	void setAge(int humanAge) { age = humanAge; }
};

ostream& operator <<(ostream& os, const Human& human)
{
	return os << human.getName() << " " << human.getAge();
}
istream& operator >>(istream& in, Human& human)
{
	string name;
	int age;
	in >> name >> age;
	if (in)
	{
		human.setName(name);
		human.setAge(age);
	}
	return in;
}

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	vector<Human> humans =
	{
		Human{"Tom",40},
		Human{"Tim",45},
		Human{"Bob",25},
		Human{"Vince",40}
	};

	ofstream out("Humans.txt");
	if (out.is_open())
	{
		for (const Human& human:humans)
		{
			out << human << endl;
		}
	}
	out.close();

	vector<Human> newHumans;
	ifstream in("Humans.txt");
	if (in.is_open())
	{
		Human human{ "",0 };
		while (in >> human)
		{
			newHumans.push_back(human);
		}
	}
	out.close();

	for (const Human& human : newHumans)
	{
		cout << human << endl;
	}
	/*vector<Point> points{Point{0,0}, Point{4,5}, Point{-5,7}};
	ofstream out("Points.txt");
	if (out.is_open())
	{
		for (const Point& point : points)
		{
			out << point.x << " " << point.y << endl;
		}
	}
	out.close();*/

	/*string line;
	ifstream in("Hello.txt");
	
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}
	in.close();
	cout << "Чтение из файла прошло" << endl;*/
}