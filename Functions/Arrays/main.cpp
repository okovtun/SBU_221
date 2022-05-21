//Arrays
//Overload in progress
#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

const int ROWS = 3;
const int COLS = 5;

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS);

void Print(int arr[], const int n);
void Print(double arr[], const int n);
void Print(char arr[], const int n);
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS);

int	 Sum(int arr[], const int n);
double	 Sum(double arr[], const int n);

double Avg(int arr[], const int n);
double Avg(double arr[], const int n);

void shiftLeft(int arr[], const int n, const int number_of_shifts);
void shiftLeft(double arr[], const int n, const int number_of_shifts);

void Sort(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднее арифмектическое элементов массива: " << Avg(arr, n) << endl;
	Sort(arr, n);
	Print(arr, n);

	int number_of_shifts;
	cout << "Введите количество сдвигов: "; cin >> number_of_shifts;
	shiftLeft(arr, n, number_of_shifts);
	Print(arr, n);

	cout << delimiter << endl;

	const int D_SIZE = 8;
	double d_arr[D_SIZE];
	FillRand(d_arr, D_SIZE);
	Print(d_arr, D_SIZE);
	cout << "Сумма элементов массива: " << Sum(d_arr, D_SIZE) << endl;
	cout << "Среднее арифмектическое элементов массива: " << Avg(d_arr, D_SIZE) << endl;

	//int number_of_shifts;
	cout << "Введите количество сдвигов: "; cin >> number_of_shifts;
	shiftLeft(d_arr, D_SIZE, number_of_shifts);
	Print(d_arr, D_SIZE);

	cout << delimiter << endl;
	const int C_SIZE = 7;
	char c_arr[C_SIZE];
	FillRand(c_arr, C_SIZE);
	Print(c_arr, C_SIZE);

	cout << delimiter << endl;


	int arr2[ROWS][COLS];
	FillRand(arr2, ROWS, COLS);
	Print(arr2, ROWS, COLS);
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	//Заполнение массива случайными числами:
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}

void FillRand(double arr[], const int n)
{
	//Заполнение массива случайными числами:
	for (int i = 0; i < n; i++)
	{
		arr[i] = double(rand() % 10000) / 100;
	}
}
void FillRand(char arr[], const int n)
{
	//Заполнение массива случайными числами:
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	//Вывод массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(double arr[], const int n)
{
	//Вывод массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(char arr[], const int n)
{
	//Вывод массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

int Sum(int arr[], const int n)
{
	//Сумма элементов массива:
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double Sum(double arr[], const int n)
{
	//Сумма элементов массива:
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

double Avg(int arr[], const int n)
{
	//Среднее арифметичсекое:
	return (double)Sum(arr, n) / n;
}
double Avg(double arr[], const int n)
{
	//Среднее арифметичсекое:
	return (double)Sum(arr, n) / n;
}

void shiftLeft(int arr[], const int n, const int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
void shiftLeft(double arr[], const int n, const int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		double buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)//счетчик 'i' выбирает элемент, в который нужно поместить минимальное значение
	{
		for (int j = i + 1; j < n; j++)	//счетчик 'j' перебирает остальные элементы массива
		{
			//arr[i] - выюранный элемент
			//arr[j] - перебираемый элемент
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}