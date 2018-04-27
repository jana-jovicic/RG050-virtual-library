#ifndef _TEXTURES_H_
#define _TEXTURES_H_

#include <GL/glut.h>
#include "image.h"

#define NUMBER_OF_TEXTURES 50
#define FILENAME1 "textures/ceiling.bmp"
#define FILENAME2 "textures/floor.bmp"
#define FILENAME3 "textures/bookcase_background.bmp"
#define FILENAME4 "textures/bookcase.bmp"
#define FILENAME5 "textures/wood_3.bmp"
#define FILENAME6 "textures/door.bmp"

#define FILENAME7 "textures/1984.bmp"

#define FILENAME8  "textures/books_19_1.bmp"
#define FILENAME9  "textures/books_19_2.bmp"
#define FILENAME10 "textures/books_19_3.bmp"

#define FILENAME11 "textures/books_30_ki.bmp"
#define FILENAME12 "textures/books_33_ki_2.bmp"
#define FILENAME13 "textures/books_sh.bmp"

#define FILENAME14 "textures/books_35.bmp"
#define FILENAME15 "textures/books_39.bmp"
#define FILENAME16 "textures/books_41.bmp"
#define FILENAME17 "textures/books_43.bmp"
#define FILENAME18 "textures/books_44.bmp"

/*#define FILENAME19 "textures/books_22_ma.bmp"
#define FILENAME20 "textures/books_34_zs.bmp"
*/
/* texture id */
extern GLuint textureNames[NUMBER_OF_TEXTURES];

void createTexture(Image* image, GLuint* textureNames, const char* fileName, int textureIndex);

void loadTextures();
void freeTextures();

#endif
