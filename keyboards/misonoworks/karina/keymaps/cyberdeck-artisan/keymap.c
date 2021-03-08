/*
Copyright 2020 MisonoWorks

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

#include "cyberdeck-artisan.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_wrapper(
        KC_ESC,  _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
        KC_TAB,  _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_MUTE,
                             KC_LCTL, KC_LALT, SPC_RSE, ENT_LWR, KC_RSFT, KC_RCTL
    ),

    [_LOWER] = LAYOUT_wrapper(
        RESET,   _________________LOWER_L1__________________, _________________LOWER_R1__________________,
        _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________,
		_______,   _________________LOWER_L3__________________, _________________LOWER_R3__________________,
                             _______, ___________________BLANK___________________
    ),

	[_RAISE] = LAYOUT_wrapper(
        _______, _________________RAISE_L1__________________, _________________RAISE_R1__________________,
        _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________,
		_______, _________________RAISE_L3__________________, _________________RAISE_R3__________________,
                             _______, ___________________BLANK___________________
    )

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDOWN);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}

