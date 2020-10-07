#ifndef MENGER_S
#define MENGER_S

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menger(int level);
void print_sponge(int size, char *sponge[size]);
void add_one(int size, char *sponge[size], int x, int y, char val);
void update_copy(int size, char *org[size], char *copy[size]);

#endif /* MENGER_S */
