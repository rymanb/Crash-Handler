#include <Windows.h>





// MiniDump Class
class MiniDump
{
public:
	static void Init();

	static LONG WINAPI WriteDump(EXCEPTION_POINTERS* pException);

private:

	
	static void WriteToFile(EXCEPTION_POINTERS* pException);
};
