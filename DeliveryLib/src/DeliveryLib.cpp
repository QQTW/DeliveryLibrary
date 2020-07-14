
#include "DeliveryLib_H.h"


Address::Address(int a_x, int a_y, string a_city, string a_street) // Конструктор для класса Address
{
	x = a_x;  // абсцисса кафе
	y = a_y;  // ордината кафе
	city = a_city;  // город, в котором расположено кафе
	street = a_street;  // улица, на которой расположено кафе
}

string Address::getCity() // получаем доступ к приватному атрибуту "city"
{
	return city;
}

string Address::getStreet()  // получаем доступ к приватному атрибуту "street"
{
	return street;
}

float Address::getDistance(int inputX, int inputY)  // Находит расстояние между двумя точками с координатами (x, y) и (inputX, inputY)
{
	return sqrt(pow(inputX - x, 2) + pow(inputY - y, 2));
}

void Address::printAddress()  // "Красиво" выводит адрес в косноль
{
	cout << "Город: " << city << ";  Улица: " << street << ";  Координаты (x,y): " << "(" << x << ", " << y << ")" << "\n";
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////


DeliverySystem::DeliverySystem(int a_cafesAmount)  // Конструктор для класса DeliverySystem
{
	cafesAmount = a_cafesAmount;  // количество кафе в системе
}

Address DeliverySystem::getRandomAddress()  // генерирует рандомный адрес для кафе
{
	string cities[5] = { "Москва", "Воронеж", "Санкт-Петербург", "Ярославль", "Новороссийск" };  // массив из 5 городов (можно добавить больше)
	string streets[5] = { "Центральная", "Молодежная", "Школьная", "Лесная ", "Садовая" };  // массив из 5 улиц (можно добавить больше)

	int randX = rand() % 100 + 1;  // рандомная координата по X  (от 1 до 99)
	int randY = rand() % 100 + 1;  // рандомная координата по Y  (от 1 до 99)

	string randCity = cities[rand() % 5];  // рандомный город из массива городов
	string randStreet = streets[abs((rand() % 5) - (rand() % 5))];  // рандомная улица из массива улиц

	Address newAddress(randX, randY, randCity, randStreet);  // создаем новый адрес

	return newAddress;
}

void DeliverySystem::printCafes()  // Выводим адреса всех кафе
{
	for (Address cafe : cafes)
	{
		cafe.printAddress();
		//cout << "\n";
	}
}

void DeliverySystem::generateCafes()  // генерирует <cafesAmount> кафе
{
	for (int i = 0; i < cafesAmount; ++i)
	{
		cafes.push_back(getRandomAddress());
	}
}

Address DeliverySystem::getNearestCafe(int userX, int userY)  // получает адрес ближайшего кафе к заданным координатам 
{
	if (cafesAmount > 0)
	{
		float distance;
		float min_distance = 100 * 100;  // минимальное расстояние от пользователя до кафе
		int nearestCafeInd = -1 - cafesAmount;  // индекс ближайшего кафе
		vector<float> distances;  // вектор всех расстояний

		// заполняем вектор расстояниями от (userX,userY) до различных кафе
		for (int i = 0; i < cafesAmount; ++i)
		{
			distance = cafes[i].getDistance(userX, userY);
			distances.push_back(distance);
		}

		// находим минимальное расстояние и индекс ближайшего кафе
		for (int i = 0; i < cafesAmount; ++i)
		{
			if (distances[i] < min_distance)
			{
				min_distance = distances[i];  // минимальное расстояние от кафе до заданных координат
				nearestCafeInd = i;  // индекс ближайшего кафе
			}
		}

		return cafes[nearestCafeInd];
	}
}

