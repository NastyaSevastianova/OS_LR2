#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;
using std::endl;

void StateMem()
{
	void* Memory;
	cout << endl << "������� �����: ";
	cin >> Memory;
	MEMORYSTATUS MemStatus;
	MEMORY_BASIC_INFORMATION MemInfo;
	GlobalMemoryStatus(&MemStatus);
	VirtualQuery(Memory, &MemInfo, sizeof(MemStatus));
	cout << "  ���������� � ��������� � ����������� �������� ������������: " << "\n";
	cout << "  ��������� �� ������� ����� ������� �������: " << MemInfo.BaseAddress << "\n";
	cout << "  ��������� �� ������� ����� ��������� �������, ���������� �������� VirtualAlloc: " << MemInfo.AllocationBase <<  "\n";
	cout << "  ������� ������ ������ ��� �������������� ��������� �������: " << MemInfo.AllocationProtect <<  "\n";
	cout << "  ������ �������, ������������ � �������� ������, � ������� ��� �������� ����� ���������� ��������, � ������: " << MemInfo.RegionSize << "\n";
	cout << "  ��������� ������� � �������. ���� ������� ����� ���� ����� �� ��������� ��������: ";
	cout << endl << endl;

	switch (MemInfo.State) {
	case MEM_COMMIT:
		cout << "  C������ ������, ��� ������� ���� �������� ���������� ���������" << endl;
		break;
	case MEM_FREE:
		cout << "  C������� ������, ����������� ��� ����������� �������� � ��������� ��� ���������" << endl;
		break;
	case MEM_RESERVE:
		cout << "  C������� ������, �� ������� �������������� �������� ������������ ��������� ������������ �������� ��� ��������� ���������� ������" << endl;
		break;
	}
	cout << endl;
	cout << "  ������ ������� � ��������� � �������: " << MemInfo.Protect << endl;
	cout << "  ��� ������� � �������. ���������� ��������� ����: " ;

	switch (MemInfo.Type) {
	case MEM_IMAGE:
		cout << "    C������� ������ � ������� ������������ \n � ���� ������� �����������" << endl;
		break;
	case  MEM_MAPPED:
		cout << "    C������� ������ ������ ������� ������������\n � ������������� �������" << endl;
		break;
	case MEM_PRIVATE:
		cout << "   C������� ������ ������ ������� �������� �������� \n (�� ������������ ������� ����������)" << endl;
		break;
	default:
		cout << MemInfo.Type << endl;
		break;
	}
}

