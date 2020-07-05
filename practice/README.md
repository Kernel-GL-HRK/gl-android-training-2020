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

# Implementation

Implementation includes next parts:
- [Android manifest](https://github.com/Serggio-26/android_manifest) for repo purpose
- [BSP for hikey960](https://github.com/Serggio-26/hikey-linaro-device.git)
- [Linux kernel 4.9 for Linaro](https://github.com/Serggio-26/hikey-linaro-kernel.git)
- [Led Control project](https://github.com/Serggio-26/gl-android-training-2020/tree/ledcontrol_project)
  - [Android UI app and service](https://github.com/Serggio-26/gl-android-training-2020/tree/ledcontrol_app)
  - [HAL daemon](https://github.com/Serggio-26/gl-android-training-2020/tree/ledcontrol_hw)
  - [SELinux policy](https://github.com/Serggio-26/gl-android-training-2020/tree/ledcontrol_sepolicy) 
