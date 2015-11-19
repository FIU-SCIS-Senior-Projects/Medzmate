#include "MedzmateConfiguration.h"
#include "AlertsManager.h"

class SchedulerProcess {
private:
    MedzmateConfiguration _configuration;
    bool IsTime(DispenserConfiguration dc);
public:

    SchedulerProcess(MedzmateConfiguration* configuration, AlertsManager* alertManager);
    void Run();
    void Signal(DispenserConfiguration dc);
};

