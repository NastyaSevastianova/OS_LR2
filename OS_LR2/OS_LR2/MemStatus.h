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
		cout << ("\n Статус памяти: \n \n");
		cout << "  Размер структуры данных в байтах: " << MemStatus.dwLength << "\n";
		cout << "  Загрузка физической памяти: " << MemStatus.dwMemoryLoad << "\n";
		cout << "  Объем фактической физической памяти в байтах: " << MemStatus.ullTotalPhys << "\n";
		cout << "  Объем физической памяти, доступной на данный момент, в байтах: " << MemStatus.ullAvailPhys << "\n";
		cout << "  Текущий размер выделенного лимита памяти в байтах: " << MemStatus.ullTotalPageFile << "\n";
		cout << "  Максимальный объем памяти, который может выделить текущий процесс, в байтах: " << MemStatus.ullAvailPageFile << "\n";
		cout << "  Размер пользовательского режима части виртуального адресного пространства вызывающего процесса в байтах: " << MemStatus.ullTotalVirtual << "\n";
	

}

