#include "PatientInformation.h"
#include <string>
#include <stdio.h>
#include <iostream>

PatientInformation::PatientInformation() {
    FirstName.assign("");
    LastName.assign("");
    Phone.assign("");
    Email.assign("");
    CareProviderFirstName.assign("");
    CareProviderLastName.assign("");
    CareProviderPhone.assign("");
    CareProviderEMail.assign("");
    MedicareId.assign("");
    MedicaidId.assign("");
    Insurance.assign("");
}

void PatientInformation::Print() {
    std::cout << "********************************\n";
    std::cout << "---Patient: " << LastName << ", " << FirstName << "\n";
    std::cout << "Phone: " << Phone << "\n";
    std::cout << "E-Mail: " << Email << "\n";
    std::cout << "---Care Provider: " << CareProviderFirstName << ", " << CareProviderLastName << "\n";
    std::cout << "Phone: " << CareProviderPhone << "\n";
    std::cout << "E-Mail: " << CareProviderEMail << "\n";
    std::cout << "Medicare Id: " << MedicareId << "\n";
    std::cout << "Medicaid Id: " << MedicaidId << "\n";
    std::cout << "Insurance: " << Insurance << "\n";
}