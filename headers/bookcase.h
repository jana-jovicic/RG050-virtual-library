#ifndef _BOOKCASE_H_
#define _BOOKCASE_H_

#define MAX_BOOKCASES 10

typedef struct{
    float x;
    float z;
}Bookcase;

extern Bookcase bookcases[MAX_BOOKCASES];

void drawBookcases();
void makeBookcase(float z, float x, int num);
void makeDesk(float z, float x);

#endif