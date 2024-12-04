#include QMK_KEYBOARD_H
// #include "print.h" // just commented out to speed up debugging

enum sofle_layers {
    _BASE,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD
};

#define SCRSHT C(S(G(KC_4)))
#define OSM_RCTRL OSM(MOD_RCTL)
#define OSM_LCTRL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_RGUI OSM(MOD_RGUI)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)
#define OSM_MEH OSM(MOD_MEH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// [_TEMPLATE] = LAYOUT(
//   _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
//   _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
//   _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
//   _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
//                       _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______  ,_______
// ),

[_BASE] = LAYOUT(
  _______ ,KC_1, KC_2 ,KC_3 ,KC_4 ,KC_5  ,                        KC_6  ,KC_7 ,KC_8   ,KC_9  ,KC_0   ,_______     ,
  KC_ESC  ,KC_Q, KC_W ,KC_E ,KC_R ,KC_T  ,                        KC_Y  ,KC_U ,KC_I   ,KC_O  ,KC_P   ,KC_EQL ,
  KC_TAB  ,KC_A, KC_S ,KC_D ,KC_F ,KC_G  ,                        KC_H  ,KC_J ,KC_K   ,KC_L  ,KC_SCLN,KC_QUOT,
  KC_GRV  ,KC_Z, KC_X ,KC_C ,KC_V ,KC_B  ,TG(_GAME)  ,XXXXXXX    ,KC_N  ,KC_M ,KC_COMM,KC_DOT,KC_SLSH,KC_BSLS,
                      OSM_MEH  ,OSL(_LOWER),OSM_LSFT  ,KC_SPC,OSL(_LOWER),_______    ,KC_ENT,OSM_RALT  ,OSL(_RAISE) ,_______
),

// needs be before LOWER and RAISE to make them work also on this laer
[_GAME] = LAYOUT(
  KC_ESC   ,KC_1   , KC_2    ,KC_3     ,KC_4     ,KC_5     ,                         KC_6   ,KC_7    ,KC_8     ,KC_9  ,KC_0    ,KC_MINS,
  KC_TAB   ,KC_Q   , KC_W    ,KC_E     ,KC_R     ,KC_T     ,                         KC_Y   ,KC_U    ,KC_I     ,KC_O  ,KC_P    ,KC_EQL ,
  KC_LSFT  ,KC_A   , KC_S    ,KC_D     ,KC_F     ,KC_G     ,                         KC_H   ,KC_J    ,KC_K     ,KC_L  ,KC_SCLN ,KC_QUOT,
  KC_ENT   ,KC_Z   , KC_X    ,KC_C     ,KC_V     ,KC_B     , TG(_GAME) , XXXXXXX   , KC_N   ,KC_M    ,KC_COMM  ,KC_DOT,KC_SLSH ,KC_BSLS,
                     KC_LCTL ,KC_LALT  ,KC_LSFT  ,KC_SPC   , MO(_LOWER), MO(_RAISE), KC_ENT ,KC_RALT ,KC_RCTL  ,KC_RGUI
),

[_LOWER] = LAYOUT(
  QK_BOOT ,KC_F1       ,KC_F2       ,KC_F3       ,KC_F4       ,KC_F5       ,                  KC_F6       ,KC_F7       ,KC_F8       ,KC_F9       ,KC_F10      ,KC_F11       ,
  SCRSHT  ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                  KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_EQL  ,
  KC_BSPC ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                  KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_MINS  ,
  _______ ,KC_LBRC ,KC_RBRC ,KC_ENT  ,KC_LCBR ,KC_RCBR ,_______ ,_______ ,_______     ,_______     ,_______     ,_______     ,KC_BSLS     ,KC_F12       ,
                         _______    ,_______     ,_______     ,KC_PMNS     ,_______ ,_______ ,_______     ,_______     ,_______     ,_______
),

 [_RAISE] = LAYOUT(
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    _______  ,_______  ,_______  ,_______  ,_______  ,QK_BOOT  ,
  _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,                    KC_TAB   ,KC_BSPC , _______ , _______  ,KC_DEL   ,_______  ,
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
),

[_NUMPAD] = LAYOUT(
  _______  ,_______  ,_______ ,_______ ,_______ ,_______ ,                    _______  ,_______  ,_______  ,_______  ,_______  ,_______  ,
  _______  ,_______  ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,                    KC_PAST  ,KC_7     ,KC_8     ,KC_9     ,KC_PPLS  ,_______  ,
  _______  ,KC_BSPC  ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,                    KC_PSLS  ,KC_4     ,KC_5     ,KC_6     ,KC_PMNS  ,_______  ,
  _______  ,_______  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F12  ,_______  ,_______  ,KC_BSPC  ,KC_1     ,KC_2     ,KC_3     ,KC_PDOT  ,KC_COMM  ,
                      _______ ,_______ ,_______ ,KC_PMNS ,_______  ,_______  ,_______  ,KC_0     ,_______  ,_______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// home row combos
const uint16_t PROGMEM combo_df[] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_sf[] = { KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_af[] = { KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM combo_jk[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_jl[] = { KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_jscln[] = { KC_J, KC_SCLN, COMBO_END};

// making outside rows redundant
const uint16_t PROGMEM combo_qw[] = { KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_as[] = { KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_zx[] = { KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_op[] = { KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_lscln[] = { KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_dotslsh[] = { KC_DOT, KC_SLSH, COMBO_END};

// layers
const uint16_t PROGMEM combo_lower_right[] = { KC_J, OSM_RALT, COMBO_END};
const uint16_t PROGMEM combo_numpad_l[] = { KC_D, OSL(_LOWER), COMBO_END};
const uint16_t PROGMEM combo_numpad_r[] = { KC_K, OSL(_RAISE), COMBO_END};
const uint16_t PROGMEM combo_meh[] = { KC_F, OSM_LSFT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_df, OSM_LGUI),
    COMBO(combo_sf, OSM_LALT),
    COMBO(combo_af, OSM_LCTRL),
    COMBO(combo_jk, OSM_RGUI),
    COMBO(combo_jl, OSM_LALT),
    COMBO(combo_jscln, OSM_RCTRL),

    COMBO(combo_qw, KC_ESC),
    COMBO(combo_as, KC_TAB),
    COMBO(combo_zx, KC_GRV),
    COMBO(combo_op, KC_EQL),
    COMBO(combo_lscln, KC_QUOT),
    COMBO(combo_dotslsh, KC_BSLS),

    COMBO(combo_lower_right, OSL(_LOWER)),
    COMBO(combo_numpad_l, MO(_NUMPAD)),
    COMBO(combo_numpad_r, MO(_NUMPAD)),
    COMBO(combo_meh, OSM_MEH),
};

void keyboard_post_init_user(void) {
  //uprintf("%s string", var);
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
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _LOWER:
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
