#include "stdafx.h"
#include "SchedulerProcess.h"
#include <ctime>


bool SchedulerProcess::IsTime(DispenserConfiguration dc)
{
	tm _tm;
	int i;
	_sleep(1000);
	_getsystime(&_tm);
	for (i = 0; i < 24; i++)
	{
		if (dc.DispensingTimes[i].tm_hour == _tm.tm_hour)
			return true;
	}
	return false;
}

SchedulerProcess::SchedulerProcess(MedzmateConfiguration configuration)
{
	_configuration = configuration;
}

void SchedulerProcess::Run()
{
	DispenserConfiguration *dispenserConfigs = _configuration.DispenserConfigurations;
	// run the process
	while (true) {
		int i;
		for (i = 0; i < DISPCONFIGS; i++)
		{
			if (IsTime(dispenserConfigs[i]))
				Signal(dispenserConfigs[i]);
		}		
	}
}

void ActionHandler::Handler(DispenserConfiguration dc)
{
	char input[256];
	printf("Dipensing %s ... \n", dc.MedicineName);
}

void ActionHandler::hookEvent(SchedulerProcess * source)
{
	__hook(&SchedulerProcess::Signal, source, &ActionHandler::Handler);
}

void ActionHandler::unhookEvent(SchedulerProcess * source)
{
	__unhook(&SchedulerProcess::Signal, source, &ActionHandler::Handler);
}
