// MedzmateProcess.cpp : main project file.

#include "SchedulerProcess.h"
#include <iostream>
#include <ctime>

int main(int argc, char **argv) {
    // default test file
    char straw [256];
    if (argc == 2) {
        cout << argv[1] << "\n";
        strcpy(straw, argv[1]);
    } else {
        // for debugging only
        strcpy(straw, "Straw_D.json");
    }

    Serializer serializer = Serializer();

    //const char* ibuprofen("ibuprofen.json");

    time_t currentTime;
    struct tm *_tm;
    time(&currentTime);
    _tm = localtime(&currentTime);

    // display time
    cout << "Hello from MedzmateProcess\n";
    printf("Time: %d:%d \n", _tm->tm_hour, _tm->tm_min);

    DispenserConfiguration med1 = serializer.DeserializeFromJsonDispenserConfiguration(straw);
    med1.DispensingTimes[0] = *_tm;
    med1.Print();
    

    /*DispenserConfiguration med2 = serializer.DeserializeFromJsonDispenserConfiguration(straw);
    med2.DispensingTimes[0] = *_tm;
    med2.Print();*/

    /*DispenserConfiguration med3 = serializer.DeserializeFromJsonDispenserConfiguration(ibuprofen);
    med3.DispensingTimes[0] = *_tm;
    med3.Print();*/
    // Initialize with test values
   /* DispenserConfiguration dispenserConfigs[1] = {
        med1
    };
    MedzmateConfiguration config("2342342323", dispenserConfigs);
    sleep(2000);*/
    // Test Data
    /*SchedulerProcess schedduler(config);
    eventHandler.hookEvent(&schedduler);
    schedduler.Run();
    eventHandler.unhookEvent(&schedduler);*/
    return 0;
}
