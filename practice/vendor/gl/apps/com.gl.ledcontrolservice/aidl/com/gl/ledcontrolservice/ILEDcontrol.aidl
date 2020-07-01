// ILEDcontrol.aidl
package com.gl.ledcontrolservice;

// Declare any non-default types here with import statements

interface ILEDcontrol {
	/**
	 * Demonstrates some basic types that you can use as parameters
	 * and return values in AIDL.
	 */
	//void basicTypes(int anInt, long aLong, boolean aBoolean, float aFloat,double aDouble, String aString);
	String get_leds_list();
	String get_trigger	        (int led_number);
	String get_max_brightness	(int led_number);
	String get_brightness		(int led_number);

	String set_trigger			(int led_number, String value);
	String set_brightness		(int led_number, String value);

}
