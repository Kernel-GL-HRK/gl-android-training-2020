package com.example.shevchenko.ledcontrol.ledservice;

/**
 * ILedInterface aidl interface
 */
interface ILedInterface  {

    boolean updateState(String ledType, boolean turnOn);
    boolean getLedState(String ledType);
}
