/* Copyright 2020 Eye Oh! Designs
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

#include "cyberdeck-artisan.h"
#include "./keymap.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_COLEMAK] = LAYOUT_1u_wrapper(
        __________________6_COL_COLEMAK_L1__________________, __________________6_COL_COLEMAK_R1__________________,
        __________________6_COL_COLEMAK_L2__________________, __________________6_COL_COLEMAK_R2__________________,
        ________________6_COL_ALT_COLEMAK_L3________________, ________________6_COL_ALT_COLEMAK_R3________________,
        KC_LCTL,                   KC_LGUI, BSP_LWR, SPC_RSE, ENT_LWR, TAB_RSE, KC_RALT,               MO(_ADJUST)
    ),
    [_LOWER] = LAYOUT_1u_wrapper(
        ___________________6_COL_LOWER_L1___________________, ___________________6_COL_LOWER_R1___________________,
        ___________________6_COL_LOWER_L2___________________, ___________________6_COL_LOWER_R2___________________,
        ___________________6_COL_LOWER_L3___________________, ___________________6_COL_LOWER_R3___________________,
        _______,                    ___________________BLANK___________________, _______,                  _______
    ),
    [_RAISE] = LAYOUT_1u_wrapper(
        ___________________6_COL_RAISE_L1___________________, ___________________6_COL_RAISE_R1___________________,
        ___________________6_COL_RAISE_L2___________________, ___________________6_COL_RAISE_R2___________________,
        ___________________6_COL_RAISE_L3___________________, ___________________6_COL_RAISE_R3___________________,
        _______,                    ___________________BLANK___________________, _______,                  _______
    ),
    [_ADJUST] = LAYOUT_1u_wrapper(
        ___________________6_COL_ADJUST_L1__________________, ___________________6_COL_ADJUST_R1__________________,
        ___________________6_COL_ADJUST_L2__________________, ___________________6_COL_ADJUST_R2__________________,
        ___________________6_COL_ADJUST_L3__________________, ___________________6_COL_ADJUST_R3__________________,
        _______,                    ___________________BLANK___________________, _______,                  _______
    ),
};
// clang-format on
