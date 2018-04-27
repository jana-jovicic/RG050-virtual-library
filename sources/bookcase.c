#include "../headers/global_variables.h"
#include "../headers/bookcase.h"
#include "../headers/books.h"
#include "../headers/texture.h"

Bookcase bookcases[MAX_BOOKCASES];
Book books[NUM_OF_BOOKS];

void drawBookcases()
{
    /* Prave se 4 police za knjige i radni sto */
    
    // zadnja desna
    glPushMatrix();
        makeBookcase(-50, 85, 0);
    glPopMatrix();

    // zadnja leva
    glPushMatrix();
        makeBookcase(-50, -85, 1);
    glPopMatrix();
    
    // prednja desna
    glPushMatrix();
        makeBookcase(50, 85, 2);
    glPopMatrix();

    // prednja leva
    glPushMatrix();
        makeBookcase(50, -85, 3);
    glPopMatrix();

    glPushMatrix();
        makeDesk(-105, -120);
    glPopMatrix();
    
    placeBooks();
}

void makeBookcase(float z, float x, int num)
{
    glBindTexture(GL_TEXTURE_2D, textureNames[4]);
    
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
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

void makeDesk(float z, float x)
{
    glBindTexture(GL_TEXTURE_2D, textureNames[5]);
    
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
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    /* Prave se knjige */
  
    /* Orwell, 1984 (postavlja se u niz books na nultu poziciju) */
    
    glBindTexture(GL_TEXTURE_2D, textureNames[7]);
    glColor4f( 1.0f, 1.0f, 1.0f, 1.0f );
    
    glPushMatrix();
        glTranslatef(-65, 135, -185);
        glRotatef(270, 1, 0, 0);
        glRotatef(-270, 0, 0, 1);
        books[0].x = -110;
        books[0].z = -90;
        books[0].y = 42;
        strcpy(books[0].title, "1984");
        makeReadableBook(books[0], textureNames[7]);
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, 0);
}