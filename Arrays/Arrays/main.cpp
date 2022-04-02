//Arrays
#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 5;
	int arr[SIZE] = {3, 5, 8};
	//arr[2] = 3;	//обращаемся ко второму элементу массива, чтобы записать в него значение 3
	//SIZE - 1 или n - 1
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}