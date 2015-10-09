#include "stdafx.h"
#include "Serializer.h"


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

DispenserConfiguration Serializer::DeserializeFromJsonDispenserConfiguration(const char * file_name)
{
	// create dispenser configuration
	DispenserConfiguration dispenser_config = DispenserConfiguration();
	// load file
	ifstream is(file_name);
	Value value;
	// read content into JSON parser
	read(is, value);

	const Array& configuration_array = value.get_array();

	for (unsigned int i = 0; i < configuration_array.size(); i++) {
		// based on json format each object represents a property with two records only
		/*
		{

		"name": "Medicine_Name",

		"value": "aspirina"

		}
		*/
		const Object& obj = configuration_array[i].get_obj();
		// first pair
		const Pair& pair1 = obj[0];
		const string& name1 = pair1.name_;
		const string& value1 = pair1.value_.get_str();
		// second pair
		const Pair& pair2 = obj[1];
		const string& name2 = pair2.name_;
		const string& value2 = pair2.value_.get_str();
		// check who is value and who is name of property
		if (name1.compare("name") == 0 && name2.compare("value") == 0) {
			// resolve values
			ResolveDispenserConfiguration(value1, value2, dispenser_config);
		}
		else if (name2.compare("name") && name1.compare("value") == 0) {
			// resolve values
			ResolveDispenserConfiguration(value2, value1, dispenser_config);
		}
	}
	return dispenser_config;
}
