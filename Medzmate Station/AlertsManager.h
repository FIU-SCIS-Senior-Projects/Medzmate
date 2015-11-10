#include "SchedulerProcess.h"

class AlertsManager : public Observer {
public:

    virtual ~AlertsManager();
    AlertsManager(SchedulerProcess*);
    // overrides Observer peration
    virtual void Update(Subject*);
};