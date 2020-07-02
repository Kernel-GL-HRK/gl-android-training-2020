#define LOG_TAG "LedControlHal"

#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include "LedController.h"

#include <log/log.h>

using ::android::hardware::configureRpcThreadpool;
using ::android::hardware::joinRpcThreadpool;
using ::android::OK;
using ::android::sp;

using namespace vendor::gl::hardware::ledcontrol::V1_0;

int main(int /* argc */, char* /* argv */ []) {
    sp<ILedController> ledcontroller = new LedController();
    configureRpcThreadpool(1, true /* will join */);
    if (ledcontroller->registerAsService() != OK) {
        ALOGE("Could not register ledcontroller 1.0 service.");
        return 1;
    } else {
        ALOGI("ILedController registred.");
    }
    joinRpcThreadpool();

    ALOGE("Service exited!");
    return 1;
}
