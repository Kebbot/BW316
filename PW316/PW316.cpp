#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <time.h>
#include "HeadClass.h"
using namespace std;

class Stack
{
	//Нижнаяя и верхняя граница стека
	enum{EMPTY = -1, FULL = 20};

	//Массив для храниния данных
	char st[FULL + 1];

	//Указатель на вершину стека
	int top;
public:
	//Конструктор
	Stack();

	//Добавление элемента
	void Push(char c);

	//Извлечение элемента
	char Pop();

	//Очистка стека
	void Clear();

	//Проверка существования элементов
	bool isEmpty();

	//Проверка переполнения стека
	bool isFull();

	//Кол-во элементов в стеке
	int getCount();
};


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	Stack ST;
	char c;
	while (!ST.isFull())// Пока не будет полон
	{
		c = 32 + rand() % 128;
		cout << c << " ";
		ST.Push(c);
	}
	cout << endl << endl;
	while (c = ST.Pop())
	{
		cout << c << " ";
	}
	cout << endl;
	return 0;
}
Stack::Stack()
{
	//изначально стек пустой
	top = EMPTY;
}
void Stack::Clear()
{
	//данные в массиве все ещё будут, но методы класса будут их игнорить
	top = EMPTY;
}
bool Stack::isEmpty()
{
	//Пусто?
	return top == EMPTY;
}
bool Stack::isFull()
{
	//Полный??
	return top == FULL;
}
int Stack::getCount()
{
	//кол-во имеющихся в стеке элементов
	return top + 1;
}
void Stack::Push(char c)
{
	/*Если в стеке есть место, то увеличиваем указатель на вершину
	стека и вставляем новый элемент*/
	if (!isFull())
		st[++top] = c;
}
char Stack::Pop()
{
	/*если в стеке есть элементы, то возвращаем верхний элемент и 
	и уменьшаем указатель на вершину стека*/
	if (!isEmpty())
		return st[top--];
	else //Если в стеке нет элементов
		return 0;
}