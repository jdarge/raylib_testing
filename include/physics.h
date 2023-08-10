#ifndef PHYSICS_INCLUDED
#define PHYSICS_INCLUDED

#include "character.h";

void update_movement(Character *character);

void update_movement_grounded(Character *character);

void update_gravity(Character *character);

#endif
