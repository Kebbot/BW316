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

class Queue
{
	//Очередь
	int* Wait;
	int MaxQueueLength; //максимальный размер
	int QueueLength; //текущий размер очереди
public:
	Queue(int m);
	~Queue();
	void Add(int c);
	void Clear();
	int Exract();
	bool isEmpty();
	bool isFull();
	int getCount();
	void Show();
};
void Queue::Show()
{
	cout << "\n________________________________________\n";
	for (int i = 0; i < QueueLength; i++)
	{
		cout << Wait[i] << " ";
	}
	cout << "\n________________________________________\n";
}
Queue::~Queue()
{
	delete[] Wait;
}
Queue::Queue(int m)
{
	MaxQueueLength = m;
	Wait = new int[MaxQueueLength];
	QueueLength = 0;
}
void Queue::Clear()
{
	QueueLength = 0;
}
bool Queue::isEmpty()
{
	return QueueLength == 0;
}
bool Queue::isFull()
{
	return QueueLength == MaxQueueLength;
}
int Queue::getCount()
{
	return QueueLength;
}
void Queue::Add(int c)
{
	if (!isFull())
		Wait[QueueLength++] = c;
}
int Queue::Exract()
{
	if (!isEmpty())
	{
		int temp = Wait[0];
		for (int i = 1; i < QueueLength; i++)
		{
			Wait[i - 1] = Wait[i];
		}
		QueueLength--;
		return temp;
	}
	else
	{
		return -1;
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	Queue QU(25);
	for (int i = 0; i < 5; i++)
	{
		QU.Add(rand() % 50);
	}
	QU.Show();
	QU.Exract();
	QU.Show();
	cout << "Элементов в очереди " << QU.getCount() << endl;



	//Stack ST;
	//char c;
	//while (!ST.isFull())// Пока не будет полон
	//{
	//	c = 32 + rand() % 128;
	//	cout << c << " ";
	//	ST.Push(c);
	//}
	//cout << endl << endl;
	//while (c = ST.Pop())
	//{
	//	cout << c << " ";
	//}
	//cout << endl;
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