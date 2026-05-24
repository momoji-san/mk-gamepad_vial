/* SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

#define VIAL_KEYBOARD_UID {0x6B, 0xE0, 0x79, 0xF1, 0x60, 0x16, 0xE0, 0x61}

#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {1, 6}

 /* LED Setting */
#define RGBLIGHT_LAYERS // 機能の有効化
#define RGBLIGHT_LED_COUNT 1 // LEDの個数
#define RGBLIGHT_MAX_LAYERS 4 // (最大32)

#define LED_LAYOUT(LED0){LED0}
#define RGBLIGHT_LED_MAP LED_LAYOUT(0)
