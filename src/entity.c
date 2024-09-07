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

const char* toString(Entity* entity) {
  return TextFormat("Entity Info: \nposition(%.2f, %.2f)\ntarget position(%.2f, %.2f)\nvelocity(%.2f, %.2f)\ndirection: %d\nstate: %d\n", entity->position.x, entity->position.y, entity->targetPosition.x, entity->targetPosition.y, entity->velocity.x, entity->velocity.y, entity->direction, entity->state);
}

Entity* initEntity(char* spriteSheetPath, int framesPerRow, int framesPerColumn) {
  Vector2 velocity = { 0.0f, 0.0f };
  Vector2 position = { 0.0f, 0.0f };
  Entity *entity = malloc(sizeof(Entity));
  entity->velocity = velocity;
  entity->state = IDLE;
  entity->direction = LEFT;
  entity->spriteSheet = initSpriteSheet(spriteSheetPath, framesPerRow, framesPerColumn);
  entity->position = position;
  return entity;
}

void renderEntity(Entity* entity) {

  int spriteRow = 0;

  entity->spriteSheet->frameCounter++;
  entity->spriteSheet->currentFrame.y = spriteRow * (float) entity->spriteSheet->spriteSheetSource.width / entity->spriteSheet->framesPerRow;

  if (entity->spriteSheet->frameCounter >= 60 / entity->spriteSheet->framesPerSecond) {
    entity->spriteSheet->currentFrame.x += (float) entity->spriteSheet->spriteSheetSource.width / entity->spriteSheet->framesPerRow;
    entity->spriteSheet->frameCounter = 0;
  }

  DrawCircle(entity->position.x, entity->position.y, 3, LIME);
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
        entity->position.x <= entity->targetPosition.x
       ) {
      entity->velocity.x = 1;
    }

    if (
        entity->state == WALKING &&
        entity->position.x >= entity->targetPosition.x
       ) {
      entity->velocity.x = -1;
    }

    if (
        entity->state == WALKING &&
        entity->position.y >= entity->targetPosition.y
       ) {
      entity->velocity.y = -1;
    }

    if (
        entity->state == WALKING &&
        entity->position.y <= entity->targetPosition.y
       ) {
      entity->velocity.y = 1;
    }

    if (
        (entity->position.x >= entity->targetPosition.x - 2 && entity->position.x <= entity->targetPosition.x + 2) &&
        (entity->position.y >= entity->targetPosition.y - 2 && entity->position.y <= entity->targetPosition.y + 2)
        ) {
      entity->velocity.x = 0.0f;
      entity->velocity.y = 0.0f;
      entity->state = IDLE;
    }

    entity->position.x += entity->velocity.x;
    entity->position.y += entity->velocity.y;

    TraceLog(LOG_INFO, toString(entity));
}
