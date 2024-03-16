#include "HeadFunction.h"
#include <iostream>
using namespace std;


void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}


void ShowArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 99;
	}
}
int Min(int* arr, int size)
{
	int temp = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (temp < arr[i])
			temp = arr[i];
	}
	return temp;
}

void ShowArr(double* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = (rand() % 100) / 3.0;
	}
}
double Min(double* arr, int size)
{
	double temp = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (temp < arr[i])
			temp = arr[i];
	}
	return temp;
}

