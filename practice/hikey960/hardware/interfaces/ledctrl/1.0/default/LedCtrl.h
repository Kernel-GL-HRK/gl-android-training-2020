#ifndef LEDCTRL_H
#define LEDCTRL_H

#include <vendor/gl/hardware/ledctrl/1.0/ILedCtrl.h>

namespace vendor {
namespace gl {
namespace hardware {
namespace ledctrl {
namespace V1_0 {
namespace implementation {

using ::android::hardware::Return;

/**
 * Led control
 */
struct LedCtrl : public ILedCtrl {
    LedCtrl();

    Return<int32_t> setLED(int32_t led, int32_t state) override;    

private:
    ~LedCtrl();
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace ledctrl
}  // namespace hardware
}  // namespace gl
}  // namespace vendor

#endif  // VENDOR_GL_HARDWARE_LEDCTRL_V1_0_LEDCTRL_H