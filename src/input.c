#include "input.h"
#include "sound.h"

void handle_input(Character *character) {
    handle_vertical(character);
    handle_horizonatal(character);
}

void handle_vertical(Character *character) {
    if (IsKeyDown(KEY_UP)) {
        handle_up(character);
    }
}

void handle_horizonatal(Character *character) {
    if (IsKeyDown(KEY_RIGHT)) {
        handle_right(character);
    } else if (IsKeyDown(KEY_LEFT)) {
        handle_left(character);
    } else {
        character->v.x = 0;
    }
}

void handle_up(Character *character) {
    if (is_on_ground(character)) {
        play_sound_jumping();
        character->v.y = -character->movement_speed * 2.0f;
    }
}

void handle_left(Character *character) {
    character->v.x = -character->movement_speed;
    if (character->box.width > 0) {
        character->box.width *= -1;
    }
}

void handle_right(Character *character) {
    character->v.x = character->movement_speed;
    if (character->box.width < 0) {
        character->box.width *= -1;
    }
}
