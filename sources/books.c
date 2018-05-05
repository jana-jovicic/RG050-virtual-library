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
    else if(!strcmp(title, "Besnilo"))
        openBook("books/Besnilo.txt");
    else if(!strcmp(title, "The book thief"))
        openBook("books/The_book_thief.txt");
    else if(!strcmp(title, "Blindness"))
        openBook("books/Blindness.txt");
    else if(!strcmp(title, "Smrt i njeni hirovi"))
        openBook("books/Smrt_i_njeni_hirovi.txt");
    else if(!strcmp(title, "The blind assassin"))
        openBook("books/The_blind_assassin.txt");
    else if(!strcmp(title, "Stranac"))
        openBook("books/Stranac.txt");
    else if(!strcmp(title, "Raven"))
        openBook("books/Raven.txt");
    else if(!strcmp(title, "Kafka na obali mora"))
        openBook("books/Kafka_na_obali_mora.txt");
    
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
    
    /* pravi se knjiga */
    glPushMatrix();
        glTranslatef(x+12.5, y+7, z-2);
        glScalef(9, 14, 1);
        glutSolidCube(1);
    glPopMatrix();
    
    /* pravi se naslovna strana knjige */
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
    /* Knjige u prednjoj desnoj polici */
    
    glPushMatrix();
        makeBooks(-95, 2, 55, 120, 9, 1, textureNames[10]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 2, 45, 120, 9, 1, textureNames[10]);
    glPopMatrix();
    
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
        makeBooks(-93, 41, 56.9, 118, 8.5, 1, textureNames[8]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 41, 45, 120, 9, 1, textureNames[8]);
    glPopMatrix();
    
    /* ---------------------- Holmes ------------------------ */
    glPushMatrix();
        books[2].x = 126;
        books[2].y = 41;
        books[2].z = 58.5;
        strcpy(books[2].title, "Holmes");
        makeReadableBook(books[2], textureNames[13]);
    glPopMatrix();
    /*--------------------------------------------------------*/
    
    /* ------------------- K. Ishiguro -------------------- */
    glPushMatrix();
        makeBooks(5, 61, 55, 20, 8, 1, textureNames[12]);
    glPopMatrix();
    
    glPushMatrix();
        books[1].x = 36;
        books[1].y = 61;
        books[1].z = 58;
        strcpy(books[1].title, "Never let me go");
        makeReadableBook(books[1], textureNames[11]);
    glPopMatrix();
    /*------------------------------------------------------*/
    
    /* --------------------- E. A. Poe --------------------- */
    
    glPushMatrix();
        books[9].x = 76;
        books[9].y = 61;
        books[9].z = 58;
        strcpy(books[9].title, "Raven");
        makeReadableBook(books[9], textureNames[36]);
    glPopMatrix();
    /*------------------------------------------------------*/
    
    glPushMatrix();
        makeBooks(-55, 61, 55, 100, 9, 1, textureNames[9]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 61, 45, 120, 9, 1, textureNames[9]);
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
    
    glPushMatrix();
        makeBooks(-95, 102, 55, 120, 9, 1, textureNames[8]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 102, 45, 120, 9, 1, textureNames[8]);
    glPopMatrix();
    
    /* Knjige u prednjoj levoj polici */
    
    glPushMatrix();
        makeBooks(-265, 2, 55, 120, 9, 1, textureNames[34]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 2, 45, 120, 9, 1, textureNames[34]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-265, 21, 55, 120, 9, 1, textureNames[31]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 21, 45, 120, 9, 1, textureNames[31]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-238, 41, 55, 93, 9, 1, textureNames[10]);
    glPopMatrix();
    glPushMatrix();
    glPushMatrix();
        makeBooks(-205, 41, 45, 60, 9, 1, textureNames[15]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-145, 41, 45, 60, 9, 1, textureNames[15]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-265, 61, 55, 120, 9, 1, textureNames[9]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 61, 45, 120, 9, 1, textureNames[9]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-265, 81, 55, 120, 9, 1, textureNames[32]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 81, 45, 120, 9, 1, textureNames[32]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-265, 102, 55, 120, 9, 1, textureNames[33]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 102, 45, 120, 9, 1, textureNames[33]);
    glPopMatrix();
    
    /*------------------------ Pekic -------------------------*/
    glPushMatrix();
        makeBooks(-65, 41, 55, 13, 8.7, 1, textureNames[18]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-52, 41, 55, 13, 8.7, 1, textureNames[18]);
    glPopMatrix();
    
    glPushMatrix();
        books[3].x = -46;
        books[3].y = 41;
        books[3].z = 58;
        strcpy(books[3].title, "Besnilo");
        makeReadableBook(books[3], textureNames[21]);
    glPopMatrix();
    /*--------------------------------------------------------*/
    
    /*------------------------ Zusak -------------------------*/
    glPushMatrix();
        books[4].x = -96;
        books[4].y = 81;
        books[4].z = 58;
        strcpy(books[4].title, "The book thief");
        makeReadableBook(books[4], textureNames[22]);
    glPopMatrix();
    /*--------------------------------------------------------*/
    
    /*--------------------- Saramago -------------------------*/
    glPushMatrix();
        books[5].x = -140;
        books[5].y = 61;
        books[5].z = 58;
        strcpy(books[5].title, "Smrt i njeni hirovi");
        makeReadableBook(books[5], textureNames[20]);
    glPopMatrix();
    
    glPushMatrix();
        books[6].x = -140;
        books[6].y = 61;
        books[6].z = -41;
        strcpy(books[6].title, "Blindness");
        makeReadableBook(books[6], textureNames[24]);
    glPopMatrix();
    /*--------------------------------------------------------*/
    
    
    /* Knjige u zadnjoj levoj polici */
    
    glPushMatrix();
        makeBooks(-265, 2, -44, 120, 9, 1, textureNames[35]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 2, -54, 120, 9, 1, textureNames[35]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-205, 21, -44, 60, 9, 1, textureNames[28]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-145, 21, -44, 60, 9, 1, textureNames[28]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 21, -54, 120, 9, 1, textureNames[8]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-205, 41, -44, 60, 9, 1, textureNames[17]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-87, 41, -44.5, 30, 9, 1, textureNames[27]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-115, 41, -44, 30, 9, 1, textureNames[26]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 41, -54, 120, 9, 1, textureNames[32]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-265, 61, -44, 120, 9, 1, textureNames[9]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 61, -54, 120, 9, 1, textureNames[9]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-265, 81, -44, 120, 9, 1, textureNames[33]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 81, -54, 120, 9, 1, textureNames[33]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-265, 101, -44, 120, 9, 1, textureNames[34]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-265, 101, -54, 120, 9, 1, textureNames[34]);
    glPopMatrix();
    
    /*--------------------- M. Atwood ------------------------*/
    glPushMatrix();
        books[7].x = -46;
        books[7].y = 61;
        books[7].z = -41;
        strcpy(books[7].title, "The blind assassin");
        makeReadableBook(books[7], textureNames[19]);
    glPopMatrix();
    /*--------------------------------------------------------*/

    /*---------------------- Kami ----------------------------*/
    glPushMatrix();
        books[8].x = -95;
        books[8].y = 81;
        books[8].z = -41;
        strcpy(books[8].title, "Stranac");
        makeReadableBook(books[8], textureNames[23]);
    glPopMatrix();
    /*--------------------------------------------------------*/
    
    
    /* Knjige u zadnjoj desnoj polici */
    
    glPushMatrix();
        makeBooks(62, 2, -44, 41, 9, 1, textureNames[39]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(25, 2, -44, 41, 9, 1, textureNames[39]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-16, 2, -44, 41, 9, 1, textureNames[39]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(62, 2, -54, 41, 9, 1, textureNames[39]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(25, 2, -54, 41, 9, 1, textureNames[39]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-16, 2, -54, 41, 9, 1, textureNames[39]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(25, 21, -44, 61, 10, 1, textureNames[14]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-36, 21, -44, 61, 10, 1, textureNames[14]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(25, 21, -54, 61, 10, 1, textureNames[14]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-36, 21, -54, 61, 10, 1, textureNames[14]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(25, 41, -44, 61, 10, 1, textureNames[38]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-36, 41, -44, 61, 10, 1, textureNames[38]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(25, 41, -54, 61, 10, 1, textureNames[38]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-36, 41, -54, 61, 10, 1, textureNames[38]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-45, 61, -44, 70, 9, 1, textureNames[37]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 61, -54, 120, 9, 1, textureNames[34]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(-95, 81, -44, 120, 9, 1, textureNames[32]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-95, 81, -54, 120, 9, 1, textureNames[32]);
    glPopMatrix();
    
    glPushMatrix();
        makeBooks(62, 101, -44, 41, 10, 1, textureNames[40]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(25, 101, -44, 41, 10, 1, textureNames[40]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-16, 101, -44, 41, 10, 1, textureNames[40]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(62, 101, -54, 41, 10, 1, textureNames[40]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(25, 101, -54, 41, 10, 1, textureNames[40]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(-16, 101, -54, 41, 10, 1, textureNames[40]);
    glPopMatrix();
    
    /* --------------------- Murakami --------------------- */
    glPushMatrix();
        makeBooks(69, 61, -43.5, 25, 9, 1, textureNames[30]);
    glPopMatrix();
    glPushMatrix();
        makeBooks(89, 61, -44, 28, 9, 1, textureNames[29]);
    glPopMatrix();
    
    glPushMatrix();
        books[10].x = 105;
        books[10].y = 61;
        books[10].z = -41;
        strcpy(books[10].title, "Kafka na obali mora");
        makeReadableBook(books[10], textureNames[25]);
    glPopMatrix();
    /*------------------------------------------------------*/
}