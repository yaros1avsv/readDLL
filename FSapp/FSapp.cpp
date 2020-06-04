// FSapp.cpp : add Factory Method

#include <iostream>
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