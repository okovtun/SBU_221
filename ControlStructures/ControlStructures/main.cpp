//ControlStructures
#include<iostream>
using namespace std;

//#define TASK_1
//#define TASK_2
#define TASK_3

void main()
{
	setlocale(LC_ALL, "Russian");
#if defined TASK_1
	int temperature;
	cout << "Введите температуру воздуха: "; cin >> temperature;
	if (temperature > 0)
	{
		cout << "На улице тепло" << endl;
	}
	else
	{
		cout << "На улице холодно" << endl;
	}
#endif

#if defined TASK_2
	int n;
	cout << "Введите число: "; cin >> n;
	if (n > 0 && n < 10)
	{
		cout << "Цель поражена" << endl;
	}
	else
	{
		cout << "Вы промахнулись" << endl;
	}
#endif

#if defined TASK_3
	double a, b;	//Числа, вводимые с клавиатуры
	char s;			//Sign - знак операции
	cout << "Введите арифметическое выражение: ";
	cin >> a >> s >> b;
	cout << a << s << b << endl;
	if (s == '+')
	{
		cout << a << s << b << "=" << a + b << endl;
	}
	else if (s == '-')
	{
		cout << a << s << b << "=" << a - b << endl;
	}
	else if (s == '*')
	{
		cout << a << s << b << "=" << a * b << endl;
	}
	else if (s == '/')
	{
		if(b!=0)cout << a << s << b << "=" << a / b << endl;
		else cout << "На ноль делить нельзя" << endl;
	}
	else
	{
		cout << "Error: No operation" << endl;
	}
#endif
}