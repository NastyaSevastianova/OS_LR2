#include <iostream>
#include <windows.h>
#include <fileapi.h>

using std::cout;
using std::cin;
using std::endl;

void StateMem()
{
	void* Memory;
	cout << endl << "Введите адрес: ";
	cin >> Memory;
	MEMORYSTATUS MemStatus;
	MEMORY_BASIC_INFORMATION MemInfo;
	GlobalMemoryStatus(&MemStatus);
	VirtualQuery(Memory, &MemInfo, sizeof(MemStatus));
	cout << "  Информация о страницах в виртуальном адресном пространстве: " << "\n";
	cout << "  Указатель на базовый адрес региона страниц: " << MemInfo.BaseAddress << "\n";
	cout << "  Указатель на базовый адрес диапазона страниц, выделенных функцией VirtualAlloc: " << MemInfo.AllocationBase <<  "\n";
	cout << "  Вариант защиты памяти при первоначальном выделении региона: " << MemInfo.AllocationProtect <<  "\n";
	cout << "  Размер области, начинающейся с базового адреса, в которой все страницы имеют одинаковые атрибуты, в байтах: " << MemInfo.RegionSize << "\n";
	cout << "  Состояние страниц в регионе. Этот элемент может быть одним из следующих значений: ";
	cout << endl << endl;

	switch (MemInfo.State) {
	case MEM_COMMIT:
		cout << "  Cраницы памяти, для которых было выделено физическое хранилище" << endl;
		break;
	case MEM_FREE:
		cout << "  Cтраницы памяти, недоступные для вызывающего процесса и доступные для выделения" << endl;
		break;
	case MEM_RESERVE:
		cout << "  Cтраницы памяти, на которых зарезервирован диапазон виртуального адресного пространства процесса без выделения физической памяти" << endl;
		break;
	}
	cout << endl;
	cout << "  Защита доступа к страницам в регионе: " << MemInfo.Protect << endl;
	cout << "  Тип страниц в регионе. Определены следующие типы: " ;

	switch (MemInfo.Type) {
	case MEM_IMAGE:
		cout << "    Cтраницы памяти в регионе отображаются \n в виде раздела изображения" << endl;
		break;
	case  MEM_MAPPED:
		cout << "    Cтраницы памяти внутри региона отображаются\n в представлении раздела" << endl;
		break;
	case MEM_PRIVATE:
		cout << "   Cтраницы памяти внутри региона являются частными \n (не используются другими процессами)" << endl;
		break;
	default:
		cout << MemInfo.Type << endl;
		break;
	}
}

