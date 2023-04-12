#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quad.h"

#define MAX_QUAD 100

Quadr *quadruplets = NULL;

int next_quadruplet_index = 0;
int next_temp_index = 0;

int insert_quadruplet(char *op, char *arg1, char *arg2, char *result)
{
    if (quadruplets == NULL)
        quadruplets = malloc(sizeof(Quadr) * MAX_QUAD);

    quadruplets[next_quadruplet_index].op = op;
    quadruplets[next_quadruplet_index].arg1 = arg1;
    quadruplets[next_quadruplet_index].arg2 = arg2;
    quadruplets[next_quadruplet_index].result = result;

    return next_quadruplet_index++;
}

char *next_temp()
{
    char *temp = malloc(sizeof(char) * 4);

    sprintf(temp, "T%d", next_temp_index++);

    return temp;
}

void display_quadruplets()
{
    for (int i = 0; i < next_quadruplet_index; i++)
        printf("%d - (%s, %s, %s, %s)\n", i, quadruplets[i].op, quadruplets[i].arg1, quadruplets[i].arg2, quadruplets[i].result);
}
