#include <raylib.h>
#include "./spritesheet.h"

#ifndef ENTITY_H
#define ENTITY_H

typedef enum {
  IDLE = 1,
  WALKING = 2,
} State;

typedef struct {
  Vector2 position;
	Spritesheet* spriteSheet;
  State state;
} Entity;

Entity* initEntity(char* spriteSheetPath, int framesPerRow, int framesPerColumn);
Spritesheet* initSpriteSheet(char* spriteSheetPath, int framesPerRow, int framesPerColumn);
void renderEntity(Entity* entity);

#endif
