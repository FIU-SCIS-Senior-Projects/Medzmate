#include "AlertsManager.h"
#include <iostream>


AlertsManager::AlertsManager() {
    
}

void AlertsManager::Light_Alert(){
    std::cout << "Light Blinks...\n";
}

void AlertsManager::Sound_Alert(std::string sound_file){
    std::cout << "Playing Sound... " << sound_file <<  "\n";
}

