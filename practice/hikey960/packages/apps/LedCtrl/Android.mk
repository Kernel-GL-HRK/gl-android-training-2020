LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_PACKAGE_NAME := LedCtrl

LOCAL_SRC_FILES := \
	$(call all-Iaidl-files-under, aidl) \
	$(call all-java-files-under, java)

LOCAL_RESOURCE_DIR := $(LOCAL_PATH)/res

LOCAL_STATIC_ANDROID_LIBRARIES := \
    android-support-v7-appcompat \
    android-support-constraint-layout

LOCAL_STATIC_JAVA_LIBRARIES += \
    android-support-constraint-layout-solver

LOCAL_CERTIFICATE := platform
LOCAL_USE_AAPT2 := true
LOCAL_PRIVATE_PLATFORM_APIS := true

include $(BUILD_PACKAGE)