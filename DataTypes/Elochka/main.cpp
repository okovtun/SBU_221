#include<iostream>
using namespace std;

#define offset "\t\t\t\t\t\t"
#define ���_������� ���_��������
//define - ����������
//���������������� (������)
//��� ��������
#define ��� ��������

/*#if defined NAME

#endif*/

//#define ELOCHKA	//���������� ELOCHKA (������� ����������� ELOCHKA)
//���������� ELOCHKA
//#define TASK_1
#define TASK_2

void main()
{
	setlocale(LC_ALL, "Russian");
#if defined ELOCHKA
//���� ���������� ELOCHKA,
//�� ������������� ���, �� ��������� #endif ����� ����� �����������
	cout << offset << "\"� ���� �������� ������\"" << endl;
	cout << endl;
	cout << offset << "� ���� �������� ������," << endl;
	cout << offset << "� ���� ��� �����," << endl;
	cout << offset << "����� � ����� ��������," << endl;
	cout << offset << "������� ����." << endl;
	cout << endl;
	cout << offset << "������ �� ���� �������:" << endl;
	cout << offset << "\"���, ������, ���-���!\"" << endl;
	cout << offset << "����� ������� ��������:" << endl;
	cout << offset << "\"������, �� ��������!\"" << endl;
	cout << endl;
	cout << offset << "�������� ����� ���������" << endl;
	cout << offset << "��� ������� ������." << endl;
	cout << offset << "����� ����, �������� ����" << endl;
	cout << offset << "������ ��������." << endl;
	cout << endl;
	cout << offset << "��! ���� �� ���� �������" << endl;
	cout << offset << "��� ������� �������," << endl;
	cout << offset << "������� ����������" << endl;
	cout << offset << "���������, �����." << endl;
	cout << endl;
	cout << offset << "����� ������� ��������," << endl;
	cout << offset << "� � ������� ��������," << endl;
	cout << offset << "������ �� ���� ������" << endl;
	cout << offset << "��� ����� �������." << endl;
	cout << endl;
	cout << offset << "������ ���, ��������," << endl;
	cout << offset << "H� �������� � ��� ������" << endl;
	cout << offset << "� �����, ����� �������" << endl;
	cout << offset << "�������� ��������!" << endl;
#endif ELOCHKA

#if defined TASK_1
	cout << "������ ������ 1" << endl;
#endif
}