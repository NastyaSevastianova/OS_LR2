#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;

void MemStatus()
{
		setlocale(LC_ALL, "Russian");
		
		MEMORYSTATUSEX MemStatus;
		MemStatus.dwLength = sizeof(MemStatus);
		GlobalMemoryStatusEx(&MemStatus);
		cout << ("\n ������ ������: \n \n");
		cout << "  ������ ��������� ������ � ������: " << MemStatus.dwLength << "\n";
		cout << "  �������� ���������� ������: " << MemStatus.dwMemoryLoad << "\n";
		cout << "  ����� ����������� ���������� ������ � ������: " << MemStatus.ullTotalPhys << "\n";
		cout << "  ����� ���������� ������, ��������� �� ������ ������, � ������: " << MemStatus.ullAvailPhys << "\n";
		cout << "  ������� ������ ����������� ������ ������ � ������: " << MemStatus.ullTotalPageFile << "\n";
		cout << "  ������������ ����� ������, ������� ����� �������� ������� �������, � ������: " << MemStatus.ullAvailPageFile << "\n";
		cout << "  ������ ����������������� ������ ����� ������������ ��������� ������������ ����������� �������� � ������: " << MemStatus.ullTotalVirtual << "\n";
	

}

