package com.gl.ledcontrolservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

import vendor.gl.hardware.led.V1_0.ILEDControl;//HAL


public class LEDcontrolService extends Service {
	static String TAG = "LED_java_service -> ";
	ILEDControl	led;	//HAL

	public LEDcontrolService() {}

	@Override
	public void onCreate()
	{
		super.onCreate();
		try 
		{
			led = ILEDControl.getService(true);	//connecting to HAL
		}catch (Exception e) 
		{
			Log.e(TAG, "error connecting to HAL");
			e.printStackTrace();
		}
	}//onCreate


	ILEDcontrol.Stub    mService = new ILEDcontrol.Stub() {

		@Override
		public String get_leds_list() throws RemoteException {
			String result="error";
			try
			{
				result = led.get_leds_list();
			} catch (Exception e) 
			{
				Log.e(TAG, "error calling HAL get_leds_list");
				e.printStackTrace();
			}
			return result;
		}//get_leds_list

		@Override
		public String get_trigger(int led_number) throws RemoteException {
			String result;//="[emulated_trigger] none bluetooth-power kbd-scrolllock kbd-numlock kbd-capslock kbd-kanalock kbd-shiftlock kbd-altgrlock kbd-ctrllock kbd-altlock kbd-shiftllock kbd-shiftrlock kbd-ctrlllock kbd-ctrlrlock mmc0 heartbeat cpu0 cpu1 cpu2 cpu3 cpu4 cpu5 cpu6 cpu7 hci0-power rfkill0 hci0rx hci0tx mmc1 rfkill1 phy0rx phy0tx phy0assoc phy0radio";
			try
			{
				result = led.get_trigger(led_number);
			} catch (Exception e) 
			{
				Log.e(TAG, "error calling HAL get_trigger ");
				e.printStackTrace();
				result = "error_calling_hal";
			} 
			return result;
		}//get_trigger

		@Override
		public String get_max_brightness(int led_number) throws RemoteException {
			String result;
			try
			{
				result = led.get_max_brightness(led_number);
			} catch (Exception e) 
			{
				Log.e(TAG, "error calling HAL get_max_brightness ");
				e.printStackTrace();
				result = "error_calling_hal";
			} 
			return result;
		}//get_max_brightness

		@Override
		public String get_brightness(int led_number) throws RemoteException {
			String result;
			try
			{
				result = led.get_brightness(led_number);
			} catch (Exception e) 
			{
				Log.e(TAG, "error calling HAL get_brightness ");
				e.printStackTrace();
				result = "error_calling_hal";
			} 
			return result;
		}//get_brightness

		@Override
		public String set_brightness(int led_number, String value) throws RemoteException {
			String result;
			try
			{
				result = led.set_brightness(led_number, value);
			} catch (Exception e) 
			{
				Log.e(TAG, "error calling HAL set_brightness ");
				e.printStackTrace();
				result = "error_calling_hal";
			} 
			return result;
		}//set_brightness

		@Override
		public String set_trigger(int led_number, String value) throws RemoteException {
			String result;
			try
			{
				result = led.set_trigger(led_number, value);
			} catch (Exception e) 
			{
				Log.e(TAG, "error calling HAL set_trigger");
				e.printStackTrace();
				result = "error_calling_hal";
			} 
			return result;
		}//set_trigger

	};//ILEDcontrol.Stub

	@Override
	public IBinder onBind(Intent intent) { return mService; }
}//LEDcontrolService
