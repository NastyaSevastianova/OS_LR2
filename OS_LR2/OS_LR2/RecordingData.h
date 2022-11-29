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
	cout << "������� �����, ������������� �������, � ������� �� ������ ������� (�����������������): ";
	wcin >> std::hex >> Memory >> std::dec;
	wcin.ignore(INT_MAX, '\n');
	if (Memory == nullptr) {
		cout << "�� ������� ��������� �����.\n";
		return;
	}

	// get info about region
	VirtualQuery(Memory, &memInfo, sizeof(memInfo));

	// check for mistakes at getting info
	if (GetLastError() != 0) {
		cout << "������!" << GetLastError() << ".\n";
		SetLastError(0);
		return;
	}

	// check if memory is accessable
	if (memInfo.State != MEM_COMMIT) {
		cout << "������. ������ �� ��������.\n";
		return;
	}

	// define max size and desired size of written data
	SIZE_T maxSize = memInfo.RegionSize - ((SIZE_T)Memory - (SIZE_T)memInfo.BaseAddress);
	SIZE_T desiredSize = 0;
	cout << "�� ������ �������� � ���� ������. " << maxSize << " ����.\n"
		<< "������� ���� ��� ����� ��������? ";
	wcin >> desiredSize;
	wcin.ignore(INT_MAX, '\n');

	// check if input was incorrect
	if (desiredSize == 0 || desiredSize > maxSize) {
		cout << "�� �� ������ �������� ����� ����� ������: " << desiredSize << " ����. �������� ��������.\n";
		return;
	}

	// write data
	unsigned numericView;
	byte* data = (byte*)Memory;
	cout << "��� " << desiredSize << " ���� (�� 0 �� 255), ���� �� ������: ";
	for (SIZE_T i = 0; i < desiredSize; ++i) {
		std::cin >> numericView;
		*(data++) = numericView;
	}

	// show typed info
	cout << "\n�� ����� ";
	for (SIZE_T i = 0; i < desiredSize; ++i) {
		numericView = *((byte*)Memory + i);
		cout << numericView << " ";
	}
}

