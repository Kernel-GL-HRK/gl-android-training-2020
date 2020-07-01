#define LOG_TAG "vendor.gl.hardware.led@1.0-service"

#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include "LED.h"

using ::android::hardware::configureRpcThreadpool;
using ::vendor::gl::hardware::led::V1_0::implementation::LED;
using ::vendor::gl::hardware::led::V1_0::ILEDControl;
using ::android::hardware::joinRpcThreadpool;
using ::android::OK;
using ::android::sp;

int main(int, char* [])
{
	sp<ILEDControl> led = new LED();
	configureRpcThreadpool(1, true  /*will join*/);
	if (led->registerAsService() != OK)
	{
		ALOGE("Could not register test 1.0 service");
		return 1;
	}
	joinRpcThreadpool();

	ALOGE("service exited");
	return 1;
}



