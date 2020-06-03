#include "pch.h"
#include "FSdll.h"

void NTFS::bootInfo() {

	string fileNameF = "\\\\.\\" + this->fileName + ":";

	HANDLE fileHandle = CreateFileA(
		fileNameF.c_str(), 
		GENERIC_READ,	  
		FILE_SHARE_READ | FILE_SHARE_WRITE, 
		NULL, 
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, 
		NULL 
	);