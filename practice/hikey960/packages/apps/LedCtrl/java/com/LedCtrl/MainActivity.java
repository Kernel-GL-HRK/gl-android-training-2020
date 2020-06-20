package com.LedCtrl;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.ledctrlservice.ILedCtrlInterface;

public class MainActivity extends AppCompatActivity {
    final static String TAG = "LedCtrl App";

    private ILedCtrlInterface ledService;
    private ServiceConnection mConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            if (service != null) {
                ledService = ILedCtrlInterface.Stub.asInterface(service);
            }
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            ledService = null;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final Button btn1 = (Button) findViewById(R.id.btn1);
        final Button btn2 = (Button) findViewById(R.id.btn2);
        final Button btn3 = (Button) findViewById(R.id.btn3);
        final Button btn4 = (Button) findViewById(R.id.btn4);

        View.OnClickListener ocl = new View.OnClickListener() {
            int b1 = 1, b2 = 1, b3 = 1, b4 = 1;

            @Override
            public void onClick(View view) {
                switch (view.getId()) {
                    case R.id.btn1:
                        try {
                            if (ledService.setLED(1, b1) != 0) {
                                if (b1 == 0) b1 = 1;
                                else if (b1 == 1) b1 = 0;
                            }
                        } catch (RemoteException | NullPointerException e) {
                            Log.e(TAG, "call failed");
                        }
                        break;
                    case R.id.btn2:
                        try {
                            if (ledService.setLED(2, b2) != 0) {
                                if (b2 == 0) b2 = 1;
                                else if (b2 == 1) b2 = 0;
                            }
                        } catch (RemoteException | NullPointerException e) {
                            Log.e(TAG, "call failed");
                        }
                        break;
                    case R.id.btn3:
                        try {
                            if (ledService.setLED(3, b3) != 0) {
                                if (b3 == 0) b3 = 1;
                                else if (b3 == 1) b3 = 0;
                            }
                        } catch (RemoteException | NullPointerException e) {
                            Log.e(TAG, "call failed");
                        }
                        break;
                    case R.id.btn4:
                        try {
                            if (ledService.setLED(4, b4) != 0) {
                                if (b4 == 0) b4 = 1;
                                else if (b4 == 1) b4 = 0;
                            }
                        } catch (RemoteException | NullPointerException e) {
                            Log.e(TAG, "call failed");
                        }
                        break;
                }
            }
        };

        btn1.setOnClickListener(ocl);
        btn2.setOnClickListener(ocl);
        btn3.setOnClickListener(ocl);
        btn4.setOnClickListener(ocl);

        Intent intent = new Intent();
        intent.setClassName("com.ledctrlservice", "com.ledctrlservice.LedCtrlService");
        try {
            bindService(intent, mConnection, BIND_AUTO_CREATE);
        } catch (SecurityException e) {
            Log.e(TAG, "bind to service failed by security");
        }
    }

    @Override
    protected void onDestroy() {
        unbindService(mConnection);
        super.onDestroy();
    }
}