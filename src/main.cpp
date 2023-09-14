#include <iostream>
#include "TestScenarios.h"
#include "CrashHandler.h"

// Pass 1-7 to choose the scenario
//   IE: project1.exe 5
int main(int argc, char* argv[]) {
	MiniDump::Init();

	__try {
		int scenario = 1; // Or change this line to pick a scenario

		if (argc > 1) {
			scenario = std::atoi(argv[1]);
		}

		// You can modify this file and wrap this call, but must call RunTest(scenario)
		RunTest(scenario);

		return 0;
	}
	__except (MiniDump::WriteDump(GetExceptionInformation())) {}


}
