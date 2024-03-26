#pragma once
class Student
{
	char* full_name;
	int markCount;
	int* marks;
public:
	
	//Set'���
	void createName(const char* studentName);
	void setName(const char* studentName);
	void setMarks(int mark, int index);

	//Get'���
	const char* getName() { return full_name; }
	int getMarks(int index) { return marks[index]; }

	//������������ � ����������

	Student(); // ����������� �� ���������
	Student(const char* studentName);
	Student(const char* studentName,
		const int studentMarkCount);
	Student(const char* studentName,
		const int studentMarkCount,
		const int* studentMarks);
	/*~Student();*/ // ����������
	//������� ������
	double getAver();
};