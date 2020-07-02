package com.example.shevchenko.ledcontrol.app;

public enum LedType {
    USER_LED_1("user_led1"), USER_LED_2("user_led2"), USER_LED_3("user_led3"), USER_LED_4("user_led4"), BT_LED("bt_active"), WIFI_LED("wifi_active");
    private final String name;

    LedType(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

