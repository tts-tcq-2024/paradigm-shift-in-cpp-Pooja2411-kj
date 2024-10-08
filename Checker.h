#include <string>
#include <map>

enum class BatteryParameter {
    TEMPERATURE,
    SOC,
    CHARGE_RATE
};

struct BatteryLimits {
    float min;
    float max;
};

struct BatteryWarningLimits {
    float min;
    float max;
};

class Battery {
public:
    Battery();
    bool isWithinLimits(float value, BatteryLimits limits, BatteryParameter parameter);
    void printErrorMessage(BatteryParameter parameter);
    bool isWithinWarningLimits(float value, BatteryWarningLimits limits, BatteryParameter parameter);
    void printWarningMessage(BatteryParameter parameter);
    bool batteryIsOk(float temperature, float soc, float chargeRate);
    bool checkParameter(float value, BatteryLimits limits, BatteryWarningLimits warningLimits, BatteryParameter parameter); 
    void testBatteryIsOk();
private:
    std::map<BatteryParameter, std::string> parameterErrorMessages;
    std::map<BatteryParameter, std::string> parameterWarningMessages;
