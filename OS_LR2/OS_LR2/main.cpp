#include <iostream>
#include <Windows.h>

#include "GetInfoOfSystem.h"
#include "MemStatus.h"
#include "StateMem.h"
#include "ReservReg.h"
#include "DriveMem.h"
#include "RecordingData.h"
#include "AccessProtection.h"
#include "MemoryReturn.h"

using namespace std;

void info()
{
	cout << "Здравствуйте! Выберите желаемый пункт меню \n\n"
		<< "a - получение информации о вычислительной системе \n"
		<< "b - определение статуса виртуальной памяти \n"
		<< "c - определение состояния конкретного участка памяти по заданному с клавиатуры адресу \n"
		<< "d - резервирование региона в автоматическом режиме и в режиме ввода адреса начала региона \n"
		<< "e - резервирование региона и передача ему физической памяти в автоматическом режиме и в режиме ввода адреса начала региона \n"
		<< "f - запись данных в ячейки памяти по заданным с клавиатуры адресам \n"
		<< "g - установкf защиты доступа для заданного (с клавиатуры) региона памяти и ее проверку \n"
		<< "h - возврат физической памяти и освобождение региона адресного пространства заданного(с клавиатуры) региона памяти \n"
		<< endl;

}


int main()
{
	setlocale(LC_ALL, "Russian");
	info();
	CHAR ch = 'y';

	while (ch != 'i')
	{

		system("cls");
		info();

		cin >> ch;

		switch (ch)
		{
		case 'a':
			GetInfoOfSystem();
			break;
		case 'b':
			MemStatus();
			break;
		case 'c':
			StateMem();
			break;
		case 'd':
			ReservReg();
			break;
		case 'e':
			DriveMem();
			break;
		case 'f':
			RecordingData();
			break;
		case 'g':
			AccessProtection();
			break;
		case 'h':
			Return();
			break;
		case 'i':
			break;
		default:
			cout << "Вы ввели неверное значение, повторите ввод с выбором из списка" << endl;

			break;
		}

		system("pause");
	}

	return 0;
}

