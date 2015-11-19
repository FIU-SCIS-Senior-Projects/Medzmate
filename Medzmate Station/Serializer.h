#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;
class DispenserConfiguration;

class Serializer
{
	void  ResolveDispenserConfiguration(string name, string value, DispenserConfiguration &dispenser_config);
public:
	Serializer();
	DispenserConfiguration DeserializeFromJsonDispenserConfiguration(string file_name);
};

