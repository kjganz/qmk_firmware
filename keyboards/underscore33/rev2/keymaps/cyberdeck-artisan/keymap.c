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
  [_COLEMAK] = LAYOUT_33_split_space_wrapper(
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
    _______________ALT_COLEMAK_L3______________, _______________ALT_COLEMAK_R3______________,
                      KC_LCTL, BSP_LWR, SPC_RSE, ______3_COL_BASE_R4______
  ),

  [_LOWER] = LAYOUT_33_split_space_wrapper(
    _________________LOWER_L1__________________, _________________LOWER_R1__________________,
    _________________LOWER_L2__________________, _________________LOWER_R2__________________,
    _________________LOWER_L3__________________, _________________LOWER_R3__________________,
                      _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_33_split_space_wrapper(
    _________________RAISE_L1__________________, _________________RAISE_R1__________________,
    _________________RAISE_L2__________________, _________________RAISE_R2__________________,
    _________________RAISE_L3__________________, _________________RAISE_R3__________________,
                      _______, _______, _______, _______, _______, _______
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
