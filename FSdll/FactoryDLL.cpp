#include "pch.h"
#include "FSdll.h"

using namespace std;

FileSystem* FileSystemFactory::create(string fileName) {


	if (checkFS(fileName).find("NTFS") != -1) {

		return new NTFS(fileName);
	}
	else {

		cout << "File system not found!" << endl;
	}
}

string FileSystemFactory::checkFS(string fileName) {

	char lpVolumeNameBuffer[MAX_PATH];
	DWORD lpVolumeSerialNumber;
	DWORD lpMaximumComponentLength;
	DWORD lpFileSystemFlags;
	char lpFileSystemNameBuffer[MAX_PATH];

	bool dataReceived = GetVolumeInformationA(
		(fileName + ":\\").c_str(),
		lpVolumeNameBuffer,
		sizeof(lpVolumeNameBuffer),
		&lpVolumeSerialNumber,
		&lpMaximumComponentLength,
		&lpFileSystemFlags,
		lpFileSystemNameBuffer,
		sizeof(lpFileSystemNameBuffer)
	);

	if (!dataReceived) return "";

	cout << "Volume file system: " << lpFileSystemNameBuffer << endl;

	return lpFileSystemNameBuffer;
}