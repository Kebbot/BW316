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
void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	
	//ifstream - для чтения с файла
	//ofstream - для записи в файл
	//fstream - совмещает запись и чтение

	//open(путь_к_файлу);
	//open(путь_к_файлу, режим_открытия);

	//ios::in - открытие файла для ввода (чтения), 
	// можно поставить только для ifstream и fstream
	ifstream in; //поток для чтения
	in.open("Hello.txt"); // открытие файла для чтения

	//ios::out - открытие файла для вывода (Записи), старые данные удаляются, 
	// можно поставить только для ofstream и fstream
	ofstream out; //поток для записи
	out.open("Hello1.txt"); // открытие файла для записи

	//ios::app - открытие для дозаписи в файл, старые данные не удаляются
	ofstream out2; //поток для записи
	out2.open("Hello2.txt", ios::app); // открытие файла для дозаписи

	//ios::ate - после открытия файла  перемещает указатель в конец файла

	//ios::trunc - файл усекается при открытии, (обнуление файла)
	ofstream out3; //поток для записи
	out2.open("Hello2.txt", ios::out | ios::trunc); //установка нескольких режимов

	//ios::binary - открывает файл в бинарном режиме


	fstream fs;
	fs.open("Hello3.txt");

	ofstream out4("Hello4.txt");
	ifstream in2("Hello5.txt");
	fstream fs2("Hello6.txt");
	if (fs2.is_open()) // если файл открыт
	{
		fs2.close();
	}



	/*char Answer;
	const int MessageCount = 8;
	int i, j;
	//Подсказки
	enum {
		CHOICE = 3, INPUT_FILENAME,
		INPUT_DIMENSIONS, INPUT_ELEMENTS,
		FILE_ERROR
	};
	//Сообщения
	char Msg[MessageCount][100]
	{
		"1. Вывести данные из текстового файла\n",
		"2. Записать данные в текстовый файл\n",
		"3. Выход из программы\n",
		"\nВаш выбор: ",
		"Введите имя обрабатываемого файла: ",
		"Введите размерности матрицы:\n",
		"Введите элементы матрицы:\n",
		"Невозможно открыть файл\n"
	};
	////Русификация сообщений и вывод меню на экран
	//for (i = 0; i < MessageCount; i++)
	//	CharToOem(Msg[i], Msg[i]);
	do
	{
		for (int i = 0; i < 4; i++)
			cout << Msg[i];
		cin >> Answer;
	} while (Answer < '1' || Answer > '3');
	if (Answer == '3')
		return;
	//Переменная для имени файла
	char FileName[80];
	//Размерности матрицы
	int M, N;
	int num;
	cout << "\n" << Msg[INPUT_FILENAME];
	cin >> FileName;
	//Если выбран первый пункт меню,
	//то выводим данные из текстового файла на экран
	if (Answer == '1')
	{
		//Если файл с указанным именем не существует,
		//выводим сообщение об ошибке
		ifstream inF(FileName, ios::in | ios::_Nocreate);
		if (!inF)
		{
			cout << endl << Msg[FILE_ERROR];
			return;
		}
		//Считываем размерность массива
		inF >> M;
		inF >> N;
		//Считываем элементы массива из файла и
		//выводим их сразу на экран
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				inF >> num;
				cout << setw(6) << num;
			}
			cout << endl;
		}
		inF.close();
	}
	//Если выбран второй пункт меню, то запрашиваем
	//у пользователя данные и выводим их в текстовый
	//файл
	else
	{
		//Открываем файл для записи.
		//Если файл с указанным именем не существует,
		//то программа создает его
		ofstream outF(FileName, ios::out);
		if (!outF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		//Запрашиваем размерность матрицы
		//и записываем данные в файл
		cout << Msg[INPUT_DIMENSIONS];
		cout << "M: ";
		cin >> M;
		cout << "N: ";
		cin >> N;
		outF << M << ' ' << N << "\n";
		cout << Msg[INPUT_ELEMENTS];
		//Запрашиваем элементы массива и записываем
		//их в файл
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				cout << "A[" << i << "][" << j << "] = ";
				cin >> num;
				outF << num << " ";
			}
			outF << "\n";
		}
		outF.close();
	}*/

	/*char path[MAX_PATH];
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
			_getch();
			cout << "\n";
		}
	}
	//Закрываем файл
	input.close();*/
	
	
}