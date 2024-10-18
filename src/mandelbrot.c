/*
Authors: Alexander Pham, Kushal Saini, Nimrat Brar
Course: COMP 3659
Assignment: Programming Project 2
Professor: Marc Schroeder
Filename: mandelbrot.c

File Status: Fully functional

Purpose: Contains functions for calculating the mandelbrot fractal
*/

#include "mandelbrot.h"

// Max and min values on the complex plane
const double IMAGINARY_END = 1.0;
const double IMAGINARY_START = -1.0;
const double REAL_START = -1.5;
const double REAL_END = 0.5;

const double INITIAL_Z = 0.0; // Initial value of variables zx and zy in the calculateMandelbrot function

int mandelbrot(int x, int y, int iterations, int imgRes)
{
    // convert x,y coordinates to complex plane
    double xComplex = xConvert(x, imgRes);
    double yComplex = yConvert(y, imgRes);

    return calculateMandelbrot(xComplex, yComplex, iterations, INITIAL_Z, INITIAL_Z);
}

double xConvert(int xPixel, int imgRes)
{
    return REAL_START + (xPixel / (((double)imgRes) - 1)) * (REAL_END - REAL_START);
}

double yConvert(int yPixel, int imgRes)
{
    return IMAGINARY_END - (yPixel / (((double)imgRes) - 1)) * (IMAGINARY_END - IMAGINARY_START);
}

int calculateMandelbrot(double xComplex, double yComplex, int iterations, double zx, double zy)
{
    double temp_zx;
    int counter;

    if ((iterations > 0) && (zx * zx + zy * zy < 4.0))
    {
        temp_zx = zx * zx - zy * zy + xComplex;
        zy = 2.0 * zx * zy + yComplex;
        zx = temp_zx;
        // recursive call, decrements iterations
        counter = calculateMandelbrot(xComplex, yComplex, iterations - 1, zx, zy);
    }
    else
    {
        counter = iterations;
    }

    return counter;
}