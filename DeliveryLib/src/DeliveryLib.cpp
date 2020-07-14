
#include "DeliveryLib_H.h"


Address::Address(int a_x, int a_y, string a_city, string a_street) // ����������� ��� ������ Address
{
	x = a_x;  // �������� ����
	y = a_y;  // �������� ����
	city = a_city;  // �����, � ������� ����������� ����
	street = a_street;  // �����, �� ������� ����������� ����
}

string Address::getCity() // �������� ������ � ���������� �������� "city"
{
	return city;
}

string Address::getStreet()  // �������� ������ � ���������� �������� "street"
{
	return street;
}

float Address::getDistance(int inputX, int inputY)  // ������� ���������� ����� ����� ������� � ������������ (x, y) � (inputX, inputY)
{
	return sqrt(pow(inputX - x, 2) + pow(inputY - y, 2));
}

void Address::printAddress()  // "�������" ������� ����� � �������
{
	cout << "�����: " << city << ";  �����: " << street << ";  ���������� (x,y): " << "(" << x << ", " << y << ")" << "\n";
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////


DeliverySystem::DeliverySystem(int a_cafesAmount)  // ����������� ��� ������ DeliverySystem
{
	cafesAmount = a_cafesAmount;  // ���������� ���� � �������
}

Address DeliverySystem::getRandomAddress()  // ���������� ��������� ����� ��� ����
{
	string cities[5] = { "������", "�������", "�����-���������", "���������", "������������" };  // ������ �� 5 ������� (����� �������� ������)
	string streets[5] = { "�����������", "����������", "��������", "������ ", "�������" };  // ������ �� 5 ���� (����� �������� ������)

	int randX = rand() % 100 + 1;  // ��������� ���������� �� X  (�� 1 �� 99)
	int randY = rand() % 100 + 1;  // ��������� ���������� �� Y  (�� 1 �� 99)

	string randCity = cities[rand() % 5];  // ��������� ����� �� ������� �������
	string randStreet = streets[abs((rand() % 5) - (rand() % 5))];  // ��������� ����� �� ������� ����

	Address newAddress(randX, randY, randCity, randStreet);  // ������� ����� �����

	return newAddress;
}

void DeliverySystem::printCafes()  // ������� ������ ���� ����
{
	for (Address cafe : cafes)
	{
		cafe.printAddress();
		//cout << "\n";
	}
}

void DeliverySystem::generateCafes()  // ���������� <cafesAmount> ����
{
	for (int i = 0; i < cafesAmount; ++i)
	{
		cafes.push_back(getRandomAddress());
	}
}

Address DeliverySystem::getNearestCafe(int userX, int userY)  // �������� ����� ���������� ���� � �������� ����������� 
{
	if (cafesAmount > 0)
	{
		float distance;
		float min_distance = 100 * 100;  // ����������� ���������� �� ������������ �� ����
		int nearestCafeInd = -1 - cafesAmount;  // ������ ���������� ����
		vector<float> distances;  // ������ ���� ����������

		// ��������� ������ ������������ �� (userX,userY) �� ��������� ����
		for (int i = 0; i < cafesAmount; ++i)
		{
			distance = cafes[i].getDistance(userX, userY);
			distances.push_back(distance);
		}

		// ������� ����������� ���������� � ������ ���������� ����
		for (int i = 0; i < cafesAmount; ++i)
		{
			if (distances[i] < min_distance)
			{
				min_distance = distances[i];  // ����������� ���������� �� ���� �� �������� ���������
				nearestCafeInd = i;  // ������ ���������� ����
			}
		}

		return cafes[nearestCafeInd];
	}
}

