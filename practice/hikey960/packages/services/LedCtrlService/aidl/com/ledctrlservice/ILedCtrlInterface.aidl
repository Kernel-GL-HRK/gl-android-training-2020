// ILedCtrlInterface.aidl
package com.ledctrlservice;

// Declare any non-default types here with import statements

interface ILedCtrlInterface {
    /**
     * Control LEDs
     */
    int setLED(int led, int state);
}
