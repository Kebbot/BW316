#pragma once

struct Elem
{
	int OwnerPoints; // ���� ������� ����
	int OppPoints; // ���� ���������
	char Match[10]; // ����
	char Name[20]; // �������
	char Opponent[20]; // ��������
	Elem* left, * right, * parent;
};

class Tree
{
	// ������
	Elem* root;
public:
	Tree();
	~Tree();

	//������ �� ���������� ����
	void Print(Elem* Node);
	
	//����� �� ���������� ����
	Elem* Search(Elem* Node, char* key);

	//Min �� ���������� ����
	Elem* Min(Elem* Node);

	//Max �� ���������� ����
	Elem* Max(Elem* Node);

	// ��������� ��� ���������� ����
	Elem* Next(Elem* Node);

	// ���������� ��� ���������� ����
	Elem* Previous(Elem* Node);

	//������� ����
	void Insert(Elem* z);

	//�������� ����� ��� ���������� ����
	void Del(Elem* z = 0); //0 - �������� ����� �����

	//�������� ������
	Elem* getRoot();
};

