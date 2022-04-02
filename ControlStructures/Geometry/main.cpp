#include<iostream>
using namespace std;

//#define SQUARE
//#define TRIANGLE_1
//#define TRIANGLE_2
//#define TRIANGLE_3
//#define TRIANGLE_4
//#define ROMBUS

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите число: "; cin >> n;
#ifdef SQUARE
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif // SQUARE

#ifdef TRIANGLE_1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif // DEBUG

#ifdef TRIANGLE_2
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
#endif // TRIANGLE_2

#ifdef TRIANGLE_3
	for (int i = 0; i < n; i++)
	{
		/*for (int j = 0; j < i; j++)cout << "  ";
		for (int j = i; j < n; j++)cout << "* ";*/
		for (int j = 0; j < n; j++)
		{
			if (j < i)cout << "  ";
			else cout << "* ";
		}
		cout << endl;
	}
#endif // TRIANGLE_3

#ifdef TRIANGLE_4
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)cout << "  ";
		for (int j = 0; j <= i; j++)cout << "* ";
		cout << endl;
	}
#endif // TRIANGLE_4

#ifdef ROMBUS
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)cout << " "; cout << "/";
		for (int j = 0; j < i; j++)cout << "  "; cout << "\\";
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)cout << " "; cout << "\\";
		for (int j = i; j < n - 1; j++)cout << "  "; cout << "/";
		cout << endl;
	}
#endif // ROMBUS

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//cout << "* ";
			//if (i % 2 == j % 2)cout << "+ ";else cout << "- ";
			//(i % 2 == j % 2) ? cout << "+ " : cout << "- ";
			cout << (i % 2 == j % 2 ? "+ " : "- ");
		}
		cout << endl;
	}
}