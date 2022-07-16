//��������, ���������� ����� � ��������
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";

int** Allocate(const int rows, const int cols);	//������� ������� �������� ������
void Clear(int**& arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);//��������� ��������� �������� � ����� ������������� �������
int* push_front(int arr[], int& n, int value); //��������� ��������� �������� � ������ ������������� �������
int* insert(int arr[], int& n, int index, int value);//��������� ��������� �������� � ������������ ������ �� ���������� �������
int* pop_back(int arr[], int& n);//������� ��������� ������� �������
int* pop_front(int arr[], int& n);//������� ������� ������� �������
int* erase(int arr[], int& n, int index);//������� �������� �� ������������ ������ �� ���������� �������

int** push_row_down(int** arr, int& rows, const int cols);//��������� ������ �����
int** push_row_up(int** arr, int& rows, const int cols);//��������� ������ ������
int** insert_row(int** arr, int& rows, const int cols, int index);//��������� ������ � ��������
void push_col_right(int** arr, const int rows, int& cols);//��������� ������� ������
void push_col_left(int** arr, const int rows, int& cols);//��������� ������� �����
void insert_col(int** arr, const int rows, int& cols, int index);//��������� ������� � ��������

int** pop_row_down(int** arr, int& rows, const int cols);//������� ����� �����
int** pop_row_up(int** arr, int& rows, const int cols);//������� ����� �����
int** erase_row(int** arr, int& rows, const int cols, int index);//������� ������ �� �������
void pop_col_right(int** arr, const int rows, int& cols);//������� ������� ������
void pop_col_left(int** arr, const int rows, int& cols);//������� ������� �����

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "�������� ������:\n";
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ������, ������� �� ������ ��������: "; cin >> index;
	cout << "������� ����������� �������: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);

	cout << "�������� ���������� �������� �������: ";
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "�������� �������� �������� �������: ";
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "������� ������ ���������� ��������: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif DYNAMIC_MEMORY_1

	int rows;	//���������� �����
	int cols;	//���������� ��������� ������
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� �������� ������: "; cin >> cols;

	//���������� ���������� ������������� �������
	int** arr = Allocate(rows, cols);
	//������������� ���������� ������������� �������
	FillRand(arr, rows, cols);
	//����� ������� �� �����
	Print(arr, rows, cols);
	//��������� ������ �����
	arr = push_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	//��������� ������ ������
	arr = push_row_up(arr, rows, cols);
	Print(arr, rows, cols);
	//��������� ������ �� ���������� �������
	int index;
	cout << "������� ������ ������, ������� ������ ��������: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	//�������� ������ � ������� ����������
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);
	//���������� ������� ������
	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	//���������� ������� �����
	push_col_left(arr, rows, cols);
	Print(arr, rows, cols);
	//��������� ������� �� ���������� �������
	cout << "������� ������ �������, ������� ������ ��������: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	//������� ������ �����
	arr = pop_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	//������� ������ ������
	arr = pop_row_up(arr, rows, cols);
	Print(arr, rows, cols);
	//������� ������ �� ���������� �������
	cout << "������� ������ ������, �������� ������ �������: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	//�������� ������� ������
	pop_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	//�������� ������� ������
	pop_col_right(arr, rows, cols);
	Print(arr, rows, cols);
	//�������� ���������� ������������� �������
	Clear(arr, rows);
	cout << arr << endl;
}
int** Allocate(const int rows, const int cols)	//������� ������� �������� ������
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
	//�������� ���������� ������������� �������
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];	//������� ������ 
	}
	delete[]arr;		//������� ������ ����������
	arr = nullptr;	//������� ��������� 
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//����� ���������� ���������� � �������� �������������
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
		//[] - ��������� �������������� (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	//����� ������� �� �����
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
	//1) ������� �������� ������
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� � �������� ������
	for (int i = 0; i < n; i++)
	{
		//�������� ���������� ��������������
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� ����� ��������� ������� ������� ������ �������
	arr = buffer;
	//������ ������ � ������ arr ����� ��������� ��������, ��������� ��� ��������� 
	// ������ ��� ������ ��������
	//5) ��������� �������� � ����� �������
	arr[n] = value;
	//6) ����� ���� ��� � ������� ��������� �������, ���������� ��� ��������� ������������� �� 1
	n++;
	//�� !!!
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n; i++)
	{
		//�������� ���������� �� ��������� �� ���� ������� ������
		buffer[i + 1] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� �����
	arr = buffer;
	//5) ��������� �������� � ������� �������
	arr[0] = value;
	//6) ����� ���� ��� � ������� ������� ��������� ��������, ���������� ��� ��������� ������������� �� 1
	n++;
	//7) ������ ����� ������
	return arr;
}

int* insert(int arr[], int& n, int index, int value)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n + 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < index; i++)
	{
		//�������� ���������� ��� ��������
		buffer[i] = arr[i];
	}
	//3) ��������� ������� � ������������ ������
	buffer[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//4) ������� �������� ������
	delete[] arr;
	//5) ��������� �����
	arr = buffer;
	//6) ����� ���� ��� ������� � �������� index ��������� ��������, ���������� ��� ��������� ������������� �� 1
	n++;
	//7) ������ ����� ������
	return arr;
}

int* pop_back(int arr[], int& n)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n - 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� �����
	arr = buffer;
	//5) ����� ���� ��� ������� ������� �������, ���������� ��� ��������� ����������� �� 1
	n--;
	return arr;
}

int* pop_front(int arr[], int& n)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n - 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//3) ������� �������� ������
	delete[] arr;
	//4) ��������� �����
	arr = buffer;
	//5) ����� ���� ��� ������� ������� �������, ���������� ��� ��������� ����������� �� 1
	n--;
	return arr;	//���������� ���������� ������
}
int* erase(int arr[], int& n, int index)
{
	//1) ��������� �������� ������ ������� �������
	int* buffer = new int[n - 1]{};
	//2) �������� ��� �������� �� ��������� ������� � ��������
	for (int i = 0; i < index; i++)
	{
		//�������� ���������� ��� ��������
		buffer[i] = arr[i];
	}
	//3) ����� �������� �������� �� ������� �������� ���������� �������� �� �������� �����

	for (int i = index; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//4) ������� �������� ������
	delete[] arr;
	//5) ��������� �����
	arr = buffer;
	//6) ����� ���� ��� ������� � �������� ��������, ���������� ��� ��������� ����������� �� 1
	n--;
	//7) ������ ����� ������
	return arr;
}

int** push_row_down(int** arr, int& rows, const int cols)
{
	//1) ������� �������� ������ ����������
	int** buffer = new int*[rows + 1]{};
	//2) �������� ������ ����� �� ��������� ������� ���������� � ��������
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������
	delete[]arr;
	//4) ��������� ����� ������� ������� ������� ������ �������
	arr = buffer;
	//5) ������� ����������� ������
	arr[rows] = new int[cols] {};
	//6) ����� ���������� �����, ���������� ����� ������������� �� 1
	rows++;
	return arr;
}

int** push_row_up(int** arr, int& rows, const int cols)
{
	//1) ������� �������� ������ ����������
	int** buffer = new int*[rows + 1]{};
	//2) �������� ������ ����� �� ��������� ������� ���������� � ��������
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3) ������� �������� ������
	delete[]arr;
	//4) ��������� ����� ������� ������� ������� ������ �������
	arr = buffer;
	//5) ������� ����������� ������
	arr[0] = new int[cols] {};
	//6) ����� ���������� ������, ���������� ����� ������������� �� 1
	rows++;
	return arr;
}

int** insert_row(int** arr, int& rows, const int cols, int index)
{
	//1) ������� �������� ������ ����������
	int** buffer = new int*[rows + 1]{};
	//2) �������� ������ ����� �� ��������� ������� ���������� � ��������
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� ����������� ������
	buffer[index] = new int[cols] {};
	//4) �������� ��������� ������
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//5) ������� �������� ������
	delete[]arr;
	//6) ��������� ����� ������� ������� ������� ������ �������
	arr = buffer;
	//7) ����� ���������� ������, ���������� ����� ������������� �� 1
	rows++;
	return arr;
}

void push_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//��������������� ��������� ������ ������ �� 1 �������
		int* buffer = new int[cols + 1]{};
		//������ ������ �������� � �������� ������
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		//������� ������
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void push_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//��������������� ��������� ������ ������ �� 1 �������
		int* buffer = new int[cols + 1]{};
		//������ ������ �������� � �������� ������
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		//������� ������
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void insert_col(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		//��������������� ��������� ������ ������ �� 1 �������
		int* buffer = new int[cols + 1]{};
		//������ ������ �������� � �������� ������
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		//������� ������
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	//return arr;
}

int** pop_row_down(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	//1) ������� �������� ������ ����������
	int** buffer = new int*[rows - 1]{};
	//2) �������� ������ ����� �� ��������� ������� ���������� � ��������
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������
	delete[]arr;
	//4) ��������� ����� ������� ������� ������� ������ �������
	arr = buffer;
	//5) ������� ����������� ������
	//arr[rows] = new int[cols] {};
	//6) ����� ���������� �����, ���������� ����� ������������� �� 1
	rows--;
	return arr;
}

int** pop_row_up(int** arr, int& rows, const int cols)
{
	//1) ������� �������� ������ ����������
	int** buffer = new int*[rows - 1]{};
	//2) �������� ������ ����� �� ��������� ������� ���������� � ��������
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	//3) ������� �������� ������
	delete[]arr;
	//4) ��������� ����� ������� ������� ������� ������ �������
	arr = buffer;
	//5) ������� ����������� ������
	arr[0] = new int[cols] {};
	//6) ����� ���������� ������, ���������� ����� ������������� �� 1
	rows--;
	return arr;
}

int** erase_row(int** arr, int& rows, const int cols, int index)
{
	//1) ������� �������� ������ ����������
	int** buffer = new int*[rows - 1]{};
	//2) �������� ������ ����� �� ��������� ������� ���������� � ��������
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� ����������� ������
	buffer[index] = new int[cols] {};
	//4) �������� ��������� ������
	for (int i = index; i < rows; i++)
	{
		buffer[i] = arr[i+1];
	}
	//5) ������� �������� ������
	delete[]arr;
	//6) ��������� ����� ������� ������� ������� ������ �������
	arr = buffer;
	//7) ����� ���������� ������, ���������� ����� ������������� �� 1
	rows--;
	return arr;
}

void pop_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//��������������� ��������� ������ ������ �� 1 �������
		int* buffer = new int[cols - 1]{};
		//������ ������ �������� � �������� ������
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		//������� ������
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}

void pop_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//��������������� ��������� ������ ������ �� 1 �������
		int* buffer = new int[cols - 1]{};
		//������ ������ �������� � �������� ������
		for (int j = 0; j < cols; j++)
		{
			buffer[j - 1] = arr[i][j];
		}
		//������� ������
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}

