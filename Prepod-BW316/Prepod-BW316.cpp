#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <io.h>
#include "HeadFunction.h"
using namespace std;
#define SHOW INTEGER


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    const int size = 10;
#ifdef SHOW
    int arr[size];
    ShowArr(arr, size);
    cout << Min(arr, size) << endl;
#endif

   


    double mass[size];
    ShowArr(mass, size);
    cout << Min(mass, size) << endl;
   
  
	return 0;
}
