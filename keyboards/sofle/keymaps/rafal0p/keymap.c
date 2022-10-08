#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_LOWER = SAFE_RANGE,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// [_TEMPLATE] = LAYOUT(
//   _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
//   _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
//   _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
//   _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
//                       _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______                       
// ),

[_BASE] = LAYOUT(
  KC_ESC  ,KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5                ,                     KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_MINS  ,
  KC_TAB  ,KC_Q     ,KC_W     ,KC_E     ,KC_R     ,KC_T                ,                     KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P     ,KC_EQL   ,
  KC_BSPC ,KC_A     ,KC_S     ,KC_D     ,KC_F     ,KC_G                ,                     KC_H     ,KC_J     ,KC_K     ,KC_L     ,KC_SCLN  ,KC_QUOT  ,
  KC_LSFT ,KC_Z     ,KC_X     ,KC_C     ,KC_V     ,KC_B                ,KC_MUTE   ,XXXXXXX  ,KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,KC_SLSH  ,KC_GRV   ,
                     KC_LGUI  ,KC_LALT  ,KC_LCTRL ,MT(MOD_LSFT,KC_SPC) ,KC_LOWER  ,KC_RCTRL ,KC_ENT   ,KC_RALT  ,KC_RAISE ,KC_RGUI                       
),

[_LOWER] = LAYOUT(
  QK_BOOT  ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,                    KC_F6    ,KC_F7    ,KC_F8    ,KC_F9    ,KC_F10   ,KC_F11   ,
  _______  ,KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,                    KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_F12   ,
  _______  ,KC_EXLM  ,KC_AT    ,KC_HASH  ,KC_DLR   ,KC_PERC  ,                    KC_CIRC  ,KC_AMPR  ,KC_ASTR  ,KC_LPRN  ,KC_RPRN  ,KC_PIPE  ,
  _______  ,_______  ,KC_LBRC  ,KC_RBRC  ,KC_LCBR  ,KC_RCBR  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
                      _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______                       
),

 [_RAISE] = LAYOUT(
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,QK_BOOT  ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,KC_RSFT  ,KC_RALT  ,KC_RCTRL ,KC_RGUI  ,_______  ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    KC_BSPC  ,KC_LEFT  ,KC_DOWN  ,KC_UP    ,KC_RGHT  ,KC_DEL   ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,KC_LSTRT ,KC_PGDN  ,KC_PGUP  ,KC_LEND  ,_______  ,
                      _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______                       
),

[_ADJUST] = LAYOUT(
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,KC_VOLD  ,KC_MUTE  ,KC_VOLU  ,_______  ,_______  ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,KC_MPRV  ,KC_MPLY  ,KC_MNXT  ,_______  ,_______  ,
                      _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______                       
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
