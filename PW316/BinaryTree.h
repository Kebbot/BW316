#pragma once

struct Elem
{
	int OwnerPoints; // Очки хозяина поля
	int OppPoints; // Очки соперника
	char Match[10]; // Счет
	char Name[20]; // Команда
	char Opponent[20]; // Соперник
	Elem* left, * right, * parent;
};

class Tree
{
	// Корень
	Elem* root;
public:
	Tree();
	~Tree();

	//Печать от указанного узла
	void Print(Elem* Node);
	
	//Поиск от указанного узла
	Elem* Search(Elem* Node, char* key);

	//Min от указанного узла
	Elem* Min(Elem* Node);

	//Max от указанного узла
	Elem* Max(Elem* Node);

	// Следующий для указанного узла
	Elem* Next(Elem* Node);

	// Предыдущий для указанного узла
	Elem* Previous(Elem* Node);

	//Вставка узла
	void Insert(Elem* z);

	//Удаление ветки для указанного узла
	void Del(Elem* z = 0); //0 - Удаление всего древа

	//Получить корень
	Elem* getRoot();
};

