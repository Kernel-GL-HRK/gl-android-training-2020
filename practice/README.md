# Practical work

Extend `hikey960` BSP from AOSP with custom interface for LEDs control.

Solution should include:
- forked AOSP manifest extended with modified projects and custom projects;
- patched kernel
(kernel building should be integrated into Android build);
- extended BSP project to include custom SW components;
- HAL: interface definition in HIDL and implementation (binderized service);
- Java service with access to the HAL above and defined interface in AIDL;
- Java GUI application with access to Java service above;

All custom components should be located in `vendor` subtree and built as vendor modules.  
Communication between java application, java service and HAL should be via binder.  
For custom components should be defined SELinux contexts and rules.

For review extend this readm with description of your solution
which will include lincs to all its components.

# Homework for LED controll: with LED controll HIDL interface, AIDL and service and APP to controll leds.
The list of repositories (that included in default manifest.xml)
git@github.com:Hobbit-iT/hikey-linaro-proprietary.git branch hikey960
git@github.com:Hobbit-iT/gl-android-training-2020.git branch gl.vendor
git@github.com:Hobbit-iT/android_manifest.git branch gl-hikey960-2020
git@github.com:Hobbit-iT/hikey-linaro-kernel.git branch gl-hikey960-4.9-2020
git@github.com:Hobbit-iT/hikey-linaro-device.git branch gl-hikey960-2020
