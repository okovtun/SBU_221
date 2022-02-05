#include<iostream>
using namespace std;

#define offset "\t\t\t\t\t\t"
#define что_заменть чем_заменить
//define - определить
//макроопределение (макрос)
//имя значение
#define имя значение

/*#if defined NAME

#endif*/

//#define ELOCHKA	//ОПРЕДЕЛЯЕТ ELOCHKA (создает определение ELOCHKA)
//определить ELOCHKA
//#define TASK_1
#define TASK_2

void main()
{
	setlocale(LC_ALL, "Russian");
#if defined ELOCHKA
//если определено ELOCHKA,
//то нижеследующий код, до директивы #endif будет виден компилятору
	cout << offset << "\"В лесу родилась Ёлочка\"" << endl;
	cout << endl;
	cout << offset << "В лесу родилась елочка," << endl;
	cout << offset << "В лесу она росла," << endl;
	cout << offset << "Зимой и летом стройная," << endl;
	cout << offset << "Зеленая была." << endl;
	cout << endl;
	cout << offset << "Метель ей пела песенку:" << endl;
	cout << offset << "\"Спи, елочка, бай-бай!\"" << endl;
	cout << offset << "Мороз снежком укутывал:" << endl;
	cout << offset << "\"Смотри, не замерзай!\"" << endl;
	cout << endl;
	cout << offset << "Трусишка зайка серенький" << endl;
	cout << offset << "Под елочкой скакал." << endl;
	cout << offset << "Порою волк, сердитый волк" << endl;
	cout << offset << "Рысцою пробегал." << endl;
	cout << endl;
	cout << offset << "Чу! Снег по лесу частому" << endl;
	cout << offset << "Под полозом скрипит," << endl;
	cout << offset << "Лошадка мохноногая" << endl;
	cout << offset << "Торопится, бежит." << endl;
	cout << endl;
	cout << offset << "Везет лошадка дровенки," << endl;
	cout << offset << "А в дровнях старичок," << endl;
	cout << offset << "Срубил он нашу елочку" << endl;
	cout << offset << "Под самый корешок." << endl;
	cout << endl;
	cout << offset << "Теперь она, нарядная," << endl;
	cout << offset << "Hа праздник к нам пришла" << endl;
	cout << offset << "И много, много радости" << endl;
	cout << offset << "Детишкам принесла!" << endl;
#endif ELOCHKA

#if defined TASK_1
	cout << "Решаем задачу 1" << endl;
#endif
}