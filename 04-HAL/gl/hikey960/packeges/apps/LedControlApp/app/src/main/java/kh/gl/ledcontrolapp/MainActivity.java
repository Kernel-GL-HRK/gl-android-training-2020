package kh.gl.ledcontrolapp;

import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.os.RemoteException;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.SeekBar;
import android.widget.TextView;

import kh.gl.ledcontrolservice.ILedInterface;

public class MainActivity extends AppCompatActivity {

    private static final String LOG_TAG = "SetLEDActivity:";
    private static final String SERVICE_PKG = "kh.gl.ledcontrolservice";
    private static final String SERVICE = "kh.gl.ledcontrolservice.LedControlService";

    private ILedInterface mService;

    private ServiceConnection mConnention = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            if(service != null)
            {
                mService = ILedInterface.Stub.asInterface(service);
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

        final SeekBar seekLED1Bar = (SeekBar) findViewById(R.id.seekBar);

        seekLED1Bar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                try {
                    Log.d(LOG_TAG, "Set GPIO(LED) 1 value:"+progress);
                    mService.ledControl(0,progress);
                } catch (RemoteException |NullPointerException e) {
                    Log.e(LOG_TAG, "!!!Set GPIO(LED) 1 value");
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
            }
        });

        final SeekBar seekLED2Bar = (SeekBar) findViewById(R.id.seekBar1);

        seekLED2Bar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                try {
                    Log.d(LOG_TAG, "Set GPIO(LED) 2 value:"+progress);
                    mService.ledControl(1,progress);
                } catch (RemoteException |NullPointerException e) {
                    Log.e(LOG_TAG, "!!!Set GPIO(LED) 2 value");
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
            }
        });

        final SeekBar seekLED3Bar = (SeekBar) findViewById(R.id.seekBar2);

        seekLED3Bar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                try {
                    Log.d(LOG_TAG, "Set GPIO(LED) 3 value:"+progress);
                    mService.ledControl(2,progress);
                } catch (RemoteException |NullPointerException e) {
                    Log.e(LOG_TAG, "!!!Set GPIO(LED) 3 value");
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
            }
        });

        final SeekBar seekLED4Bar = (SeekBar) findViewById(R.id.seekBar3);

        seekLED4Bar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                try {
                    Log.d(LOG_TAG, "Set GPIO(LED) 4 value:"+progress);
                    mService.ledControl(3,progress);
                } catch (RemoteException |NullPointerException e) {
                    Log.e(LOG_TAG, "!!!Set GPIO(LED) 4 value");
                }
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
            }
        });

        Intent inten = new Intent();
        inten.setClassName(SERVICE_PKG,SERVICE);
        bindService(inten, mConnention, BIND_AUTO_CREATE);
    }

    protected void onDestroy() {
        super.onDestroy();
        unbindService(mConnention);
    }
}