#include QMK_KEYBOARD_H
// #include "print.h"

#define ACTION_TAP_DANCE_FN_ADVANCED_USER(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, user_user_data) \
    { .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void *)user_user_data, }

enum sofle_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_LOWER = SAFE_RANGE,
    KC_RAISE,
    KC_ADJUST
};

enum tap_dance_codes {
    DNC_1, DNC_2 ,DNC_3 , DNC_4 ,DNC_5           ,DNC_6 ,DNC_7 ,DNC_8   ,DNC_9  ,DNC_0   ,DNC_MINS,
    DNC_Q, DNC_W ,DNC_E , DNC_R ,DNC_T           ,DNC_Y ,DNC_U ,DNC_I   ,DNC_O  ,DNC_P   ,DNC_EQL ,
    DNC_A, DNC_S ,DNC_D , DNC_F ,DNC_G           ,DNC_H ,DNC_J ,DNC_K   ,DNC_L  ,DNC_SCLN,DNC_QUOT,
    DNC_Z, DNC_X ,DNC_C , DNC_V ,DNC_B           ,DNC_N ,DNC_M ,DNC_COMM,DNC_DOT,DNC_SLSH,DNC_BSLS,
    DNC_SPC, DNC_ENT
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
  KC_ESC  ,TD(DNC_1), TD(DNC_2) ,TD(DNC_3) ,TD(DNC_4) ,TD(DNC_5)  ,                     TD(DNC_6)  ,TD(DNC_7) ,TD(DNC_8)   ,TD(DNC_9)  ,TD(DNC_0)   ,TD(DNC_MINS),
  KC_TAB  ,TD(DNC_Q), TD(DNC_W) ,TD(DNC_E) ,TD(DNC_R) ,TD(DNC_T)  ,                     TD(DNC_Y)  ,TD(DNC_U) ,TD(DNC_I)   ,TD(DNC_O)  ,TD(DNC_P)   ,TD(DNC_EQL) ,
  KC_BSPC ,TD(DNC_A), TD(DNC_S) ,TD(DNC_D) ,TD(DNC_F) ,TD(DNC_G)  ,                     TD(DNC_H)  ,TD(DNC_J) ,TD(DNC_K)   ,TD(DNC_L)  ,TD(DNC_SCLN),TD(DNC_QUOT),
  KC_GRV  ,TD(DNC_Z), TD(DNC_X) ,TD(DNC_C) ,TD(DNC_V) ,TD(DNC_B)  ,KC_MUTE   ,XXXXXXX  ,TD(DNC_N)  ,TD(DNC_M) ,TD(DNC_COMM),TD(DNC_DOT),TD(DNC_SLSH),TD(DNC_BSLS),
                      KC_LCTRL  ,KC_LALT   ,KC_LSFT   ,TD(DNC_SPC),KC_LOWER  ,KC_RAISE ,TD(DNC_ENT),KC_RALT   ,KC_RAISE    ,KC_RGUI                               
),

// C(S(G(KC_4))) - macos screenshot
[_LOWER] = LAYOUT(
  QK_BOOT      ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,                    KC_F6    ,KC_F7    ,KC_F8    ,KC_F9    ,KC_F10   ,KC_F11   ,
  C(S(G(KC_4))),KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,                    KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_F12   ,
  _______      ,KC_EXLM  ,KC_AT    ,KC_HASH  ,KC_DLR   ,KC_PERC  ,                    KC_CIRC  ,KC_AMPR  ,KC_ASTR  ,KC_LPRN  ,KC_RPRN  ,_______  ,
  KC_ENT       ,KC_ENT   ,KC_LBRC  ,KC_RBRC  ,KC_LCBR  ,KC_RCBR  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
                          _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______                       
),

 [_RAISE] = LAYOUT(
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,QK_BOOT  ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    KC_TAB   ,KC_RSFT  ,KC_RALT  ,KC_RCTRL ,KC_RGUI  ,_______  ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    KC_BSPC  ,KC_LEFT  ,KC_DOWN  ,KC_UP    ,KC_RGHT  ,KC_DEL   ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,C(KC_A)  ,KC_PGDN  ,KC_PGUP  ,C(KC_E)  ,_______  ,
                      _______  ,_______  ,_______  ,KC_UNDS  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______                       
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

// 69 = KC_F12, nobody should ever need to dance higher
static tap dance_state[69];

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

void on_dance(qk_tap_dance_state_t *state, void *user_data);
void dance_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = (uint16_t)user_data;

    if(state->count == 3) {
        tap_code16(keycode);
        tap_code16(keycode);
        tap_code16(keycode);
    }
    if(state->count > 3) {
        tap_code16(keycode);
    }
}

void dance_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = (uint16_t)user_data;
    
    dance_state[keycode].step = dance_step(state);
    switch (dance_state[keycode].step) {
        case SINGLE_TAP: register_code16(keycode); break;
        case DOUBLE_TAP: register_code16(keycode); register_code16(keycode); break;
        case DOUBLE_HOLD: register_code16(LGUI(keycode)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(keycode); register_code16(keycode);
    }
}

void dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = (uint16_t)user_data;

    wait_ms(10);
    switch (dance_state[keycode].step) {
        case SINGLE_TAP: unregister_code16(keycode); break;
        case DOUBLE_TAP: unregister_code16(keycode); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(keycode)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(keycode); break;
    }
    dance_state[keycode].step = 0;
}

void dance_spc_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = (uint16_t)user_data;
    
    dance_state[keycode].step = dance_step(state);
    switch (dance_state[keycode].step) {
        case SINGLE_TAP: register_code16(keycode); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(keycode); register_code16(keycode); break;
        case DOUBLE_HOLD: register_code16(LGUI(keycode)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(keycode); register_code16(keycode);
    }
}

void dance_spc_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = (uint16_t)user_data;

    wait_ms(10);
    switch (dance_state[keycode].step) {
        case SINGLE_TAP: unregister_code16(keycode); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(keycode); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(keycode)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(keycode); break;
    }
    dance_state[keycode].step = 0;
}

void dance_ent_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = (uint16_t)user_data;
    
    dance_state[keycode].step = dance_step(state);
    switch (dance_state[keycode].step) {
        case SINGLE_TAP: register_code16(keycode); break;
        case SINGLE_HOLD: register_code16(KC_RSFT); break;
        case DOUBLE_TAP: register_code16(keycode); register_code16(keycode); break;
        case DOUBLE_HOLD: register_code16(RGUI(keycode)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(keycode); register_code16(keycode);
    }
}

void dance_ent_reset(qk_tap_dance_state_t *state, void *user_data) {
    uint16_t keycode = (uint16_t)user_data;

    wait_ms(10);
    switch (dance_state[keycode].step) {
        case SINGLE_TAP: unregister_code16(keycode); break;
        case SINGLE_HOLD: unregister_code16(KC_RSFT); break;
        case DOUBLE_TAP: unregister_code16(keycode); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(keycode)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(keycode); break;
    }
    dance_state[keycode].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DNC_1] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_1),
    [DNC_2] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_2),
    [DNC_3] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_3),
    [DNC_4] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_4),
    [DNC_5] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_5),
    [DNC_6] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_6),
    [DNC_7] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_7),
    [DNC_8] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_8),
    [DNC_9] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_9),
    [DNC_0] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_0),
    [DNC_MINS] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_MINS),
    [DNC_Q] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_Q),
    [DNC_W] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_W),
    [DNC_E] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_E),
    [DNC_R] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_R),
    [DNC_T] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_T),
    [DNC_Y] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_Y),
    [DNC_U] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_U),
    [DNC_I] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_I),
    [DNC_O] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_O),
    [DNC_P] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_P),
    [DNC_EQL] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_EQL),
    [DNC_A] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_A),
    [DNC_S] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_S),
    [DNC_D] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_D),
    [DNC_F] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_F),
    [DNC_G] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_G),
    [DNC_H] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_H),
    [DNC_J] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_J),
    [DNC_K] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_K),
    [DNC_L] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_L),
    [DNC_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_SCLN),
    [DNC_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_QUOT),
    [DNC_Z] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_Z),
    [DNC_X] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_X),
    [DNC_C] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_C),
    [DNC_V] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_V),
    [DNC_B] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_B),
    [DNC_N] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_N),
    [DNC_M] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_M),
    [DNC_COMM] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_COMM),
    [DNC_DOT] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_DOT),
    [DNC_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_SLSH),
    [DNC_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_finished, dance_reset, KC_BSLS),
    [DNC_SPC] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_spc_finished, dance_spc_reset, KC_SPC),
    [DNC_ENT] = ACTION_TAP_DANCE_FN_ADVANCED_USER(on_dance, dance_ent_finished, dance_ent_reset, KC_ENT),
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
        switch (get_highest_layer(layer_state)) {
            case _LOWER:
                if (clockwise) {
                    tap_code16(LCTL(KC_TAB));
                } else {
                    tap_code16(LCTL(LSFT(KC_TAB)));
                }
            default:
                if (clockwise) {
                    tap_code16(KC_TAB);
                } else {
                    tap_code16(LSFT(KC_TAB));
                }
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _RAISE:
                if (clockwise) {
                    tap_code16(LSG(KC_Z));
                } else {
                    tap_code16(LGUI(KC_Z));
                }
                break;
            default:
                if (clockwise) {
                    tap_code16(LGUI(KC_RIGHT_BRACKET));
                } else {
                    tap_code16(LGUI(KC_LEFT_BRACKET));
                }
        }
    }
    return true;
}

#endif
