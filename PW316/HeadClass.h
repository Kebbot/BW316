#pragma once
class Student
{
	char* full_name;
	int markCount;
	int* marks;
public:
	
	//Set'эры
	void createName(const char* studentName);
	void setName(const char* studentName);
	void setMarks(int mark, int index);

	//Get'эры
	const char* getName() { return full_name; }
	int getMarks(int index) { return marks[index]; }

	//Конструкторы и деструктор

	Student(); // конструктор по умолчанию
	Student(const char* studentName);
	Student(const char* studentName,
		const int studentMarkCount);
	Student(const char* studentName,
		const int studentMarkCount,
		const int* studentMarks);
	/*~Student();*/ // деструктор
	//Обычные методы
	double getAver();
};