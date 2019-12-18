/* Provides tap-hold-expire functionality.
 *
 * When THE key is tapped, a keycode is sent upon release.
 * When THE key is held, a different keycode is sent
 * when the press duration reaches TAPPING_TERM (and not upon release).
 */
#include "tap_hold_expire.h"
#include "custom_keycodes.h"

static int8_t tap_hold_highest_action = -1;

void process_tap_hold_expire_action(tap_hold_expire_action_t *action, bool pressed) {
    if (pressed) {
        action->state.timer = timer_read();
    } else {
        if (timer_elapsed(action->state.timer) < TAPPING_TERM) {
            tap_code16(action->tap_keycode);
        }
        action->state.timer = 0;
    }
};

bool process_tap_hold_expire(uint16_t keycode, keyrecord_t *record) {
    uint16_t                  idx = keycode - QK_TAP_HOLD_EXPIRE;
    tap_hold_expire_action_t *action;

    switch (keycode) {
        case QK_TAP_HOLD_EXPIRE ... QK_TAP_HOLD_EXPIRE_MAX:
            if ((int16_t)idx > tap_hold_highest_action) tap_hold_highest_action = idx;
            action = &tap_hold_expire_actions[idx];
            process_tap_hold_expire_action(action, record->event.pressed);
            return false;
    };
    return true;
};

void matrix_scan_tap_hold_expire(void) {
    tap_hold_expire_action_t *action;

    for (int i = 0; i <= tap_hold_highest_action; i++) {
        action = &tap_hold_expire_actions[i];
        if (action->state.timer && timer_elapsed(action->state.timer) >= TAPPING_TERM) {
            tap_code16(action->hold_keycode);
            action->state.timer = 0;
        }
    }
};
