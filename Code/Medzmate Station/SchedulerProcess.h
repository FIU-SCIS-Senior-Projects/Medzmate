#include <list>

using namespace std;

class MedzmateConfiguration;
class DispenserConfiguration;
class AlertsManager;

class SchedulerProcess {
private:
    list<DispenserConfiguration> _dispenser_configs;
    MedzmateConfiguration* _medzmate_config;
    AlertsManager* _alertManager;
    bool IsTime(list<DispenserConfiguration>::iterator dc);
public:

    SchedulerProcess(MedzmateConfiguration* medzmate_config, list<DispenserConfiguration> dispenser_configs, AlertsManager* alertManager);
    void Run();
    void Signal(list<DispenserConfiguration>::iterator dc);
};

