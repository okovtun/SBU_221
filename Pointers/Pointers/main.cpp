//Pointers
#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;
	cout << &a << endl;
	cout << pa << endl;
	cout << *pa << endl;

	int* pb;
	int b = 3;
	//pb - работаем с адресом
	//*pb - разыменовываем адрес, и работаем со значением по адресу
	pb = &b;

	cout << *pb << endl;
	//int - int
	//int* - ”казатель на int
	//double - double
	//double* - ”казатель на double
	//char - char
	//char* - ”казатель на char  
#endif // POINTERS_BASICS

	const int n = 5;
	short arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}

/*
------------------------------------------------
& - Address-of operator (ќператор вз€ти€ адреса)
* - Dereference operator (ќператор разыменовани€)
------------------------------------------------
*/

/*
------------------------------------------------
+
-
++
--
------------------------------------------------
*/