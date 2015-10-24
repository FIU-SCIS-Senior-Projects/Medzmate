#include "MedzmateConfiguration.h"
#include <string.h>
#include <stdio.h>

MedzmateConfiguration::MedzmateConfiguration(char* serialNumber, DispenserConfiguration * configurations)
{
	char buffer[32];
	strcpy(SerialNumber, serialNumber);
	// coy the configurations
	int i;
	for (i = 0; i < DISPCONFIGS; i++)
	{
		DispenserConfigurations[i] = DispenserConfiguration(configurations[i]);
	}
}

MedzmateConfiguration::MedzmateConfiguration()
{
}
