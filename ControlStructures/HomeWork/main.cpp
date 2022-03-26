#include <iostream>
#include <Windows.h>
using namespace std;
#define offset "\t\t\t\t"

void main()
{
	//	setlocale(LC_ALL, "");
	SetConsoleCP(CP_UTF8);
	int chess_size;
	int i = 0, j = 0;
	cout << offset << "Enter chessboard size: "; cin >> chess_size;
	cout << offset << char(0xDA);
	for (i = 0; i < chess_size * 2; i++) cout << char(0xC4);
	cout << char(0xBF) << endl;
	for (i = 0; i < chess_size; i++)
	{
		cout << offset << char(0xB3);
		for (j = 0; j < chess_size; j++)
		{
			if (((i % 2 == 0) && (j % 2 == 0))/* || ((i % 2 != 0) && (j % 2 != 0))*/) cout << char(0xB2) << char(0xB2);
			else cout << char(0xB0) << char(0xB0);
		}
		cout << char(0xB3);
		cout << endl;
	}
	cout << offset << char(0xC0);
	for (i = 0; i < chess_size * 2; i++) cout << char(0xC4);
	cout << char(0xD9) << endl;
}