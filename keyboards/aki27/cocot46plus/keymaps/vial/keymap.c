/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _WBASE,
    _LOWER,
    _RAISE,
    _MOUSE,
    _WMOUSE,
    _DEVICE
};

#define LSPC LT(_LOWER, KC_SPC)
#define RENT LT(_RAISE, KC_ENT)

// In the buttom row, KC_MS_BTN3 binds middle-click to the encoder's button press
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LALT, KC_LGUI,    LSPC,  KC_LNG2, KC_MS_BTN1,             KC_MS_BTN2,  KC_LNG1,    RENT, KC_BSPC,  KC_ESC,
                                                                 XXXXXXX, KC_MS_BTN3,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_WBASE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_MINUS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_LGUI, KC_LALT,    LSPC, KC_LNG2, KC_MS_BTN1,              KC_MS_BTN2,  KC_LNG1,    RENT, KC_BSPC,  KC_ESC,
                                                                 XXXXXXX, KC_MS_BTN3,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_LOWER] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
       KC_GRV, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                                       S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_BSLS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_LCBR, KC_RCBR,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TRNS,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                        KC_F11,  KC_F12, KC_TRNS, KC_TRNS, KC_RBRC, KC_RBRC,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_MS_BTN4,             KC_MS_BTN5,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 XXXXXXX, KC_MS_BTN3,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_RAISE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TILD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PIPE,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_TRNS, KC_TRNS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                                                 XXXXXXX,   KC_MUTE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_MOUSE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        MO(6), KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_MS_BTN1,             KC_MS_BTN2,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                                                 XXXXXXX, KC_MS_BTN3,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_WMOUSE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
        MO(6), KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_MS_BTN1,             KC_MS_BTN2,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                                                 XXXXXXX, KC_MS_BTN3,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    ),
  [_DEVICE] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       XXXXXXX,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15,  EE_CLR,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,             XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    )
};

// Same function on all layers for now.
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_WBASE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_LOWER] = { ENCODER_CCW_CW(C(S(KC_TAB)), C(KC_TAB)) },
    [_RAISE] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MOUSE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_WMOUSE] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [_DEVICE] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) }
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    if (win_mode) {
        state = update_tri_layer_state(state, _LOWER, _RAISE, _WMOUSE);
    } else {
        state = update_tri_layer_state(state, _LOWER, _RAISE, _MOUSE);
    }
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        rgblight_sethsv_range(HSV_RED, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _MOUSE:
    case _WMOUSE:
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _DEVICE:
        rgblight_sethsv_range(HSV_WHITE, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    default:
        rgblight_sethsv_range( 0, 0, 0, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    }
    rgblight_set_effect_range( 2, 10);
    return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

