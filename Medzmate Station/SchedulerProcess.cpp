#include "SchedulerProcess.h"
#include "MedzmateConfiguration.h"
#include "DispenserConfiguration.h"
#include "AlertsManager.h"
#include <time.h>
#include <unistd.h>
#include <iostream>

SchedulerProcess::SchedulerProcess(MedzmateConfiguration* medzmate_config, list<DispenserConfiguration> dispenser_configs, AlertsManager* alertManager) {
    _medzmate_config = medzmate_config;
    _dispenser_configs = dispenser_configs;
    _alertManager = alertManager;
}

void SchedulerProcess::Signal(list<DispenserConfiguration>::iterator dc) {

    usleep(2000000);
    if (_medzmate_config->Light_Alarm) {
        _alertManager->Light_Alert();
    }
    if (!_medzmate_config->Sound_Type.empty()) {
        _alertManager->Sound_Alert(_medzmate_config->Sound_Type);
    }
}

bool IsWeekDay(struct tm *_tm, list<DispenserConfiguration>::iterator dc) {

    if (_tm->tm_wday == 0) {
        return dc->Sunday;
    } else if (_tm->tm_wday == 1) {
        return dc->Monday;
    } else if (_tm->tm_wday == 2) {
        return dc->Tuesday;
    } else if (_tm->tm_wday == 3) {
        return dc->Wednesday;
    } else if (_tm->tm_wday == 4) {
        return dc->Thursday;
    } else if (_tm->tm_wday == 5) {
        return dc->Friday;
    } else if (_tm->tm_wday == 6) {
        return dc->Saturday;
    }
    return false;
}

bool SchedulerProcess::IsTime(list<DispenserConfiguration>::iterator dc) {
    time_t currentTime;
    struct tm *_tm;
    int i;

    time(&currentTime);
    _tm = localtime(&currentTime);
    //std::cout << "local time: " << _tm->tm_hour << ":00\n";
    //std::cout << "Dispensing Time " << dc->DispensingTimes[2].tm_hour << ":00\n";
    //std::cout << "Day " << IsWeekDay(_tm, dc) << "\n";
    for (i = 0; i < 24; i++) {
        if (dc->DispensingTimes[i].tm_hour == _tm->tm_hour && IsWeekDay(_tm, dc))
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
