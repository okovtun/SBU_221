#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	//cout << true << endl;
	//cout << false << endl;
	cout << "SHORT:\n";
	cout << sizeof(short) << endl;
	cout << SHRT_MIN << " ... " << SHRT_MAX << endl;
	cout << 0 << " ... " << USHRT_MAX << endl;
	//SHRT - short
	//USHRT - unsigned short

	cout << "LONG LONG:\n";
	cout << sizeof(long long) << endl;
	cout << 0 << " ... " << ULLONG_MAX << endl;
	cout << LLONG_MIN << " ... " << LLONG_MAX << endl;

	//						type name;
	int number;	//��������� ����������
	cout << "������� �����: "; //������� ����������� �� ����
	cin >> number;	//������ �������� ���������� � ����������
	cout << number << endl;	//������� ����������� � ���������� �������� �� �����
	//cout << - ����� �� �����
	//cin >> - ���� � ����������
}