#define LOG_TAG "LedCtrl"

#include <log/log.h>
#include "LedCtrl.h"

namespace vendor {
namespace gl {
namespace hardware {
namespace ledctrl {
namespace V1_0 {
namespace implementation {

LedCtrl::LedCtrl() {
    ALOGD("->LedCtrl::LedCtrl()");
    //off triggers on leds
    for (int i = 1; i < 5; i++) {
    	char ledPath[64] = {};
    	if(snprintf(ledPath, sizeof(ledPath), "/sys/class/leds/user_led%d/trigger", i)>0){           
    		FILE* file = fopen(ledPath, "w");
    		if (file!=0){    			
                fprintf(file, "none\n");
                fclose(file);
            }  
        }  	
    }
}

LedCtrl::~LedCtrl() {
    ALOGD("->LedCtrl::~LedCtrl()");
}

Return<int32_t> LedCtrl::setLED(int32_t led, int32_t state){
    ALOGD("->LedCtrl::setLED(%d, %d)", led, state);
    char ledPath[64] = {};
    if(snprintf(ledPath, sizeof(ledPath), "/sys/class/leds/user_led%u/brightness", led)<=0){
    	return 0;
    }
    FILE* file = fopen(ledPath, "w");
	if (file!=0){
		fprintf(file, "%u\n", state);
		fclose(file);
		return 1;
	} else return 0;
    return 0;
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace ledctrl
}  // namespace hardware
}  // namespace gl
}  // namespace vendor