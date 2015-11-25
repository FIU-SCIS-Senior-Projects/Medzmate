// MedzmateProcess.cpp : main project file.

#include "SchedulerProcess.h"
#include "Serializer.h"
#include "DispenserConfiguration.h"
#include "MedzmateConfiguration.h"
#include "AlertsManager.h"
#include <iostream>
#include <ctime>
#include <string>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define STRAWSCOUNT 7

const char *file_name_template = "Documents/Straw_%s.json";
const char *letters [] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M"};

void open_or_create_file(char* filename) {
    int file_fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    // open file
    file_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
    if (file_fd < 0) {
        fprintf(stderr, "Could not open file %s\n", filename);
    }
    close(file_fd);
}

void InitializeStrawConfigurationFiles() {

    char buffer [30];
    for (int i = 0; i < STRAWSCOUNT; i++) {
        sprintf(buffer, file_name_template, letters[i]);
        open_or_create_file(buffer);
    }
}

int main(int argc, char **argv) {

    time_t currentTime;
    struct tm *_tm;
    time(&currentTime);
    _tm = localtime(&currentTime);

    std::cout << "Starting Medzmate Process...\n";
    usleep(2000000);

    //  InitializeStrawConfigurationFiles();

    // initialize serializer
    Serializer serializer = Serializer();

    // read general configuration
    MedzmateConfiguration medz_config = serializer.DeserializeFromJsonMedzmateConfiguration("Documents/medzmate_config.json");
    medz_config.Print();

    list<DispenserConfiguration> disp_configs = list < DispenserConfiguration>();

    char buffer [30];
    std::string filename;
    for (int i = 0; i < STRAWSCOUNT; i++) {
        sprintf(buffer, file_name_template, letters[i]);
        filename.assign(buffer);
        DispenserConfiguration med = serializer.DeserializeFromJsonDispenserConfiguration(filename);
        if (!med.MedicineName.empty()) {
            disp_configs.push_front(med);
            med.Print();
        }
    }

    AlertsManager alert_mngr = AlertsManager();

    SchedulerProcess scheduler = SchedulerProcess(&medz_config, disp_configs, &alert_mngr);
    scheduler.Run();

    return 0;
}
