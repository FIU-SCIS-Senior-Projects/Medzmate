#include "Serializer.h"
#include "MedzmateConfiguration.h"
#include "Parser.h"


void Serializer::ResolveDispenserConfiguration(string name, string value, DispenserConfiguration& dispenser_config)
{
	if (name == "Medicine_Name") {
		strcpy(dispenser_config.MedicineName, value.c_str());
	}
	else if (name == "Doctors_First_Name") {
		strcpy(dispenser_config.DoctorsName, value.c_str());
	}
	else if (name == "Doctors_Last_Name") {
		strcpy(dispenser_config.DoctorsLastName, value.c_str());
	}
	else if (name == "Quantity") {
		dispenser_config.Quantity = atoi(value.c_str());
	}
	else if (name == "Mass") {
		dispenser_config.MedicineMass = atoi(value.c_str());
	}
	else if (name == "nDoses") {
		dispenser_config.DossageNumber = atoi(value.c_str());
	}
	else if (name == "Monday") {
		dispenser_config.Monday = value == "on";
	}
	else if (name == "Tuesday") {
		dispenser_config.Tuesday = value == "on";
	}
	else if (name == "Wednesday") {
		dispenser_config.Wednesday = value == "on";
	}
	else if (name == "Thursday") {
		dispenser_config.Thursday = value == "on";
	}
	else if (name == "Friday") {
		dispenser_config.Friday = value == "on";
	}
	else if (name == "Saturday") {
		dispenser_config.Saturday = value == "on";
	}
	else if (name == "Sunday") {
		dispenser_config.Sunday = value == "on";
	}
	else if (name == "Symptoms") {
		strcpy(dispenser_config.Symptoms, value.c_str());
	}
	else if (name == "Side_Effects") {
		strcpy(dispenser_config.SideEffects, value.c_str());
	}
	else if (name == "Straw_id") {
		strcpy(dispenser_config.StrawId, value.c_str());
	}
}

Serializer::Serializer()
{
}

DispenserConfiguration Serializer::DeserializeFromJsonDispenserConfiguration(string file_name)
{
	// create dispenser configuration
	DispenserConfiguration dispenser_config = DispenserConfiguration();
	Parser parser = Parser(file_name);
        std::cout << "De-serialization of file " << file_name << " started ...\n";
	list<NameValuePair> properties = parser.Start();
	for (list<NameValuePair>::iterator it = properties.begin(); it != properties.end(); it++){
		ResolveDispenserConfiguration(it->name, it->value, dispenser_config);
	}
	return dispenser_config;

}
