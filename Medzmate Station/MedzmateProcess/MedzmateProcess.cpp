// MedzmateProcess.cpp : main project file.

#include "stdafx.h"
#include "SchedulerProcess.h"
#include <iostream>
#include <ctime>

using namespace System;

int main()
{	
	ActionHandler eventHandler;

	Serializer serializer = Serializer();
	const char* aspirin("aspirin.txt");
	const char* ibuprofen("ibuprofen.txt");

	tm _tm;
	_getsystime(&_tm);
	_tm.tm_hour = _tm.tm_hour;
	// display time
	printf("Time: %d:%d \n", _tm.tm_hour, _tm.tm_min);

	DispenserConfiguration med1 = serializer.DeserializeFromJsonDispenserConfiguration(aspirin);
	med1.Print();
	med1.DispensingTimes[0] = _tm;
	DispenserConfiguration med2 = serializer.DeserializeFromJsonDispenserConfiguration(ibuprofen);
	med2.DispensingTimes[0] = _tm;
	med2.Print();
	// Initialize with test values
	DispenserConfiguration dispenserConfigs[2] = { 
		med1,
		med2
	};
	MedzmateConfiguration config("2342342323", dispenserConfigs);
	// Test Data
	SchedulerProcess schedduler(config);
	eventHandler.hookEvent(&schedduler);
	schedduler.Run();
	eventHandler.unhookEvent(&schedduler);
    return 0;
}
