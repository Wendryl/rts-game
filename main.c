#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include "src/entity.h"

int main() {
  const int SCREEN_WIDTH = 800;
  const int SCREEN_HEIGHT = 600;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RTS");
  SetTargetFPS(60);

  Entity* player = initEntity("./assets/Factions/Knights/Troops/Dead/Dead.png", 7, 2);

  while (!WindowShouldClose()) {

    Vector2 mousePos = GetMousePosition();
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
      Color color = { 0x00, 0x00, 0x00, 0x93 };
      DrawCircleV(mousePos, 10, color);
    }

    updateEntity(player, mousePos);
    BeginDrawing();
      ClearBackground(WHITE);
      renderEntity(player);
    EndDrawing();
  }

  return 0;
}
