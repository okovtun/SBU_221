#include<iostream>
#include<conio.h>
using namespace std;

#define UP_ARROW	72
#define DOWN_ARROW	80
#define LEFT_ARROW	75
#define RIGHT_ARROW	77
#define Space	' '
#define Enter	13
#define Escape	27

void main()
{
	setlocale(LC_ALL, "");
	cout << "Shooter" << endl;

	char key;
	do
	{
		key = _getch();
		//cout << (int)key << "\t" << key << endl;
		switch (key)
		{
		case UP_ARROW:	case 'w':case 'W': cout << "Вперед" << endl; break;
		case DOWN_ARROW:case 's':case 'S': cout << "Назад" << endl; break;
		case LEFT_ARROW:case 'a':case 'A': cout << "Влево" << endl; break;
		case RIGHT_ARROW:case 'd':case 'D': cout << "Вправо" << endl; break;
		case ' ': cout << "Прыжок" << endl; break;
		case Enter:  cout << "Огонь" << endl; break;
		case Escape: cout << "Выход" << endl;
		case -32:break;
		default:  //if (key != Escape && key != -32)
			cout << "Error" << endl;
		}
	} while (key != Escape);
}