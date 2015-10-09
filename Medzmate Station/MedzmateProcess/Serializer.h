#include "json_spirit.h"
#include "MedzmateConfiguration.h"
#include <fstream>

#ifndef JSON_SPIRIT_VALUE_ENABLED
#error Please define JSON_SPIRIT_VALUE_ENABLED for the Value type to be enabled 
#endif

using namespace std;
using namespace json_spirit;

class Serializer
{
	void  ResolveDispenserConfiguration(string name, string value, DispenserConfiguration &dispenser_config);
public:
	Serializer();
	DispenserConfiguration DeserializeFromJsonDispenserConfiguration(const char * file_name);
};

