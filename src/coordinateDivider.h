/*
Authors: Alexander Pham, Kushal Saini, Nimrat Brar
Course: COMP 3659
Assignment: Programming Project 2
Professor: Marc Schroeder
Filename: coordinateDivider.c

File Status: Fully functional

Purpose: Contains functions for dividing an image into sections
*/

#ifndef COORDINATE_DIVIDER_H
#define COORDINATE_DIVIDER_H

#include <stdlib.h>

typedef struct coordinateRange {
    int xStart;
    int yStart;
    int xEnd;
    int yEnd;
} coordinateRange;

struct coordinateRange* divideCoordinates(int threadCount, int resolution);
void testDivideCoordinates(int threadCount, int resolution);

#endif
