// ILedControlInterface.aidl
package com.example.ledcontrolservice;

// Declare any non-default types here with import statements

interface ILedControlInterface {

    const int LED_1 = 1;
    const int LED_2 = 2;
    const int LED_3 = 3;
    const int LED_4 = 4;
    const int LED_ON = 1;
    const int LED_OFF = 0;

    void setLedValue(int ledNum, int ledState);
}
