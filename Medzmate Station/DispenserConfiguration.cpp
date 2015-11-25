#include "DispenserConfiguration.h"
#include <string.h>
#include <iostream>

DispenserConfiguration::DispenserConfiguration() {
    DoctorsName.assign("");
    DoctorsLastName.assign("");
    MedicineName.assign("");
    Quantity = 0;
    MedicineMass = 0;
    DosageNumber = 0;
    Monday = false;
    Tuesday = false;
    Wednesday = false;
    Thursday = false;
    Friday = false;
    Saturday = false;
    Sunday = false;
    Symptoms.assign("");
    SideEffects.assign("");
    StrawId.assign("");
}

void DispenserConfiguration::Print() {
    std::cout << "********************************\n";
    std::cout << "---Straw: " << StrawId << "\n";
    std::cout << "---Medicine Name: " << MedicineName << "\n";
    std::cout << "Doctors Name: " << DoctorsName << "\n";
    std::cout << "Doctors Last Name: " << DoctorsLastName << "\n";
    std::cout << "Quantity: " << Quantity << "\n";
    std::cout << "Medicine Mass: " << MedicineMass << "\n";
    std::cout << "Dosage Number: " << DosageNumber << "\n";
    if (Monday == true)
        std::cout << "-----Monday\n";
    if (Tuesday == true)
        std::cout << "-----Tuesday\n";
    if (Wednesday == true)
        std::cout << "-----Wednesday\n";
    if (Thursday == true)
        std::cout << "-----Thursday\n";
    if (Friday == true)
        std::cout << "-----Friday\n";
    if (Saturday == true)
        std::cout << "-----Saturday\n";
    if (Sunday == true)
        std::cout << "-----Sunday\n";
    std::cout << "---Symptoms: " << Symptoms << "\n";
    std::cout << "---SideEffects: " << SideEffects << "\n";

    std::cout << "********************************\n";
}
