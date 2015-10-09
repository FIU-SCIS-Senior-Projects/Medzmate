#include "DispenserConfiguration.h"
#include <string.h>
#include <iostream>

DispenserConfiguration::DispenserConfiguration()
{
}

DispenserConfiguration::DispenserConfiguration(char medicineName[32])
{
	strcpy(MedicineName, medicineName);
}

void DispenserConfiguration::Print()
{
	printf("********************************\n");
	printf("Doctors Name: %s \n", DoctorsName);
	printf("Doctors Last Name: %s \n", DoctorsLastName);
	printf("---Medicine Name: %s \n", MedicineName);
	printf("---Quantity: %d \n", Quantity);
	printf("---Medicine Mass: %d g\n", MedicineMass);
	printf("---Dossage Number: %d \n", DossageNumber);
	if (Monday == true)
		printf("-----Monday\n");
	if (Tuesday == true)
		printf("-----Tuesday\n");
	if (Wednesday == true)
		printf("-----Wednesday\n");
	if (Thursday == true)
		printf("-----Thursday\n");
	if (Friday == true)
		printf("-----Friday\n");
	if (Saturday == true)
		printf("-----Saturday\n");
	if (Sunday == true)
		printf("-----Sunday\n");
	printf("---Symptoms: %s \n", Symptoms);
	printf("---SideEffects: %s \n", SideEffects);
	printf("---Straw: %s \n", StrawId);
	printf("********************************\n");
}
