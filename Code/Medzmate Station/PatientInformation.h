#include <ctime>
#include <stdio.h>
#include <string>

class PatientInformation
{
public:
	PatientInformation();
	std::string FirstName;
	std::string LastName ;
	std::string Phone;
	std::string Email;
	std::string CareProviderFirstName;
	std::string CareProviderLastName;
        std::string CareProviderPhone;
        std::string CareProviderEMail;
        std::string MedicareId;
        std::string MedicaidId;
        std::string Insurance;
	void Print();
};