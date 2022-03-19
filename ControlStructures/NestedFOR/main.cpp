#include<iostream>
using namespace std;

//#define MULTIPLICATION_TABLE
#define PYTHAGORAS_TABLE	//TODO
#define SIMPLE_NUMBERS

void main()
{
	setlocale(LC_ALL, "");
#ifdef MULTIPLICATION_TABLE
	int n = 10;
	for (int i = 1; i <= n; i++)
	{
		//Здесть счетчика j еще нет.
		for (int j = 1; j <= n; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		//Здесь счетчика j уже нет.
	}
#endif // MULTIPLICATION_TABLE

	int n;	//предел, до которого будем выводить простые числа
	//bool simple = true;
	cout << "Введите число: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		bool simple = true;	//Предполагаем что число простое
		//но это нужно проверить:
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0)simple = false;
		}
		if(simple)cout << i << "\t";
	}
	cout << endl;
}

/*
---------------
1*1 = 1
1*2 = 2
...
...
2*1 = 2
2*2 = 4
---------------
*/