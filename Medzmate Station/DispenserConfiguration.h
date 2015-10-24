#include <ctime>
#include <stdio.h>

class DispenserConfiguration
{
public:
	DispenserConfiguration();
	DispenserConfiguration(char MedicineName[32]);
	char MedicineName [32];
	char DoctorsName [32];
	char DoctorsLastName[32];
	int Quantity;
	tm ExpirationDate;
	int MedicineMass;
	int DossageNumber;
	bool Monday;
	bool Tuesday;
	bool Wednesday;
	bool Thursday;
	bool Friday;
	bool Saturday;
	bool Sunday;
	tm DispensingTimes [24];
	char Symptoms[512];
	char SideEffects[512];
	char StrawId [1];
	void Print();
};

