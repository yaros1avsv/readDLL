//Factory method

#include "pch.h"
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include "FSdLL.h"
#include <string>

void getInfo(string fileName) {
	FileSystemFactory factory = FileSystemFactory();
	FileSystem* FS = factory.create(fileName);
	FS->bootInfo();
};