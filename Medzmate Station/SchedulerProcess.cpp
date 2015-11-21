#include "SchedulerProcess.h"
#include "MedzmateConfiguration.h"
#include "DispenserConfiguration.h"
#include "AlertsManager.h"
#include <time.h>

SchedulerProcess::SchedulerProcess(MedzmateConfiguration* medzmate_config, list<DispenserConfiguration> dispenser_configs, AlertsManager* alertManager)
{
    _medzmate_config = medzmate_config;
    _dispenser_configs = dispenser_configs;
    _alertManager = alertManager;
}

void SchedulerProcess::Signal(list<DispenserConfiguration>::iterator dc) {

    usleep(2000000);
    if(_medzmate_config->Light_Alarm){
        _alertManager->Light_Alert();
    }
    if(!_medzmate_config->Sound_Type.empty()){
        _alertManager->Sound_Alert(_medzmate_config->Sound_Type);
    }
}

bool SchedulerProcess::IsTime(list<DispenserConfiguration>::iterator dc) {
    time_t currentTime;
    struct tm *_tm;
    int i;

    time(&currentTime);
    _tm = localtime(&currentTime);
    for (i = 0; i < 24; i++) {
        if (dc->DispensingTimes[i].tm_hour == _tm->tm_hour)
            return true;
    }
    return false;
}

void SchedulerProcess::Run() {
   
    // run the process
    while (true) {
        for (list<DispenserConfiguration>::iterator it = _dispenser_configs.begin(); it != _dispenser_configs.end(); it++) {
            if (IsTime(it))
                Signal(it);
        }
    }
}
