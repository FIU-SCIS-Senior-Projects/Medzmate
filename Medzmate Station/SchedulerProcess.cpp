#include "SchedulerProcess.h"
#include <time.h>

void Subject::Attach(Observer* o) {
    _observers->push_front(o);
}

void Subject::Detach(Observer* o) {
    _observers->remove(o);
}

void Subject::Notify() {
    for (list<Observer*>::iterator it = _observers->begin(); it != _observers->end(); it++) {

    }
}

SchedulerProcess::SchedulerProcess(MedzmateConfiguration configuration) {
    _configuration = configuration;
}

SchedulerProcess::~SchedulerProcess() {

}

void SchedulerProcess::Signal(DispenserConfiguration dc) {
    // call base method to notify observers
    Notify();
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
/*
void SchedulerProcess::Run() {
    DispenserConfiguration *dispenserConfigs = _configuration.DispenserConfigurations;
    // run the process
    while (true) {
        int i;
        for (i = 0; i < DISPCONFIGS; i++) {
            if (IsTime(dispenserConfigs[i]))
                Signal(dispenserConfigs[i]);
        }
    }
}

void ActionHandler::Handler(DispenserConfiguration dc) {
    char input[256];
    printf("Ready to dispense %s ... \n", dc.MedicineName);
}

void ActionHandler::LightBlinks(DispenserConfiguration dc) {
    char input[256];
    printf("Light Blinks ... \n");
}

void ActionHandler::hookEvent(SchedulerProcess * source) {
    //__hook(&SchedulerProcess::Signal, source, &ActionHandler::Handler);
    //__hook(&SchedulerProcess::Signal, source, &ActionHandler::LightBlinks);
}

void ActionHandler::unhookEvent(SchedulerProcess * source) {
    //__unhook(&SchedulerProcess::Signal, source, &ActionHandler::Handler);
    //__unhook(&SchedulerProcess::Signal, source, &ActionHandler::LightBlinks);
}*/
