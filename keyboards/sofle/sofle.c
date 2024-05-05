// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

#ifdef SWAP_HANDS_ENABLE

__attribute__((weak)) const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] =
    // The LAYOUT macro could work for this, but it was harder to figure out the
    // identity using it.

    // This is the identity layout.
    /*
    {
        { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} },
        { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} },
        { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} },
        { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} },
        { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} },

        { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} },
        { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} },
        { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} },
        { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} },
        { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} },
    };
    */

    // This is the mirror, q <-> p, w <-> o, etc...
    {
        {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}}, {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}}, {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}}, {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}}, {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}},

        {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}}, {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}}, {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}}, {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}}, {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
};

#    ifdef ENCODER_MAP_ENABLE
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = {1, 0};
#    endif

#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {0,   0,   0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,  0,  0,   0,   0,   128, 128, 128, 0,   0,   0,  192, 224, 240, 240, 240, 240, 240, 240, 240, 224, 0,  0,  0,  0,  0,  0, 0, 0,   0,   0,   0,  0,  0,  0,  0,  0,  0,   0,   0,   112, 112, 112, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 192, 224, 240, 0,   0, 240, 252, 254, 255, 255, 255, 1,   240, 252, 255, 255, 255, 255, 255, 255, 255, 255, 127, 31,  7,   0, 0, 0, 0, 0, 0, 0, 0,
                                            0,   0,   0, 0, 0, 0, 0, 0, 0,   0,   0,   254, 254, 254, 0,  0,  240, 248, 252, 30,  14,  14,  14,  14,  14, 14,  30,  252, 248, 240, 0,   0,   254, 254, 252, 28, 14, 14, 14, 14, 0, 0, 254, 254, 252, 28, 14, 14, 14, 14, 30, 252, 248, 240, 0,   0,   240, 248, 252, 222, 206, 206, 206, 206, 206, 206, 222, 252, 248, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 255, 254, 240, 255, 255, 255, 255, 255, 255, 248, 255, 255, 255, 255, 255, 255, 255, 255, 255, 193, 128, 128, 128, 192, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   128, 255, 255, 255, 0, 0,   15,  31,  63,  120, 112, 112, 112, 112, 112, 112, 120, 63,  31,  15,  0,   0,   127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 127,
                                            127, 127, 0, 0, 0, 0, 0, 0, 127, 127, 127, 0,   0,   15,  31, 63, 121, 113, 113, 113, 113, 113, 113, 121, 61, 29,  13,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0, 0, 0,   0,   0,   0,  0,  0,  0,  0,  0,  0,   0,   1,   3,   3,   3,   3,   1,   1,   3,   3,   7,   7,   7,   3,   3,   1,   3,   7,   7, 7, 7, 7, 7, 7, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7,  7,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0};
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 3:
            oled_write_P(PSTR("Lower"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return true;
}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif
