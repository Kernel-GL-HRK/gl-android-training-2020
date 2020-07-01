package com.gl.ledcontrolapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;

import android.os.IBinder;
import android.os.RemoteException;

import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

import com.gl.ledcontrolservice.ILEDcontrol;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener{
    private ILEDcontrol             mService;       //the service to work with LEDs
    private int                     mLED;           //current LED number
    private int                     mTrigger;       //current trigger number for the LED

    //-----------------------------------------------------------
    private ServiceConnection mConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            final TextView  txtStatus           = (TextView) findViewById(R.id.textStatus);
            final Spinner   spinner_led         = findViewById(R.id.spinner_led);
            txtStatus.setText("connected to the Service");
            if (service != null)
                mService = ILEDcontrol.Stub.asInterface(service);
            if(mService != null) {
                try {
                    String[] items = mService.get_leds_list().split(" ");
                    spinner_led.setAdapter(new ArrayAdapter<>(
                            getBaseContext(), android.R.layout.simple_spinner_dropdown_item, items));
                    txtStatus.setText("LEDs list is received successfully");
                }catch (RemoteException e) {
                    txtStatus.setText("error receiving LEDs list");
                }
            }else txtStatus.setText("null-service");
        }//onServiceConnected

        @Override
        public void onServiceDisconnected(ComponentName name) { mService = null; }
    };//ServiceConnection

    //-----------------------------------------------------------
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final TextView txtStatus = (TextView) findViewById(R.id.textStatus);
        final Spinner   spinner_trigger = findViewById(R.id.spinner_trigger);
        final Spinner   spinner_led     = findViewById(R.id.spinner_led);
        final Button    button_set      = findViewById(R.id.button_set_brightness);

        //connecting to the service
        Intent intent = new Intent();
        intent.setClassName("com.gl.ledcontrolservice", "com.gl.ledcontrolservice.LEDcontrolService");
        try
        {
            if (!bindService(intent, mConnection, BIND_AUTO_CREATE))
                txtStatus.setText("it seems that the Keeper service isn't installed");
        } catch (SecurityException e)
        {
            txtStatus.setText("error binding to the service.");
        }
        spinner_led.setOnItemSelectedListener(this);
        spinner_trigger.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                //changing trigger
                if(mTrigger != position) {  //to exclude changing on initialization.
                    String newTrigger = parent.getItemAtPosition(position).toString();
                    //String text = spinner.getSelectedItem().toString();
                    final TextView txtStatus = (TextView) findViewById(R.id.textStatus);
                    try {
                        int result = find_selected_trigger(mService.set_trigger(mLED, newTrigger).split(" "));
                        if (result == position)
                            txtStatus.setText("the trigger is set successfully");
                        else
                            txtStatus.setText("it looks like we can't change trigger for this LED");
                    } catch (NullPointerException | RemoteException e) {
                        txtStatus.setText("error receiving trigger of the LED ");
                    }
                }
            }//onItemSelected

            @Override
            public void onNothingSelected(AdapterView<?> parent) {}
        });//setOnItemSelectedListener

        button_set.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final EditText txtBrightness = (EditText) findViewById(R.id.editTextNumber_brightness);
                final TextView txtStatus = (TextView) findViewById(R.id.textStatus);
                String value = txtBrightness.getText().toString();
                try {
                    String result = mService.set_brightness(mLED, value);
                    if(result != value)
                        txtBrightness.setText(result);
                    txtStatus.setText("brightness of the LED is set to "+result);
                }catch (NullPointerException | RemoteException e) {
                    txtStatus.setText("error trying set the brightness");
                }
            }//onClick
        });//setOnClickListener
    }//onCreate

    ///find the first string in [braces], removes the braces and returns the string number.
    private int find_selected_trigger(String[] d){
        int result = -1;
        for (int i=0; i< d.length; ++i){
            String str_cur = d[i];
            if(str_cur.startsWith("[") && str_cur.endsWith("]"))
            {
                result = i;
                d[i] = str_cur.substring(1, str_cur.length()-1);
                break;
            }
        }
        return result;
    };//find_selected_trigger

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        //changing LED
        final TextView txtStatus = (TextView) findViewById(R.id.textStatus);
        final TextView txtMaxBrightness = (TextView) findViewById(R.id.textView_max_brightness);
        final EditText txtBrightness = (EditText) findViewById(R.id.editTextNumber_brightness);
        final Spinner   spinner_trigger     = findViewById(R.id.spinner_trigger);
        mLED =  position;
        try {
            //getting the trigger
            String[] items = mService.get_trigger(mLED).split(" ");
            mTrigger = find_selected_trigger(items);
            spinner_trigger.setAdapter(new ArrayAdapter<>
                    (getBaseContext(), android.R.layout.simple_spinner_dropdown_item, items));
            if(mTrigger >= 0)
                spinner_trigger.setSelection(mTrigger);
            //getting the max_brightness
            txtMaxBrightness.setText("maximum brightness is " + mService.get_max_brightness(mLED));
            //getting the brightness
            txtBrightness.setText(mService.get_brightness(mLED));
            txtStatus.setText("the LED settings is read successfully.\n" +
                    "note: the brightness is volatile and might not correspond real value.");
        }catch (NullPointerException | RemoteException e) {
            txtStatus.setText("error getting the LED settings");
        }
    }//onItemSelected

    @Override
    public void onNothingSelected(AdapterView<?> parent) {}
}//MainActivity