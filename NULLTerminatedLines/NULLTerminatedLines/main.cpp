//NULLTerminatedLines
#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char str[]);	//���������� ����� ������ � ��������

void main()
{
	//setlocale(LC_ALL, "");
	system("chcp 1251");
	//C-string		char
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";

	const int SIZE = 256;
	char str[SIZE] = {};

	cout << "������� ������: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << sizeof(str) << endl;
}