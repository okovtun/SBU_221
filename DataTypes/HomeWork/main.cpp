#include<iostream>
using namespace std;

//#define TASK_1
//#define TASK_2
//#define TASK_3
#define TASK_4
//#define TASK_5
//#define TASK_6
//#define TASK_7


void main()

{

	setlocale(LC_ALL, "Russian");

#if defined TASK_1
	double money;
	cout << "Введите денежную сумму: "; cin >> money;
	money += .00001;
	int rub = money;
	cout << rub << " руб.\t";
	int cop = (money - rub) * 100;
	cout << cop << " коп.\n";

#endif

#if defined TASK_2
	double price_of_copybook;
	int number_of_copybooks;
	double price_of_pencil;
	int number_of_pencils;
	cout << "Введите цену тетради: "; cin >> price_of_copybook;
	cout << "Введите количесво тетрадей: "; cin >> number_of_copybooks;
	cout << "Введите цену карандаша: "; cin >> price_of_pencil;
	cout << "Введите количество карандашей: "; cin >> number_of_pencils;
	double total_price = price_of_copybook * number_of_copybooks + price_of_pencil * number_of_pencils;
	cout << "ОБщая стоимость: " << total_price << " руб." << endl;
#endif

#if defined TASK_3
	double price_of_copybook;
	double price_of_cover;
	int number_of_sets;
	cout << "Введите цену тетради: "; cin >> price_of_copybook;
	cout << "Введите цену обложки: "; cin >> price_of_cover;
	cout << "Введите количество комплектов: "; cin >> number_of_sets;
	double total_price = (price_of_copybook + price_of_cover) * number_of_sets;
	cout << "Общая стоимость: " << total_price << " руб." << endl;
#endif

#if defined TASK_4
	int yard_distance;
	int returne_distance;
	double consumption_of_gasoline;
	double price_of_a_gasoline;
	//double gasoline_consumption_there_and_back;
	//double a_trip_to_the_summer_dacha_and_back;
	cout << "Расстояние до дачи: ";  cin >> yard_distance;
	cout << "Расcтояние обратно: "; cin >> returne_distance;
	cout << "Расход бензина: ";  cin >> consumption_of_gasoline;
	cout << "Цена литра бензина: "; cin >> price_of_a_gasoline;
	double gasoline_consumption_there_and_back = (yard_distance + returne_distance) * consumption_of_gasoline / 100;
	double a_trip_to_the_summer_dacha_and_back = gasoline_consumption_there_and_back * price_of_a_gasoline;
	cout << "Поездка на дачу и обратно: " << a_trip_to_the_summer_dacha_and_back << " руб." << endl;
#endif

#if defined TASK_5
	int air_temperature;
	cout << "Введите число: "; cin >> air_temperature;
	if (air_temperature > 0)
	{
		cout << "На улице тепло" << endl;
	}
	else if (air_temperature < 0)
	{
		cout << "На улице холодно" << endl;
	}
#endif

#if defined TASK_6
	int number;
	cout << "Введите число: "; cin >> number;
	if (number < 10)
	{
		cout << "Цель поражена" << endl;
	}
	else if (number > 10)
	{
		cout << "Вы промахнулись" << endl;
	}
#endif

#if defined TASK_7

#endif
}