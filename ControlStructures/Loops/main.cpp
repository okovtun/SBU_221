#include<iostream>
#include<conio.h>	//_getch();
using namespace std;

//#define WHILE
#define DO_WHILE

void main()
{
	setlocale(LC_ALL, "");
#if defined WHILE
	int n;	//Количество итераций (итерация - это однократное выполнение тела цикла)
	int i = 0;//Счетчик цикла (считает сколько раз будет выполнен цикл)
	cout << "Введите количество итераций: "; cin >> n;
	while (i < n)
	{
		cout << i << "Hello" << endl;
		i++;
	}
#endif

#if defined DO_WHILE
	char key;	//Буде хранить код клавиши
	do
	{
		key = _getch();//ожидает нажатие клавиши, и возвращает ASCII-код нажатой клавиши
		cout << (int)key << "\t" << key << endl;
		//(int)key - явное преобразование типов char в int
	} while (key != 27);
#endif
}