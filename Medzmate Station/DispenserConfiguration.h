#include <ctime>
#include <stdio.h>
#include <string>

class DispenserConfiguration
{
public:
	DispenserConfiguration();
	std::string MedicineName;
	std::string DoctorsName ;
	std::string DoctorsLastName;
	int Quantity;
	tm ExpirationDate;
	int MedicineMass;
	int DosageNumber;
	bool Monday;
	bool Tuesday;
	bool Wednesday;
	bool Thursday;
	bool Friday;
	bool Saturday;
	bool Sunday;
	tm DispensingTimes [24];
	std::string Symptoms;
	std::string SideEffects;
	std::string StrawId;
	void Print();
};

