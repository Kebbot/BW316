#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

class Human
{
public:
    string name;
    int age;
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int size = 10;

    // Инициализация Вектора
    vector<Human> number; // Пустой
    vector<Human> number_1(number); // Копия number
    vector<Human> number_2 = number; // Копия number (присвоеный)
    vector<Human> number_3(size); // Состоит из 10 чисел которые равны 0
    vector<int> number_4(10, 5); // Состоит из 10 чисел которые равны 5
    vector<int> number_5{ 5,4,3,2,1 }; // Состоит из чисел 5,4,3,2,1
    vector<int> number_6 = { 1,2,3,4,5 }; // Состоит из чисел 1,2,3,4,5

    number_3[0].age = 25;
    number_3[0].name = "Арман";

    cout << number_3.at(0).age << endl;
    cout << number_3.at(0).name << endl;

    number_4.at(0) = 40;
    number_4[1] = 3;
    cout << number_4.front() << endl;
    number_4.at(9) = 99;
    cout << number_4.back() << endl;

    vector<int> number_7;
    number_7.push_back(55);
    number_7.push_back(77);
    number_7.push_back(22);
    for (int n : number_7)
    {
        cout << n << ' ';
    }
    cout << endl;

    number_6.emplace_back(2000);
    for (int n : number_6)
    {
        cout << n << ' ';
    }
    cout << endl;

    auto ipop = number_6.cbegin();
    number_6.emplace(ipop + 4, 3000);
    for (int n : number_6)
    {
        cout << n << ' ';
    }
    cout << endl;

    number_6.insert(ipop + 2,3, 9000);
    for (int n : number_6)
    {
        cout << n << ' ';
    }
    cout << endl;

    auto begin = number_6.cend();
    number_6.insert(begin, { 5,5,5 });
    for (int n : number_6)
    {
        cout << n << ' ';
    }
    cout << endl;

    auto begin1 = number_5.cbegin();
    number_5.erase(begin1+2);
    for (int n : number_5)
    {
        cout << n << ' ';
    }
    cout << endl;
    auto first = number_6.cbegin();
    auto last = number_6.cend();
    number_6.erase(first + 3, last - 1);
    for (int n : number_6)
    {
        cout << n << ' ';
    }
    return 0;
}
/* Обращение к элементам объекта vector
* 1. [index] - По индексу в квадратных скобках
* 2. .at(index) - Через функцию встроенную в vector
* 3. .front() - Через функцию которая указывает на первый элемент
* 4. .back() - Через функцию которая указывает на последний элемент
*/

/* Добавление элементов в vector
* 1. .push_back() - Добавляет необходимый элемент в конец
* 2. .emplace_back() - Добавляет необходимый элемент в конец
* 3. .emplace(post, value) - Вставляет элемент value на место post
* *.emplace(post + 4, 3000); -  константный указатель на первый элемент + номер индекса
* 4. .insert(post, value) - Копия .emplace(post, value)
* 5. .insert(post, n, value) - ставит n кол-во элементов value на место post
* 6. .insert(post, values) - ставит на место post список элементов values
*/

/* Удаление элементов из vector
* 1. .clear() - удаляет все элементы
* 2. .pop_back() - удаляет последний элемент
* 3. .erase(p) - удаление по итератору (указателю на элемент) + индекс
* 4. .erase(first, last) - удаляет элементы в жиапазоне от first до last
*/

//.cbegin() - создает константный указатель на первый элемент делая его итератором
//.cend() - создает константный указатель на последний элемент делая его итератором