#ifndef SOUND_INCLUDED
#define SOUND_INCLUDED

#include "raylib.h"

extern Sound sound_walking;
extern Sound sound_jumping;
extern Sound sound_landing;

void play_sound_walking(void);

void play_sound_jumping(void);

void play_sound_landing(void);

#endif
