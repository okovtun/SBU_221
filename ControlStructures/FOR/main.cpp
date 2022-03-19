#include<iostream>
using namespace std;

//#define FOR_SYNTAX
//#define FACTORIAL
//#define POWER
//#define ASCII

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef FOR_SYNTAX
	int n;	//���������� ��������
	cout << "������� ���������� ��������: "; cin >> n;
	for (
		int i = 0;
		i < n;
		i++)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // FOR_SYNTAX

#ifdef FACTORIAL
	int n;	//�����, ��� ��������� ����������
	double f = 1;	//��������� �����
	cout << "������� ����� ��� ���������� ����������:"; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "! = ";
		f *= i;
		cout << f << endl;
	}
	cout << endl;
#endif // FACTORIAL

#ifdef POWER
	double a;	//��������� �������
	int n;	//���������� �������
	double N = 1;	//�������
	cout << "������� ��������� �������: "; cin >> a;
	cout << "������� ���������� �������: "; cin >> n;
	if (n < 0)
	{
		a = 1 / a;	//���������� ��������� � �����������
		n = -n;	//������ ���� ���������� �� ���������������
	}
	for (int i = 0; i < n; i++)
	{
		N *= a;//��������� �������� �� ��������� �������, � �������� ������������� �������
		//N = N * a;
		//N = a * N;
	}
	cout << N << endl;
#endif // POWER

#ifdef ASCII
	cout << "������� ASCII-��������:\n";
	setlocale(LC_ALL, "C");	//������������� ��������� �� ���������
	for (int i = 0; i < 256; i++)
	{
		if (i % 16 == 0)cout << endl;
		cout << (char)i << " ";
	}
	cout << endl;
	setlocale(LC_ALL, "Rus");
	cout << "��� � �������� �����" << endl;
#endif // ASCII

}