#include<iostream>
using namespace std;

//#define FOR_SYNTAX

void main()
{
	setlocale(LC_ALL, "");
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

	int n;	//�����, ��� ��������� ����������
	double f=1;	//��������� �����
	cout << "������� ����� ��� ���������� ����������:"; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << i << "! = ";
		f *= i;
		cout << f << endl;
	}
	cout << endl;
}