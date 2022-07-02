#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T**& arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n, T value);
template<typename T>T* push_front(T* arr, int& n, T value);
template<typename T>T* pop_back(T* arr, int& n);
template<typename T>T* pop_front(T* arr, int& n);

template<typename T>T** push_row_down(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_down(T** arr, int& rows, const int cols);

template<typename T>void push_col_right(T** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

typedef char DataType;
//typedef existing_type alias;
//existing - существующий
//alias - псевдоним
#define DATA_TYPE double

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "Исходный массив:\n";
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	//arr = push_front(arr, n, value);
	Print(arr = push_front(arr, n, value), n);
	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_front(arr, n), n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int rows;	//количество строк
	int cols;	//количество элементов строки
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	//Объявление двумерного динамического массива:
	DATA_TYPE** arr = Allocate<DATA_TYPE>(rows, cols);

	//Использование двумерного динамического массива:
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление последней строки:\n";
	arr = pop_row_down(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
	cout << arr << endl;
}
template<typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T*[rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols] {};
	}
	return arr;
}
template<typename T>void Clear(T**& arr, const int rows)
{
	//Удаление двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];	//удаляем строки
	}
	delete[] arr;	//удаляем массив указателей
	arr = nullptr;	//Оператор delete[] принимает указатель arr, 
	//и удаляет память по адресу в этом указателе, при этом
	//адрес хранящийся в указателе arr НЕ изменяется, и вполне
	//возможна ситуация, когда к массиву обратятся после его удаления,
	//что приведет к ошибке на этапе выполнения и аварийному завершению программы.
	//Для того чтобы избежать таких ситуаций указатели лучше занулять после удаления,
	//и при акждом обрахении к массиву проверять массив на nullptr.
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования:
		*(arr + i) = rand();
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования:
		*(arr + i) = double(rand() % (maxRand - minRand) + minRand)/100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand()%10000;
			arr[i][j] /= 100;
		}
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - оператор индексирования (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << tab;
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T>T* push_back(T arr[], int& n, T value)
{
	//1) Создаем буферный массив:
	T* buffer = new T[n + 1]{};
	//2) Копируем все элементы из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		//Элементы копируются соответственно:
		buffer[i] = arr[i];
	}
	//3) Удавляем исходный массив:
	delete[] arr;
	//4) Подменяем адрес исходного массива, адресом нового массива:
	arr = buffer;
	//Только теперь в массив arr можно добавлять значение, поскольку там появилася
	//ячейка для нового значения.

	//5) Добавляем значение в конец массива
	arr[n] = value;
	//6) После того как в массиве добавился элемент, количество его элементов увеличивается на 1
	n++;
	//		Mission complete!
	return arr;
}
template<typename T>T* push_front(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)
		//Элементы копируются со смещением на 1 элемент вправо:
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

template<typename T>T* pop_back(T* arr, int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T* pop_front(T* arr, int& n)
{
	T* buffer = new T[--n]{};
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T** push_row_down(T** arr, int& rows, const int cols)
{
	return push_back(arr, rows, new T[cols]{});
}
template<typename T>T** pop_row_down(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	return pop_back(arr, rows);
}
template<typename T>void push_col_right(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], cols, T());//T() - значение по умолчанию для шаблонного типа
		cols--;	//Компенсируем увеличение cols функцией push_back
	}
	cols++;
}