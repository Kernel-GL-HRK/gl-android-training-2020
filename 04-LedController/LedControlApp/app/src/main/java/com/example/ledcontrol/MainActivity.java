
package com.example.ledcontrol;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.CompoundButton;
import android.widget.Switch;

import com.example.ledcontrolservice.ILedControlInterface;

public class MainActivity extends AppCompatActivity {
    private static final String LOG_TAG = "LedControlApp";
    private static final String SERVICE_PKG = "com.example.ledcontrolservice";
    private static final String SERVICE = "com.example.ledcontrolservice.LedControlService";
    private ILedControlInterface mService = null;
 
    private ServiceConnection mConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            Log.i(LOG_TAG, "onServiceConnected()");
            mService = ILedControlInterface.Stub.asInterface(service);
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {
            Log.i(LOG_TAG, "onServiceDisconnected()");
            mService = null;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.i(LOG_TAG, "onCreate()");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Switch ledControl_1 = (Switch) findViewById(R.id.led_1);
        ledControl_1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                Log.i(LOG_TAG, "Led_1 CheckedChanged()");
                try {
                    if (b) {
                        mService.setLedValue(ILedControlInterface.LED_1, ILedControlInterface.LED_ON);
                    } else {
                        mService.setLedValue(ILedControlInterface.LED_1, ILedControlInterface.LED_OFF);
                    }
                } catch (Exception e) {
                    Log.e(LOG_TAG, "Error service connection");
                }
            }
        });

        Switch ledControl_2 = (Switch) findViewById(R.id.led_2);
        ledControl_2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                Log.i(LOG_TAG, "Led_2 CheckedChanged()");
                try {
                    if (b) {
                        mService.setLedValue(ILedControlInterface.LED_2, ILedControlInterface.LED_ON);
                    } else {
                        mService.setLedValue(ILedControlInterface.LED_2, ILedControlInterface.LED_OFF);
                    }
                } catch (Exception e) {
                    Log.e(LOG_TAG, "Error service connection");
                }
            }
        });

        Switch ledControl_3 = (Switch) findViewById(R.id.led_3);
        ledControl_3.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                Log.i(LOG_TAG, "Led_3 onCheckedChanged()");
                try {
                    if (b) {
                        mService.setLedValue(ILedControlInterface.LED_3, ILedControlInterface.LED_ON);
                    } else {
                        mService.setLedValue(ILedControlInterface.LED_3, ILedControlInterface.LED_OFF);
                    }
                } catch (Exception e) {
                    Log.e(LOG_TAG, "Error service connection");
                }
            }
        });

        Switch ledControl_4 = (Switch) findViewById(R.id.led_4);
        ledControl_4.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                Log.i(LOG_TAG, "Led_4 CheckedChanged()");
                try {
                    if (b) {
                        mService.setLedValue(ILedControlInterface.LED_4, ILedControlInterface.LED_ON);
                    } else {
                        mService.setLedValue(ILedControlInterface.LED_4, ILedControlInterface.LED_OFF);
                    }
                } catch (Exception e) {
                    Log.e(LOG_TAG, "Error service connection");
                }
            }
        });
        
        Intent intent = new Intent();
        intent.setAction(SERVICE);
        intent.setPackage(SERVICE_PKG);

        try {
            bindService(intent, mConnection, Context.BIND_AUTO_CREATE);
        } catch (Exception e) {
            Log.e(LOG_TAG, "Error binding service");
        }
    }

    @Override
    protected void onDestroy() {
        Log.i(LOG_TAG, "onDestroy()");

        unbindService(mConnection);
        super.onDestroy();
    }

}