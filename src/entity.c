#include <stdio.h>
#include <stdlib.h>
#include "entity.h"

Direction getEntityDirection(Vector2 targetPosition, Vector2 currentPosition) {
  if (targetPosition.y > currentPosition.y) {
    return DOWN;
  }

  if (targetPosition.y < currentPosition.y) {
    return UP;
  }

  return RIGHT;
}

Entity* initEntity(char* spriteSheetPath, int framesPerRow, int framesPerColumn) {
  Vector2 position = { 15.0f, 15.0f };
  Vector2 velocity = { 0.0f, 0.0f };
  Entity *entity = malloc(sizeof(Entity));
  entity->position = position;
  entity->velocity = velocity;
  entity->state = IDLE;
  entity->direction = LEFT;
  entity->spriteSheet = initSpriteSheet(spriteSheetPath, framesPerRow, framesPerColumn);
  Vector2 center = {
    entity->position.x + (float) entity->spriteSheet->spriteSheetSource.width / framesPerRow / 2,
    entity->position.y + (float) entity->spriteSheet->spriteSheetSource.height / framesPerColumn / 2
  };
  entity->center = center;
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

  int spriteRow = 0;

  entity->spriteSheet->frameCounter++;
  entity->spriteSheet->currentFrame.y = spriteRow * (float) entity->spriteSheet->spriteSheetSource.width / entity->spriteSheet->framesPerRow;

  if (entity->spriteSheet->frameCounter >= 60 / entity->spriteSheet->framesPerSecond) {
    entity->spriteSheet->currentFrame.x += (float) entity->spriteSheet->spriteSheetSource.width / entity->spriteSheet->framesPerRow;
    entity->spriteSheet->frameCounter = 0;
  }

  DrawTextureRec(entity->spriteSheet->spriteSheetSource, entity->spriteSheet->currentFrame, entity->position, WHITE);
}

void updateEntity(Entity* entity, Vector2 mousePos) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      entity->targetPosition = mousePos;
      entity->state = WALKING;
      entity->direction = getEntityDirection(entity->targetPosition, entity->position);
    }

    if (
        entity->state == WALKING &&
        entity->center.x <= entity->targetPosition.x
       ) {
      entity->velocity.x = 1;
    }

    if (
        entity->state == WALKING &&
        entity->center.x >= entity->targetPosition.x
       ) {
      entity->velocity.x = -1;
    }

    if (
        entity->state == WALKING &&
        entity->center.y >= entity->targetPosition.y
       ) {
      entity->velocity.y = -1;
    }

    if (
        entity->state == WALKING &&
        entity->center.y <= entity->targetPosition.y
       ) {
      entity->velocity.y = 1;
    }

    if (
        (entity->center.x >= entity->targetPosition.x - 2 && entity->center.x <= entity->targetPosition.x + 2) &&
        (entity->center.y >= entity->targetPosition.y - 2 && entity->center.y <= entity->targetPosition.y + 2)
        ) {
      entity->velocity.x = 0.0f;
      entity->velocity.y = 0.0f;
      entity->state = IDLE;
    }

    entity->position.x += entity->velocity.x;
    entity->position.y += entity->velocity.y;
    Vector2 center = {
      entity->position.x + (float) entity->spriteSheet->spriteSheetSource.width / entity->spriteSheet->framesPerRow / 2,
      entity->position.y + (float) entity->spriteSheet->spriteSheetSource.height / entity->spriteSheet->framesPerColumn / 2
    };
    entity->center = center;
}
