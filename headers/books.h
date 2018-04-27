#ifndef _BOOKs_H_
#define _BOOKs_H_

#define NUM_OF_BOOKS 3

typedef struct{
    float x;
    float y;
    float z;
    char title[200];
}Book;

extern Book books[NUM_OF_BOOKS];

void displayBook(char *title);
void openBook(char *titlePath);

void makeBooks(float x, float y, float z, float scaleX, float scaleY, float scaleZ, GLuint textureName);
void makeReadableBook(Book b, GLuint textureName);
void placeBooks();

#endif