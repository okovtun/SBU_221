//NULLTerminatedLines
#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char str[]);	//Возвращает длину строки в символах

void main()
{
	//setlocale(LC_ALL, "");
	system("chcp 1251");
	//C-string		char
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";

	const int SIZE = 256;
	char str[SIZE] = {};

	cout << "Введите строку: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << sizeof(str) << endl;
}