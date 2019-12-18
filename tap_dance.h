#include "quantum.h"

typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    DOUBLE_TAP        = 3,
    DOUBLE_HOLD       = 4,
    DOUBLE_SINGLE_TAP = 5,  // Send two single taps.
    TRIPLE_TAP        = 6,
    TRIPLE_HOLD       = 7,
    TRIPLE_SINGLE_TAP = 8  // Send three single taps.
};

int current_dance(qk_tap_dance_state_t *state);
