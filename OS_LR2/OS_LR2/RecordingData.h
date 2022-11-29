#include <iostream>
#include <windows.h>
#include <fileapi.h>


using std::cout;
using std::wcin;


void RecordingData()
{
	MEMORY_BASIC_INFORMATION memInfo;
	LPVOID Memory = nullptr;

	// specify region
	cout << "Введите адрес, принадлежащий региону, в который вы хотите попасть (шестнадцатеричный): ";
	wcin >> std::hex >> Memory >> std::dec;
	wcin.ignore(INT_MAX, '\n');
	if (Memory == nullptr) {
		cout << "Не удалось разобрать адрес.\n";
		return;
	}

	// get info about region
	VirtualQuery(Memory, &memInfo, sizeof(memInfo));

	// check for mistakes at getting info
	if (GetLastError() != 0) {
		cout << "Ошибка!" << GetLastError() << ".\n";
		SetLastError(0);
		return;
	}

	// check if memory is accessable
	if (memInfo.State != MEM_COMMIT) {
		cout << "Ошибка. Память не выделена.\n";
		return;
	}

	// define max size and desired size of written data
	SIZE_T maxSize = memInfo.RegionSize - ((SIZE_T)Memory - (SIZE_T)memInfo.BaseAddress);
	SIZE_T desiredSize = 0;
	cout << "Вы можете написать в этот регион. " << maxSize << " байт.\n"
		<< "Сколько байт вам нужно записать? ";
	wcin >> desiredSize;
	wcin.ignore(INT_MAX, '\n');

	// check if input was incorrect
	if (desiredSize == 0 || desiredSize > maxSize) {
		cout << "Вы не можете записать такой объем данных: " << desiredSize << " байт. Операция прервана.\n";
		return;
	}

	// write data
	unsigned numericView;
	byte* data = (byte*)Memory;
	cout << "Тип " << desiredSize << " байт (от 0 до 255), один за другим: ";
	for (SIZE_T i = 0; i < desiredSize; ++i) {
		std::cin >> numericView;
		*(data++) = numericView;
	}

	// show typed info
	cout << "\nВы ввели ";
	for (SIZE_T i = 0; i < desiredSize; ++i) {
		numericView = *((byte*)Memory + i);
		cout << numericView << " ";
	}
}

