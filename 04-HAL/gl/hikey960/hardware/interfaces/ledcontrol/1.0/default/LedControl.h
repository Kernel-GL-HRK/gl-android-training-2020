#pragma once

#include <vendor/gl/hardware/ledcontrol/1.0/ILedControl.h>
#include <vector>
#include <string>

namespace vendor {
namespace gl {
namespace hardware {
namespace ledcontrol {
namespace V1_0 {
namespace implementation {

using ::android::hardware::Return;

/*Led control class*/
class LedControl : public ILedControl {
public:
    LedControl();
	~LedControl();
    Return<Result> setLedState(int ledPin, int state)  override;
private:
	std::vector<std::string> m_ledBrightnessPath;
	std::vector<std::string> m_ledTriggerPath;
	void setLedTrigger(void) const;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace ledcontrol
}  // namespace hardware
}  // namespace gl
}  // namespace vendor
