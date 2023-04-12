#ifndef QUAD_H
#define QUAD_H

typedef struct Quadr
{
    char *op;
    char *arg1;
    char *arg2;
    char *result;
} Quadr;

int insert_quadruplet(char *op, char *arg1, char *arg2, char *result);

char *next_temp();

void display_quadruplets();

#endif // QUADR_H
