#include <iostream>
#include <windows.h>
#include <fileapi.h>


using std::cout;
using std::cin;
using std::endl;

int Free() {
    int choise;
    cout << "1 - ������������ ������� ��������� ������������" << endl;
    cout << "2 - ������� ���������� ������" << endl;
    cout << endl << endl;
    cin >> choise;
    return choise;
}

void Return()
{
        SIZE_T Size;
        DWORD OldProtect = 0;
        DWORD NewProtect = 0;
        DWORD attribute = 0;
        int choise;
        bool flag;
        PVOID Memory;

        choise = Free();
        if (choise == 1)
        {
            cout << endl << "������� �����: ";
            cin >> Memory;
            flag = VirtualFree(Memory, 0, MEM_RELEASE);
        }
        else if (choise == 2)
        {
            cout << endl << "������� ���������� ������ ��� ��������:";
            cin >> Size;
            cout << endl << "������� �����: ";
            cin >> Memory;
            flag = VirtualFree(Memory, Size, MEM_DECOMMIT);

        }

        if (flag != 0) {
            cout << endl << "�������" << endl;
        }
        else {
            cout << endl << "������!" << endl;
        }
        
}

