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

#define FILENAME18 "textures/books_pekic.bmp"
#define FILENAME19 "textures/books_22_ma.bmp"
#define FILENAME20 "textures/books_34_zs.bmp"
#define FILENAME21 "textures/books_besnilo_3.bmp"
#define FILENAME22 "textures/books_book_thief.bmp"
#define FILENAME23 "textures/books_stranger.bmp"
#define FILENAME24 "textures/books_blindness.bmp"
#define FILENAME25 "textures/books_kafka_na_obali_mora.bmp"

#define FILENAME26 "textures/books_hp_10.bmp"
#define FILENAME27 "textures/books_got_4.bmp"
#define FILENAME28 "textures/books_32_sk_2.bmp"
#define FILENAME29 "textures/books_murakami.bmp"
#define FILENAME30 "textures/books_murakami_3.bmp"

#define FILENAME31 "textures/books_45_1.bmp"
#define FILENAME32 "textures/books_45_2.bmp"
#define FILENAME33 "textures/books_45_3.bmp"
#define FILENAME34 "textures/books_46_1.bmp"
#define FILENAME35 "textures/books_47_2.bmp"

#define FILENAME36 "textures/books_poe_1.bmp"
#define FILENAME37 "textures/books_50.bmp"
#define FILENAME38 "textures/books_52.bmp"
#define FILENAME39 "textures/books_53.bmp"
#define FILENAME40 "textures/books_54.bmp"

/* texture id */
extern GLuint textureNames[NUMBER_OF_TEXTURES];

void createTexture(Image* image, GLuint* textureNames, const char* fileName, int textureIndex);

void loadTextures();
void freeTextures();

#endif
