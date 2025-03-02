/* Copyright 2023 Brian Low
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
 */
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
  };

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    RGBRST,
    KC_ENT_RAISE,
    KC_D_MUTE,
    KC_ENC0,
    KC_ENC1,
  };

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// /*
//  * QWERTY
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
//  * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
//  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *            | LCTL | LGUI | LCMD | LALT | /Enter  /       \Space \  | RALT | RCMD | RGUI | RCTL |
//  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
//  *            `----------------------------------'           '------''---------------------------'
//  */
// 
// LAYOUT(
//     KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV,
//     KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
//     KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//     KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY,KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
//                       KC_LCTL, KC_LGUI, KC_LCMD, KC_LALT, KC_ENT,    KC_SPC, KC_RALT,  KC_RCMD,  KC_RGUI, KC_RCTL
// )
// };



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------.                ,---------------------------------------------.
      KC_NO,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,   KC_8,  KC_9,   KC_0,   KC_NO,
  //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
     KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_BSPC,
  //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
     LCTL_T(KC_ESC),
            KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                    KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN,KC_QUOT,
  //|------+------+------+------+------+------+------|  |------+------+------+-------+------+-------+--------|
    SC_LSPO,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,KC_ENC0, LT(0, KC_ENC1),
                                                                  KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,SC_RSPC,
  //|------+------+------+------+------+------+------|  |------+------+------+-------+------+-------+--------|
                   KC_NO, KC_NO,KC_LGUI,
                                        LALT_T(KC_SPC),
                                               KC_ENT,   KC_SPC,LT(0, KC_ENT_RAISE),
                                                                       LOWER, KC_NO, KC_NO
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT(
    //,-----------------------------------------.                ,---------------------------------------------.
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
       KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,   KC_8,  KC_9,   KC_0,  KC_DEL,
    //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
      KC_TRNS,KC_NO,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,             KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_NO,   KC_NO,
    //|------+------+------+------+------+------+------|  |------+------+------+-------+------+-------+--------|
      KC_TRNS, KC_NO,KC_BTN2,KC_WH_D,KC_WH_U,KC_BTN1,KC_TRNS, KC_TRNS,KC_HOME,KC_PGDN,KC_PGUP,KC_END,KC_NO, KC_TRNS,
    //|------+------+------+------+------+------+------|  |------+------+------+-------+------+-------+--------|
                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
                                //`--------------------'  `--------------------'
    ),

  [_RAISE] = LAYOUT(
      //,-----------------------------------------.                ,---------------------------------------------.
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
        KC_NUBS,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,              KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,
      //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
        KC_TRNS,KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_MINS,KC_EQL,KC_LCBR,KC_RCBR,KC_PIPE,KC_GRV,
      //|------+------+------+------+------+------+------|  |------+------+------+-------+------+-------+--------|
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9,KC_F10,KC_TRNS, KC_TRNS,KC_UNDS,KC_PLUS,KC_LBRC,KC_RBRC,KC_BSLS,KC_TRNS,
      //|------+------+------+------+------+------+------|  |------+------+------+-------+------+-------+--------|
                    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
                                  //`--------------------'  `--------------------'
      ),

  [_ADJUST] = LAYOUT(
      //,-----------------------------------------.                ,---------------------------------------------.
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,           KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
      //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
        QK_BOOT,RGBRST, KC_NO, KC_NO, KC_NO, KC_NO,                KC_MPLY,KC_MUTE,KC_NO, KC_NO, KC_NO, KC_NO,
      //|------+------+------+------+------+------|                |------+------+-------+------+-------+--------|
        RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,RGB_SPI,KC_NO,               KC_PAUSE,KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO,
      //|------+------+------+------+------+------+------|  |------+------+------+-------+------+-------+--------|
      RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,RGB_SPD,KC_NO,KC_TRNS, KC_TRNS,KC_SCRL,KC_VOLD, KC_NO, KC_NO, KC_NO, RGB_RMOD,
      //|------+------+------+------+------+------+------|  |------+------+------+-------+------+-------+--------|
                    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
                                  //`--------------------'  `--------------------'
    ),
};
#ifdef ENCODER_ENABLE

enum encoder_layer {
    _ENC_MEDIA = 0, // Volume up/down, mute. Next/previous, play/pause (tap), encoder layer (hold)
    _ENC_DIR,       // Arrow up/down, HOME. Arrow left/right, END (tap), encoder layer (hold)
    _ENC_FDIR,      // Arrow pageup/pagedown, HOME. Arrow left/right, END (tap), encoder layer (hold)
    __ENC_MAX       // Used to easily spot layer overflow
};

static uint8_t encoder_layer_state = _ENC_MEDIA;

// Dimensions are [Encoder layer][Encoder ID][click (0), clockwise (1), counterclockwise (2)]
const uint16_t PROGMEM enc_keymaps[][NUM_ENCODERS][3] = {
    [_ENC_MEDIA] = {{KC_MUTE,  KC_VOLU, KC_VOLD},   {KC_MPLY, KC_MNXT, KC_MPRV}},
    [_ENC_DIR]   = {{KC_HOME, KC_RIGHT, KC_LEFT},   {KC_END,  KC_DOWN, KC_UP}},
    [_ENC_FDIR]  = {{KC_HOME, KC_RIGHT, KC_LEFT},   {KC_END,  KC_PGDN, KC_PGUP}},
}; 

static void encoder_layer_rot(void) {
    encoder_layer_state += 1;
    if (encoder_layer_state == __ENC_MAX) {
        encoder_layer_state = 0;
    }
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(enc_keymaps[encoder_layer_state][index][1]);
    } else {
        tap_code(enc_keymaps[encoder_layer_state][index][2]);
    }
    return true;
}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_ln_P(PSTR("F.G.\n"), false);

    oled_write_P(PSTR("\n\n\n"), false);

    // Print current encoder layer
    oled_write_ln_P(PSTR("E.LAY"), false);
    switch (encoder_layer_state) {
        case _ENC_MEDIA:
            oled_write_P(PSTR("Media"), false);
            break;
        case _ENC_DIR:
            oled_write_P(PSTR("Dir\n"), false);
            break;
        case _ENC_FDIR:
            oled_write_P(PSTR("FDir\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current keyboard layer
    oled_write_ln_P(PSTR("K.LAY"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif


// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
      layer_on(layer3);
    } else {
      layer_off(layer3);
    }
  }

  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LOWER:
        if (record->event.pressed) {
          layer_on(_LOWER);
          update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        } else {
          layer_off(_LOWER);
          update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        }
        return false;
      case RAISE:
        if (record->event.pressed) {
          layer_on(_RAISE);
          update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        } else {
          layer_off(_RAISE);
          update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
        }
        return false;
      case ADJUST:
          if (record->event.pressed) {
            layer_on(_ADJUST);
          } else {
            layer_off(_ADJUST);
          }
          return false;
      case LT(0, KC_ENT_RAISE):
          if (record->tap.count && record->event.pressed) {
              tap_code(KC_ENT); // TAP Enter // tap
          } else if (record->event.pressed) {
              layer_on(_RAISE);  // Activate layer // hold
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else if (!record->tap.count) {
              layer_off(_RAISE); // De-activate layer // de-hold
              update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
      case KC_ENC0:
          if (record->event.pressed) {
              tap_code16(enc_keymaps[encoder_layer_state][0][0]); // click for encoder 0, depends on layer
          }
          return false;
      case LT(0, KC_ENC1):
          if (record->tap.count && record->event.pressed) {
              tap_code16(enc_keymaps[encoder_layer_state][1][0]); // click for encoder 1, depends on layer // tap
          } else if (record->event.pressed) {
              encoder_layer_rot(); // Rotate layer // hold
          }
          return false;
      case RGBRST:
        #ifdef RGBLIGHT_ENABLE
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        #endif
        #ifdef RGB_MATRIX_ENABLE
          if (record->event.pressed) {
            eeconfig_update_rgb_matrix_default();
            rgb_matrix_enable();
          }
        #endif
        break;
    }
    return true;
  }

  uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_ENC1):
            return TAPPING_TERM*2;
        default:
            return TAPPING_TERM;
    }
}