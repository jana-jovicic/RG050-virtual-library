#ifndef _ROOM_H_
#define _ROOM_H_

void drawFloor();
void drawRoom();

void drawXZQuad(GLfloat x, GLfloat y, GLfloat z, GLfloat normal);
void drawYZQuad(GLfloat x, GLfloat y, GLfloat z, GLfloat dx, GLfloat normal);
void drawXYQuad(GLfloat x, GLfloat y, GLfloat z, GLfloat dz, GLfloat normal);


#endif