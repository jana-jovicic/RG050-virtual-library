/* kod sa casa, samo ubacen u funkcije */

#include "../headers/texture.h"

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
