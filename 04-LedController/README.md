04 - Creation of userspace app,  service and android hal.

Dependencies:
Android manifest:

Hikey Linaro Device:

Hikey Linaro Kernel:

Hikey Linaro Poprietary:

How to build:
1. cd ~/hikey960
2. . ./build/envsetup.sh
3. lunch hikey960-userdebug
4. make -j16
How to flash:
1. adb reboot bootloader
2. ./device/linaro/hikey/installer/hikey960/flash-all.sh
