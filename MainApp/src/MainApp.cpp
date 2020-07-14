
#include "DeliveryLib_H.h"

/*

-��������� ���������� ������ ���� �� ���������� ������� (�����, �����, �������� ����, �������� ����)
-������������ ������ ���� ������������ (userX, userY)
-��������� ������ ����� ���������� � ������������ ����

*/

int main()
{
	setlocale(LC_ALL, "Russian");  // ��� ������� ���� � �������

	int cafesAmount = 5;  // ������ ���������� ����

	// ������ ���������� ������������
	int userX = 99;
	int userY = 99;

	DeliverySystem ds(cafesAmount);

	ds.generateCafes();  // ���������� ����

	Address nearestCafe = ds.getNearestCafe(userX, userY);  // ������� ��������� ����

	nearestCafe.printAddress();  // �������� ����� ���������� ����


	cout << "\n";
	ds.printCafes();  // �������� ������ ���� ���� (��� ��������)
}