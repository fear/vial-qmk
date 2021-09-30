/* Copyright 2021 Jonavin Eng
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
 *
 *
 *  RGB LED layout ISO
 *  led number, function of the key
 *  68, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      70, Prt                Rotary(Mute)   69, Side led 12
 *  71, Side led 02    1, `~       7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       79, (=+)     86, BackSpc            73, Del        72, Side led 13
 *  74, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       90, ]}                              76, PgUp       75, Side led 14
 *  77, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"       95, #        97, Enter              87, PgDn       78, Side led 15
 *  81, Side led 05    4, Sh_L     67,\		   10, Z        16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?             		  91, Sh_R     94, Up    83, End        82, Side led 16
 *  84, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              			   33, SPACE                              49, Alt_R    55, FN       65, Ct_R                  96, Left     98, Down  80, Right      85, Side led 17
 *  88, Side led 07                                                                                                                                                                                                        		    89, Side led 18
 *  92, Side led 08                                                                                                                                                                                                                 93, Side led 19
 */

#ifdef RGB_MATRIX_ENABLE
    enum led_location_map {
        LED_ESC,        // 0
        LED_GRV,        // 1
        LED_TAB,        // 2
        LED_CAPS,       // 3
        LED_LSFT,       // 4
        LED_LCTL,       // 5
        LED_F1,         // 6
        LED_1,          // 7
        LED_Q,          // 8
        LED_A,          // 9
        LED_Z,          // 10
        LED_LGUI,       // 11
        LED_F2,         // 12
        LED_2,          // 13
        LED_W,          // 14
        LED_S,          // 15
        LED_X,          // 16
        LED_LALT,       // 17
        LED_F3,         // 18
        LED_3,          // 19
        LED_E,          // 20
        LED_D,          // 21
        LED_C,          // 22
        LED_F4,         // 23
        LED_4,          // 24
        LED_R,          // 25
        LED_F,          // 26
        LED_V,          // 27
        LED_F5,         // 28
        LED_5,          // 29
        LED_T,          // 30
        LED_G,          // 31
        LED_B,          // 32
        LED_SPCE,       // 33
        LED_F6,         // 34
        LED_6,          // 35
        LED_Y,          // 36
        LED_H,          // 37
        LED_N,          // 38
        LED_F7,         // 39
        LED_7,          // 40
        LED_U,          // 41
        LED_J,          // 42
        LED_M,          // 43
        LED_F8,         // 44
        LED_8,          // 45
        LED_I,          // 46
        LED_K,          // 47
        LED_COMM,       // 48
        LED_RALT,       // 49
        LED_F9,         // 50
        LED_9,          // 51
        LED_O,          // 52
        LED_L,          // 53
        LED_DOT,        // 54
        LED_FN,         // 55
        LED_F10,        // 56
        LED_0,          // 57
        LED_P,          // 58
        LED_SCLN,       // 59  ;:
        LED_SLSH,       // 60  /?
        LED_F11,        // 61
        LED_MINS,       // 62  -
        LED_LBRC,       // 63  [
        LED_QUOT,       // 64 "'
        LED_RCTL,       // 65
        LED_F12,        // 66
        LED_BSLS,       // 67
        LED_L1,         // 68
        LED_R1,         // 69
        LED_PSCR,       // 70
        LED_L2,         // 71
        LED_R2,         // 72
        LED_DEL,        // 73
        LED_L3,         // 74
        LED_R3,         // 75
        LED_PGUP,       // 76
        LED_L4,         // 77
        LED_R4,         // 78
        LED_EQL,        // 79
        LED_RIGHT,      // 80
        LED_L5,         // 81
        LED_R5,         // 82
        LED_END,        // 83
        LED_L6,         // 84
        LED_R6,         // 85
        LED_BSPC,       // 86
        LED_PGDN,       // 87
        LED_L7,         // 88
        LED_R7,         // 89
        LED_RBRC,       // 90
        LED_RSFT,       // 91
        LED_L8,         // 92
        LED_R8,         // 93
        LED_UP,         // 94
        LED_HASH,       // 95
        LED_LEFT,       // 96
        LED_ENT,        // 97
        LED_DOWN,       // 98
    };

    const uint8_t LED_LIST_WASD[] = { LED_W, LED_A, LED_S, LED_D };

    const uint8_t LED_LIST_ARROWS[] = { LED_LEFT, LED_RIGHT, LED_UP, LED_DOWN };

    const uint8_t LED_LIST_FUNCROW[] = { LED_ESC, LED_F1, LED_F2, LED_F3, LED_F4, LED_F5, LED_F6, LED_F7, LED_F8, LED_F9, LED_F10, LED_F11, LED_F12, LED_PSCR };

    const uint8_t LED_LIST_NUMROW[] = { LED_GRV, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_0, LED_MINS, LED_EQL, LED_BSPC, LED_DEL };

    const uint8_t LED_LIST_NUMPAD[] = { LED_7, LED_8, LED_9, LED_U, LED_I, LED_O, LED_J, LED_K, LED_L, LED_M, LED_COMM, LED_DOT };

    const uint8_t LED_SIDE_LEFT[] = { LED_L1, LED_L2, LED_L3, LED_L4, LED_L5, LED_L6, LED_L7, LED_L8 };

    const uint8_t LED_SIDE_RIGHT[] = { LED_R1, LED_R2, LED_R3, LED_R4, LED_R5, LED_R6, LED_R7, LED_R8 };

    const uint8_t LED_SIDE[] = { LED_L1, LED_L2, LED_L3, LED_L4, LED_L5, LED_L6, LED_L7, LED_L8, LED_R1, LED_R2, LED_R3, LED_R4, LED_R5, LED_R6, LED_R7, LED_R8 };

    const uint8_t LED_ALL[] = {
        LED_ESC,
        LED_GRV,
        LED_TAB,
        LED_CAPS,
        LED_LSFT,
        LED_LCTL,
        LED_F1,
        LED_1,
        LED_Q,
        LED_A,
        LED_Z,
        LED_LGUI,
        LED_F2,
        LED_2,
        LED_W,
        LED_S,
        LED_X,
        LED_LALT,
        LED_F3,
        LED_3,
        LED_E,
        LED_D,
        LED_C,
        LED_F4,
        LED_4,
        LED_R,
        LED_F,
        LED_V,
        LED_F5,
        LED_5,
        LED_T,
        LED_G,
        LED_B,
        LED_SPCE,
        LED_F6,
        LED_6,
        LED_Y,
        LED_H,
        LED_N,
        LED_F7,
        LED_7,
        LED_U,
        LED_J,
        LED_M,
        LED_F8,
        LED_8,
        LED_I,
        LED_K,
        LED_COMM,
        LED_RALT,
        LED_F9,
        LED_9,
        LED_O,
        LED_L,
        LED_DOT,
        LED_FN,
        LED_F10,
        LED_0,
        LED_P,
        LED_SCLN,
        LED_SLSH,
        LED_F11,
        LED_MINS,
        LED_LBRC,
        LED_QUOT,
        LED_RCTL,
        LED_F12,
        LED_BSLS,
        LED_L1,
        LED_R1,
        LED_PSCR,
        LED_L2,
        LED_R2,
        LED_DEL,
        LED_L3,
        LED_R3,
        LED_PGUP,
        LED_L4,
        LED_R4,
        LED_EQL,
        LED_RIGHT,
        LED_L5,
        LED_R5,
        LED_END,
        LED_L6,
        LED_R6,
        LED_BSPC,
        LED_PGDN,
        LED_L7,
        LED_R7,
        LED_RBRC,
        LED_RSFT,
        LED_L8,
        LED_R8,
        LED_UP,
        LED_HASH,
        LED_LEFT,
        LED_ENT,
        LED_DOWN
    };
#endif
