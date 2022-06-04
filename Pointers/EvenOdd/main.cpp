#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "Исходный массив:\n";
	Print(arr, n);

	//1) Считаем количество четных и нечетных значений в исходном массиве:
	int even_size = 0;	//Количество четных значений в массиве
	int odd_size = 0;	//Количество нечетных значений в массиве
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even_size++;
		else odd_size++;
	}
	cout << "Количество четных элементов:  " << even_size << endl;
	cout << "Количество нечетных элементов:" << odd_size << endl;

	//2) Выделяем память для четных и нечетных элементов:
	int* even_arr = new int[even_size] {};
	int* odd_arr = new int[odd_size] {};
	//{} - инициализируют память, выделяемую оператором new, 
	//т.е. заполняют ее значением по умолчанию, для int - это 0

	//3) Копируем четные и нечетные элементы в соответсвующие массивы:
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		/*if (arr[i] % 2 == 0)
			even_arr[j++] = arr[i];
		else
			odd_arr[k++] = arr[i];*/
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}

	//4) Выводим массивы на экран:
	cout << "Массив с четными элементами:\n"; Print(even_arr, even_size);
	cout << "Массив с нечетными элементами:\n"; Print(odd_arr, odd_size);

	//Оператор delete[] освождает память, занимаемую массивом, и возвращает эту память
	//обратно ОС.
	delete[] odd_arr;
	delete[] even_arr;
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования:
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - оператор индексирования (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}