#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;

void OEM(DWORD oem) {
	switch (oem) {
	case PROCESSOR_ARCHITECTURE_AMD64:
		cout << "\nАрхитектура процессора: AMD64;\n";
		break;
	case PROCESSOR_ARCHITECTURE_ARM:
		cout << "\nАрхитектура процессора: ARM;\n";
		break;
	case PROCESSOR_ARCHITECTURE_ARM64:
		cout << "\nАрхитектура процессора: ARM64;\n";
		break;
	case PROCESSOR_ARCHITECTURE_IA64:
		cout << "\nАрхитектура процессора: на базе Intel Itanium;\n";
		break;
	case PROCESSOR_ARCHITECTURE_INTEL:
		cout << "\nАрхитектура процессора: x86;\n";
		break;
	case PROCESSOR_ARCHITECTURE_UNKNOWN:
		cout << "\nАрхитектура процессора: неизвестна;\n";
		break;
	default:
		cout << "\nАрхитектура процессора: UNEXPECTED VALUE;\n";
	}
}

void GetInfoOfSystem(){
	setlocale(LC_ALL, "Russian");

	LPSYSTEM_INFO sysInfo;

	sysInfo = new SYSTEM_INFO();
	GetNativeSystemInfo(sysInfo);

	OEM(sysInfo->wProcessorArchitecture);
	cout << "Размер страницы: " << sysInfo->dwPageSize << ";\n";
	cout << "Минимальный адрес выделения памяти (шестнадцатеричный): " << sysInfo->lpMinimumApplicationAddress << ";\n";
	cout << "Максимальный адрес выделения памяти (шестнадцатеричный): " << sysInfo->lpMaximumApplicationAddress << ";\n";
	cout << "Ревизия процессора: " << sysInfo->wProcessorRevision << ";\n";
	cout << "Маска активного процессора: " << sysInfo->dwActiveProcessorMask << ";\n";
	cout << "Детализация распределения: " << sysInfo->dwAllocationGranularity << ";\n";
	cout << "Уровень процессора:: " << sysInfo->wProcessorLevel << ";\n";

	delete sysInfo;
}

