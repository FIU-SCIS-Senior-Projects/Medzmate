// MedzmateProcess.cpp : main project file.

#include "stdafx.h"
#include "SchedulerProcess.h"
#include <iostream>

using namespace System;

int main()
{	
	ActionHandler eventHandler;
	// Initialize with test values
	DispenserConfiguration dispenserConfigs[8] = { 
		DispenserConfiguration("Medicine 1"), 
		DispenserConfiguration("Medicine 2"),
		DispenserConfiguration("Medicine 3"),
		DispenserConfiguration("Medicine 4"),
		DispenserConfiguration("Medicine 5"),
		DispenserConfiguration("Medicine 6"),
		DispenserConfiguration("Medicine 7"),
		DispenserConfiguration("Medicine 8")
	};
	MedzmateConfiguration config("2342342323", dispenserConfigs);
	// Test Data
	SchedulerProcess schedduler(config);
	eventHandler.hookEvent(&schedduler);
	schedduler.Run();
	eventHandler.unhookEvent(&schedduler);
    return 0;
}
