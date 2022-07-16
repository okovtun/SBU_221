//удаление, добавление строк и столбцов
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

int** Allocate(const int rows, const int cols);	//функция которая выделяет память
void Clear(int**& arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);//добавляет указанное значение в конец динамиечского массива
int* push_front(int arr[], int& n, int value); //добавляет указанное значение в начало динамиечского массива
int* insert(int arr[], int& n, int index, int value);//вставляет указанное значение в динамиечский массив по указанному индексу
int* pop_back(int arr[], int& n);//удаляет последний элемент массива
int* pop_front(int arr[], int& n);//удаляет нулевой элемент массива
int* erase(int arr[], int& n, int index);//удаляет значение из динамиечский массив по указанному индексу

int** push_row_down(int** arr, int& rows, const int cols);//добавляет строку снизу
int** push_row_up(int** arr, int& rows, const int cols);//добавляет строку сверху
int** insert_row(int** arr, int& rows, const int cols, int index);//вставляет строку в середину
void push_col_right(int** arr, const int rows, int& cols);//добавляет столбец справа
void push_col_left(int** arr, const int rows, int& cols);//добавляет столбец слева
void insert_col(int** arr, const int rows, int& cols, int index);//вставляет столбец в середину

int** pop_row_down(int** arr, int& rows, const int cols);//удаляет сроку снизу
int** pop_row_up(int** arr, int& rows, const int cols);//удаляет сроку снизу
int** erase_row(int** arr, int& rows, const int cols, int index);//удаляет строку по индексу
void pop_col_right(int** arr, const int rows, int& cols);//удаляет столбец справа
void pop_col_left(int** arr, const int rows, int& cols);//удаляет столбец слева

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

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
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс, который вы хотите добавить: "; cin >> index;
	cout << "Введите вставляемый элемент: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);

	cout << "Удаление последнего элемента массива: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаление нулевого элемента массива: ";
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif DYNAMIC_MEMORY_1

	int rows;	//количество строк
	int cols;	//количество элементов строки
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элеметов строки: "; cin >> cols;

	//обьявление двумерного динамического массива
	int** arr = Allocate(rows, cols);
	//использование двумерного динамического массива
	FillRand(arr, rows, cols);
	//вывод массива на экран
	Print(arr, rows, cols);
	//добавляем строку снизу
	arr = push_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	//добавляем строку сверху
	arr = push_row_up(arr, rows, cols);
	Print(arr, rows, cols);
	//вставляем строку по указанному индексу
	int index;
	cout << "Введите индекс строки, которую хотите добавить: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	//добавить строку с другими значениями
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);
	//добавление столбца справа
	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	//добавление столбца слева
	push_col_left(arr, rows, cols);
	Print(arr, rows, cols);
	//вставляем столбец по указанному индексу
	cout << "Введите индекс столбца, который хотите добавить: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	//удаляем строку снизу
	arr = pop_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	//удаляем строку сверху
	arr = pop_row_up(arr, rows, cols);
	Print(arr, rows, cols);
	//удаляем строку по указанному индексу
	cout << "Введите индекс строки, которыый хотите удалить: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	//удаление столбца справа
	pop_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	//удаление столбца сслева
	pop_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	//удаление двумерного динамического массива
	Clear(arr, rows);
	cout << arr << endl;
}
int** Allocate(const int rows, const int cols)	//функция которая выделяет память
{
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void Clear(int**& arr, const int rows)
{
	//удаление двумерного динамического массива
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];	//удаляем строки 
	}
	delete[]arr;		//удаляем массив указателей
	arr = nullptr;	//очищает указатель 
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
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
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - опереатор индексирования (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	//вывод массива на экран
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
int* push_back(int arr[], int& n, int value)
{
	//1) создаем буферный массив
	int* buffer = new int[n + 1]{};
	//2) копируем все элементы из исходного в буферный массив
	for (int i = 0; i < n; i++)
	{
		//элементы копируются соответственно
		buffer[i] = arr[i];
	}
	//3) удаляем исходный массив
	delete[] arr;
	//4) подменяем адрес исходного массива адресом нового массива
	arr = buffer;
	//только теперь в массив arr можно добавлять значение, поскольку там появилася 
	// ячейка для нового значения
	//5) добавляем значение в конец массива
	arr[n] = value;
	//6) после того как в массиве добавился элемент, количество его элементов увеличивается на 1
	n++;
	//всё !!!
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	//1) объявляем буферный массив нужного размера
	int* buffer = new int[n + 1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		//элементы копируются со смещением на один элемент вправо
		buffer[i + 1] = arr[i];
	}
	//3) удаляем исходный массив
	delete[] arr;
	//4) подменяем адрес
	arr = buffer;
	//5) добавляем значение в нулевой элемент
	arr[0] = value;
	//6) после того как в нулевой элемент присвоили значение, количество его элементов увеличивается на 1
	n++;
	//7) вернем новый массив
	return arr;
}

int* insert(int arr[], int& n, int index, int value)
{
	//1) объявляем буферный массив нужного размера
	int* buffer = new int[n + 1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < index; i++)
	{
		//элементы копируются без смещения
		buffer[i] = arr[i];
	}
	//3) вставляем элемент в динамиечский массив
	buffer[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//4) удаляем исходный массив
	delete[] arr;
	//5) подменяем адрес
	arr = buffer;
	//6) после того как элемент с индексом index присвоили значение, количество его элементов увеличивается на 1
	n++;
	//7) вернем новый массив
	return arr;
}

int* pop_back(int arr[], int& n)
{
	//1) обьявляем буферный массив нужного размера
	int* buffer = new int[n - 1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	//3) удаляем исходный массив
	delete[] arr;
	//4) подменяем адрес
	arr = buffer;
	//5) после того как удалили элемент массива, количество его элементов уменьшается на 1
	n--;
	return arr;
}

int* pop_front(int arr[], int& n)
{
	//1) обьявляем буферный массив нужного размера
	int* buffer = new int[n - 1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//3) удаляем исходный массив
	delete[] arr;
	//4) подменяем адрес
	arr = buffer;
	//5) после того как удалили элемент массива, количество его элементов уменьшается на 1
	n--;
	return arr;	//возвращаем полученный массив
}
int* erase(int arr[], int& n, int index)
{
	//1) объявляем буферный массив нужного размера
	int* buffer = new int[n - 1]{};
	//2) копируем все элементы из исходного массива в буферный
	for (int i = 0; i < index; i++)
	{
		//элементы копируются без смещения
		buffer[i] = arr[i];
	}
	//3) после удаления элемента по индексу копируем оставшиеся значения по смещению влево

	for (int i = index; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//4) удаляем исходный массив
	delete[] arr;
	//5) подменяем адрес
	arr = buffer;
	//6) после того как элемент с индексом удалился, количество его элементов уменьшается на 1
	n--;
	//7) вернем новый массив
	return arr;
}

int** push_row_down(int** arr, int& rows, const int cols)
{
	//1) создаем буферный массив указателей
	int** buffer = new int*[rows + 1]{};
	//2) копируем адреса строк из исходного массива указателей в буферный
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) удаляем ихсодный массив
	delete[]arr;
	//4) подменяем адрес старого массива адресом нового массива
	arr = buffer;
	//5) создаем добавляемую строку
	arr[rows] = new int[cols] {};
	//6) после добавления стоки, количество строк увеличивается на 1
	rows++;
	return arr;
}

int** push_row_up(int** arr, int& rows, const int cols)
{
	//1) создаем буферный массив указателей
	int** buffer = new int*[rows + 1]{};
	//2) копируем адреса строк из исходного массива указателей в буферный
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3) удаляем ихсодный массив
	delete[]arr;
	//4) подменяем адрес старого массива адресом нового массива
	arr = buffer;
	//5) создаем добавляемую строку
	arr[0] = new int[cols] {};
	//6) после добавления строки, количество строк увеличивается на 1
	rows++;
	return arr;
}

int** insert_row(int** arr, int& rows, const int cols, int index)
{
	//1) создаем буферный массив указателей
	int** buffer = new int*[rows + 1]{};
	//2) копируем адреса строк из исходного массива указателей в буферный
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//3) создаем добавляемую строку
	buffer[index] = new int[cols] {};
	//4) копируем оставшеся строки
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//5) удаляем ихсодный массив
	delete[]arr;
	//6) подменяем адрес старого массива адресом нового массива
	arr = buffer;
	//7) после добавления строки, количество строк увеличивается на 1
	rows++;
	return arr;
}

void push_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//последовательно увеличаем каждую строку на 1 элемент
		int* buffer = new int[cols + 1]{};
		//текщую строку копируем в буферный массив
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		//удаляем строку
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void push_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//последовательно увеличаем каждую строку на 1 элемент
		int* buffer = new int[cols + 1]{};
		//текщую строку копируем в буферный массив
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		//удаляем строку
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void insert_col(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		//последовательно увеличаем каждую строку на 1 элемент
		int* buffer = new int[cols + 1]{};
		//текщую строку копируем в буферный массив
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		//удаляем строку
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	//return arr;
}

int** pop_row_down(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	//1) создаем буферный массив указателей
	int** buffer = new int*[rows - 1]{};
	//2) копируем адреса строк из исходного массива указателей в буферный
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	//3) удаляем ихсодный массив
	delete[]arr;
	//4) подменяем адрес старого массива адресом нового массива
	arr = buffer;
	//5) создаем добавляемую строку
	//arr[rows] = new int[cols] {};
	//6) после добавления стоки, количество строк увеличивается на 1
	rows--;
	return arr;
}

int** pop_row_up(int** arr, int& rows, const int cols)
{
	//1) создаем буферный массив указателей
	int** buffer = new int*[rows - 1]{};
	//2) копируем адреса строк из исходного массива указателей в буферный
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//3) удаляем ихсодный массив
	delete[]arr;
	//4) подменяем адрес старого массива адресом нового массива
	arr = buffer;
	//5) создаем добавляемую строку
	arr[0] = new int[cols] {};
	//6) после добавления строки, количество строк увеличивается на 1
	rows--;
	return arr;
}

int** erase_row(int** arr, int& rows, const int cols, int index)
{
	//1) создаем буферный массив указателей
	int** buffer = new int*[rows - 1]{};
	//2) копируем адреса строк из исходного массива указателей в буферный
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//3) создаем добавляемую строку
	buffer[index] = new int[cols] {};
	//4) копируем оставшеся строки
	for (int i = index; i < rows; i++)
	{
		buffer[i] = arr[i+1];
	}
	//5) удаляем ихсодный массив
	delete[]arr;
	//6) подменяем адрес старого массива адресом нового массива
	arr = buffer;
	//7) после добавления строки, количество строк увеличивается на 1
	rows--;
	return arr;
}

void pop_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//последовательно увеличаем каждую строку на 1 элемент
		int* buffer = new int[cols - 1]{};
		//текщую строку копируем в буферный массив
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		//удаляем строку
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}

void pop_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//последовательно увеличаем каждую строку на 1 элемент
		int* buffer = new int[cols - 1]{};
		//текщую строку копируем в буферный массив
		for (int j = 0; j < cols; j++)
		{
			buffer[j - 1] = arr[i][j];
		}
		//удаляем строку
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}

