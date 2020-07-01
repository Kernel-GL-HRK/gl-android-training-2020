#define LOG_TAG "LEDControl"

#include <stdio.h>
#include <dirent.h>
//std 
#include <iostream>
#include <fstream>
#include <algorithm>

//android
#include <log/log.h>

//local
#include "LED.h"

using namespace vendor;
using namespace gl;
using namespace hardware;
using namespace led;
using namespace V1_0;
using namespace implementation;
using namespace ::android::hardware;

//---------------------------------------------------------------
constexpr char leds_dir[]		= "/sys/class/leds/";
constexpr char brightness[]		= "/brightness";
constexpr char max_brightness[] = "/max_brightness";
constexpr char trigger[]		= "/trigger";

//---------------------------------------------------------------
LED:: LED() { ALOGD("->LED::LED()"); };
LED::~LED() { ALOGD("->LED::~LED()"); };
//---------------------------------------------------------------

bool LED::populate_leds()
{
	if (DIR * dir = opendir(leds_dir)) 
	{
		while (auto const* entry = readdir(dir))
			if(entry->d_type != DT_DIR)
				m_leds.push_back(entry->d_name);
		closedir(dir);
		std::sort(m_leds.begin(), m_leds.end());
		return true;
	}
	ALOGD("->LED error reading directory: %s", strerror(errno));
	return false;
}
//---------------------------------------------------------------

std::string const LED::read_file (size_t led_num, char const* name)
{
	std::string result;
	if(led_num>=0 && led_num < m_leds.size())//bounds check
	{
		std::string fname{ leds_dir };
		fname += m_leds[led_num];
		fname += name;

		std::ifstream myfile(fname);
		if (myfile.is_open())
		{
			if (getline(myfile, result))
				ALOGD("->LED successfully read '%s' from the file '%s'", result.c_str(), fname.c_str());
			myfile.close();
		}
		else
		{
			ALOGD("->LED can't read from the file: %s", fname.c_str());
			result = "error";
		}
	} else
		result = "error_wrong_LED_number";
	return result;
}
//---------------------------------------------------------------  

std::string const LED::write_file (size_t led_num, char const* name, const std::string value)
{
	std::string result;
	if(led_num>=0 && led_num < m_leds.size())//bounds check
	{
		std::string fname{ leds_dir };
		fname += m_leds[led_num];
		fname += name;

		std::ofstream myfile(fname);
		if (myfile.is_open())
		{
			myfile << value;
			myfile.close();
		}
		else
		{
			ALOGD("->LED can't write to the file %s", fname.c_str());
			result = "error_writing_to_the_device";
		}
	} else
		result = "error_wrong_LED_number";
	return result;
}
//---------------------------------------------------------------  

Return<void> LED::get_leds_list(ILEDControl::get_leds_list_cb _hidl_cb)
{
	ALOGD("->LED::get_leds_list");
	std::string result;

	if (m_leds.size() || populate_leds()) 
		for (auto& cur_led : m_leds)
		{
			result += cur_led;
			result += ' ';
		}
	else
		result = "error_enumerating_LEDs";

	_hidl_cb(result);
	return Return<void>();
}
//---------------------------------------------------------------  

Return<void> LED::get_trigger(const int32_t led_number, ILEDControl::get_trigger_cb _hidl_cb)
{
	ALOGD("->LED::get_trigger for LED #%d", led_number);
	_hidl_cb(read_file(led_number, trigger));
	return Return<void>();
}
//--------------------------------------------------------------- 

Return<void> LED::get_max_brightness(const int32_t led_number, get_trigger_cb _hidl_cb) 
{
	ALOGD("->LED::get_max_brightness for LED #%d", led_number);
	_hidl_cb(read_file(led_number, max_brightness));
	return Return<void>();
}
//---------------------------------------------------------------

Return<void> LED::get_brightness(const int32_t led_number, get_trigger_cb _hidl_cb) 
{
	ALOGD("->LED::get_brightness for LED #%d", led_number);
	_hidl_cb(read_file(led_number, brightness));
	return Return<void>();
}
//---------------------------------------------------------------

Return<void> LED::set_trigger (const int32_t led_number, const hidl_string& value, get_trigger_cb _hidl_cb)
{
	ALOGD("->LED::set_trigger for LED #%d", led_number);
	write_file(led_number, trigger, value);
	_hidl_cb(read_file(led_number, trigger));
	return Return<void>();
}
//---------------------------------------------------------------

Return<void> LED::set_brightness(const int32_t led_number, const hidl_string& value, get_trigger_cb _hidl_cb)
{
	ALOGD("->LED::set_brightness for LED #%d", led_number);
	write_file(led_number, brightness, value);
	_hidl_cb(read_file(led_number, brightness));
	return Return<void>();
}
//---------------------------------------------------------------
//---------------------------------------------------------------
