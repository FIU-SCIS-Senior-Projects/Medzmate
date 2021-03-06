#include <fstream>
#include <string.h>
#include "Serializer.h"
#include "MedzmateConfiguration.h"
#include "DispenserConfiguration.h"
#include "PatientInformation.h"
#include "Parser.h"

using namespace std;

Serializer::Serializer() {
}

void Serializer::ResolveDispenserConfiguration(string name, string value, DispenserConfiguration& dispenser_config) {
    if (name == "Medicine_Name") {
        dispenser_config.MedicineName = value;
    } else if (name == "Doctors_First_Name") {
        dispenser_config.DoctorsName = value;
    } else if (name == "Doctors_Last_Name") {
        dispenser_config.DoctorsLastName = value;
    } else if (name == "Quantity") {
        dispenser_config.Quantity = atoi(value.c_str());
    } else if (name == "Mass") {
        dispenser_config.MedicineMass = atoi(value.c_str());
    } else if (name == "nDoses") {
        dispenser_config.DosageNumber = atoi(value.c_str());
    } else if (name == "Monday") {
        dispenser_config.Monday = value == "on";
    } else if (name == "Tuesday") {
        dispenser_config.Tuesday = value == "on";
    } else if (name == "Wednesday") {
        dispenser_config.Wednesday = value == "on";
    } else if (name == "Thursday") {
        dispenser_config.Thursday = value == "on";
    } else if (name == "Friday") {
        dispenser_config.Friday = value == "on";
    } else if (name == "Saturday") {
        dispenser_config.Saturday = value == "on";
    } else if (name == "Sunday") {
        dispenser_config.Sunday = value == "on";
    } else if (name == "Symptoms") {
        dispenser_config.Symptoms = value;
    } else if (name == "Side_Effects") {
        dispenser_config.SideEffects = value;
    } else if (name == "Straw_id") {
        dispenser_config.StrawId = value;
    }
}

void Serializer::ResolveMedzmateConfiguration(string name, string value, MedzmateConfiguration& medzmate_config) {
    if (name == "alarmType_light") {
        medzmate_config.Light_Alarm = value == "on";
    } else if (name == "Sound_Type") {
        medzmate_config.Sound_Type = value;
    } else if (name == "Time_Before") {
        medzmate_config.Time_Before = atoi(value.c_str());
    } else if (name == "Time_after") {
        medzmate_config.Time_After = atoi(value.c_str());
    } else if (name == "Primary_Contact_First_Name") {
        medzmate_config.Primary_Contact_First_Name = value;
    } else if (name == "Primary_Contact_Last_Name") {
        medzmate_config.Primary_Contact_Last_Name = value;
    } else if (name == "Primary_Contact_Phone") {
        medzmate_config.Primary_Contact_Phone = value;
    } else if (name == "Primary_Contact_Email") {
        medzmate_config.Primary_Contact_Email = value;
    } else if (name == "Secondary_contact_Name") {
        medzmate_config.Secondary_Contact_Name = value;
    } else if (name == "CSecondary_contact_Last_Name") {
        medzmate_config.Secondary_Contact_Last_Name = value;
    } else if (name == "Secondary_contact_Email") {
        medzmate_config.Secondary_Contact_Email = value;
    } else if (name == "CarePhone") {
        medzmate_config.Care_Phone = value;
    }
}

void Serializer::ResolvePatientInformation(string name, string value, PatientInformation &patient_info) {
    if (name == "Patients_First_Name") {
        patient_info.FirstName = value;
    } else if (name == "Patients_Last_Name") {
        patient_info.LastName = value;
    } else if (name == "Email") {
        patient_info.Email = value;
    } else if (name == "Phone") {
        patient_info.Phone = value;
    } else if (name == "CarePro_First_Name") {
        patient_info.CareProviderFirstName = value;
    } else if (name == "CarePro_Last_Name") {
        patient_info.CareProviderLastName = value;
    } else if (name == "CarePhone") {
        patient_info.CareProviderPhone = value;
    } else if (name == "CareEmail") {
        patient_info.CareProviderEMail = value;
    } else if (name == "Medicare") {
        patient_info.MedicareId = value;
    } else if (name == "Medicaid") {
        patient_info.MedicaidId = value;
    } else if (name == "Insurance") {
        patient_info.Insurance = value;
    }
}

DispenserConfiguration Serializer::DeserializeFromJsonDispenserConfiguration(string file_name) {
    // create dispenser configuration
    DispenserConfiguration dispenser_config = DispenserConfiguration();
    Parser parser = Parser(file_name);
    //std::cout << "De-serialization of file " << file_name << " started ...\n";
    list<NameValuePair> properties = parser.Start();
    for (list<NameValuePair>::iterator it = properties.begin(); it != properties.end(); it++) {
        ResolveDispenserConfiguration(it->name, it->value, dispenser_config);
    }
    // set up the dispensing 
    if (dispenser_config.DosageNumber != 0) {
        int hour_interval = 24 / dispenser_config.DosageNumber;
        for (int i = 1; i <= dispenser_config.DosageNumber; i++) {
            struct tm _tm;
            // set hour since the beginning of day
            _tm.tm_hour = hour_interval * i;
            dispenser_config.DispensingTimes[i - 1] = _tm;
        }
    }
    return dispenser_config;
}

MedzmateConfiguration Serializer::DeserializeFromJsonMedzmateConfiguration(string file_name) {
    // create medzmate configuration
    MedzmateConfiguration medzmate_config = MedzmateConfiguration();
    Parser parser = Parser(file_name);
    //std::cout << "De-serialization of file " << file_name << " started ...\n";
    list<NameValuePair> properties = parser.Start();
    for (list<NameValuePair>::iterator it = properties.begin(); it != properties.end(); it++) {
        ResolveMedzmateConfiguration(it->name, it->value, medzmate_config);
    }
    return medzmate_config;
}

PatientInformation Serializer::DeserilizeFromJsonPatientInformation(string file_name) {
    PatientInformation patient_info = PatientInformation();
    Parser parser = Parser(file_name);
    list<NameValuePair> properties = parser.Start();
    for (list<NameValuePair>::iterator it = properties.begin(); it != properties.end(); it++) {
        ResolvePatientInformation(it->name, it->value, patient_info);
    }
    return patient_info;
}