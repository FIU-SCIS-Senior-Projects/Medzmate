#include "DispenserConfiguration.h"


#define DISPCONFIGS 8

class MedzmateConfiguration
{
	
public:
	MedzmateConfiguration();
	MedzmateConfiguration(char* serialNumber, DispenserConfiguration* configurations);
	char SerialNumber[56];
	DispenserConfiguration DispenserConfigurations[DISPCONFIGS];
};

