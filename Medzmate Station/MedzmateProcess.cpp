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
    std::string straw_a;
    std::string straw_b;
    std::string straw_c;
    if (argc == 2) {
        straw_a.assign(argv[1]);
    } else if (argc == 3) {
        straw_b.assign(argv[2]);

    } else if (argc == 4) {
        straw_b.assign(argv[3]);
    } else {
        // for debugging only
        straw_a.assign("Straw_A.json");
        straw_b.assign("Straw_B.json");
        straw_c.assign("Straw_C.json");
    }

    // initialize serializer
    Serializer serializer = Serializer();

    time_t currentTime;
    struct tm *_tm;
    time(&currentTime);
    _tm = localtime(&currentTime);

    std::cout << "Starting Medzmate Process...\n";

    // read general configuration
    MedzmateConfiguration medz_config = serializer.DeserializeFromJsonMedzmateConfiguration("medzmate_config.json");
    medz_config.Print();

    DispenserConfiguration med1 = serializer.DeserializeFromJsonDispenserConfiguration(straw_a);
    med1.DispensingTimes[0] = *_tm;
    med1.Print();

    DispenserConfiguration med2 = serializer.DeserializeFromJsonDispenserConfiguration(straw_b);
    med2.DispensingTimes[0] = *_tm;
    med2.Print();
    
    DispenserConfiguration med3 = serializer.DeserializeFromJsonDispenserConfiguration(straw_c);
    med3.DispensingTimes[0] = *_tm;
    med3.Print();

    return 0;
}
