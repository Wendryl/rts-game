#include "./spritesheet.h"
#include <stdlib.h>

SpriteSheet* initSpriteSheet(char* spriteSheetPath, int framesPerRow, int framesPerColumn) {
  SpriteSheet* spriteSheet = malloc(sizeof(SpriteSheet));
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
