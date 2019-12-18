/* Modals key.
 *
 * Single tap: Open Death Summary
 * Double tap: Open DotaPlus overlay
 * Triple tap: Open Console
 */

enum {
    DEATH_SUMMARY = KC_EQUAL,
    OPEN_CONSOLE  = KC_BSLASH,
    OPEN_DOTAPLUS = KC_F9,
};

static tap modals_state = {.is_press_action = true, .state = 0};

void modals_finished(qk_tap_dance_state_t *state, void *user_data) {
    modals_state.state = current_dance(state);
    switch (modals_state.state) {
        case SINGLE_TAP:
            register_code(DEATH_SUMMARY);
            break;
        case DOUBLE_TAP:
            register_code(OPEN_DOTAPLUS);
            break;
        case TRIPLE_TAP:
            register_code(OPEN_CONSOLE);
            break;
    }
}

void modals_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (modals_state.state) {
        case SINGLE_TAP:
            unregister_code(DEATH_SUMMARY);
            break;
        case DOUBLE_TAP:
            unregister_code16(OPEN_DOTAPLUS);
            break;
        case TRIPLE_TAP:
            unregister_code(OPEN_CONSOLE);
            break;
    }
    modals_state.state = 0;
}
