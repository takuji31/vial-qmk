/* Copyright 2022 DZTECH <moyi4681@Live.cn>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "config.h"
#include "vial.h"

#include "keys.c"

enum {
    TD_WLOWER_ALT_GRV = 99,
};

enum {
    _BASE = 0,
    _LOWER = 3,
    _RAISE = 4,
    _ADJUST = 15,
    _WBASE = 1,
    _WLOWER = 5,
    _WRAISE = 6,
    _WADJUST = 15,
};


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    state = update_tri_layer_state(state, _WLOWER, _WRAISE, _WADJUST);
    return state;
};

bool process_detected_host_os_user(os_variant_t detected_os) {
        switch (detected_os) {
        case OS_WINDOWS:
            set_single_persistent_default_layer(_WBASE);
            break;
        default:
            set_single_persistent_default_layer(_BASE);
            break;
    }
    return true;
}

void install_tap_dance_entries(void) {
    vial_tap_dance_entry_t td0 = { LALT(KC_GRV), MO(_WLOWER), KC_NO, KC_NO, TAPPING_TERM };
    dynamic_keymap_set_tap_dance(TD_WLOWER_ALT_GRV, &td0);
}

void keyboard_post_init_user(void) {
  #ifdef TAP_DANCE_ENABLE
  install_tap_dance_entries();
  #endif
}
