#include <iostream>
#include "MedzmateConfiguration.h"

[event_source(native)]
public class SchedulerProcess
{
	MedzmateConfiguration _configuration;
	bool IsTime(DispenserConfiguration dc);
public:
	SchedulerProcess(MedzmateConfiguration configuration);
	void Run();
	__event void Signal(DispenserConfiguration dc);
};

[event_receiver(native)]
class ActionHandler
{
public:
	void Handler(DispenserConfiguration dc);
	void hookEvent(SchedulerProcess* source);
	void unhookEvent(SchedulerProcess* source);
};

