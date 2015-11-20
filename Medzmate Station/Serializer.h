#include <fstream>
#include <string>
#include <stdlib.h>

class DispenserConfiguration;
class MedzmateConfiguration;

using namespace std;


class Serializer {
    void ResolveDispenserConfiguration(string name, string value, DispenserConfiguration &dispenser_config);
    void ResolveMedzmateConfiguration(string name, string value, MedzmateConfiguration &medzmate_config);
public:
    Serializer();
    DispenserConfiguration DeserializeFromJsonDispenserConfiguration(string file_name);
    MedzmateConfiguration DeserializeFromJsonMedzmateConfiguration(string file_name);
};

