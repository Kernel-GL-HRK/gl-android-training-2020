#define LOG_TAG "vendor.gl.hikey960.hardware.leds@1.0::Leds"

#include <log/log.h>
#include "Leds.h"
#include <iostream>
#include <fstream>
#include <string>


namespace vendor {
namespace gl {
namespace hikey960 {
namespace hardware {
namespace leds {
namespace V1_0 {
namespace implementation {

	Leds::Leds() {
		ALOGI("Leds::Leds()");
	}

	Leds::~Leds() {
		ALOGI("Leds::~Leds()");
	}

	Return<void> Leds::setCustomLedSettings() {
		ALOGI("Leds::setCustomLedSettings");

		saveInitSate();

		writeToFile(LEDS_PATH + USR_LED1_FOLDER + TRIGGER_FILE_NAME, NONE_TRIGGER_VALUE);
		writeToFile(LEDS_PATH + USR_LED2_FOLDER + TRIGGER_FILE_NAME, NONE_TRIGGER_VALUE);
		writeToFile(LEDS_PATH + USR_LED3_FOLDER + TRIGGER_FILE_NAME, NONE_TRIGGER_VALUE);
		writeToFile(LEDS_PATH + USR_LED4_FOLDER + TRIGGER_FILE_NAME, NONE_TRIGGER_VALUE);
		writeToFile(LEDS_PATH + BT_FOLDER + TRIGGER_FILE_NAME, NONE_TRIGGER_VALUE);
		writeToFile(LEDS_PATH + WIFI_FOLDER + TRIGGER_FILE_NAME, NONE_TRIGGER_VALUE);

		writeToFile(LEDS_PATH + USR_LED1_FOLDER + BRIGHTNESS_FILE_NAME, LED_TURN_OFF_VALUE);
		writeToFile(LEDS_PATH + USR_LED2_FOLDER + BRIGHTNESS_FILE_NAME, LED_TURN_OFF_VALUE);
		writeToFile(LEDS_PATH + USR_LED3_FOLDER + BRIGHTNESS_FILE_NAME, LED_TURN_OFF_VALUE);
		writeToFile(LEDS_PATH + USR_LED4_FOLDER + BRIGHTNESS_FILE_NAME, LED_TURN_OFF_VALUE);
		writeToFile(LEDS_PATH + BT_FOLDER + BRIGHTNESS_FILE_NAME, LED_TURN_OFF_VALUE);
		writeToFile(LEDS_PATH + WIFI_FOLDER + BRIGHTNESS_FILE_NAME, LED_TURN_OFF_VALUE);

		ALOGI("Leds::setCustomLedSettings. Check that init values are written.");


		std::string usrLed1TriggerInitValueTmp = readFromFile(LEDS_PATH + USR_LED1_FOLDER + TRIGGER_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Trigger value from usrLed1 file= %s", usrLed1TriggerInitValue.c_str(), usrLed1TriggerInitValueTmp.c_str());
		std::string usrLed2TriggerInitValueTmp = readFromFile(LEDS_PATH + USR_LED2_FOLDER + TRIGGER_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Trigger value from usrLed2 file= %s", usrLed2TriggerInitValue.c_str(), usrLed2TriggerInitValueTmp.c_str());
		std::string usrLed3TriggerInitValueTmp = readFromFile(LEDS_PATH + USR_LED3_FOLDER + TRIGGER_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Trigger value from usrLed3 file= %s", usrLed3TriggerInitValue.c_str(), usrLed3TriggerInitValueTmp.c_str());
		std::string usrLed4TriggerInitValueTmp = readFromFile(LEDS_PATH + USR_LED4_FOLDER + TRIGGER_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Trigger value from usrLed4 file= %s", usrLed4TriggerInitValue.c_str(), usrLed4TriggerInitValueTmp.c_str());
		std::string btLedTriggerInitValueTmp = readFromFile(LEDS_PATH + BT_FOLDER + TRIGGER_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Trigger value from btLed file= %s", btLedTriggerInitValue.c_str(), btLedTriggerInitValueTmp.c_str());
		std::string wifiLedTriggerInitValueTmp = readFromFile(LEDS_PATH + WIFI_FOLDER + TRIGGER_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Trigger value from wifiLed file= %s", wifiLedTriggerInitValue.c_str(), wifiLedTriggerInitValueTmp.c_str());

		std::string usrLed1BrightnessInitValueTmp = readFromFile(LEDS_PATH + USR_LED1_FOLDER + BRIGHTNESS_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Brightness value from usrLed1 file= %s", usrLed1BrightnessInitValue.c_str(), usrLed1BrightnessInitValueTmp.c_str());
		std::string usrLed2BrightnessInitValueTmp = readFromFile(LEDS_PATH + USR_LED2_FOLDER + BRIGHTNESS_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Brightness value from usrLed2 file= %s", usrLed2BrightnessInitValue.c_str(), usrLed2BrightnessInitValueTmp.c_str());
		std::string usrLed3BrightnessInitValueTmp = readFromFile(LEDS_PATH + USR_LED3_FOLDER + BRIGHTNESS_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Brightness value from usrLed3 file= %s", usrLed3BrightnessInitValue.c_str(), usrLed3BrightnessInitValueTmp.c_str());
		std::string usrLed4BrightnessInitValueTmp = readFromFile(LEDS_PATH + USR_LED4_FOLDER + BRIGHTNESS_FILE_NAME); 
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Brightness value from usrLed4 file= %s", usrLed4BrightnessInitValue.c_str(), usrLed4BrightnessInitValueTmp.c_str());
		std::string btLedBrightnessInitValueTmp = readFromFile(LEDS_PATH + BT_FOLDER + BRIGHTNESS_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Brightness value from btLed file= %s", btLedBrightnessInitValue.c_str(), btLedBrightnessInitValueTmp.c_str());
		std::string wifiLedBrightnessInitValueTmp = readFromFile(LEDS_PATH + WIFI_FOLDER + BRIGHTNESS_FILE_NAME);
		ALOGI("Leds::setCustomLedSettings. Value from variable= %s. Brightness value from wifiLed file= %s", wifiLedBrightnessInitValue.c_str(), wifiLedBrightnessInitValueTmp.c_str());

		return Void();
	}

	Return<bool> Leds::updateState(const hidl_string& ledType, bool turnOn) {
		std::string ledTypeValue = ledType;
		std::string brightnessValue;
		std::string ledFolder;

		ALOGI("Leds::updateState(%s, %d)", ledTypeValue.c_str(), turnOn);

		
		if (turnOn) {
			brightnessValue = LED_TURN_ON_VALUE;
		} else {
			brightnessValue = LED_TURN_OFF_VALUE;
		}

		ledFolder = defineLedFolder(ledTypeValue);

		if (!ledFolder.empty()) {
			writeToFile(LEDS_PATH + ledFolder + BRIGHTNESS_FILE_NAME, brightnessValue);
			return true;
		} else {
			ALOGI("Unable to define led folder");
			return false;
		}

		return false;
	}

	Return<bool> Leds::getLedState(const hidl_string& ledType) {
		std::string ledTypeValue = ledType;
		std::string brightnessValue;
		std::string ledFolder;

		ALOGI("Leds::getLedState(%s)", ledTypeValue.c_str());

		ledFolder = defineLedFolder(ledTypeValue);
		if (!ledFolder.empty()) {
			brightnessValue = readFromFile(LEDS_PATH + ledFolder + BRIGHTNESS_FILE_NAME);
			ALOGI("Brightness value = %s for ledType = %s", brightnessValue.c_str(), ledTypeValue.c_str());
			if (brightnessValue == LED_TURN_ON_VALUE) {
				return true;
			} else {
				return false;
			}

		} else {
			ALOGI("Unable to define led folder");
			return false;
		}
	}

	Return<void> Leds::setDefaultLedSettings() {
		ALOGI("Leds::setDefaultLedSettings");

		writeToFile(LEDS_PATH + USR_LED1_FOLDER + TRIGGER_FILE_NAME, usrLed1TriggerInitValue);
		writeToFile(LEDS_PATH + USR_LED2_FOLDER + TRIGGER_FILE_NAME, usrLed2TriggerInitValue);
		writeToFile(LEDS_PATH + USR_LED3_FOLDER + TRIGGER_FILE_NAME, usrLed3TriggerInitValue);
		writeToFile(LEDS_PATH + USR_LED4_FOLDER + TRIGGER_FILE_NAME, usrLed4TriggerInitValue);
		writeToFile(LEDS_PATH + BT_FOLDER + TRIGGER_FILE_NAME, btLedTriggerInitValue);
		writeToFile(LEDS_PATH + WIFI_FOLDER + TRIGGER_FILE_NAME, wifiLedTriggerInitValue);

		writeToFile(LEDS_PATH + USR_LED1_FOLDER + BRIGHTNESS_FILE_NAME, usrLed1BrightnessInitValue);
		writeToFile(LEDS_PATH + USR_LED2_FOLDER + BRIGHTNESS_FILE_NAME, usrLed2BrightnessInitValue);
		writeToFile(LEDS_PATH + USR_LED3_FOLDER + BRIGHTNESS_FILE_NAME, usrLed3BrightnessInitValue);
		writeToFile(LEDS_PATH + USR_LED4_FOLDER + BRIGHTNESS_FILE_NAME, usrLed4BrightnessInitValue);
		writeToFile(LEDS_PATH + BT_FOLDER + BRIGHTNESS_FILE_NAME, btLedBrightnessInitValue);
		writeToFile(LEDS_PATH + WIFI_FOLDER + BRIGHTNESS_FILE_NAME, wifiLedBrightnessInitValue);

		return Void();
	}

	Return<void> Leds::saveInitSate() {
		ALOGI("Leds::saveInitSate");

		usrLed1TriggerInitValue = readFromFile(LEDS_PATH + USR_LED1_FOLDER + TRIGGER_FILE_NAME);
		usrLed2TriggerInitValue = readFromFile(LEDS_PATH + USR_LED2_FOLDER + TRIGGER_FILE_NAME);
		usrLed3TriggerInitValue = readFromFile(LEDS_PATH + USR_LED3_FOLDER + TRIGGER_FILE_NAME);
		usrLed4TriggerInitValue = readFromFile(LEDS_PATH + USR_LED4_FOLDER + TRIGGER_FILE_NAME); 
		btLedTriggerInitValue = readFromFile(LEDS_PATH + BT_FOLDER + TRIGGER_FILE_NAME);
		wifiLedTriggerInitValue = readFromFile(LEDS_PATH + WIFI_FOLDER + TRIGGER_FILE_NAME);

		usrLed1BrightnessInitValue = readFromFile(LEDS_PATH + USR_LED1_FOLDER + BRIGHTNESS_FILE_NAME);
		usrLed2BrightnessInitValue = readFromFile(LEDS_PATH + USR_LED2_FOLDER + BRIGHTNESS_FILE_NAME);
		usrLed3BrightnessInitValue = readFromFile(LEDS_PATH + USR_LED3_FOLDER + BRIGHTNESS_FILE_NAME);
		usrLed4BrightnessInitValue = readFromFile(LEDS_PATH + USR_LED4_FOLDER + BRIGHTNESS_FILE_NAME); 
		btLedBrightnessInitValue = readFromFile(LEDS_PATH + BT_FOLDER + BRIGHTNESS_FILE_NAME);
		wifiLedBrightnessInitValue = readFromFile(LEDS_PATH + WIFI_FOLDER + BRIGHTNESS_FILE_NAME);

		return Void();
	}

	Return<std::string> Leds::defineLedFolder(std::string ledType) {
		std::string ledFolder;

		if (ledType == USR_LED1_FOLDER) {
			ledFolder = USR_LED1_FOLDER;
		} else if (ledType == USR_LED2_FOLDER) {
			ledFolder = USR_LED2_FOLDER;
		} else if (ledType == USR_LED3_FOLDER) {
			ledFolder = USR_LED3_FOLDER;
		} else if (ledType == USR_LED4_FOLDER) {
			ledFolder = USR_LED4_FOLDER;
		} else if (ledType == BT_FOLDER) {
			ledFolder = BT_FOLDER;
		} else if (ledType == WIFI_FOLDER) {
			ledFolder = WIFI_FOLDER;
		}

		return ledFolder;
	}

	Return<void> Leds::writeToFile(std::string fileName, std::string value) {
		ALOGI("Leds::writeToFile(%s, %s)", fileName.c_str(), value.c_str());

		std::fstream fs;
		fs.open(fileName, std::fstream::out);
		if (!fs.is_open()) {
			ALOGI("Unable to open file (%s)", fileName.c_str());
		} else {
			fs << value;
			fs.close();
		}
		return Void();
	}

	Return<std::string> Leds::readFromFile(std::string fileName) {
		ALOGI("Leds::readFromFile (%s)", fileName.c_str());

		std::string line;

		std::ifstream file (fileName);
		if (file.is_open()) {
			std::getline(file, line);
			ALOGI("Read from file=%s, value=%s ", fileName.c_str(), line.c_str());
			file.close();
		} else {
			ALOGI("Unable to open file (%s)", fileName.c_str());
		}

		return line;
	}

}  // namespace implementation 
}  // namespace V1_0
}  // namespace leds
}  // namespace hardware
}  // namespace hikey960
}  // namespace gl
}  // namespace vendor
