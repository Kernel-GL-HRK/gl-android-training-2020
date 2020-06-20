#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include "LedControl.h"

using ::android::hardware::configureRpcThreadpool;
using ::vendor::gl::hardware::ledcontrol::V1_0::implementation::LedControl;
using ::vendor::gl::hardware::ledcontrol::V1_0::ILedControl;
using ::android::hardware::joinRpcThreadpool;
using ::android::OK;
using ::android::sp;

int main(int /* argc */, char* /* argv */ []) {
    sp<ILedControl> ledControl = new LedControl();
    configureRpcThreadpool(1, true /* will join */);
    if (ledControl->registerAsService() != OK) {
        ALOGE("Register error!");
        return 1;
    }
    joinRpcThreadpool();

    return 1;
}
