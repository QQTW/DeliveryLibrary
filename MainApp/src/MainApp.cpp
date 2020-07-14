
#include "DeliveryLib_H.h"

/*

-Программа генерирует адреса кафе по следующему шаблону (Город, Улица, Абсцисса кафе, Ордината кафе)
-Пользователь вводит свое расположение (userX, userY)
-Программа выдает адрес ближайшего к пользователю кафе

*/

int main()
{
	setlocale(LC_ALL, "Russian");  // для русских букв в консоли

	int cafesAmount = 5;  // задаем количество кафе

	// задаем координаты пользователя
	int userX = 99;
	int userY = 99;

	DeliverySystem ds(cafesAmount);

	ds.generateCafes();  // генерируем кафе

	Address nearestCafe = ds.getNearestCafe(userX, userY);  // находим ближайшее кафе

	nearestCafe.printAddress();  // печатаем адрес ближайшего кафе


	cout << "\n";
	ds.printCafes();  // печатаем адреса всех кафе (для проверки)
}