#include "CrashHandler.h"
#include <DbgHelp.h>
#include <cstdio>

#pragma comment ( lib, "dbghelp.lib" )

void MiniDump::Init()
{
	// 30000k size
	unsigned long size = 22000;
	SetThreadStackGuarantee(&size);
}

LONG WINAPI MiniDump::WriteDump(EXCEPTION_POINTERS* pException)
{
	// Write the dump
	MiniDump::WriteToFile(pException);

	// Return EXCEPTION_CONTINUE_SEARCH so the exception is passed to the next handler
	return EXCEPTION_CONTINUE_SEARCH;
}

void MiniDump::WriteToFile(EXCEPTION_POINTERS* pException)
{

	// Create the file
	MINIDUMP_EXCEPTION_INFORMATION mdei;
	mdei.ThreadId = GetCurrentThreadId();
	mdei.ExceptionPointers = pException; // comes from exception
	mdei.ClientPointers = FALSE; // used when writing for a different process
	
	// create the file
	HANDLE hFile = CreateFileA("crash_dump.dmp", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	// set the minidump type
	MINIDUMP_TYPE type = MINIDUMP_TYPE(MiniDumpNormal | MiniDumpWithDataSegs | MiniDumpWithCodeSegs |
		MiniDumpWithIndirectlyReferencedMemory | MiniDumpWithUnloadedModules | MiniDumpWithFullMemory);
	
	// write the dump
	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, type, &mdei, NULL, NULL);
}



