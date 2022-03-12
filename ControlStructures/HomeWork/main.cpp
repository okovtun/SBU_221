#include <iostream>
#include<string>
using namespace std;

#define arrowPointer " -> "
#define doubleTab " \t\t "
#define inputError " �� ���������� �������� "
#define InputValue " ������� �������� ��������:  "

void Task_1()
{
	int value;
	int temp = 0;
	int temp2 = 1;
	int temp3 = 0;
	cout << doubleTab << "��������� ����� (������� �1)." << endl;
	cout << InputValue << arrowPointer;
	cin >> value;

	while (true)
	{
		temp3 = temp + temp2;
		temp = temp2;
		temp2 = temp3;
		if (temp3 <= value)
		{
			cout << temp3 << doubleTab;
		}
		else
		{
			break;
		}

	}

	cout << endl << "������� ��� ��������� �� ���������� ������������� �����" << endl;
}

void Task_2()
{
	int result = 0;
	cout << doubleTab << "������� ��������� (������� �2)." << endl;
	for (int i = 1; i <= 9; i++)
	{

		for (int j = 1; j <= 10; j++)
		{
			result = i * j;
			cout << i << " * " << j << " = " << result << endl;
		}

		cout << endl;
	}
}

void Task_3()
{
	int result = 0;
	cout << doubleTab << "������� �������� (������� �3)." << "\n" << "\n";
	for (int i = 1; i <= 9; i++)
	{

		for (int j = 1; j < 10; j++)
		{
			result = i * j;

			if (result >= 10)
			{
				cout << result << "|";
			}
			else
			{
				cout << " " << result << "|";
			}
		}

		cout << endl;
	}
}


void TaskEnd()
{
	cout << "��������� �����������!";
}

void TaskSelection()
{
	string numberOfTask;
	cout << endl << doubleTab << "������� ����� ��������� ������� ��� ��������, �� 1 �� 4, ������� q ��� ������" << arrowPointer;
	cin >> numberOfTask; cout << endl;
	if (numberOfTask == "1")
	{
		Task_1();
		TaskSelection();
	}
	else if (numberOfTask == "2")
	{
		Task_2();
		TaskSelection();
	}
	else if (numberOfTask == "3")
	{
		Task_3();
		TaskSelection();
	}
	else if (numberOfTask == "q")
	{
		TaskEnd();
	}
	else
	{
		cout << inputError << endl;
		TaskSelection();
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	TaskSelection();
}