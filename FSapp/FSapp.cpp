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

	string diskNameFormated = "\\\\.\\" + diskName + ":";

	string SysName = FindFSName(diskName);
	if (!fsIsSupported(SysName))
	{
		cout << SysName << "not NTFS" << endl;
		cin.get();
		cin.get();
		exit(0);
	}

	BPB _bpb;
	if (getFsInfo(diskNameFormated, &_bpb))
	{
		PrintBootSectInfo(_bpb);
	}
	cout << "Press Enter to exit";
	cin.get();
	cin.get();
	exit(0);
}