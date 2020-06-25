package com.asp.myservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

public class HolderService extends Service {
    private static String myStorageStr = "";
    private static final String LOG_TAG = "Storage_Service:";

    public HolderService() {
    }

    IMyAInterface.Stub sservice = new IMyAInterface.Stub(){

        @Override
        public void setValue(String value) throws RemoteException {
            myStorageStr = value;
            Log.i(LOG_TAG, "Storage set to: " + myStorageStr);
        }

        @Override
        public String getValue() throws RemoteException {
            Log.i(LOG_TAG, "get_value: " + myStorageStr);
            return myStorageStr;
        }
    };

    @Override
    public IBinder onBind(Intent intent) {
        return sservice;
    };
}
