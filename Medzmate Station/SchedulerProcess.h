

class MedzmateConfiguration;
class DispenserConfiguration;
class AlertsManager;

class SchedulerProcess {
private:
    
    bool IsTime(DispenserConfiguration dc);
public:

    SchedulerProcess(MedzmateConfiguration* configuration, AlertsManager* alertManager);
    void Run();
    void Signal(DispenserConfiguration dc);
};

