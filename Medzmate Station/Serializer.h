#include "MedzmateConfiguration.h"
#include "Parser.h"
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Serializer
{
	void  ResolveDispenserConfiguration(string name, string value, DispenserConfiguration &dispenser_config);
public:
	Serializer();
	DispenserConfiguration DeserializeFromJsonDispenserConfiguration(const char * file_name);
};

