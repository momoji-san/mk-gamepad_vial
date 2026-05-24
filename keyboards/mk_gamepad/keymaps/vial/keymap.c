// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
  _1ST = 0,
  _2ND,
  _3RD,
  _4TH
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──┬──┬──┬─  ─┬──┬──┬─ ─┬──┐
     * │ A  │ B  │EXEC│SELECT│DOWN│LEFT│RIGHT│DOWN│
     * └──┴──┴──┴─  ─┴──┴──┴─ ─┴──┘
     */
    [_1ST] = LAYOUT(
    	KC_F, KC_S, KC_F4, TO(1), KC_DOWN, KC_LEFT, KC_RIGHT, KC_UP
    ),
    [_2ND] = LAYOUT(
        KC_ENT, KC_F1, KC_ESC, TO(2), KC_DOWN, KC_LEFT, KC_RIGHT, KC_UP
    ),
    [_3RD] = LAYOUT(
        KC_A, KC_B, KC_F4, TO(3), KC_DOWN, KC_LEFT, KC_RIGHT, KC_UP
    ),
    [_4TH] = LAYOUT(
        KC_A, KC_B, KC_F4, TO(0), KC_DOWN, KC_LEFT, KC_RIGHT, KC_UP
    )
};

/////// LED Setting ////////

#ifdef RGBLIGHT_LAYERS

const rgblight_segment_t PROGMEM rgb_layer_1st[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 0,0,30}   // WHITE
);
const rgblight_segment_t PROGMEM rgb_layer_2nd[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 170,255,30}  //BLUE
);
const rgblight_segment_t PROGMEM rgb_layer_3rd[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 43,255,30}   //YELLOW
);
const rgblight_segment_t PROGMEM rgb_layer_4th[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 0,255,30}   //RED
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_1st,
    rgb_layer_2nd,
    rgb_layer_3rd,
    rgb_layer_4th
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _1ST));
    rgblight_set_layer_state(1, layer_state_cmp(state, _2ND));
    rgblight_set_layer_state(2, layer_state_cmp(state, _3RD));
    rgblight_set_layer_state(3, layer_state_cmp(state, _4TH));
    return state;
}

#endif // RGBLIGHT_LAYERS

