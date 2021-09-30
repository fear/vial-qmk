#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"

enum custom_keycodes {
  KC_WLCK = SAFE_RANGE, // Lock GuiKey
};

bool _isWinKeyDisabled = false;

enum custom_layers {
    _BASE = 0,
    _FN1,
    _NUMPAD,
    _LOCK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN1] = LAYOUT(
        _______, TG(2),   TG(3),   _______, _______, DM_REC1, DM_RSTP, DM_PLY1, _______, _______, KC_NLCK, KC_SLCK, KC_CLCK, _______,          RGB_TOG,
        RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______, RESET,            RGB_HUI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   RGB_HUD,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_SAI,
        _______, _______, _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, RGB_SAD,
        _______, KC_WLCK, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD,RGB_SPI
    ),
    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_P0,   _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, MO(1),   _______, _______, _______, _______
    ),
    [_LOCK] = LAYOUT(
        XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, MO(1),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

// Disable win key
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_WLCK:
            if (record->event.pressed) {
                _isWinKeyDisabled = !_isWinKeyDisabled; //toggle status
                if(_isWinKeyDisabled) {
                    process_magic(GUI_OFF, record);
                } else {
                    process_magic(GUI_ON, record);
                }
            } else  unregister_code16(keycode);
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}

#ifdef RGB_MATRIX_ENABLE
    // Capslock, Scroll lock and Numlock  indicator on Left side lights.
    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
            rgb_matrix_set_color(LED_F11, RGB_GREEN);
        }
        if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {   // on if NUM lock is OFF
            rgb_matrix_set_color(LED_F10, RGB_GREEN);
        }
        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(LED_CAPS, RGB_RED);
            rgb_matrix_set_color(LED_F12, RGB_GREEN);
        }
        if (_isWinKeyDisabled) {
            rgb_matrix_set_color(LED_LGUI, RGB_RED);  //light up Win key when disabled
        }

        switch(get_highest_layer(layer_state)){  // special handling per layer
            case _BASE: // Base Layer
                break;
            case _LOCK: // LockKB Layer
                for (uint8_t i=0; i < sizeof(LED_SIDE)/sizeof(LED_SIDE[0]); i++) {
                    rgb_matrix_set_color(LED_SIDE[i], RGB_RED);
                }
                for (uint8_t i=0; i < sizeof(LED_LIST_FUNCROW)/sizeof(LED_LIST_FUNCROW[0]); i++) {
                    rgb_matrix_set_color(LED_LIST_FUNCROW[i], RGB_RED);
                }
                break;
            case _NUMPAD: // Numpad layer
                for (uint8_t i=0; i < sizeof(LED_LIST_NUMPAD)/sizeof(LED_LIST_NUMPAD[0]); i++) {
                    rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_GREEN);
                }
                for (uint8_t i=0; i < sizeof(LED_SIDE_RIGHT)/sizeof(LED_SIDE_RIGHT[0]); i++) {
                    rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_GREEN);
                }
                break;
            case _FN1:
                for (uint8_t i=0; i < sizeof(LED_SIDE_RIGHT)/sizeof(LED_SIDE_RIGHT[0]); i++) {
                    rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_RED);
                }
                rgb_matrix_set_color(LED_BSPC, RGB_RED);        // RESET
                rgb_matrix_set_color(LED_GRV,  RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_1,    RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_2,    RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_3,    RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_4,    RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_5,    RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_6,    RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_7,    RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_8,    RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_9,    RGB_PURPLE);     // RGB Mode
                rgb_matrix_set_color(LED_N,    RGB_CYAN);       // NKRO Toggle
                rgb_matrix_set_color(LED_DEL,  RGB_PURPLE);     // RGB Sat
                rgb_matrix_set_color(LED_PGUP, RGB_PURPLE);     // RGB Sat
                rgb_matrix_set_color(LED_PGDN, RGB_ORANGE);     // RGB Hue
                rgb_matrix_set_color(LED_END,  RGB_ORANGE);     // RGB Hue
                rgb_matrix_set_color(LED_F1,   RGB_BLUE);       // Layer Toggle
                rgb_matrix_set_color(LED_F2,   RGB_BLUE);       // Layer Toggle
                rgb_matrix_set_color(LED_F5,   RGB_CHARTREUSE); // Dynamic Makro
                rgb_matrix_set_color(LED_F6,   RGB_CHARTREUSE); // Dynamic Makro
                rgb_matrix_set_color(LED_F7,   RGB_CHARTREUSE); // Dynamic Makro
                rgb_matrix_set_color(LED_LGUI, RGB_SPRINGGREEN);// Toggle GUI
                rgb_matrix_set_color(LED_F10,  RGB_GOLD);       // NumLock
                rgb_matrix_set_color(LED_F11,  RGB_GOLD);       // Rolllock
                rgb_matrix_set_color(LED_F12,  RGB_GOLD);       // Capslock
                break;
            default:
                break;
        }
    }

    void suspend_power_down_user(void) {
        rgb_matrix_set_suspend_state(true);
    }

    void suspend_wakeup_init_user(void) {
        rgb_matrix_set_suspend_state(false);
    }
#endif
