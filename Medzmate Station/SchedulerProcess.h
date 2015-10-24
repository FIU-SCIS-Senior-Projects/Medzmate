#include <iostream>
#include "Serializer.h"

//[event_source(native)]
class SchedulerProcess
{
	MedzmateConfiguration _configuration;
	bool IsTime(DispenserConfiguration dc);
public:
	SchedulerProcess(MedzmateConfiguration configuration);
	void Run();
	void Signal(DispenserConfiguration dc);
};

//[event_receiver(native)]
class ActionHandler
{
public:
	void Handler(DispenserConfiguration dc);
	void LightBlinks(DispenserConfiguration dc);
	void hookEvent(SchedulerProcess* source);
	void unhookEvent(SchedulerProcess* source);
};

