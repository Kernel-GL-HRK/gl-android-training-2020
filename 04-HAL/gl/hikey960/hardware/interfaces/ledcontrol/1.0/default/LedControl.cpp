#include <vendor/gl/hardware/ledcontrol/1.0/types.h>
#include <log/log.h>
#include <fstream>
#include <algorithm>

#include "LedControl.h"

namespace vendor {
namespace gl {
namespace hardware {
namespace ledcontrol {
namespace V1_0 {
namespace implementation {

LedControl::LedControl() {
    ALOGD("%s()", __FUNCTION__);

    m_ledBrightnessPath.push_back("/sys/class/leds/user_led1/brightness");
	m_ledBrightnessPath.push_back("/sys/class/leds/user_led2/brightness");
	m_ledBrightnessPath.push_back("/sys/class/leds/user_led3/brightness");
	m_ledBrightnessPath.push_back("/sys/class/leds/user_led4/brightness");

	m_ledTriggerPath.push_back("/sys/class/leds/user_led1/trigger");
	m_ledTriggerPath.push_back("/sys/class/leds/user_led2/trigger");
	m_ledTriggerPath.push_back("/sys/class/leds/user_led3/trigger");
	m_ledTriggerPath.push_back("/sys/class/leds/user_led4/trigger");

	this->setLedTrigger();

}

LedControl::~LedControl() {
    ALOGD("%s()", __FUNCTION__);
    m_ledBrightnessPath.clear();
    m_ledTriggerPath.clear();
}

void LedControl::setLedTrigger(void) const
{
	auto l = [](std::string path)->void
			{
				std::fstream file;
   				file.open(path, std::fstream::out);
				if (!file.is_open())
				{
					ALOGD("The led pin doesnt exist!");
				}

   				file << "none";
   				file.close();
			};
	std::for_each(m_ledTriggerPath.begin(),m_ledTriggerPath.end(),l);
}


Return<Result> LedControl::setLedState(int ledPin, int state) {

    ALOGD("setLedState ledPin = %d state = %d ", ledPin, state);

	std::fstream file;

   	file.open(m_ledBrightnessPath.at(ledPin), std::fstream::out);

	if (!file.is_open()) {
		ALOGD("The led pin doesnt exist!");
		return Result::ERROR;
	}

	if(state) state = 1;

   	file << state;
   	file.close();

    return Result::OK;
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace ledcontrol
}  // namespace hardware
}  // namespace gl
}  // namespace vendor
