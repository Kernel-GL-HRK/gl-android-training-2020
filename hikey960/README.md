### Led Control Application
Led Control application is placed by the path: ```vendor\gl\hikey960\packages\apps\LedControlApplication```
### Led Control Service
Led Control service is placed by the path: ```vendor\gl\hikey960\packages\services\LedService```
### Led Control HAL
Led Control HAL is placed by the path: ```vendor\gl\hikey960\hardware\interfaces\leds```

### Dependencies:

Android manifest: ```https://github.com/Oksana-Shevchenko/android_manifest```

Hikey Linaro Device: ```https://github.com/Oksana-Shevchenko/hikey-linaro-device```

Hikey Linaro Kernel: ```https://github.com/Oksana-Shevchenko/hikey-linaro-kernel```

Hikey Linaro Poprietary: ```https://github.com/Oksana-Shevchenko/hikey-linaro-proprietary/tree/hikey960-android-p```

Led control HAL, Service, Application: ```https://github.com/Oksana-Shevchenko/gl-android-training-2020/tree/04-LedHal```

### How to build:

1. cd ~/hikey960
2. sync repo in project folder
3. . ./build/envsetup.sh
4. lunch hikey960-userdebug
5. make -j4
6. adb reboot bootloader
7. cd device/linaro/hikey/installer/hikey960
8. ./flash-all.sh
