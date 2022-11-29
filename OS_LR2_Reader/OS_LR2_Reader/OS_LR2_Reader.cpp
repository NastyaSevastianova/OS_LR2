#include <iostream>
#include<windows.h>
#include<string>

using namespace std;

void Reader()
{
	setlocale(LC_ALL, "Russian");
	string FileMap; 
	HANDLE HandleMap; 
	LPVOID Memory; 
	cout << "Введите имя файла: ";
	cin >> FileMap;

	HandleMap = OpenFileMappingA(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, FileMap.c_str());
	//проецирование фрагмента файла в память
	Memory = MapViewOfFile(HandleMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if (Memory)
	{
		cout << "Содержимое файла " << (char*)Memory << endl << endl;
		cout << "Для завершения введите любой символ: ";
		cin >> FileMap;
		UnmapViewOfFile(Memory); //завершение проецирования файла
	}
	else
	{
		cout << "Ошибка!";
	}
}

int main()
{
	Reader();
	return 0;
}