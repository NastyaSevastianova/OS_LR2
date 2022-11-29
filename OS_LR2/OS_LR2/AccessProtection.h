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
	cout << "������� �����, ������������� �������, � ������� �� ������ �������� ������: ";
	wcin >> std::hex >> Memory >> std::dec;
	wcin.ignore(INT_MAX, '\n');
	if (Memory == nullptr) {
		cout << "�� ������� ��������� �����.\n";
		return;
	}

	// get info about region
	VirtualQuery(Memory, &memInfo, sizeof(memInfo));

	// check for mistakes
	if (GetLastError() != 0) {
		cout << "������. " << GetLastError() << ".\n";
		SetLastError(0);
		return;
	}

	// change protection
	cout << "�� �������� ������ �������, ������� � "
		<< memInfo.BaseAddress
		<< ", � �������� " << memInfo.RegionSize << " ����."
		<< "\n������� ����� ����� ������ ������ (�����������������)" << endl;
	wcin >> std::hex >> newProtection >> std::dec;
	wcin.ignore(INT_MAX, '\n');
	if (VirtualProtect(memInfo.BaseAddress, memInfo.RegionSize, newProtection, &oldProtection))
		cout << "������ ������� ��������.\n"
		<< "������ �������� �����:" << oldProtection << ".\n";
	else {
		cout << "�� ������� �������� ������."
			<< " ������: " << GetLastError() << ".\n"
			<< "��������� �������: �� ���� �������� ������ ��� �������� �������� �����.\n";
		SetLastError(0);
	}
}

