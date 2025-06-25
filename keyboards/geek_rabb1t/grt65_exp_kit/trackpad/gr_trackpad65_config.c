/* Copyright 2025 Geek-rabb1t (@geek-rabb1t)
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
#include "gr_trackpad65_config.h"

typedef enum  {
    cursor_speed = 0,
    scroll_speed = 1,
    cursor_correct = 2,
    tap_sensitivity = 3,

    enable_accel = 4,
    reverse_vertical_scroll = 5,
    reverse_horizontal_scroll = 6,

    inertia_cursor = 7,
    inertia_scroll = 8,
    move_on_edge = 9,

    scroll_only = 10,

    rotate = 11

} config_col_t;


gr_trackpad65_config_t gr_trackpad_config = {
    .cursor_speed = GRT_SPD_5,
};

const static int MIN_SPEED = 1;
const static int MAX_SPEED = 9;

int resolve_speed(uint16_t keycode, int defaultValue) {
    int speed = keycode - GRT_SPD_1 + 1;
    return
        speed < MIN_SPEED ? defaultValue :
        speed > MAX_SPEED ? defaultValue : speed;
}

bool resolve_bool(uint16_t keycode, bool defaultValue) {
    return
        keycode == GRT_ON ? true :
        keycode == GRT_OFF ? false : defaultValue;
}

rotate_modes_t resolve_rotate(uint16_t keycode, rotate_modes_t defaultValue) {
    switch (keycode) {
        case ROTATE_0:
        case ROTATE_90:
        case ROTATE_180:
        case ROTATE_270:
            return keycode;
        default:
            return defaultValue;
    }
}

static uint8_t configuration_layer = 0;
static uint8_t configuration_row = 0;

int read_speed(uint8_t col, int defaultValue) {
    uint16_t keycode = dynamic_keymap_get_keycode(configuration_layer, configuration_row, col);
    return resolve_speed(keycode, defaultValue);
}

bool read_bool(uint8_t col, bool defaultValue) {
    uint16_t keycode = dynamic_keymap_get_keycode(configuration_layer, configuration_row, col);
    return resolve_bool(keycode, defaultValue);
}

rotate_modes_t read_rotate(uint8_t col, rotate_modes_t defaultValue) {
    uint16_t keycode = dynamic_keymap_get_keycode(configuration_layer, configuration_row, col);
    return resolve_rotate(keycode, defaultValue);
}

void load_gr_trackpad65_config(uint8_t config_layer, uint8_t config_row, bool allow_rotate)  {
    configuration_layer = config_layer;
    configuration_row = config_row;

    gr_trackpad_config.cursor_speed    = read_speed(cursor_speed, 5);
    gr_trackpad_config.scroll_speed    = read_speed(scroll_speed, 5);

    gr_trackpad_config.cursor_correct  = read_speed(cursor_correct, 2);
    gr_trackpad_config.tap_sensitivity = read_speed(tap_sensitivity, 5);

    gr_trackpad_config.enable_accel    = read_bool(enable_accel, false);

    gr_trackpad_config.reverse_vertical_scroll = read_bool(reverse_vertical_scroll, false);
    gr_trackpad_config.reverse_horizontal_scroll = read_bool(reverse_horizontal_scroll, false);

    gr_trackpad_config.inertia_cursor  = read_bool(inertia_cursor, true);
    gr_trackpad_config.inertia_scroll  = read_bool(inertia_scroll, true);
    gr_trackpad_config.move_on_edge    = read_bool(move_on_edge, false);

    gr_trackpad_config.scroll_only     = read_bool(scroll_only, false);

    if (allow_rotate) {
        gr_trackpad_config.rotate = read_rotate(rotate, ROTATE_0);
    } else {
        gr_trackpad_config.rotate = ROTATE_0;
    }
}
