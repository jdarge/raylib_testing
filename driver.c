/*

 PATHS:
 sound:
    resources/sounds/moving
 textures:
    resources/textures/scarfy

*/

#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

const int screen_width = 1600;
const int screen_height = 900;
const float ground_position = (float) screen_height / 1.3f;

const int frame_jump_up = 3;
const int frame_jump_down = 4;

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

int main(void) {

    bool is_moving = false;
    // bool canDoubleJump = true;

    InitWindow(screen_width, screen_height, "2D Scarfy");
    InitAudioDevice();

    Character *scarfy = init_character("resources/textures/scarfy/scarfy.png", 6, 1);

    Sound sound_walking = LoadSound("resources/sounds/moving/walk.mp3");
    Sound sound_jumping = LoadSound("resources/sounds/moving/jump.mp3");
    Sound sound_landing = LoadSound("resources/sounds/moving/land.mp3");

    SetTargetFPS(60);
    unsigned frame_delay = 5;
    unsigned frame_delay_counter = 0;
    unsigned frame_index = 0;

    while (!WindowShouldClose()) {

        DrawText("Press < or >", 20, 20, 12, BLACK);

        bool ground_check = is_on_ground(scarfy);

        if (is_on_ground(scarfy)) {
            if (IsKeyDown(KEY_UP)) {
                PlaySound(sound_jumping);
                scarfy->v.y = -scarfy->movement_speed * 2.0f;
            }

            if (IsKeyDown(KEY_RIGHT)) {
                scarfy->v.x = scarfy->movement_speed;
                if (scarfy->box.width < 0) {
                    scarfy->box.width *= -1;
                }
            } else if (IsKeyDown(KEY_LEFT)) {
                scarfy->v.x = -scarfy->movement_speed;
                if (scarfy->box.width > 0) {
                    scarfy->box.width *= -1;
                }
            } else {
                scarfy->v.x = 0;
            }
        }

        is_moving = (scarfy->v.x == 0.0f && scarfy->v.y == 0.0f) ? false : true;
        scarfy->pos = Vector2Add(scarfy->pos, scarfy->v);

        bool grounded = is_on_ground(scarfy);
        if (grounded) {
            scarfy->v.y = 0;
            scarfy->pos.y = ground_position - (float) scarfy->height;
            if(ground_check == false) {
                PlaySound(sound_landing);
            }
        } else {
            scarfy->v.y += scarfy->gravity;
        }

        if (++frame_delay_counter > frame_delay) {

            frame_delay_counter = 0;

            if (is_moving) {
                if (grounded) {
                    ++frame_index;
                    frame_index %= scarfy->frames;
                    if(frame_index == 1 || frame_index == 4) {
                        PlaySound(sound_walking);
                    }
                } else {
                    // TODO: hardcoded sprite frames lol
                    if (scarfy->v.y < 0) {
                        frame_index = frame_jump_up;
                    } else {
                        frame_index = frame_jump_down;
                    }
                }
                scarfy->box.x = (float) scarfy->width * (float) frame_index;
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTextureRec(scarfy->texture, scarfy->box, scarfy->pos, WHITE);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}

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
