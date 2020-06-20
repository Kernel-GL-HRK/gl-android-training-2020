PRODUCT_PACKAGES += \
	LedCtrlService \
	LedCtrl \
	vendor.gl.hardware.ledctrl@1.0-service	

DEVICE_MANIFEST_FILE += \
	vendor/gl/hikey960/hardware/interfaces/manifest.xml

DEVICE_MATRIX_FILE += \
	vendor/gl/hikey960/hardware/interfaces/compatibility_matrix.xml

BOARD_SEPOLICY_DIRS += \
	vendor/gl/hikey960/sepolicy