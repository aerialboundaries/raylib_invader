#pragma once

#include <raylib.h>

typedef struct {
  Texture2D image;
  Vector2 position;
} Spaceship;

/* Constructer & Destructer */
void spaceship_init(Spaceship *ship, Vector2 position, const char *image_path);
void spaceship_destroy(Spaceship *ship);

/* functions */
void spaceship_draw(const Spaceship *ship);
void spaceship_move_left(Spaceship *ship);
void spaceship_move_right(Spaceship *ship);
void spaceship_fire_laser(Spaceship *ship);
