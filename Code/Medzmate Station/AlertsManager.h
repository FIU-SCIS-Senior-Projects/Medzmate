#include <string>

class AlertsManager {
private:
    
public:

    AlertsManager();
    void Alert();
    void Light_Alert();
    void Sound_Alert(std::string sound_file);
};
