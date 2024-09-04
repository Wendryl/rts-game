#include <raylib.h>

#ifndef SPRITESHEET_H
#define SPRITESHEET_H

typedef struct {
  Texture2D spriteSheetSource;
  int framesPerRow;
  int framesPerColumn;
  int framesPerSecond;
	int frameCounter;
	Rectangle currentFrame;
} Spritesheet;

#endif
