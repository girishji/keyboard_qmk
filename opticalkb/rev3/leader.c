#include "leader.h"

#define LEADER_PER_KEY_TIMEOUT 1000
#define LEADER_MAP_COUNT 100
#define LEADER_MAP_INVALID (LEADER_MAP_COUNT+1)

bool     leading              = false;
uint16_t leader_time          = 0;
uint16_t leader_sequence[5]   = {0, 0, 0, 0, 0};
uint8_t  leader_sequence_size = 0;
struct {
    uint8_t size;
    uint16_t keycode[LEADER_MAP_COUNT][5];
    void (*operation[LEADER_MAP_COUNT])(void);
} maps = {0, {{0}}};

void leader_start(void);
void leader_end(void);
bool leader_sequence_add(uint16_t keycode);
bool leader_sequence_active(void);
bool leader_sequence_timed_out(void);
void leader_reset_timer(void);
uint8_t full_match(void);
bool partial_match(void);

// Should be called at every iteration of main loop (not just when key press is
// detected).
void leader_task(void) {
    if (leader_sequence_active() && leader_sequence_timed_out()) {
        if (leader_sequence_size > 0) {
            uint8_t full_match_idx = full_match();
            if (full_match_idx != LEADER_MAP_INVALID) {
                (maps.operation[full_match_idx])();
            }
        }
        leader_end();
    }
}

// Returns true (let qmk process keycode further) or false.
bool process_leader(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (leader_sequence_active()) {
            if (!leader_sequence_timed_out()) {
#ifndef LEADER_KEY_STRICT_KEY_PROCESSING
                if (IS_QK_MOD_TAP(keycode)) {
                    keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
                } else if (IS_QK_LAYER_TAP(keycode)) {
                    keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
                }
#endif
                if (!leader_sequence_add(keycode)) {
                    leader_end();
                    return true;
                }
                if (!partial_match()) {
                    uint8_t full_match_idx = full_match();
                    uprintf("full_match_idx %d\n", full_match_idx);
                    if (full_match_idx != LEADER_MAP_INVALID) {  // full match
                        (maps.operation[full_match_idx])();
                        leader_end();
                        return false;
                    } else {
                        uprintf("partial match=no, full_match=no\n");
                        leader_end();
                        return true;
                    }
                } else {  // partial match
                    uprintf("partial match\n");
                    leader_reset_timer();
                    return false;
                }
            // } else {
            //     uprintf("here4\n");
            //     if (keycode == QK_LEADER) {
            //         uprintf("QK_LEADER again, timer expired\n");
            //         leader_start();
            //         return false;
            //     } else {
            //         leader_end();
            //         return true;
            //     }
            }
        } else if (keycode == QK_LEADER) {
            uprintf("QK_LEADER tapped\n");
            leader_start();
            return false;
        }
    }
    return true;
}

void leader_start(void) {
    leading              = true;
    leader_time          = timer_read();
    leader_sequence_size = 0;
    memset(leader_sequence, 0, sizeof(leader_sequence));
}

void leader_end(void) {
    leading = false;
}

bool leader_sequence_active(void) {
    return leading;
}

bool leader_sequence_add(uint16_t keycode) {
    if (leader_sequence_size >= ARRAY_SIZE(leader_sequence)) {
        return false;
    }
#if defined(LEADER_NO_TIMEOUT)
    if (leader_sequence_size == 0) {
        leader_reset_timer();
    }
#endif
    leader_sequence[leader_sequence_size] = keycode;
    leader_sequence_size++;
    return true;
}

bool leader_sequence_timed_out(void) {
    return timer_elapsed(leader_time) > LEADER_PER_KEY_TIMEOUT;
}

void leader_reset_timer(void) {
    leader_time = timer_read();
}

bool leader_map_key_sequence(void (*op)(void), uint8_t kc_count, ...) {
    if (maps.size > LEADER_MAP_COUNT || kc_count > 5) return false;
    va_list args;  // Declare a va_list to hold variable arguments
    va_start(args, kc_count);  // Initialize the argument list
    for (int i = 0; i < kc_count; i++) {
        maps.keycode[maps.size][i] = (uint16_t)va_arg(args, int);
    }
    maps.operation[maps.size] = op;
    maps.size++;
    va_end(args);  // Clean up the argument list
    return true;
}

// Return index to array where full match exists.
uint8_t full_match(void) {
    for (uint8_t i = 0; i < maps.size; i++) {
        uint16_t *kc = maps.keycode[i];
        if (leader_sequence[0] == kc[0] && leader_sequence[1] == kc[1] &&
                leader_sequence[2] == kc[2] && leader_sequence[3] == kc[3] &&
                leader_sequence[4] == kc[4]) {
            return i;
        }
    }
    return LEADER_MAP_INVALID;
}

bool partial_match(void) {
    for (int i = 0; i < maps.size; i++) {
        uint16_t *kc = maps.keycode[i];
        bool pmatch = true;
        uint8_t j;
        for (j = 0; j < 5; j++) {
            uprintf("partial match leader %X KC %X \n", leader_sequence[j], kc[j]);
            if (leader_sequence[j] != 0) {
                if (leader_sequence[j] != kc[j]) {
                    pmatch = false;
                    break;
                }
            } else {
                break;
            }
        }
        if (pmatch && j < 5 && leader_sequence[j] == 0 && kc[j] != 0) {
            return true;
        }
    }
    return false;
}
