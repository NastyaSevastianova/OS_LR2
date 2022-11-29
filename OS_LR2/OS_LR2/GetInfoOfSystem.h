#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;

void OEM(DWORD oem) {
	switch (oem) {
	case PROCESSOR_ARCHITECTURE_AMD64:
		cout << "\n����������� ����������: AMD64;\n";
		break;
	case PROCESSOR_ARCHITECTURE_ARM:
		cout << "\n����������� ����������: ARM;\n";
		break;
	case PROCESSOR_ARCHITECTURE_ARM64:
		cout << "\n����������� ����������: ARM64;\n";
		break;
	case PROCESSOR_ARCHITECTURE_IA64:
		cout << "\n����������� ����������: �� ���� Intel Itanium;\n";
		break;
	case PROCESSOR_ARCHITECTURE_INTEL:
		cout << "\n����������� ����������: x86;\n";
		break;
	case PROCESSOR_ARCHITECTURE_UNKNOWN:
		cout << "\n����������� ����������: ����������;\n";
		break;
	default:
		cout << "\n����������� ����������: UNEXPECTED VALUE;\n";
	}
}

void GetInfoOfSystem(){
	setlocale(LC_ALL, "Russian");

	LPSYSTEM_INFO sysInfo;

	sysInfo = new SYSTEM_INFO();
	GetNativeSystemInfo(sysInfo);

	OEM(sysInfo->wProcessorArchitecture);
	cout << "������ ��������: " << sysInfo->dwPageSize << ";\n";
	cout << "����������� ����� ��������� ������ (�����������������): " << sysInfo->lpMinimumApplicationAddress << ";\n";
	cout << "������������ ����� ��������� ������ (�����������������): " << sysInfo->lpMaximumApplicationAddress << ";\n";
	cout << "������� ����������: " << sysInfo->wProcessorRevision << ";\n";
	cout << "����� ��������� ����������: " << sysInfo->dwActiveProcessorMask << ";\n";
	cout << "����������� �������������: " << sysInfo->dwAllocationGranularity << ";\n";
	cout << "������� ����������:: " << sysInfo->wProcessorLevel << ";\n";

	delete sysInfo;
}

