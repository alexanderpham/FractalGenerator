/*
Authors: Alexander Pham, Kushal Saini, Nimrat Brar
Course: COMP 3659
Assignment: Programming Project 2
Professor: Marc Schroeder
Filename: main.h

Program Status: Fully functional

Purpose: Output a BMP image of a mandelbrot fractal

Inputs (command line args):

    - arg 1: Resolution of image
        - image generated is a square, so only 1 dimension needed

    - arg 2: Max number of iterations to be performed in the mandelbrot algorithm
        - higher = more detail, longer render time
        - lower = less detail, shorter render time

    - arg 3: Number of threads that should be created
        - must be less than resolution
*/

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "memMap.h"
#include "bitmapLib.h"
#include "coordinateDivider.h"
#include "mandelbrot.h"

#define MAX_FILESIZE 192000054 // = 192.000054 MB
// #define MAX_FILESIZE (MAX_RESOLUTION << 1)3 + 54
#define MAX_RESOLUTION ((MAX_FILESIZE - IMAGE_DATA_OFFSET)/3) >> 1  //8000 pixels
#define MAX_ITERATIONS 4294967295 // unsgined int max

#define TRUE 1
#define FALSE 0

// Holds the parameters for the renderRange function
typedef struct renderRangeParams {
    coordinateRange* range;
    unsigned int iterations;
    unsigned int imgRes;
    char* bmpFile;
} renderRangeParams;

/*
Function: renderRange
Purpose: renders the specified range of coordinates
Input: pointer to renderRangeParams structure
*/
void* renderRange(void* args);

/*
Function: drawPixel
Purpose: renders a pixel
Inputs:
    - x: x coordinate
    - y: y coordinate
    - imgRes: image resolution
    - percentNotUsed: percent of iterations not used in mandelbrot calculation
        - determines colour
    - imgData: pointer to bmp file in memory
*/
void drawPixel(unsigned int x, unsigned int y, unsigned int imgRes, float percentNotUsed, char *imgData);

#endif