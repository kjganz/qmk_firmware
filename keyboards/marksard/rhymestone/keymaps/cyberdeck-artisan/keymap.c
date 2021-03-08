/* Copyright 2020 marksard
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
#include "./common/oled_helper.h"

#include "cyberdeck-artisan.h"

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  KANJI,
  RGBRST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_ortho_4x10_wrapper(
  //,---------------------------------------------------------------------------------------------------.
    _________________COLEMAK_L1________________,    _________________COLEMAK_R1________________,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
    _________________COLEMAK_L2________________,    _________________COLEMAK_R2________________,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
    _______________ALT_COLEMAK_L3______________,    _______________ALT_COLEMAK_R3______________,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
    KC_LCTL, KC_LALT, KC_LGUI, BSP_LWR, SPC_RSE,    ENT_LWR, TAB_RSE, KC_RSFT, KC_RALT, KC_RCTL
  //,---------------------------------------------------------------------------------------------------.
  ),

  [_LOWER] = LAYOUT_ortho_4x10_wrapper(
  //,---------------------------------------------------------------------------------------------------.
    _________________LOWER_L1__________________,    _________________LOWER_R1__________________,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
    _________________LOWER_L2__________________,    _________________LOWER_R2__________________,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
    _________________LOWER_L3__________________,    _________________LOWER_R3__________________,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
    ___________________BLANK___________________,    ___________________BLANK___________________
  //,---------------------------------------------------------------------------------------------------.
  ),

  [_RAISE] = LAYOUT_ortho_4x10_wrapper(
  //,---------------------------------------------------------------------------------------------------.
    _________________RAISE_L1__________________,    _________________RAISE_R1__________________,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
    _________________RAISE_L2__________________,    _________________RAISE_R2__________________,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
    _________________RAISE_L3__________________,    _________________RAISE_R3__________________,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
    ___________________BLANK___________________,    ___________________BLANK___________________
  //,---------------------------------------------------------------------------------------------------.
  ),

  [_ADJUST] = LAYOUT_ortho_4x10_wrapper(
  //,---------------------------------------------------------------------------------------------------.
        RESET,   RGBRST,  AG_NORM,  AG_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_INS,  KC_PSCR,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_NLCK,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  KC_BTN1,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
    ___________________BLANK___________________, ___________________BLANK___________________
  //,---------------------------------------------------------------------------------------------------.
  )
};

#define L_BASE _COLEMAK
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

#ifdef OLED_DRIVER_ENABLE
#include <stdio.h>
#include <string.h>

typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define LAYER_DISPLAY_MAX 5
const LAYER_DISPLAY_NAME layer_display_name[LAYER_DISPLAY_MAX] = {
  {L_BASE, "Colemak"},
  {L_BASE + 1, "Colemak"},
  {L_LOWER, "Nav"},
  {L_RAISE, "Num/Sym"},
  {L_ADJUST_TRI, "Adjust"}
};

static inline const char* get_leyer_status(void) {

  for (uint8_t i = 0; i < LAYER_DISPLAY_MAX; ++i) {
    if (layer_state == 0 && layer_display_name[i].state == default_layer_state) {

      return layer_display_name[i].name;
    } else if (layer_state != 0 && layer_display_name[i].state == layer_state) {

      return layer_display_name[i].name;
    }
  }

  return "?";
}

static char layer_status_buf[24] = "Layer state ready.\n";
static inline void update_keymap_status(void) {

  snprintf(layer_status_buf, sizeof(layer_status_buf) - 1, "OS:%s Layer:%s\n",
    keymap_config.swap_lalt_lgui? "win" : "mac", get_leyer_status());
}

static inline void render_keymap_status(void) {

  oled_write(layer_status_buf, false);
}

#define UPDATE_KEYMAP_STATUS() update_keymap_status()

static inline void render_status(void) {

  UPDATE_LED_STATUS();
  RENDER_LED_STATUS();
  render_keymap_status();
  RENDER_LOCK_STATUS();
  RENDER_KEY_STATUS();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

  if (is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

void oled_task_user(void) {

  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
}

#else

#define UPDATE_KEYMAP_STATUS()

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  UPDATE_KEY_STATUS(keycode, record);

  bool result = false;
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }

      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }

      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      break;
    case KANJI:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui == false) {
          register_code(KC_LANG2);
        } else {
          register_code16(A(KC_GRV));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  UPDATE_KEYMAP_STATUS();
  return result;
}
