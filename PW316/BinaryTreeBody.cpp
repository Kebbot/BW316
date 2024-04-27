#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "BinaryTree.h"
using namespace std;

Tree::Tree()
{
	root = NULL;
}
Tree::~Tree()
{
	Del();
}
//����������� ����� ������
void Tree::Print(Elem* Node)
{
	if (Node != 0)
	{
		Print(Node->left);
		cout << Node->OwnerPoints << ' '
			<< Node->Name
			<< Node->Match
			<< Node->Opponent 
			<< ' ' << Node->OppPoints
			<< endl;
		Print(Node->right);
	}
}
Elem* Tree::Search(Elem* Node, char* k)
{
	//���� ���� ���� � ����� �� ���������
	while (Node != 0 && strcmp(k, Node->Name) != 0)
	{
		if (strcmp(k, Node->Name) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	return Node;
}
Elem* Tree::Min(Elem* Node)
{
	//����� ������ "������" ����
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}
Elem* Tree::Max(Elem* Node)
{
	//����� ������ "�������" ����
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}
Elem* Tree::Next(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//���� ���� ������ �������
		if (Node->right != 0)
			return Min(Node->right);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node ������
		while (y != 0 && Node == y->right)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
Elem* Tree::Previous(Elem* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//���� ���� ����� �������
		if (Node->left != 0)
			return Max(Node->left);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node �����
		while (y != 0 && Node == y->left)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
Elem* Tree::getRoot()
{
	return root;
}
void Tree::Insert(Elem* z)
{
	//�������� ���
	z->left = NULL;
	z->right = NULL;
	Elem* y = NULL;
	Elem* Node = root;
	//����� �����
	while (Node != 0)
	{
		//������� ��������
		y = Node;
		if (strcmp(z->Name, Node->Name) < 0)
			Node = Node->left;
		else
			Node = Node->right;
	}
	//��������� ��������
	z->parent = y;
	if (y == 0) //������� ������ (������������)
		root = z;
	//��� ���� ������?
	else if (strcmp(z->Name, y->Name) < 0)
		y->left = z;
	else
		y->right = z;
}
void Tree::Del(Elem* z)
{
	//�������� �����
	if (z != 0)
	{
		Elem* Node, * y;
		//�� 2 �������
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);
		if (y->left != 0)
			Node = y->left;
		else
			Node = y->right;
		if (Node != 0)
			Node->parent = y->parent;
		//��������� �������� ����?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//����� �� ��������?
			y->parent->left = Node;
		else
			//������ �� ��������?
			y->parent->right = Node;
		if (y != z)
		{
			//����������� ������ ����
			strcpy_s(z->Name, y->Name);
			strcpy_s(z->Opponent, y->Opponent);
			strcpy_s(z->Match, y->Match);
			z->OppPoints = y->OppPoints;
			z->OwnerPoints = y->OwnerPoints;
		}
		delete y;
	}
	else //�������� ����� ������
		while (root != 0)
			Del(root);
}


