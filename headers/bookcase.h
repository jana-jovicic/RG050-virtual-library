#ifndef _BOOKCASE_H_
#define _BOOKCASE_H_

#define MAX_BOOKCASES 10
#define NUM_OF_BOOKS 2

typedef struct{
    float x;
    float z;
}Bookcase;

typedef struct{
    float x;
    float z;
    char title[200];
}Book;

extern Bookcase bookcases[MAX_BOOKCASES];
extern Book books[NUM_OF_BOOKS];

void drawBookcases();
void makeBookcase(float z, float x, int num);
void makeDesk(float z, float x);


#endif