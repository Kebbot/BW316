#pragma once

void PrintArr(int* arr, int size);
// - ������� ������� ������

#define INTEGER

#ifdef INTEGER
void ShowArr(int* arr, int size);
int Min(int* arr, int size);

#endif // INTEGER

#define DOUBLE

#ifdef DOUBLE
void ShowArr(double* arr, int size);
double Min(double* arr, int size);
// - ������� ������� ������
#endif // DOUBLE
