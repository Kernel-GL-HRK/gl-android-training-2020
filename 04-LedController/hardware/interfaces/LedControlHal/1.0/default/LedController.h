#ifndef VENDOR_GL_HARDWARE_LED_H
#define VENDOR_GL_HARDWARE_LED_H

#include <vendor/gl/hardware/ledcontrol/1.0/ILedController.h>
#include <vendor/gl/hardware/ledcontrol/1.0/types.h>

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

					using namespace android::hardware;

					class LedController : public ILedController
					{
					public:
						LedController();
						//	Return<LedState> getLedState(Leds led) override;
						Return<int32_t> setLedState(LedNum led, LedState state) override;

					private:
						bool writeLedTrigger(LedNum led, const std::string &trigger);
						bool writeLedBright(LedNum led, LedState state);
					};

				} // namespace V1_0
			}	  // namespace ledcontrol
		}		  // namespace hardware
	}			  // namespace gl
} // namespace vendor

#endif // VENDOR_GL_HARDWARE_LED_H
