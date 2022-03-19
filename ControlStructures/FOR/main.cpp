#include<iostream>
using namespace std;

//#define FOR_SYNTAX
//#define FACTORIAL
//#define POWER
//#define ASCII

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef FOR_SYNTAX
	int n;	//количество итераций
	cout << "Введите количество итераций: "; cin >> n;
	for (
		int i = 0;
		i < n;
		i++)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // FOR_SYNTAX

#ifdef FACTORIAL
	int n;	//Число, для вычсления Факториала
	double f = 1;	//Факотриал числа
	cout << "Введите число для вычисления Факториала:"; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "! = ";
		f *= i;
		cout << f << endl;
	}
	cout << endl;
#endif // FACTORIAL

#ifdef POWER
	double a;	//Основание степени
	int n;	//Показатель степени
	double N = 1;	//Степень
	cout << "Введите основание степени: "; cin >> a;
	cout << "Введите показатель степени: "; cin >> n;
	if (n < 0)
	{
		a = 1 / a;	//Отправляем основание в знаменатель
		n = -n;	//Меняем знак показателя на противоположный
	}
	for (int i = 0; i < n; i++)
	{
		N *= a;//Результат умножаем на основание степени, и получаем промежуточную степень
		//N = N * a;
		//N = a * N;
	}
	cout << N << endl;
#endif // POWER

#ifdef ASCII
	cout << "Таблица ASCII-символов:\n";
	setlocale(LC_ALL, "C");	//Устанавливает кодировку по умолчанию
	for (int i = 0; i < 256; i++)
	{
		if (i % 16 == 0)cout << endl;
		cout << (char)i << " ";
	}
	cout << endl;
	setlocale(LC_ALL, "Rus");
	cout << "Вот и сказочке конец" << endl;
#endif // ASCII

}