#include <stdio.h>
#include <stdlib.h>

void afm(int vmap[100][100], int l, int h);/*show the map*/
void AI(int vmap[100][100], int l, int h, int x, int y, int date);/*artificial intelegenece fill the map with fire days*/
int *zeropos(int vmap[100][100], int l, int h);/*find the zero prosition (the fire startup*/
int h(FILE* map);/*count the map high (lines)*/
int l(FILE* map);/*count the length (columns)*/