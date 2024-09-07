#include <raylib.h>
#include "./spritesheet.h"

#ifndef ENTITY_H
#define ENTITY_H

typedef enum {
  IDLE = 1,
  WALKING = 2,
  ATTACKING = 3,
} State;

typedef enum {
  UP = 1,
  DOWN = 2,
  LEFT = 3,
  RIGHT = 4,
} Direction;

typedef struct {
  Vector2 position;
  Vector2 targetPosition;
  Vector2 velocity;
	SpriteSheet* spriteSheet;
  State state;
  Direction direction;
} Entity;

Entity* initEntity(char* spriteSheetPath, int framesPerRow, int framesPerColumn);
void renderEntity(Entity* entity);
void updateEntity(Entity* entity, Vector2 mousePos);

#endif
