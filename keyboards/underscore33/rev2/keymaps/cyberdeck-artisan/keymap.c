/* Copyright 2020 tominabox1
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

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV
};

#define KC_NUM_ENT LT(_NUM_SYM, KC_ENT)
#define KC_NAV_SPC LT(_NAV, KC_SPC)
#define KC_GA LGUI_T(KC_A)
#define KC_AR LALT_T(KC_R)
#define KC_CS LCTL_T(KC_S)
#define KC_ST LSFT_T(KC_T)
#define KC_SN RSFT_T(KC_N)
#define KC_CE RCTL_T(KC_E)
#define KC_AI RALT_T(KC_I)
#define KC_GSCLN RGUI_T(KC_SCLN)

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_33_split_space(
    KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,   KC_J,   KC_L,    KC_U,   KC_Y, KC_SCLN,
    KC_A,   KC_R,  KC_S,  KC_T,   KC_D,   KC_H,  KC_N,   KC_E,  KC_I, KC_O,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M, KC_COMM, KC_DOT,  KC_SLSH,
                 KC_LCTL, KC_LALT, KC_NAV_SPC, KC_NUM_ENT, KC_RSFT, KC_RCTL
  ),

  [_NUM_SYM] = LAYOUT_33_split_space(
    KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR, KC_EQUAL,  KC_MINS,
       KC_1,     KC_2,     KC_3,     KC_4,      KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_BSLS,  KC_LCBR,  KC_LBRC,  KC_LPRN,   KC_UNDS,  KC_RPRN,  KC_RBRC,  KC_RCBR,   KC_DOT,   KC_GRV,
                  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
  ),

  [_NAV] = LAYOUT_33_split_space(
    RESET,    KC_TRNS,    KC_UP,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                   KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
  ),

};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),

};
#endif
