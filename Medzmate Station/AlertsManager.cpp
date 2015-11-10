#include "AlertsManager.h"


AlertsManager::AlertsManager(SchedulerProcess* process){
    process->Attach(this);
}