#include <iostream>
#include <windows.h>
#include <fileapi.h>


using std::cout;
using std::cin;
using std::endl;
	
void ReservReg() 
{
	cout << "Выберите режим работы:" << endl;
	LPVOID Memory;
	int choise;

	cout << "1 - резервирование региона в автоматическом режиме" << endl << "2 - ручное резервирование региона" << endl;
	cin >> choise;
	switch (choise) {
	case 1:
		if (Memory = VirtualAlloc(NULL, 4096, MEM_RESERVE, PAGE_READWRITE))
			cout << "Была зарезервирована область памяти по базовому адресу " << Memory << endl;
		else cout << "Ошибка" << GetLastError() << endl;
		break;
	case 2:
		cout << "Введите адрес памяти " << endl;
		cin >> Memory;
		if (VirtualAlloc(Memory, 4096, MEM_RESERVE, PAGE_READWRITE))
			cout << "Память по адресу " << Memory << " была успешно зарезервирована." << endl;
		else
			cout << "Ошибка" << GetLastError() << endl;
		}
	}




