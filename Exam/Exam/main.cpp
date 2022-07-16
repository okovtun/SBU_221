#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	cout << sizeof("+") << endl;
	cout << typeid(123.f).name() << endl;
}