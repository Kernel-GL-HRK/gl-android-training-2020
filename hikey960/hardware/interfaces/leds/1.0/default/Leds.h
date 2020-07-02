#ifndef VENDOR_GL_HIKEY960_HARDWARE_LEDS_V1_0_LEDS_H_
#define VENDOR_GL_HIKEY960_HARDWARE_LEDS_V1_0_LEDS_H_

#include <vendor/gl/hikey960/hardware/leds/1.0/ILedControl.h>

namespace vendor {
namespace gl {
namespace hikey960 {
namespace hardware {
namespace leds {
namespace V1_0 {
namespace implementation {

using android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::hidl_string;

static const std::string LEDS_PATH = "/sys/class/leds/";
static const std::string BT_FOLDER = "bt_active";
static const std::string USR_LED1_FOLDER = "user_led1";
static const std::string USR_LED2_FOLDER = "user_led2";
static const std::string USR_LED3_FOLDER = "user_led3";
static const std::string USR_LED4_FOLDER = "user_led4";
static const std::string WIFI_FOLDER = "wifi_active";

static const std::string TRIGGER_FILE_NAME = "/trigger";
static const std::string BRIGHTNESS_FILE_NAME = "/brightness";

static const std::string NONE_TRIGGER_VALUE = "none";
static const std::string LED_TURN_ON_VALUE = "255";
static const std::string LED_TURN_OFF_VALUE = "0";

class Leds: public ILedControl {
public:
    	Leds();
	~Leds();
	std::string usrLed1TriggerInitValue;
	std::string usrLed2TriggerInitValue;
	std::string usrLed3TriggerInitValue;
	std::string usrLed4TriggerInitValue;
	std::string btLedTriggerInitValue;
	std::string wifiLedTriggerInitValue;

	std::string usrLed1BrightnessInitValue;
	std::string usrLed2BrightnessInitValue;
	std::string usrLed3BrightnessInitValue;
	std::string usrLed4BrightnessInitValue;
	std::string btLedBrightnessInitValue;
	std::string wifiLedBrightnessInitValue;

	Return<void> setCustomLedSettings(void) override;
	Return<bool> updateState(const hidl_string& ledType, bool turnOn) override;
	Return<bool> getLedState(const hidl_string& ledType) override;
	Return<void> setDefaultLedSettings(void) override;
private:
	Return<void> saveInitSate(void);
	Return<std::string> defineLedFolder(std::string ledType);
	Return<void> writeToFile(std::string fileName, std::string value);
	Return<std::string> readFromFile(std::string fileName);
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace leds
}  // namespace hardware
}  // namespace hikey960
}  // namespace gl
}  // namespace vendor

#endif //VENDOR_GL_HIKEY960_HARDWARE_LEDS_V1_0_LEDS_H_
