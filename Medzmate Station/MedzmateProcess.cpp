// MedzmateProcess.cpp : main project file.

#include "SchedulerProcess.h"
#include "Serializer.h"
#include "DispenserConfiguration.h"
#include "MedzmateConfiguration.h"
#include <iostream>
#include <ctime>
#include <string>

int main(int argc, char **argv) {
    
    // default test file
    std::string straw;
    if (argc == 2) {
        straw.assign(argv[1]);
    } else {
        // for debugging only
        straw.assign("Straw_D.json");
    }

    Serializer serializer = Serializer();

    time_t currentTime;
    struct tm *_tm;
    time(&currentTime);
    _tm = localtime(&currentTime);

    // display time
    std::cout << "Hello from MedzmateProcess\n";
    
    MedzmateConfiguration medz_config = serializer.DeserializeFromJsonMedzmateConfiguration("medzmate_config.json");
    medz_config.Print();

    DispenserConfiguration med1 = serializer.DeserializeFromJsonDispenserConfiguration(straw);
    med1.DispensingTimes[0] = *_tm;
    med1.Print();

    return 0;
}
