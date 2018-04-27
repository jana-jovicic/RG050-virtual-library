#include "../headers/global_variables.h"
#include "../headers/keyboard.h"
#include "../headers/books.h"
#include "../headers/texture.h"
#include "../headers/room.h"

void displayBook(char *title)
{    
    int width, height;

    glfwMakeContextCurrent(bookWindow);

    glfwGetFramebufferSize(bookWindow, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(1.0, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
       
    
    if(!strcmp(title, "1984"))
        openBook("books/1984.txt");
    else if(!strcmp(title, "Never let me go"))
        openBook("books/Never_let_me_go.txt");
    else if(!strcmp(title, "Holmes"))
        openBook("books/Holmes.txt");
    
    glfwSwapBuffers(bookWindow);
}

void openBook(char *titlePath)
{
    
    /* Kreiranje fonta je uradjeno na osnovu tutorijala:
       http://ftgl.sourceforge.net/docs/html/ftgl-tutorial.html
     */
    
    glColor4d(0.0, 0.0, 0.0, 1.0);
        
    FTGLfont *font = ftglCreatePixmapFont("books/HomePlanetBB-BoldItalic.ttf");

    if(!font){
        exit(EXIT_FAILURE);
    }

    ftglSetFontFaceSize(font, 16, 16);
    
    FILE *f = fopen(titlePath, "r");
    if(f == NULL){
        fprintf(stderr, "File open failed\n");
        exit(EXIT_FAILURE);
    }
    
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    GLfloat fontX = -0.99;
    GLfloat fontY = 0.95;
    
    glRasterPos2f(fontX, fontY);
    
    while((read = getline(&line, &len, f)) != -1)
    {
        ftglRenderFont(font, line, FTGL_RENDER_ALL);
        fontY -= 0.045;
        glRasterPos2f(fontX, fontY);
    }
    
    ftglDestroyFont(font);
}

void makeBooks(float x, float y, float z, float scaleX, float scaleY, float scaleZ, GLuint textureName){
    
    glBindTexture(GL_TEXTURE_2D, textureName);
    glColor4f( 0.5f, 0.5f, 0.5f, 1.0f );
    
    glTranslatef(x, y, z);
    glScalef(scaleX, scaleY, scaleZ);
    
    glBegin(GL_QUADS);
            glNormal3f(0, 0, 1);

            glTexCoord2f(0, 0);
            glVertex3f(1, 0, 0.01);

            glTexCoord2f(1, 0);
            glVertex3f(2, 0, 0.01);

            glTexCoord2f(1, 1);
            glVertex3f(2, 2, 0.01);

            glTexCoord2f(0, 1);
            glVertex3f(1, 2, 0.01);
    glEnd();
        
    glPopMatrix();
        
    glBindTexture(GL_TEXTURE_2D, 0);
}

void makeReadableBook(Book b, GLuint textureName){
    
    float x = b.x;
    float y = b.y;
    float z = b.z;
    
    glBindTexture(GL_TEXTURE_2D, textureName);
    glColor4f( 0.9f, 1.0f, 1.0f, 1.0f );
    
    glPushMatrix();
        glTranslatef(x+12.5, y+7, z-2);
        glScalef(9, 14, 1);
        glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    
    glTranslatef(x-1, y, z-1.5);
    glScalef(9, 7, 1);
    
    glBegin(GL_QUADS);
            glNormal3f(0, 0, 1);

            glTexCoord2f(0, 0);
            glVertex3f(1, 0, 0.01);

            glTexCoord2f(1, 0);
            glVertex3f(2, 0, 0.01);

            glTexCoord2f(1, 1);
            glVertex3f(2, 2, 0.01);

            glTexCoord2f(0, 1);
            glVertex3f(1, 2, 0.01);
    glEnd();
        
    glPopMatrix();
        
    glBindTexture(GL_TEXTURE_2D, 0);
}

void placeBooks()
{    
    /* Knjige u prednjoj levoj polici */
    
    glPushMatrix();
        makeBooks(-95, 2, 55, 120, 8.5, 1, textureNames[10]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 2, 45, 120, 8.5, 1, textureNames[10]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-93, 41, 56.9, 118, 8, 1, textureNames[8]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 41, 45, 120, 8.5, 1, textureNames[8]);
    glPopMatrix();
    
    
    /* ------------------- K. Ishiguro -------------------- */
    glPushMatrix();
        makeBooks(5, 61, 55, 20, 8, 1, textureNames[12]);
    glPopMatrix();
    
    /* Never let me go */
    glPushMatrix();
        books[1].x = 36;
        books[1].y = 61;
        books[1].z = 58;
        strcpy(books[1].title, "Never let me go");
        makeReadableBook(books[1], textureNames[11]);
    glPopMatrix();
    /*------------------------------------------------------*/
    
    glPushMatrix();
        makeBooks(-55, 61, 55, 100, 9, 1, textureNames[9]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 61, 45, 120, 8, 1, textureNames[9]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-95, 102, 55, 120, 8.5, 1, textureNames[8]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 102, 45, 120, 8.5, 1, textureNames[8]);
    glPopMatrix();
    
    
    /* ---------------------- Holmes ------------------------ */
    /*glPushMatrix();
        makeBooks(114, 41, 55, 15, 8, 1, textureNames[13]);
    glPopMatrix();
    */
    glPushMatrix();
        books[2].x = 126;
        books[2].y = 41;
        books[2].z = 58.5;
        strcpy(books[2].title, "Holmes");
        makeReadableBook(books[2], textureNames[13]);
    glPopMatrix();
    /*--------------------------------------------------------*/

    glPushMatrix();
        makeBooks(25, 21, 57.5, 61, 10, 1, textureNames[15]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-36, 21, 57.5, 61, 10, 1, textureNames[15]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(25, 21, 45, 61, 10, 1, textureNames[17]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-36, 21, 45, 61, 10, 1, textureNames[17]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(25, 81, 45, 61, 10, 1, textureNames[14]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-36, 81, 45, 61, 10, 1, textureNames[14]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(25, 81, 55, 61, 10, 1, textureNames[14]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-36, 81, 55, 61, 10, 1, textureNames[14]);
    glPopMatrix();
}