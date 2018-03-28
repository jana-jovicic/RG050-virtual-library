#include "../headers/global_variables.h"
#include "../headers/bookcase.h"
#include "../headers/texture.h"

Bookcase bookcases[MAX_BOOKCASES];

void drawBookcases()
{
    /* Prave se 4 police za knjige i radni sto */
    
    glBindTexture(GL_TEXTURE_2D, textureNames[4]);
    
    glPushMatrix();
        makeBookcase(-50, 85, 0);
    glPopMatrix();

    glPushMatrix();
        makeBookcase(-50, -85, 1);
    glPopMatrix();
    
    glPushMatrix();
        makeBookcase(50, 85, 2);
    glPopMatrix();

    glPushMatrix();
        makeBookcase(50, -85, 3);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, 0);
    
    glBindTexture(GL_TEXTURE_2D, textureNames[5]);
    
    glPushMatrix();
        makeDesk(-105, -120);
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

void makeBookcase(float z, float x, int num)
{
    bookcases[num].z = z;
    bookcases[num].x = x;
    
    glColor3f(0.17f, 0.12f, 0.0f);
  
    /* Prave se police */
    int i, j = 0;
    for(i = 0; i < 7; i++){
        glPushMatrix();
            glTranslatef(x, j, z);
            glScalef(120, 2, 20);
            glutSolidCube(1);
        glPopMatrix();
        j += 20;
    }
    
    /* Prave se bocne strane ormana */
    glPushMatrix();
        if(x > 0)
            glTranslatef(x*1.7, x*0.71, z);
        else
            glTranslatef(x*1.7, -x*0.71, z);
        glRotatef(-90, 0, 0, 1);
        glScalef(120, 2, 20);
        glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
        if(x > 0)
            glTranslatef(x*0.3, x*0.71, z);
        else
            glTranslatef(x*0.3, -x*0.71, z);
        glRotatef(90, 0, 0, 1);
        glScalef(120, 2, 20);
        glutSolidCube(1);
    glPopMatrix();
}

void makeDesk(float z, float x)
{
    /* radna ploca */
    glPushMatrix();
        glTranslatef(x, 40, z);
        glScalef(30, 3, 80);
        glutSolidCube(1);
    glPopMatrix();
    
    /* bocne strane */
    glPushMatrix();
        glTranslatef(x, 10, z+35);
        glRotatef(90, 1, 0, 0);
        glScalef(20, 3, 60);
        glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(x, 10, z-35);
        glRotatef(90, 1, 0, 0);
        glScalef(20, 3, 60);
        glutSolidCube(1);
    glPopMatrix();
}