#define LOG_TAG "vendor.gl.hikey960.hardware.leds@1.0-service"

#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include <log/log.h>
#include "Leds.h"

using ::android::hardware::configureRpcThreadpool;
using ::android::hardware::joinRpcThreadpool;
using ::android::OK;
using ::android::sp;
using ::vendor::gl::hikey960::hardware::leds::V1_0::implementation::Leds;
using ::vendor::gl::hikey960::hardware::leds::V1_0::ILedControl;

int main(int /*argc*/, char* /*argv*/[]) {
    sp<ILedControl> leds = new Leds();
    configureRpcThreadpool(1, true /* will join */);
    if (leds->registerAsService() != OK) {
        ALOGE("Could not register leds 1.0 service.");
        return 1;
    }
    ALOGI("Leds is registered.");
    joinRpcThreadpool();

    ALOGE("Service exited!");
    return 1;
}
