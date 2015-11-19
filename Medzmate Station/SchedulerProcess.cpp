#include "SchedulerProcess.h"
#include "MedzmateConfiguration.h"
#include "DispenserConfiguration.h"
#include "AlertsManager.h"
#include <time.h>

SchedulerProcess::SchedulerProcess(MedzmateConfiguration* configuration, AlertsManager* alertManager)
{

}

void SchedulerProcess::Signal(DispenserConfiguration dc) {


}

bool SchedulerProcess::IsTime(DispenserConfiguration dc) {
    time_t currentTime;
    struct tm *_tm;
    int i;

    time(&currentTime);
    _tm = localtime(&currentTime);
    for (i = 0; i < 24; i++) {
        if (dc.DispensingTimes[i].tm_hour == _tm->tm_hour)
            return true;
    }
    return false;
}

void SchedulerProcess::Run() {
   /* DispenserConfiguration *dispenserConfigs = _configuration.DispenserConfigurations;
    // run the process
    while (true) {
        int i;
        for (i = 0; i < DISPCONFIGS; i++) {
            if (IsTime(dispenserConfigs[i]))
                Signal(dispenserConfigs[i]);
        }
    }*/
}
