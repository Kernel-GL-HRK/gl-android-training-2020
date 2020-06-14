PRODUCT_PACKAGES += \
    vendor.gl.hardware.ledcontrol@1.0-service \
    LedControlApp \
    LedControlService

DEVICE_MANIFEST_FILE += vendor/gl/hikey960/hardware/interfaces/manifest.xml

DEVICE_MATRIX_FILE += vendor/gl/hikey960/hardware/interfaces/compatibility_matrix.xml

BOARD_SEPOLICY_DIRS += vendor/gl/hikey960/sepolicy

#TARGET_FS_CONFIG_GEN += vendor/gl/hikey960/hardware/interface/config.fs