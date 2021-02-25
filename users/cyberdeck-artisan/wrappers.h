/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#pragma once
#include "cyberdeck-artisan.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x10_wrapper(...)       LAYOUT_ortho_4x10(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
#define LAYOUT_split_3x6_3_wrapper(...)      LAYOUT_split_3x6_3(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define _______________ALT_COLEMAK_L3______________       Z_LSFT,  KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH
#define _______________ALT_COLEMAK_R3______________       KC_K,    KC_M,    KC_COMM, KC_DOT,  SLASH_RSFT

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define ______________6_COL_COLEMAK_L1_____________       KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define ______________6_COL_COLEMAK_L2_____________       KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define ______________6_COL_COLEMAK_L3_____________       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define ____________6_COL_ALT_COLEMAK_L3___________       KC_LSFT, Z_LSFT,  KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH
#define _______________ALT_COLEMAK_R3______________       KC_K,    KC_M,    KC_COMM, KC_DOT,  SLASH_RSFT


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define ________________SYMBOL_LEFT________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define ________________SYMBOL_RIGHT_______________       KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL
#define ___________________BLANK___________________       _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________        ________________SYMBOL_LEFT________________
#define _________________LOWER_L2__________________        ________________NUMBER_LEFT________________
#define _________________LOWER_L3__________________        _______, _______, KC_LPRN, KC_RPRN,  KC_GRV

#define _________________LOWER_R1__________________        ________________SYMBOL_RIGHT_______________
#define _________________LOWER_R2__________________        ________________NUMBER_RIGHT_______________
#define _________________LOWER_R3__________________        KC_BSLS, KC_MINS,  KC_EQL, _______, _______


#define _________________RAISE_L1__________________        _______, KC_HOME, KC_UP,   KC_END,  _______
#define _________________RAISE_L2__________________        KC_HYPR, KC_LEFT, KC_DOWN, KC_RGHT, _______
#define _________________RAISE_L3__________________        _________________FUNC_LEFT_________________

#define _________________RAISE_R1__________________        _______, KC_LBRC, KC_RBRC, _______, KC_CAPS
#define _________________RAISE_R2__________________        _______, KC_LCBR, KC_RCBR, _______, KC_QUOT
#define _________________RAISE_R3__________________        _________________FUNC_RIGHT________________

// clang-format on
