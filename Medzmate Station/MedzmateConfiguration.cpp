#include "MedzmateConfiguration.h"
#include "DispenserConfiguration.h"
#include <string>
#include <stdio.h>
#include <iostream>

MedzmateConfiguration::MedzmateConfiguration(std::string serialNumber, DispenserConfiguration configurations []) {
    // coy the configurations
    int i;
    for (i = 0; i < DISPCONFIGS; i++) {
        //DispenserConfigurations[i] = DispenserConfiguration(configurations[i]);
    }
}

MedzmateConfiguration::MedzmateConfiguration() {
}


void MedzmateConfiguration::Print() {

    std::cout << "*******************Medzmate Configuration *********************\n";
    if (Light_Alarm)
        std::cout << "---Light Alarm: ON"<< "\n";
    else
        std::cout << "---Light Alarm: OFF" << "\n";
    std::cout << "---Sound Type: " << Sound_Type << "\n";
    std::cout << "---Time Before: " << Time_Before << "\n";
    std::cout << "---Time After: " << Time_After << "\n";
    std::cout << "---Primary Contact First Name: " << Primary_Contact_First_Name << "\n";
    std::cout << "---Primary Contact Last Name: " << Primary_Contact_Last_Name << "\n";
    std::cout << "---Primary Contact Phone: " << Primary_Contact_Phone << "\n";
    std::cout << "---Primary Contact Email: " << Primary_Contact_Email << "\n";
    std::cout << "---Secondary Contact Name: " << Secondary_Contact_Name << "\n";
    std::cout << "---Secondary Contact Last Name: " << Secondary_Contact_Last_Name << "\n";
    std::cout << "---Secondary Contact Email: " << Secondary_Contact_Email << "\n";
    std::cout << "---Care Phone: " << Care_Phone << "\n";
}