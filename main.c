#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include "src/entity.h"

int main() {
  const int SCREEN_WIDTH = 600;
  const int SCREEN_HEIGHT = 400;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RTS");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(WHITE);
    EndDrawing();
  }

  return 0;
}
