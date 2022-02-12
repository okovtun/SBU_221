#include<iostream>
using namespace std;

#define TASK_1
//#define TASK_2

void main()
{
	setlocale(LC_ALL, "");

#if defined TASK_1
	double money;
	cout << "Введите денежную сумму: "; cin >> money;
	money += .00001;
	int rub = money;
	cout << rub << " руб.\t";
	int cop = (money - rub)*100;
	cout << cop << " коп.\n";
#endif

#if defined TASK_2
	double price_of_copybook;
	int number_of_copybooks;
	double price_of_pencil;
	int number_of_pencils;
	cout << "Введите цену тетради: "; cin >> price_of_copybook;
	cout << "Введите количество тетрадей: "; cin >> number_of_copybooks;
	cout << "Введите цену карандаша: "; cin >> price_of_pencil;
	cout << "Введите количество карандащей: "; cin >> number_of_pencils;
	double total_price = price_of_copybook * number_of_copybooks + price_of_pencil * number_of_pencils;
	cout << "Общая стоимость: " << total_price << " руб." << endl;
#endif
}