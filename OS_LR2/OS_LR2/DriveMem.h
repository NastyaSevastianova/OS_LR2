#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;
using std::endl;

void DriveMem()
{
	cout << "�������� ����� ������:" << endl;
	LPVOID Memory;
	int choise;

	cout << "1 - �������������� ������� � �������������� ������" << endl << "2 - ������ �������������� �������" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		if (Memory = VirtualAlloc(NULL, 4096, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE))
			cout << "���� ��������������� ������� ������ �� �������� ������ " << Memory << endl;
		else if (GetLastError() == 487)
		{
			if (VirtualAlloc(Memory, 4096, MEM_COMMIT, PAGE_READWRITE))
				cout << "������ �� ������ " << Memory << " ���� ������� ���������������." << endl;
			else
				cout << "������ " << GetLastError() << "\n" << endl;
		}
		break;
	case 2:
		cout << "������� ����� ������ " << endl;
		cin >> Memory;
		if (VirtualAlloc(Memory, 4096, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE))
			cout << "������ �� ������ " << Memory << " ���� ������� ���������������." << endl;
		else if (GetLastError() == 487)
		{
			if (VirtualAlloc(Memory, 4096, MEM_COMMIT, PAGE_READWRITE))
				cout << "������ �� ������ " << Memory << " ���� ������� ���������������." << endl;
			else
				cout << "������" << GetLastError() << "\n" << endl;
		}
		break;
	}
}

