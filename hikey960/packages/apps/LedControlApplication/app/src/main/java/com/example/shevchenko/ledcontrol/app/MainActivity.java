package com.example.shevchenko.ledcontrol.app;

import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;

import com.example.shevchenko.ledcontrol.ledservice.ILedInterface;

public class MainActivity extends AppCompatActivity {
    private final static String TAG = "LedControlApplication";
    private ILedInterface ledService;

    private ServiceConnection connection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            if (service != null) {
                ledService = ILedInterface.Stub.asInterface(service);
            }
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {

        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final CheckBox led1 = findViewById(R.id.checkBoxLed1);
        final CheckBox led2 = findViewById(R.id.checkBoxLed2);
        final CheckBox led3 = findViewById(R.id.checkBoxLed3);
        final CheckBox led4 = findViewById(R.id.checkBoxLed4);
        final CheckBox btLed = findViewById(R.id.checkBoxBTLed);
        final CheckBox wifiLed = findViewById(R.id.checkBoxWifiLed);
        final Button btnUpdate = findViewById(R.id.btnUpdate);
        final Button btnRefresh = findViewById(R.id.btnRefresh);

        btnUpdate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    boolean isLed1TurnOn = led1.isChecked();
                    boolean isLed2TurnOn = led2.isChecked();
                    boolean isLed3TurnOn = led3.isChecked();
                    boolean isLed4TurnOn = led4.isChecked();
                    boolean isBtLedTurnOn = btLed.isChecked();
                    boolean isWifiLedTurnOn = wifiLed.isChecked();

                    ledService.updateState(LedType.USER_LED_1.getName(), isLed1TurnOn);
                    ledService.updateState(LedType.USER_LED_2.getName(), isLed2TurnOn);
                    ledService.updateState(LedType.USER_LED_3.getName(), isLed3TurnOn);
                    ledService.updateState(LedType.USER_LED_4.getName(), isLed4TurnOn);
                    ledService.updateState(LedType.BT_LED.getName(), isBtLedTurnOn);
                    ledService.updateState(LedType.WIFI_LED.getName(), isWifiLedTurnOn);
                } catch (RemoteException | NullPointerException e) {
                    Log.e(TAG, e.getMessage());
                }
            }
        });

        btnRefresh.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    led1.setChecked(ledService.getLedState(LedType.USER_LED_1.getName()));
                    led2.setChecked(ledService.getLedState(LedType.USER_LED_2.getName()));
                    led3.setChecked(ledService.getLedState(LedType.USER_LED_3.getName()));
                    led4.setChecked(ledService.getLedState(LedType.USER_LED_4.getName()));
                    btLed.setChecked(ledService.getLedState(LedType.BT_LED.getName()));
                    wifiLed.setChecked(ledService.getLedState(LedType.WIFI_LED.getName()));
                } catch (RemoteException | NullPointerException e) {
                    Log.e(TAG, e.getMessage());
                }
            }
        });

        final Intent intent = new Intent();
        intent.setClassName("com.example.shevchenko.ledcontrol.ledservice", "com.example.shevchenko.ledcontrol.ledservice.LedService");
        try {
            bindService(intent, connection, BIND_AUTO_CREATE);
        } catch (SecurityException e) {
            Log.e(TAG, "bind to service failed by security reason");
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        unbindService(connection);
    }
}
