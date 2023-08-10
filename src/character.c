#include <stdlib.h>

#include "character.h"
#include "world.h"

bool is_on_ground(Character *character) {
    return character->pos.y + (float) character->height >= ground_position;
}

Character *init_character(char *texture_location, int frames, float gravity) {

    Character *character = (Character *) malloc(sizeof(Character));

    character->texture = LoadTexture(texture_location);
    character->frames = frames;

    character->width = character->texture.width / frames; // frames per sprite box
    character->height = character->texture.height;

    character->box = (Rectangle) {0.0f, 0.0f, (float) character->width, (float) character->height};
    character->pos = (Vector2) {(float) screen_width / 2.0f, (float) ground_position};
    character->v = (Vector2) {0.0f, 0.0f};

    character->movement_speed = (float) frames * 1.45f;
    character->gravity = gravity;

    return character;
}
