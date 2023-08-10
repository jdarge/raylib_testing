#include "raylib.h"

#include "character.h"
#include "frame.h"
#include "input.h"
#include "physics.h"
#include "sound.h"
#include "world.h"

void show_error(char *err) {
    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);
        DrawText(err, 20, 20, 20, RED);

        EndDrawing();
    }
}

int main(void) {

    InitWindow(screen_width, screen_height, "2D Scarfy");
    InitAudioDevice();

    Character *scarfy = init_character("resources/textures/scarfy/scarfy.png", 6, 1);

    bool moving = false;
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        DrawText("Press < or >", 20, 20, 12, RAYWHITE);

        bool ground_check = is_on_ground(scarfy);
        handle_input(scarfy);
        moving = is_moving(scarfy);
        update_movement(scarfy);

        bool grounded = is_on_ground(scarfy);
        if (grounded) {
            update_movement_grounded(scarfy);
            if (ground_check == false) {
                play_sound_landing();
            }
        } else {
            update_gravity(scarfy);
        }

        next_frame(scarfy);
        if(moving && grounded) {
            if(is_touching_ground_frame()) {
                play_sound_walking();
            }
        }

        BeginDrawing();
        ClearBackground(GRAY);
        DrawTextureRec(scarfy->texture, scarfy->box, scarfy->pos, WHITE);
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}

