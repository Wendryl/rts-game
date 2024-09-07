#include <raylib.h>

#ifndef SPRITESHEET_H
#define SPRITESHEET_H

typedef enum {
  EMPTY = 0,
  ANIM_IDLE = 1,
  ANIM_WALKING = 2,
  ANIM_WALKING_UP = 3,
  ANIM_WALKING_DOWN = 3,
  ANIM_ATTACKING = 4,
  ANIM_ATTACKING_UP = 4,
  ANIM_ATTACKING_DOWN = 4,
} SpriteType;

typedef struct {
  Texture2D spriteSheetSource;
  int framesPerRow;
  int framesPerColumn;
  int framesPerSecond;
	int frameCounter;
	Rectangle currentFrame;
} SpriteSheet;

SpriteSheet* initSpriteSheet(char* spriteSheetPath, int framesPerRow, int framesPerColumn);
#endif
