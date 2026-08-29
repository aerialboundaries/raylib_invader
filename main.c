#include <raylib.h>

#include "spaceship.h"

#define IMAGE_SPACESHIP "Graphics/spaceship.png"

int main(void)
{
  Color grey = {29, 29, 27, 255};
  int windowWidth = 750;
  int windowHeight = 700;

  InitWindow(windowWidth, windowHeight, "C Space Invaders");
  SetTargetFPS(60);

  /* declare Spaceship ship as real */
  Spaceship ship;

  /* spaceship create with graphic path with IMAGE_SPACESHIP */
  /* ship is real structure, so, must be initialized by constant value */
  spaceship_init(&ship, (Vector2){0.0f, 0.0f}, IMAGE_SPACESHIP);

  /* calculate position with loaded image size */
  ship.position.x = (GetScreenWidth() - ship.image.width) / 2.0f;
  ship.position.y = GetScreenHeight() - ship.image.height;

  while (WindowShouldClose() == false) {

    BeginDrawing();
    ClearBackground(grey);

    /* draw spaceship */
    spaceship_draw(&ship);

    EndDrawing();
  }

  /* destroy texture */
  spaceship_destroy(&ship);

  CloseWindow();
  return 0;
}
