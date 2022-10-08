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

enum tap_dance_codes {
    DNC_Z,
    DNC_X,
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
  KC_LSFT ,TD(DNC_Z),TD(DNC_X),KC_C     ,KC_V     ,KC_B                ,KC_MUTE   ,XXXXXXX  ,KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,KC_SLSH  ,KC_GRV   ,
                     KC_LCTRL ,KC_LGUI  ,KC_LALT  ,MT(MOD_LSFT,KC_SPC) ,KC_LOWER  ,KC_RCTRL ,KC_ENT   ,KC_RALT  ,KC_RAISE ,KC_RGUI                       
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
    }
    return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

void on_dance_z(qk_tap_dance_state_t *state, void *user_data);
void dance_z_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_z_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_z(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Z);
        tap_code16(KC_Z);
        tap_code16(KC_Z);
    }
    if(state->count > 3) {
        tap_code16(KC_Z);
    }
}

void dance_z_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_Z); break;
        case DOUBLE_TAP: register_code16(KC_Z); register_code16(KC_Z); break;
        case DOUBLE_HOLD: register_code16(LGUI(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Z); register_code16(KC_Z);
    }
}

void dance_z_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_Z); break;
        case DOUBLE_TAP: unregister_code16(KC_Z); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(KC_Z)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Z); break;
    }
    dance_state[0].step = 0;
}

void on_dance_x(qk_tap_dance_state_t *state, void *user_data);
void dance_x_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_x_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_x(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_X);
        tap_code16(KC_X);
        tap_code16(KC_Z);
    }
    if(state->count > 3) {
        tap_code16(KC_X);
    }
}

void dance_x_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_X); break;
        case DOUBLE_TAP: register_code16(KC_X); register_code16(KC_X); break;
        case DOUBLE_HOLD: register_code16(LGUI(KC_X)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_X); register_code16(KC_X);
    }
}

void dance_x_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_X); break;
        case DOUBLE_TAP: unregister_code16(KC_X); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(KC_X)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_X); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DNC_Z] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_z, dance_z_finished, dance_z_reset),
    [DNC_X] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_x, dance_x_finished, dance_x_reset),
};

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
            tap_code16(LSG(KC_Z));
        } else {
            tap_code16(G(KC_Z));
        }
    }
    return true;
}

#endif
