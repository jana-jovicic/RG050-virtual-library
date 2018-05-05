/* kod sa casa, samo ubacen u funkcije */

#include "../headers/texture.h"
#include <stdio.h>

GLuint textureNames[NUMBER_OF_TEXTURES];

void loadTextures()
{
	glEnable(GL_TEXTURE_2D);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	Image* image = image_init(0, 0);

	glGenTextures(NUMBER_OF_TEXTURES, textureNames);

	createTexture(image, textureNames, FILENAME1, 1);
	createTexture(image, textureNames, FILENAME2, 2);
	createTexture(image, textureNames, FILENAME3, 3);
        createTexture(image, textureNames, FILENAME4, 4);
        createTexture(image, textureNames, FILENAME5, 5);
        createTexture(image, textureNames, FILENAME6, 6);
        createTexture(image, textureNames, FILENAME7, 7);
        createTexture(image, textureNames, FILENAME8, 8);
        createTexture(image, textureNames, FILENAME9, 9);
        createTexture(image, textureNames, FILENAME10, 10);
        createTexture(image, textureNames, FILENAME11, 11);
        createTexture(image, textureNames, FILENAME12, 12);
        createTexture(image, textureNames, FILENAME13, 13);
        createTexture(image, textureNames, FILENAME14, 14);
        createTexture(image, textureNames, FILENAME15, 15);
        createTexture(image, textureNames, FILENAME16, 16);
        createTexture(image, textureNames, FILENAME17, 17);
        createTexture(image, textureNames, FILENAME18, 18);
        createTexture(image, textureNames, FILENAME19, 19);
        createTexture(image, textureNames, FILENAME20, 20);
        createTexture(image, textureNames, FILENAME21, 21);
        createTexture(image, textureNames, FILENAME22, 22);
        createTexture(image, textureNames, FILENAME23, 23);
        createTexture(image, textureNames, FILENAME24, 24);
        createTexture(image, textureNames, FILENAME25, 25);
        createTexture(image, textureNames, FILENAME26, 26);
        createTexture(image, textureNames, FILENAME27, 27);
        createTexture(image, textureNames, FILENAME28, 28);
        createTexture(image, textureNames, FILENAME29, 29);
        createTexture(image, textureNames, FILENAME30, 30);
        createTexture(image, textureNames, FILENAME31, 31);
        createTexture(image, textureNames, FILENAME32, 32);
        createTexture(image, textureNames, FILENAME33, 33);
        createTexture(image, textureNames, FILENAME34, 34);
        createTexture(image, textureNames, FILENAME35, 35);
        createTexture(image, textureNames, FILENAME36, 36);
        createTexture(image, textureNames, FILENAME37, 37);
        createTexture(image, textureNames, FILENAME38, 38);
        createTexture(image, textureNames, FILENAME39, 39);
        createTexture(image, textureNames, FILENAME40, 40);
        
	glBindTexture(GL_TEXTURE_2D, 0);

	image_done(image);
}

void createTexture(Image* image, GLuint* textureNames, const char* fileName, int textureIndex)
{
    image_read(image, fileName);

    glBindTexture(GL_TEXTURE_2D, textureNames[textureIndex]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
}

void freeTextures()
{
	glDeleteTextures(2, textureNames);
}
