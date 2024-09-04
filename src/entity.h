#include <raylib.h>
#include "./spritesheet.h"

#ifndef ENTITY_H
#define ENTITY_H

typedef struct {
  Vector2 position;
	Spritesheet* spriteSheet;
} Entity;

Entity* initEntity(char* spriteSheetPath, int framesPerRow, int framesPerColumn);
Spritesheet* initSpriteSheet(char* spriteSheetPath, int framesPerRow, int framesPerColumn);
void renderEntity(Entity* entity);

#endif
