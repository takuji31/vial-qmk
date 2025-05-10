# This file intentionally left blank

POINTING_DEVICE_ENABLE = yes
# MOUSEKEY_ENABLE = yes
POINTING_DEVICE_DRIVER = custom

# ENCODER_MAP_ENABLE = yes
I2C_DRIVER_REQUIRED = yes
SRC += trackpad/azoteq_iqs5xx.c
SRC += trackpad/gr_trackpad65.c
SRC += trackpad/gr_trackpad65_driver.c
SRC += trackpad/gr_trackpad65_config.c
SRC += trackpad/gr_trackpad65_reporter.c
