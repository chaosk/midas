#include "quantum.h"

#define TH(n) (QK_TAP_HOLD_EXPIRE | ((n)&0xFF))

typedef struct {
    uint16_t timer;
} tap_hold_expire_state_t;

typedef struct {
    uint16_t tap_keycode;
    uint16_t hold_keycode;
    tap_hold_expire_state_t state;
    uint16_t custom_tapping_term;
} tap_hold_expire_action_t;

#define ACTION_TAP_HOLD_EXPIRE(kc1, kc2) \
        { .tap_keycode = kc1, .hold_keycode = kc2 }

#define ACTION_TAP_HOLD_EXPIRE_TIME(kc1, kc2, tapping_term) \
        { .tap_keycode = kc1, .hold_keycode = kc2, .custom_tapping_term = tapping_term }

extern tap_hold_expire_action_t tap_hold_expire_actions[];

void process_tap_hold_expire_action(tap_hold_expire_action_t *action, bool pressed);
bool process_tap_hold_expire(uint16_t keycode, keyrecord_t *record);
void matrix_scan_tap_hold_expire(void);
