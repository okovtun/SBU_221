#include<iostream>
#include<conio.h>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;;

//#define PALINDROME

void main()
{
	setlocale(LC_ALL, "");
#ifdef PALINDROME
	int number;		//число, вводимое с клавиатуры
	int reverse = 0;	//обратная запись введенного числа
	cout << "Введите число: "; cin >> number;
	int buffer = number;
	while (buffer)
	{
		reverse *= 10;	//освобождаем место под младший разряд
		reverse += buffer % 10;//получаем младший разряд числа, и сохраняем его
		buffer /= 10;	//убираем сохраненный разряд
	}
	cout << number << endl;
	cout << reverse << endl;
	if (number == reverse)
	{
		cout << "Число палиндром" << endl;
	}
	else
	{
		cout << "Число НЕ палиндром" << endl;
	}
#endif

	char key;	//код клавиши
	do
	{
		key = _getch();
		cout << (int)key << "\t" << key << endl;
		if (key == 'w' || key == 'W')cout << "Вперед" << endl;
		else if (key == 's' || key == 'S')cout << "Назад" << endl;
		else if (key == 'a' || key == 'A')cout << "Влево" << endl;
		else if (key == 'd' || key == 'D')cout << "Вправо" << endl;
		else if (key == 32)cout << "Прыжок" << endl;
		else cout << "Error: нет такого действия" << endl;
	} while (key != 27);
}