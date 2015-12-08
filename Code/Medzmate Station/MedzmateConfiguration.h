#include <string>
#include <list>

using namespace std;


#define DISPCONFIGS 8

class DispenserConfiguration;

class MedzmateConfiguration {

public:
    MedzmateConfiguration();
    MedzmateConfiguration(std::string serialNumber);
    bool Light_Alarm;
    std::string Sound_Type;
    int Time_Before;
    int Time_After;
    std::string Primary_Contact_First_Name;
    std::string Primary_Contact_Last_Name;
    std::string Primary_Contact_Phone;
    std::string Primary_Contact_Email;
    std::string Secondary_Contact_Name;
    std::string Secondary_Contact_Last_Name;
    std::string Secondary_Contact_Email;
    std::string Care_Phone;
    void Print();
};

