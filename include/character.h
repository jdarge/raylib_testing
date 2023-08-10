#ifndef CHARACTER_INCLUDED
#define CHARACTER_INCLUDED

#include "raylib.h"

typedef struct Character {
    Texture2D texture;
    Rectangle box;
    Vector2 pos;
    Vector2 v;

    int frames;
    int width;
    int height;

    float movement_speed;
    float gravity;

} Character;

bool is_on_ground(Character *character);

Character *init_character(char *texture_location, int frames, float gravity);

#endif
