#include "stdafx.h"
#include "SchedulerProcess.h"


bool SchedulerProcess::IsTime(DispenserConfiguration dc)
{
	_sleep(1000);
	return true;
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
