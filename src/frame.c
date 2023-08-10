#include "frame.h"
#include "character.h"

unsigned frame_delay = 5;
unsigned frame_delay_counter = 0;
unsigned frame_index = 0;

const int frame_jump_up = 3;
const int frame_jump_down = 4;

void next_frame(Character* character) {
    if (++frame_delay_counter > frame_delay) {

        frame_delay_counter = 0;

        if (is_moving(character)) {
            if (is_on_ground(character)) {
                ++frame_index;
                frame_index %= character->frames;
            } else {
                // TODO: hardcoded sprite frames lol
                if (character->v.y < 0) {
                    frame_index = frame_jump_up;
                } else {
                    frame_index = frame_jump_down;
                }
            }
            character->box.x = (float) character->width * (float) frame_index;
        }
    }
}

unsigned int is_touching_ground_frame (void) {
    return (frame_index == 1 || frame_index == 4);
}

unsigned int is_moving (Character* character) {
    return (character->v.x == 0.0f && character->v.y == 0.0f) ? false : true;
}
