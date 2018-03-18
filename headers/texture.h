#ifndef _TEXTURES_H_
#define _TEXTURES_H_

#include <GL/glut.h>
#include "image.h"

#define NUMBER_OF_TEXTURES 50
#define FILENAME1 "textures/ceiling.bmp"
#define FILENAME2 "textures/floor.bmp"
#define FILENAME3 "textures/bookcase_background.bmp"

/* texture id */
extern GLuint textureNames[NUMBER_OF_TEXTURES];

void createTexture(Image* image, GLuint* textureNames, const char* fileName, int textureIndex);

void loadTextures();
void freeTextures();

#endif
