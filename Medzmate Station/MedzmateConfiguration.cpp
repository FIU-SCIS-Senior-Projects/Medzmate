#include "MedzmateConfiguration.h"
#include <string>
#include <stdio.h>
#include <iostream>

MedzmateConfiguration::MedzmateConfiguration(std::string serialNumber, DispenserConfiguration configurations []) {
    // coy the configurations
    int i;
    for (i = 0; i < DISPCONFIGS; i++) {
        DispenserConfigurations[i] = DispenserConfiguration(configurations[i]);
    }
}

MedzmateConfiguration::MedzmateConfiguration() {
}


void MedzmateConfiguration::Print() {

    std::cout << "*******************Medzmate Configuration *********************\n";
    if (Light_Alarm)
        std::cout << "Light Alarm: ON";
    else
        std::cout << "Light Alarm: OFF";
    std::cout << "Sound Type: " << Sound_Type;
    std::cout << "Time Before: " << Time_Before;
    std::cout << "Time After: " << Time_After;
    std::cout << "Primary Contact First Name: " << Primary_Contact_First_Name;
    std::cout << "Primary Contact Last Name: " << Primary_Contact_Last_Name;
    std::cout << "Primary Contact Phone: " << Primary_Contact_Phone;
    std::cout << "Primary Contact Email: " << Primary_Contact_Email;
    std::cout << "Secondary Contact Name: " << Secondary_Contact_Name;
    std::cout << "Secondary Contact Last Name: " << Secondary_Contact_Last_Name;
    std::cout << "Secondary Contact Email: " << Secondary_Contact_Email;
    std::cout << "Care Phone: " << Care_Phone;
}