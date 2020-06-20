package kh.gl.ledcontrolservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;

import vendor.gl.hardware.ledcontrol.V1_0.ILedControl;

public class LedControlService extends Service {

    private static final String LOG_TAG = "LED_SERVICE:";
    private ILedControl ledControl = null;

    public LedControlService() {
    }

    ILedInterface.Stub mService = new ILedInterface.Stub() {
        @Override
        public void ledControl(int led, int state) throws RemoteException {
            Log.d(LOG_TAG, String.format("-----> setLedState(%d, %d)", led, state));

        try {
            if (ledControl == null) {
                ledControl = ILedControl.getService(true);
            }
            ledControl.setLedState(led, state);
        } catch (Exception e) {
            Log.e(LOG_TAG, "call service failed");
        }


        }
    };

    @Override
    public IBinder onBind(Intent intent) {
        return mService;
    }
}
