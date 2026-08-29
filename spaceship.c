#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "spaceship.h"

static void terminate(const char *message)
{
  fprintf(stderr, "%s\n", message);
  exit(EXIT_FAILURE);
}

/* Constructer & Destructer */
void spaceship_init(Spaceship *ship, Vector2 position, const char *image_path)
{
  if (ship == NULL) {
    terminate("spaceship cannot be created");
  }
  if (image_path == NULL) {
    terminate("image_path is NULL");
  }
  ship->position = position;
  ship->image = LoadTexture(image_path);
}

void spaceship_destroy(Spaceship *ship)
{
  if (ship == NULL) {
    terminate("spaceship cannot be destoyed");
  }
  UnloadTexture(ship->image);
}

/* functions */
void spaceship_draw(const Spaceship *ship)
{
  if (ship == NULL) {
    terminate("ship cannot be drawn");
  }
  DrawTextureV(ship->image, ship->position, WHITE);
}

void spaceship_move_left(Spaceship *ship)
{
  if (ship == NULL) {
    terminate("ship cannot move");
  }
  ship->position.x -= 5.0f;
}

void spaceship_move_right(Spaceship *ship)
{
  if (ship == NULL) {
    terminate("ship cannot move");
  }
  ship->position.x += 5.0f;
}

void spaceship_fire_laser(Spaceship *ship)
{
  if (ship == NULL) {
    terminate("ship cannot move");
  }
  // process for fire
}
