#include "../headers/global_variables.h"
#include "../headers/keyboard.h"
#include "../headers/books.h"

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
        fontY -= 0.04;
        glRasterPos2f(fontX, fontY);
    }
    
    ftglDestroyFont(font);
}