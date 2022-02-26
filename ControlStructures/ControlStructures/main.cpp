//ControlStructures
#include<iostream>
using namespace std;

//#define TASK_1
//#define TASK_2
#define TASK_3

void main()
{
	setlocale(LC_ALL, "Russian");
#if defined TASK_1
	int temperature;
	cout << "������� ����������� �������: "; cin >> temperature;
	if (temperature > 0)
	{
		cout << "�� ����� �����" << endl;
	}
	else
	{
		cout << "�� ����� �������" << endl;
	}
#endif

#if defined TASK_2
	int n;
	cout << "������� �����: "; cin >> n;
	if (n > 0 && n < 10)
	{
		cout << "���� ��������" << endl;
	}
	else
	{
		cout << "�� ������������" << endl;
	}
#endif

#if defined TASK_3
	double a, b;	//�����, �������� � ����������
	char s;			//Sign - ���� ��������
	cout << "������� �������������� ���������: ";
	cin >> a >> s >> b;
	cout << a << s << b << endl;
	if (s == '+')
	{
		cout << a << s << b << "=" << a + b << endl;
	}
	else if (s == '-')
	{
		cout << a << s << b << "=" << a - b << endl;
	}
	else if (s == '*')
	{
		cout << a << s << b << "=" << a * b << endl;
	}
	else if (s == '/')
	{
		if(b!=0)cout << a << s << b << "=" << a / b << endl;
		else cout << "�� ���� ������ ������" << endl;
	}
	else
	{
		cout << "Error: No operation" << endl;
	}
#endif
}