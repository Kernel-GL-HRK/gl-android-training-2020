PRODUCT_PACKAGES += \
	vendor.gl.hikey960.hardware.leds@1.0-service \
	LedService \
	LedControlApplication

DEVICE_MANIFEST_FILE += \
    	vendor/gl/hikey960/hardware/interfaces/manifest.xml \

DEVICE_MATRIX += \
	vendor/gl/hikey960/hardware/interfaces/compatibility_matrix.xml

BOARD_SEPOLICY_DIRS += \
	vendor/gl/hikey960/sepolicy