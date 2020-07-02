package com.example.shevchenko.ledcontrol.ledservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

import vendor.gl.hikey960.hardware.leds.V1_0.ILedControl;

public class LedService extends Service {
    private ILedControl ledControl;
    private final static String TAG = "LedService";

    public LedService() {
    }

    private ILedInterface.Stub ledService = new ILedInterface.Stub() {
        @Override
        public boolean updateState(String ledType, boolean turnOn) throws RemoteException {
            Log.i(TAG, "Update state to " + turnOn + " for led = " + ledType);
            boolean isSuccess;
            try {
                isSuccess = ledControl.updateState(ledType, turnOn);
            } catch (Exception e) {
                Log.e(TAG, e.getMessage());
                isSuccess = false;
            }
            return isSuccess;
        }

        @Override
        public boolean getLedState(String ledType) throws RemoteException {
            Log.i(TAG, "Get state for led = " + ledType);
            try {
                return ledControl.getLedState(ledType);
            } catch (Exception e) {
                Log.e(TAG, e.getMessage());
                throw new RemoteException(e.getMessage());
            }
        }
    };

    @Override
    public IBinder onBind(Intent intent) {
        return ledService;
    }

    @Override
    public void onCreate() {
        try {
            ledControl = ILedControl.getService(true);
            ledControl.setCustomLedSettings();
        } catch(Exception e) {
            Log.e(TAG, e.getMessage());
        }
    }

    @Override
    public void onDestroy() {
        try {
            ledControl.setDefaultLedSettings();
        } catch(Exception e) {
            Log.e(TAG, e.getMessage());
        }
    }
}

