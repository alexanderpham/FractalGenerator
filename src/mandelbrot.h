/*
Authors: Alexander Pham, Kushal Saini, Nimrat Brar
Course: COMP 3659
Assignment: Programming Project 2
Professor: Marc Schroeder
Filename: mandelbrot.c

File Status: Fully functional

Purpose: Contains functions for calculating the mandelbrot fractal
*/

#ifndef MANDELBROT_H
#define MANDELBROT_H

/*
Function: mandelbrot
Purpose: calls functions to calculate mandelbrot fractal for coordinates
Inputs:
    - x: x coordinate
    - y: y coordinate
    - iterations: max number of iterations to be performed on the mandelbrot equation
    - imgRes: dimension of the image
*/
int mandelbrot(int x, int y, int iterations, int imgRes);

/*
Function: xConvert
Purpose: converts x coordinate to complex x-coordinate on the real axis
Inputs:
    - xPixel: x coordinate
    - imageSize: dimension of image
*/
double xConvert (int xPixel, int imgRes);

/*
Function: yConvert
Purpose: converts y coordinate to complex y-coordinate on the imaginary axis
Inputs:
    - yPixel: y coordinate
    - imageSize: dimension of image
*/
double yConvert (int yPixel, int imgRes);

/*
Function: calculateMandelbrot
Purpose: calculates the number of iterations not used on the mandelbrot equation
Inputs:
    - xComplex: x-coordinate on the complex plane (real axis)
    - yComplex: y-coordinate on the complex plane (imaginary axis)
    - iterations: max number of iterations that can be performed
    - zx: real number value in mandelbrot equation
    - zy: imaginary number value in mandelbrot equation
*/
int calculateMandelbrot(double xComplex, double yComplex, int iterations, double zx, double zy);

#endif