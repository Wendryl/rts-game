#include <stdio.h>
#include <stdlib.h>
#include "entity.h"

Entity* initEntity(char* spriteSheetPath, int framesPerRow, int framesPerColumn) {
  Vector2 position = { 15.0f, 15.0f };
  Entity *entity = malloc(sizeof(Entity));
  entity->position = position;
  entity->spriteSheet = initSpriteSheet(spriteSheetPath, framesPerRow, framesPerColumn);
  return entity;
}

Spritesheet* initSpriteSheet(char* spriteSheetPath, int framesPerRow, int framesPerColumn) {
  Spritesheet* spriteSheet = malloc(sizeof(Spritesheet));
  Texture2D spriteSheetSource = LoadTexture(spriteSheetPath);
  spriteSheet->spriteSheetSource = spriteSheetSource;
  spriteSheet->frameCounter = 0;
  spriteSheet->framesPerRow = framesPerRow;
  spriteSheet->framesPerColumn = framesPerColumn;
  spriteSheet->framesPerSecond = 12;
  Rectangle currentFrame = {
    0.0f,
    0.0f,
    (float) spriteSheetSource.width / framesPerRow,
    (float)  spriteSheetSource.height / framesPerColumn
  };
  spriteSheet->currentFrame = currentFrame;

  return spriteSheet;
}

void renderEntity(Entity* entity) {
  entity->spriteSheet->frameCounter++;
  entity->spriteSheet->currentFrame.y = 2 * (float) entity->spriteSheet->spriteSheetSource.width / entity->spriteSheet->framesPerRow;

  if (entity->spriteSheet->frameCounter >= 60 / entity->spriteSheet->framesPerSecond) {
    entity->spriteSheet->currentFrame.x += (float) entity->spriteSheet->spriteSheetSource.width / entity->spriteSheet->framesPerRow;
    entity->spriteSheet->frameCounter = 0;
  }

  DrawTextureRec(entity->spriteSheet->spriteSheetSource, entity->spriteSheet->currentFrame, entity->position, WHITE);
}
