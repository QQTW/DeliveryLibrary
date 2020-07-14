#pragma once

// В хедере объявляется каждая функция, объект и тип данных, являющиеся частью интерфейса вызова модуля  (*.h файле) 
// Грубо говоря, в заголовочном файле ты пишешь шаблон, прототип своей программы, а реализация классов и методов уже делается в отдельном *.cpp файле

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


class Address
{
private:
	int x, y;
	string city;
	string street;

public:
	Address(int a_x, int a_y, string a_city, string a_street);

	string getCity();
	string getStreet();

	float getDistance(int inputX, int inputY);
	void printAddress();
};


class DeliverySystem
{
private:
	int cafesAmount;
	vector<Address> cafes;
	Address getRandomAddress();

public:
	DeliverySystem(int a_cafesAmount);

	void printCafes();
	void generateCafes();
	Address getNearestCafe(int userX, int userY);
};