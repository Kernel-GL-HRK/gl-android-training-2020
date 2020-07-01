#pragma once
#include <vendor/gl/hardware/led/1.0/ILEDControl.h>
//#include <system/libhidl/base/include/hidl/HidlSupport.h>

//#include <HidlSupport.h>

#include <string>
#include <string_view>
#include <vector>

namespace vendor{
namespace gl{
namespace hardware{
namespace led{
namespace V1_0{
namespace implementation{
using namespace ::android::hardware;

struct LED : public ILEDControl
{
	LED();

	///returns list of LEDs divided by space. The order of LEDs is important. 
	Return<void>	get_leds_list		(														get_leds_list_cb _hidl_cb)	override;

	///returns content of trigger-file for given LED. 
	Return<void>	get_trigger			(const int32_t led_number,								get_trigger_cb _hidl_cb)	override;

	///returns content of max_brightness-file for given LED. 
	Return<void>	get_max_brightness	(const int32_t led_number,								get_trigger_cb _hidl_cb)	override;

	///returns content of brightness-file for given LED. 
	Return<void>	get_brightness		(const int32_t led_number,								get_trigger_cb _hidl_cb)	override;

	///writes value-string to trigger-file of given LED. Returns content of the file.
	Return<void>	set_trigger			(const int32_t led_number, const hidl_string& value,	get_trigger_cb _hidl_cb)	override;

	///writes value-string to brightness-file of given LED. Returns content of the file.
	Return<void>	set_brightness		(const int32_t led_number, const hidl_string& value,	get_trigger_cb _hidl_cb)	override;

private:
	/// the list of LED-names in the system.
	std::vector<std::string_view>	m_leds; 

	~LED();	//destructor
	bool populate_leds();	///< fills m_leds with values.

	/// reads file name for led# led_num
	std::string const read_file		(size_t led_num, char const* name);	

	/// writes string value to file name for led# led_num
	std::string const write_file	(size_t led_num, char const* name, const std::string value);
};//struct LED

}//namespace implementation
}//namespace V1_0
}//namespace led
}//namespace hardware
}//namespace gl
}//namespace vendor

