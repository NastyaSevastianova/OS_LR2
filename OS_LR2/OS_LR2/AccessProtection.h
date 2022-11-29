#include <iostream>
#include <windows.h>
#include <fileapi.h>


using std::cout;
using std::wcin;
using std::endl;


void AccessProtection()
{
	MEMORY_BASIC_INFORMATION memInfo;
	PVOID Memory = nullptr;
	DWORD newProtection, oldProtection;

	// specify region
	cout << "Введите адрес, принадлежащий региону, в котором вы хотите изменить защиту: ";
	wcin >> std::hex >> Memory >> std::dec;
	wcin.ignore(INT_MAX, '\n');
	if (Memory == nullptr) {
		cout << "Не удалось разобрать адрес.\n";
		return;
	}

	// get info about region
	VirtualQuery(Memory, &memInfo, sizeof(memInfo));

	// check for mistakes
	if (GetLastError() != 0) {
		cout << "Ошибка. " << GetLastError() << ".\n";
		SetLastError(0);
		return;
	}

	// change protection
	cout << "Вы измените защиту региона, начиная с "
		<< memInfo.BaseAddress
		<< ", с размером " << memInfo.RegionSize << " байт."
		<< "\nВведите новое слово защиты флагов (шестнадцатеричное)" << endl;
	wcin >> std::hex >> newProtection >> std::dec;
	wcin.ignore(INT_MAX, '\n');
	if (VirtualProtect(memInfo.BaseAddress, memInfo.RegionSize, newProtection, &oldProtection))
		cout << "Защита успешно изменена.\n"
		<< "Старое защитное слово:" << oldProtection << ".\n";
	else {
		cout << "Не удалось изменить защиту."
			<< " Ошибка: " << GetLastError() << ".\n"
			<< "Возможные причины: не была выделена память или неверное защитное слово.\n";
		SetLastError(0);
	}
}

