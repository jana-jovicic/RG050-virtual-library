#include "../headers/global_variables.h"
#include "../headers/room.h"
#include "../headers/texture.h"

void drawFloor()
{
	GLfloat gDiffuseMaterial[] = { 1.0f, 0.7f, 0.75f, 0.6f };
	GLfloat gSpecularMaterial[] = { 1.0, 1.0, 1.0, 1.0f };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, gDiffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, gSpecularMaterial);

	glColor4f(gDiffuseMaterial[0], gDiffuseMaterial[1],
		gDiffuseMaterial[2], gDiffuseMaterial[3]);
        
        glBindTexture(GL_TEXTURE_2D, textureNames[2]);

	GLfloat x = xRange;
	GLfloat y = 0.0f;
	GLfloat z = zRange;
        
        drawXZQuad(x, y, z, 1.0f);
        
        glBindTexture(GL_TEXTURE_2D, 0);
}

void drawRoom()
{
	GLfloat gDiffuseMaterial[] = { 1.0f, 0.71f, 0.75f, 0.5f };
	GLfloat gSpecularMaterial[] = { 0.0, 0.0, 0.0, 1.0f };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, gDiffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, gSpecularMaterial);

	glColor4f(gDiffuseMaterial[0], gDiffuseMaterial[1],
		gDiffuseMaterial[2], gDiffuseMaterial[3]);

        glBindTexture(GL_TEXTURE_2D, textureNames[3]);
        
        /* Zadnji zid */
	GLfloat x = xRange;
	GLfloat y = yRange;
	GLfloat z = 0.0f;
        GLfloat dz = -zRange;
        drawXYQuad(x, y, z, dz, 1.0f);
        
        glBindTexture(GL_TEXTURE_2D, 0);
        
        drawDoor();

        glColor4f(gDiffuseMaterial[0], gDiffuseMaterial[1],
		gDiffuseMaterial[2], gDiffuseMaterial[3]);
        
        glBindTexture(GL_TEXTURE_2D, textureNames[3]);
        
	/* Prednji zid */       
	dz = zRange; 
        drawXYQuad(x, y, z, dz, -1.0f);
        
	glColor4f(0.54f, 0.37f, 0.4f, gDiffuseMaterial[3]);
        
	/* Levi zid */
	y = yRange;
        z = zRange;
        x = 0.0f;
        GLfloat dx = -xRange;
        drawYZQuad(x, y, z, dx, 1.0f);
        
	/* Desni zid */
	dx = xRange;
        drawYZQuad(x, y, z, dx, -1.0f);
       
        glBindTexture(GL_TEXTURE_2D, 0);
        
	/* Plafon */
        glBindTexture(GL_TEXTURE_2D, textureNames[1]);
	//glColor4f(0.54f, 0.28f, 0.4f, gDiffuseMaterial[3]);
        x = xRange;
        y = yRange;
        z = zRange;
	drawXZQuad(x, y, z, -1.0f);
        glBindTexture(GL_TEXTURE_2D, 0);

}

void drawXZQuad(GLfloat x, GLfloat y, GLfloat z, GLfloat normal)
{
        glBegin(GL_QUADS);
            glNormal3f(0.0f, normal, 0.0f);
            glTexCoord2f(x/100, z/100); glVertex3f(x, y, z);
            glTexCoord2f(-x/100, z/100); glVertex3f(-x, y, z);
            glTexCoord2f(-x/100, -z/100); glVertex3f(-x, y, -z);
            glTexCoord2f(x/100, -z/100); glVertex3f(x, y, -z);
        glEnd();
}

void drawYZQuad(GLfloat x, GLfloat y, GLfloat z, GLfloat dx, GLfloat normal)
{               
        glBegin(GL_QUADS);
            glNormal3f(normal, 0.0f, 0.0f);
            glTexCoord2f((x+dx)/150, z/150); glVertex3f(x + dx, y, z);
            glTexCoord2f((x+dx)/150, -z/150); glVertex3f(x + dx, 0, z);
            glTexCoord2f(0, -z/150); glVertex3f(x + dx, 0, -z);
            glTexCoord2f(x/150, z/150);  glVertex3f(x + dx, y, -z);
        glEnd();
}

void drawXYQuad(GLfloat x, GLfloat y, GLfloat z, GLfloat dz, GLfloat normal)
{
        glBegin(GL_QUADS);
            glNormal3f(0.0f, 0.0f, normal);
            glTexCoord2f(x/150, y/150); glVertex3f(x, y, z + dz);
            glTexCoord2f(-x/150, y/150); glVertex3f(-x, y, z + dz);
            glTexCoord2f(-x/150, 0); glVertex3f(-x, 0, z + dz);
            glTexCoord2f(x/150, 0); glVertex3f(x, 0, z + dz);
        glEnd();
}

void drawDoor()
{
    glBindTexture(GL_TEXTURE_2D, textureNames[6]);
    
    glPushMatrix();
    glColor3f(0.17f, 0.12f, 0.0f);
    
    glTranslatef(-94, 0, zRange-1);
    glScalef(61.5, 55.5, 50);
    
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(1, 0, 0.01);

        glTexCoord2f(1, 0);
        glVertex3f(2.2, 0, 0.01);

        glTexCoord2f(1, 1);
        glVertex3f(2.2, 2.2, 0.01);

        glTexCoord2f(0, 1);
        glVertex3f(1, 2.2, 0.01);
    glEnd();
    
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, 0);
}


