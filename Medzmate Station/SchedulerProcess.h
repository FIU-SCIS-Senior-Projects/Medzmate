#include "Serializer.h"

class Subject;
class SchedulerProcess;

class Observer {
public:

    virtual ~Observer();
    virtual void Update(SchedulerProcess process) = 0;

protected:
    Observer();
};

class Subject {
public:

    //virtual ~Subject();
    virtual void Attach(Observer*);
    virtual void Detach(Observer*);
    virtual void Notify();

private:
    list<Observer*> *_observers;
};


class SchedulerProcess: public Subject {

private:    
    MedzmateConfiguration _configuration;
    bool IsTime(DispenserConfiguration dc);
public:
    ~SchedulerProcess();
    SchedulerProcess(MedzmateConfiguration configuration);
    /*void Run();*/
    void Signal(DispenserConfiguration dc);
};

