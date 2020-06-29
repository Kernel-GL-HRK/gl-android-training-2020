#define LOG_TAG "vendor.gl.hardware.ledctrl@1.0-service"

#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include "LedCtrl.h"

using ::android::hardware::configureRpcThreadpool;
using ::vendor::gl::hardware::ledctrl::V1_0::implementation::LedCtrl;
using ::vendor::gl::hardware::ledctrl::V1_0::ILedCtrl;
using ::android::hardware::joinRpcThreadpool;
using ::android::OK;
using ::android::sp;

int main(int /* argc */, char* /* argv */ []) {
    sp<ILedCtrl> ledctrl = new LedCtrl();
    configureRpcThreadpool(1, true /* will join */);
    if (ledctrl->registerAsService() != OK) {
        ALOGE("Could not register ledctrl 1.0 service.");
        return 1;
    }
    joinRpcThreadpool();

    ALOGE("Service exited!");
    return 1;
}
