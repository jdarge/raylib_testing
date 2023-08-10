#include "physics.h"
#include "raymath.h"
#include "world.h"

void update_movement(Character *character) {
    character->pos = Vector2Add(character->pos, character->v);
}

void update_movement_grounded(Character *character) {
    character->v.y = 0;
    character->pos.y = ground_position - (float) character->height;
}

void update_gravity(Character *character) {
    character->v.y += character->gravity;
}
