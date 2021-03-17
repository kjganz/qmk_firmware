#include "combo.h"

enum combos {
    COMBO_BSPC,
    COMBO_NUMBAK,
    //   COMBO_TAB,
    COMBO_ESC,
    COMBO_DEL,
};

const uint16_t PROGMEM combo_bspc[]   = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
// const uint16_t PROGMEM combo_tab[] =    {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_BSPC]   = COMBO(combo_bspc, KC_BSPC),
    [COMBO_NUMBAK] = COMBO(combo_numbak, KC_BSPC),
    // [COMBO_TAB] =    COMBO(combo_tab,KC_TAB),
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_DEL] = COMBO(combo_del, KC_DEL),
};
