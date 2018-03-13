#include "../headers/global_variables.h"
#include "../headers/room.h"

void drawFloor()
{
	GLfloat gDiffuseMaterial[] = { 1.0f, 0.7f, 0.75f, 0.6f };
	GLfloat gSpecularMaterial[] = { 1.0, 1.0, 1.0, 1.0f };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, gDiffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, gSpecularMaterial);

	glColor4f(gDiffuseMaterial[0], gDiffuseMaterial[1],
		gDiffuseMaterial[2], gDiffuseMaterial[3]);

	GLfloat x = xRange;
	GLfloat y = 0.0f;
	GLfloat z = zRange;
        
        drawXZQuad(x, y, z, 1.0f);
}

void drawRoom()
{
	GLfloat gDiffuseMaterial[] = { 1.0f, 0.71f, 0.75f, 0.5f };
	GLfloat gSpecularMaterial[] = { 0.0, 0.0, 0.0, 1.0f };

	glMaterialfv(GL_FRONT, GL_DIFFUSE, gDiffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, gSpecularMaterial);

	glColor4f(gDiffuseMaterial[0], gDiffuseMaterial[1],
		gDiffuseMaterial[2], gDiffuseMaterial[3]);

        /* Zadnji zid */
	GLfloat x = xRange;
	GLfloat y = yRange;
	GLfloat z = 0.0f;
        GLfloat dz = -zRange;
        drawXYQuad(x, y, z, dz, 1.0f);

	/* Prednji zid */       
	dz = zRange; 
        drawXYQuad(x, y, z, dz, -1.0f);
        
	
	/* Levi zid */
	glColor4f(0.54f, 0.37f, 0.4f, gDiffuseMaterial[3]);
	y = yRange;
        z = zRange;
        x = 0;
        GLfloat dx = -xRange;
        drawYZQuad(x, y, z, dx, 1.0f);
	
	/* Desni zid */
	dx = xRange;
        drawYZQuad(x, y, z, dx, -1.0f);
        
	
	/* Plafon */
	glColor4f(0.54f, 0.28f, 0.36f, gDiffuseMaterial[3]);
        x = xRange;
        y = yRange;
        z = zRange;
	drawXZQuad(x, y, z, -1.0f);

}

void drawXZQuad(GLfloat x, GLfloat y, GLfloat z, GLfloat normal){
                    
        glBegin(GL_QUADS);
            glNormal3f(0.0f, normal, 0.0f);
            glVertex3f(x, y, z);
            glVertex3f(-x, y, z);
            glVertex3f(-x, y, -z);
            glVertex3f(x, y, -z);
        glEnd();
}

void drawYZQuad(GLfloat x, GLfloat y, GLfloat z, GLfloat dx, GLfloat normal){
                    
        glBegin(GL_QUADS);
            glNormal3f(normal, 0.0f, 0.0f);
            glVertex3f(x + dx, y, z);
            glVertex3f(x + dx, 0, z);
            glVertex3f(x + dx, 0, -z);
            glVertex3f(x + dx, y, -z);
        glEnd();
}

void drawXYQuad(GLfloat x, GLfloat y, GLfloat z, GLfloat dz, GLfloat normal){
                    
        glBegin(GL_QUADS);
            glNormal3f(0.0f, 0.0f, normal);
            glVertex3f(x, y, z + dz);
            glVertex3f(-x, y, z + dz);
            glVertex3f(-x, 0, z + dz);
            glVertex3f(x, 0, z + dz);
        glEnd();
}

