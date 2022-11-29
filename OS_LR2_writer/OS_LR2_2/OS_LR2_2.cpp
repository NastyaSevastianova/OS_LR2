#include <iostream>
#include<windows.h>
#include<string>

using namespace std;

void Writer()
{
	setlocale(LC_ALL, "Russian");
	string file;
	string FileMap; 
	HANDLE FileHandle;
	HANDLE HandleMap;
	char* str = new char[5000];
	LPVOID Memory;

	cout << "Введите путь файла: ";
	cin >> file;
	cout << "Введите имя файла: ";
	cin >> FileMap;

	FileHandle = CreateFileA(file.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	HandleMap = CreateFileMappingA(FileHandle, NULL, PAGE_READWRITE, 0, 1024, FileMap.c_str());
	//проецирование фрагмента файла в память
	Memory = MapViewOfFile(HandleMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if (Memory)
	{
		cout << "Введите строку (без пробелов): ";
		cin >> str;
		memcpy(Memory, str, strlen(str) * sizeof(char));
		cout << "Запуск программы чтения для считывания данных с входных данных\n";
		cout << "Ожидание: ";
		cin >> file;
		UnmapViewOfFile(Memory); //завершение проецирования файла
	}
	else
	{
		cout << "Ошибка!";
	}
}

int main()
{
	Writer();
	return 0;
}