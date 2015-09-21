#include "stdafx.h"
#include "DispenserConfiguration.h"
#include <string.h>


DispenserConfiguration::DispenserConfiguration()
{
}

DispenserConfiguration::DispenserConfiguration(char medicineName[32])
{
	strcpy(MedicineName, medicineName);
}
