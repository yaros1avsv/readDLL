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

	// Error handling
	if (fileHandle == INVALID_HANDLE_VALUE)
	{

		cout << "Error! Run the program as an administrator!" << endl;
		return;
	}

	// If the setpointer function doesn't work, bootInfo closes
	if (!setPointerToBegin(fileHandle)) return;

	// Allocating memory
	BYTE* buffer[1024];
	DWORD bytesRead;

	// Data reading
	bool readResult = ReadFile(
		fileHandle,
		buffer,
		1024,
		&bytesRead,
		NULL
	);

	if (!readResult || bytesRead != 1024)
	{
		// Error handling
		cout << "Error!" << endl;
		return;
	}

	// Declared the structure in the header file
	// Initializing the pointer
	PrintBootSectInfo(*reinterpret_cast<NTFS_BR*>(buffer));

	// Close a file
	CloseHandle(fileHandle);
	return;
}


void NTFS::PrintBootSectInfo(NTFS_BR bootRec) {

	printf("File system type: %s\n", bootRec.oemID);
	printf("Sector size: %d\n", bootRec.bytesPerSector);
	printf("Sectors per cluster: %d\n", bootRec.sectorPerCluster);
	printf("Volume descriptor: 0x%X\n", bootRec.mediaDiscr);
	printf("Sectors per track: %d\n", bootRec.sectorperTrack);
	printf("Number of heads: %d\n", bootRec.numOfHeaders);
	printf("Number of sectors: %lld\n", bootRec.totalSectors);
	printf("First cluster of MFT:  %lld\n", bootRec.lcnForSMFT);
	printf("First cluster of MFT mirror: %lld\n", bootRec.lcnForSMFTMirr);
	printf("Clusters per MFT Record: %d\n", bootRec.clusterPerMFT);
	printf("Clusters per Index Record: %d\n", bootRec.clusterPerIndex);
}

bool NTFS::setPointerToBegin(HANDLE fileHandle) {
	// The offset must correspond to the sector boundary
	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart = 0;

	// ...
	unsigned long currentPosition = SetFilePointer(
		fileHandle,
		sectorOffset.LowPart,
		&sectorOffset.HighPart,
		FILE_BEGIN
	);

	if (currentPosition != sectorOffset.LowPart)
	{
		cout << "Error! Offset error!" << endl;
		return false;
	}
	return  true;
}