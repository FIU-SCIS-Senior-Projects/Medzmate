#include <ctime>

class DispenserConfiguration
{
public:
	DispenserConfiguration();
	DispenserConfiguration(char MedicineName[32]);
	char MedicineName [32];
	char DoctorsName [32];
	char DoctorsLastName[32];
	int Quantity;
	time_t ExpirationDate;
	double MedicineMass;
	int DossageFrequency;
	bool FrequencyInHours; // Hours or Minutes
	time_t StartTime [24];
	int Containers [8];
	char Symptoms[512];
	char SideEffects[512];
};

