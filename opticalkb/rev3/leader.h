#pragma once

#include QMK_KEYBOARD_H

bool process_leader(uint16_t keycode, keyrecord_t *record);
bool leader_map_key_sequence(void (*op)(void), uint8_t count, ...);
void leader_task(void);
