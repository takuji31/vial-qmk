/*
 * Copyright 2025 Geek-rabb1t (@geek-rabb1t)
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

#include "gr_trackpad65_reporter.h"
#include "gr_trackpad65_cursor_corrector.h"
#include "gesture/gr_trackpad65_state.h"




// static uint8_t max_fingers = 0;
// static int16_t swipe_distance_x = 0;
// static int16_t swipe_distance_y = 0;
// static uint16_t tap_interval = 0;
// static uint16_t tap_timer = 0;
// static uint16_t gesture_timer = 0;
// static bool doubleTap = false;

// static trackpad_state_t trackpad_state = trackpad_state_idle;
// static scroll_direction_t scroll_direction = scroll_direction_tbd;
// static position_t scroll_rest = {0};

report_mouse_t trackpad_reporter_report(azoteq_iqs5xx_base_data_t base_data) {
    trackpad_base_data_t trackpad_data = cursor_corrector_correct(base_data);
    return trackpad_report(trackpad_data);
}
