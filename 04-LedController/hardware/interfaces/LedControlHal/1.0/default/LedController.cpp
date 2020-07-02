#include <android/log.h>
#include <fstream>
#include <sstream>

#include "LedController.h"

#define LOG_TAG "LedControlHal"

namespace vendor
{
	namespace gl
	{
		namespace hardware
		{
			namespace ledcontrol
			{
				namespace V1_0
				{

					LedController::LedController()
					{
						__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "init Led Controller()");

						writeLedTrigger(LedNum::LED_1, "none");
						writeLedBright(LedNum::LED_1, LedState::LED_OFF);

						writeLedTrigger(LedNum::LED_2, "none");
						writeLedBright(LedNum::LED_2, LedState::LED_OFF);

						writeLedTrigger(LedNum::LED_3, "none");
						writeLedBright(LedNum::LED_3, LedState::LED_OFF);

						writeLedTrigger(LedNum::LED_4, "none");
						writeLedBright(LedNum::LED_4, LedState::LED_OFF);
					}

					Return<int32_t> LedController::setLedState(LedNum led_num, LedState state)
					{
						__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "setLedState()");

						writeLedBright(led, state);

						return 0;
					}

					Return<LedState> LEdController::getLedState(LedNum led_num)
					{
						return LedState::LED_OFF;
					}

					bool LedController::writeLedTrigger(LedNum led_num, const std::string &trigger)
					{
						__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "-> writeLedTrigger()");

						std::fstream fs;
						std::stringstream trig_path;

						path << "/sys/class/leds/user_led" << (int32_t)led_num << "/brightness";
						fs.open(trig_path, std::fstream::out);

						if (!fs.is_open())
						{
							__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Error opening trigger");
							return false;
						}

						fs << trigger;
						fs.close();

						return true;
					}

					bool LedController::writeLedBright(LedNum led_num, LedState state)
					{
						std::fstream fs;
						std::stringstream br_path;

						br_path << "/sys/class/leds/user_led" << (int32_t)led_num << "/brightness";

						fs.open(br_path, std::fstream::out);

						if (!fs.is_open())
						{
							__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Error opening brightness");
							return false;
						}

						fs << state;
						fs.close();

						return true;
					}

				} // namespace V1_0
			}	  // namespace ledcontrol
		}		  // namespace hardware
	}			  // namespace gl
} // namespace vendor