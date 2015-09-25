// MedzmateProcess.cpp : main project file.

#include "stdafx.h"
#include "SchedulerProcess.h"
#include <iostream>
#include <ctime>

using namespace System;

int main()
{	
	ActionHandler eventHandler;

	tm _tm;
	_getsystime(&_tm);
	_tm.tm_hour = _tm.tm_hour;
	// display time
	printf("Time: %d:%d \n", _tm.tm_hour, _tm.tm_min);

	DispenserConfiguration med1 = DispenserConfiguration("Medicine 1");
	DispenserConfiguration med2 = DispenserConfiguration("Medicine 2");
	med2.DispensingTimes[0] = _tm;
	med2.DispensingTimes[0].tm_hour += 1;
	DispenserConfiguration med3 = DispenserConfiguration("Medicine 3");
	med3.DispensingTimes[0] = _tm;
	med3.DispensingTimes[0].tm_hour += 1;
	DispenserConfiguration med4 = DispenserConfiguration("Medicine 4");
	med4.DispensingTimes[0] = _tm;
	DispenserConfiguration med5 = DispenserConfiguration("Medicine 5");
	DispenserConfiguration med6 = DispenserConfiguration("Medicine 6");
	med6.DispensingTimes[0] = _tm;
	DispenserConfiguration med7 = DispenserConfiguration("Medicine 7");
	// med7.DispensingTimes[0] = _tm;
	DispenserConfiguration med8 = DispenserConfiguration("Medicine 8");

	// Initialize with test values
	DispenserConfiguration dispenserConfigs[8] = { 
		med1,
		med2,
		med3,
		med4,
		med5,
		med6,
		med7,
		med8,
	};
	MedzmateConfiguration config("2342342323", dispenserConfigs);
	// Test Data
	SchedulerProcess schedduler(config);
	eventHandler.hookEvent(&schedduler);
	schedduler.Run();
	eventHandler.unhookEvent(&schedduler);
    return 0;
}
