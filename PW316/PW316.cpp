#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

//Максимальная длинна пути к файлу
#define MAX_PATH 260
//Кол-во столбцов на экране
#define NUM_COLS 18
//Кол-во строк на экране
#define NUM_ROWS 24
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	char path[MAX_PATH];
	//запрашиваем путь к файлу
	cout << "Input path to file: ";
	cin.getline(path, MAX_PATH);

	int counter = 0, i = 0, j = 0;
	char text[NUM_COLS];

	//Открытие файла  в двичном режиме
	ifstream input(path, ios::in | ios::binary);
	if (!input)
	{
		cout << "Can Not open file for display!" << endl;
		return;
	}
	//Режим отображения в верхнем регистре 
	// для шеснадцатиричного ввода
	cout.setf(ios::uppercase);

	//Пока не конец файла, читаем из него данные
	// и проводим форматированный вывод на экран
	while (!input.eof());
	{
		//Посимвольное чтение
		for ( i = 0; (i < NUM_COLS && !input.eof()); i++)
		{
			input.get(text[i]);
		}
		if (i < NUM_COLS)
			i--;
		for (j = 0; j < i; j++)
			if ((unsigned)text[j] < 0x10)
				//кол-во символом для отображения числа 
				// меньше чем 2?
				cout << setw(2) << 0 << hex << (unsigned)text[j];
			else
				cout << setw(3) << hex << (unsigned)text[j];
		//выравнивание для незавершенной строки
		for (; j < NUM_COLS; j++)
			cout << "      ";
		cout << "\t";
		for (j = 0; j < i; j++)
			//символ не является управляющим?
			if (text[j] > 31 && text[j] <= 255)
				cout << text[j];
			else
				cout << ".";
		cout << "\n";
		//Если экран уже заполнен,
//производим остановку
		if (++counter == NUM_ROWS)
		{
			counter = 0;
			cout << "Press any key to continue..." <<
				flush;
			//Ожидаем нажатия любой клавиши
			getch();
			cout << "\n";
		}
	}
	//Закрываем файл
	input.close();
	

	return 0;
}