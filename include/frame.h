#ifndef FRAME_INCLUDED
#define FRAME_INCLUDED

#include "character.h"

extern unsigned frame_delay;
extern unsigned frame_delay_counter;
extern unsigned frame_index;

extern const int frame_jump_up;
extern const int frame_jump_down;

void next_frame(Character *character);

unsigned int is_touching_ground_frame(void);

unsigned int is_moving(Character *character);

#endif
