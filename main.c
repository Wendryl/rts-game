#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include "src/entity.h"

int main() {
  const int SCREEN_WIDTH = 600;
  const int SCREEN_HEIGHT = 400;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RTS");
  SetTargetFPS(60);

  Entity* player = initEntity("./assets/Factions/Knights/Troops/Dead/Dead.png", 7, 2);

  while (!WindowShouldClose()) {

    Vector2 mousePos = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      player->state = WALKING;
    }

    if (
        player->state == WALKING &&
        player->position.x <= mousePos.x
       ) {
      player->position.x += 2;
    }

    if (
        player->state == WALKING &&
        player->position.x >= mousePos.x
       ) {
      player->position.x -= 2;
    }

    if (
        player->state == WALKING &&
        player->position.y >= mousePos.y
       ) {
      player->position.y -= 2;
    }

    if (
        player->state == WALKING &&
        player->position.y <= mousePos.y
       ) {
      player->position.y += 2;
    }

    if (player->position.x == mousePos.x && player->position.y == mousePos.y) {
      player->state = IDLE;
    }

    BeginDrawing();
      ClearBackground(WHITE);
      renderEntity(player);
    EndDrawing();
  }

  return 0;
}
