/* Escape key.
 *
 * Single tap: Escape key
 * Single hold: Scoreboard
 * Double tap: Pause
 */

enum {
    ESCAPE     = KC_ESC,
    SCOREBOARD = KC_GRAVE,
    PAUSE      = KC_F7,
};

static tap escape_state = {.is_press_action = true, .state = 0};

void escape_finished(qk_tap_dance_state_t *state, void *user_data) {
    escape_state.state = current_dance(state);
    switch (escape_state.state) {
        case SINGLE_TAP:
            register_code(ESCAPE);
            break;
        case SINGLE_HOLD:
            register_code16(SCOREBOARD);
            break;
        case DOUBLE_TAP:
            register_code(PAUSE);
            break;
    }
}

void escape_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (escape_state.state) {
        case SINGLE_TAP:
            unregister_code(ESCAPE);
            break;
        case SINGLE_HOLD:
            unregister_code16(SCOREBOARD);
            break;
        case DOUBLE_TAP:
            unregister_code(PAUSE);
            break;
    }
    escape_state.state = 0;
}
