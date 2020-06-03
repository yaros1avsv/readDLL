// FSapp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <windows.h>
#include <Winioctl.h>
#include <wchar.h>
#include <algorithm>
#include "FSdll.h"

using namespace std;

int main()
{
	string diskName;

	while (1)
	{
		cout << "Enter your drive letter" << endl;
		diskName = cin.get();
		if (diskName.length() == 1)
		{
			break;
		}
	}
	getInfo(diskName);

	cin.get();
	exit(0);
}