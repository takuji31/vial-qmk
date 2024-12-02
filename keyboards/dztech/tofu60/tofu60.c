#include QMK_KEYBOARD_H
#include "quantum.h"

#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    return true;
}
#endif
