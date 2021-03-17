// #include "cyberdeck-artisan.h"

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     UPDATE_KEY_STATUS(keycode, record);

//     bool result = false;
//     switch (keycode) {
//         case LOWER:
//             if (record->event.pressed) {
//                 layer_on(_LOWER);
//             } else {
//                 layer_off(_LOWER);
//             }

//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             break;
//         case RAISE:
//             if (record->event.pressed) {
//                 layer_on(_RAISE);
//             } else {
//                 layer_off(_RAISE);
//             }

//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//             break;
//         default:
//             result = true;
//             break;
//     }

//     UPDATE_KEYMAP_STATUS();
//     return result;
// }
