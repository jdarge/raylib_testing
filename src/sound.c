#include "sound.h"
#include "raylib.h"

Sound sound_walking;
Sound sound_jumping;
Sound sound_landing;

void play_sound_walking(void) {
    if (!IsSoundReady(sound_walking)) {
        sound_walking = LoadSound("resources/sounds/moving/walk.mp3");
    }
    PlaySound(sound_walking);
}

void play_sound_jumping(void) {
    if (!IsSoundReady(sound_jumping)) {
        sound_jumping = LoadSound("resources/sounds/moving/jump.mp3");
    }
    PlaySound(sound_jumping);
}

void play_sound_landing(void) {
    if(!IsSoundReady(sound_landing)) {
        sound_landing = LoadSound("resources/sounds/moving/land.mp3");
    }
    PlaySound(sound_landing);
}
