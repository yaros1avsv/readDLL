#pragma once

#ifdef FSREADER_EXPORTS
#define FSREADER_API __declspec(dllexport)
#else
#define FSREADER_API __declspec(dllimport)
#endif

#include <iostream>
#include <windows.h>
#include <Winioctl.h>
#include <wchar.h>
#include <algorithm>
#include <stdio.h>

#pragma pack(1)
typedef struct _BIOS_PARAM_BLOCK
{
	BYTE jumpCode[3];
	BYTE oemID[8];
	WORD bytesPerSector;
	BYTE sectorPerCluster;
	WORD reservedSectors;
	BYTE always0[3];
	WORD notUsed;
	BYTE mediaDiscr;
	WORD always02;
	WORD sectorperTrack;
	WORD numOfHeaders;
	DWORD hiddenSectors;
	DWORD notUsed2;
	DWORD notused3;
	ULONGLONG totalSectors;
	ULONGLONG lcnForSMFT;
	ULONGLONG lcnForSMFTMirr;
	DWORD clusterPerFileRecordSegm;
	BYTE clusterPerIndexBuff;
	BYTE notUsed4[3];
	ULONGLONG volumeSerialNumber;
	DWORD checksum;
	BYTE bootstrap[426];
	WORD endMarker;
} BPB;
#pragma pack()

extern "C++" FSREADER_API void PrintBootSectInfo(BPB _bpb);
extern "C++" FSREADER_API std::string FindFSName(std::string diskName);
extern "C++" FSREADER_API bool fsIsSupported(std::string SysName);
extern "C++" FSREADER_API bool getFsInfo(std::string diskNameFormated, BPB * _bpb);
