/*
Authors: Alexander Pham, Kushal Saini, Nimrat Brar
Course: COMP 3659
Assignment: Programming Project 2
Professor: Marc Schroeder
Filename: bitmapLib.c

File Status: Fully functional

Purpose: Contains functions for creating a bmp file
*/

#ifndef BITMAPLIB_H
#define BITMAPLIB_H

#include <stdio.h>

// Header Information
#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL 24
#define IMAGE_DATA_OFFSET 54
#define HEADER_SIZE 40
#define PLANES 1
#define COMPRESSION 0
#define X_PIXELS_PER_METER 0
#define Y_PIXELS_PER_METER 0
#define TOTAL_COLORS 0
#define IMPORTANT_COLORS 0

// Colour Information
#define RGB(r,g,b) ((RGBColour){(r),(g),(b)})
#define BLACK RGB(0, 0, 0)
#define SUNSET_RED RGB(189, 74, 82)
#define RED_ORANGE RGB(232, 112, 82)
#define LIGHT_ORANGE RGB(245, 164, 97)
#define YELLOW_ORANGE RGB(232, 196, 107)
#define CYAN_TEAL RGB(41, 158, 143)
#define R_OFFSET(x, y, imgRes) ((y * imgRes + x)*BYTES_PER_PIXEL + IMAGE_DATA_OFFSET)
#define G_OFFSET(x, y, imgRes) ((y * imgRes + x)*BYTES_PER_PIXEL + IMAGE_DATA_OFFSET + 1)
#define B_OFFSET(x, y, imgRes) ((y * imgRes + x)*BYTES_PER_PIXEL + IMAGE_DATA_OFFSET + 2)

// Holds the rgb values of a pixel
typedef struct RGBColour {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGBColour;

/*
Function: calculateFileSize
Purpose: calculates the size of the bmp file from the resolution
Input:
    - imgRes: dimension of image
Return:
    - unsinged int: size of file in bytes
*/
unsigned int calculateFilesize(unsigned int imgRes);

/*
Function: writeHeader
Purpose: writes the header of the bitmap
Input:
    - header: pointer to the bmp file
    - res: dimensionss of image
    - filesize: total size of bmp file in bytes
    - imgSize: size of the image data in bytes
*/
void writeHeader(char* header, unsigned int res, unsigned int filesize, unsigned int imgSize);

/*
Function: writePixel
Purpose: writes a single pixel to the file (adding padding where needed)
Input:
    - x: x coordinate
    - y: y coordinate
    - imgRes: dimensions of image
    - colour: struct containing rgb values for the pixel
*/
void writePixel(unsigned int x, unsigned int y, unsigned int imgRes, RGBColour* colour, char* bmpFile);

#endif