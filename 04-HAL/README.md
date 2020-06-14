
# Description:
A simple project for controlling the hikey 960 LEDs.

Implemented:
- User android app for controlling hikey 960 leds.
- Android service for exchanging data between user app and HAL.
- HAL for controlling leds via sysfs.
- Added sepolicy.

## Project struct:

hikey960
    ├── device-vendor.mk
    ├── hardware
    │   └── interfaces
    │       ├── Android.bp
    │       ├── compatibility_matrix.xml
    │       ├── config.fs
    │       ├── ledcontrol
    │       │   └── 1.0
    │       │       ├── Android.bp
    │       │       ├── default
    │       │       │   ├── Android.bp
    │       │       │   ├── LedControl.cpp
    │       │       │   ├── LedControl.h
    │       │       │   ├── service.cpp
    │       │       │   └── vendor.gl.hardware.ledcontrol@1.0-service.rc
    │       │       ├── ILedControl.hal
    │       │       └── types.hal
    │       └── manifest.xml
	├── packeges
    │   ├── apps
    		└── LedControlApp
    │   └── services
   	│	│       └── LedControlService
    └── sepolicy
        ├── file_contexts
        ├── file.te
        ├── hwservice_contexts
        ├── hwservice.te
        ├── ledcontrol.te
        └── platform_app.te



![Image alt](https://github.com/kurtwalkir/QT_OPENCV4/raw/master/ImageViewer/ImageViewer/sreen.png)