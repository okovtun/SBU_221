#include<iostream>
#include<conio.h>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;;

//#define PALINDROME

void main()
{
	setlocale(LC_ALL, "");
#ifdef PALINDROME
	int number;		//�����, �������� � ����������
	int reverse = 0;	//�������� ������ ���������� �����
	cout << "������� �����: "; cin >> number;
	int buffer = number;
	while (buffer)
	{
		reverse *= 10;	//����������� ����� ��� ������� ������
		reverse += buffer % 10;//�������� ������� ������ �����, � ��������� ���
		buffer /= 10;	//������� ����������� ������
	}
	cout << number << endl;
	cout << reverse << endl;
	if (number == reverse)
	{
		cout << "����� ���������" << endl;
	}
	else
	{
		cout << "����� �� ���������" << endl;
	}
#endif

	char key;	//��� �������
	do
	{
		key = _getch();
		cout << (int)key << "\t" << key << endl;
		if (key == 'w' || key == 'W')cout << "������" << endl;
		else if (key == 's' || key == 'S')cout << "�����" << endl;
		else if (key == 'a' || key == 'A')cout << "�����" << endl;
		else if (key == 'd' || key == 'D')cout << "������" << endl;
		else if (key == 32)cout << "������" << endl;
		else cout << "Error: ��� ������ ��������" << endl;
	} while (key != 27);
}