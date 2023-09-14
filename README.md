Crash Handler and Debugging
-----------------------------------


### Integration  
- To integrate the crash handeler into a new project simply add CrashHandler.cpp and CrashHandler.h to the project and include the header in the main.cpp file. Then call the MiniDump::Init() function in the main function before any other code is executed. This will initialize the crash handler and allow it to catch any crashes that occur in the program. Then wrap your existing code in a __try and __except block. For the __except block call the MiniDump::WriteDump() function. This will handle the crash and write the dump file to the current directory. for example:  
```cpp
int main()
{
  MiniDump::Init();
  __try
  {
    // Existing code
  }
  __except (MiniDump::WriteDump(GetExceptionInformation()))
  {
    // Handle crash
  }
}
```

### Requirements  
- Include CrashHandler.cpp and CrashHandler.h in the project

### Output  
- In the event of a crash, it will write a dump file(.dmp) containing a snapshot of the crash that can be ran and debugged using Visual Studio. The name of the file will be crash_dump.dmp. The dump file will be in the same directory as the executable that crashed.
