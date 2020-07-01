#
# GlobalLogic Android training
# Makefile for vendor components
#

PRODUCT_PACKAGES += \
	vendor.gl.hardware.led@1.0-service \
	com.gl.ledcontrolservice \
	com.gl.ledcontrolapp \

TARGET_FS_CONFIG_GEN += \
	vendor/gl/hardware/interfaces/config.fs

#HALs:
DEVICE_MANIFEST_FILE += \
	vendor/gl/hardware/interfaces/manifest.xml

DEVICE_MATRIX_FILE += \
	vendor/gl/hardware/interfaces/compatibility_matrix.xml

BOARD_SEPOLICY_DIRS += \
	vendor/gl/sepolicy