/*
Authors: Alexander Pham, Kushal Saini, Nimrat Brar
Course: COMP 3659
Assignment: Programming Project 2
Professor: Marc Schroeder
Filename: coordinateDivider.c

File Status: Fully functional

Purpose: Contains functions for dividing an image into sections
*/

#include "coordinateDivider.h"

struct coordinateRange* divideCoordinates(int threadCount, int resolution) {
    /*
    this function is given two parameters, threadCount and resolution.
    ThreadCount is the number of threads that the function caller desires to use
    and the resolution is just how big the image of the fractal will be.
    This functions purpose is to divide up the work for a specified amount of threads for
    certain sections of the overall image.
    this function returns a pointer to the array of coordinates structs so any c
    thread can access the coordinates they need to render.
    return pointer to array of coordinateRange structs
    */

    //Let us allocate memory so other threads can access this.
    struct coordinateRange* ranges = (struct coordinateRange*)malloc(threadCount * sizeof(struct coordinateRange));
    if(ranges == NULL)
    {
        return NULL;
    }

    //calculate the number of rows and columns for each thread

    //int rowsPerThread = resolution / threadCount;
    int colsPerThread = resolution/ threadCount;
    // Calculate the coordinates

    for ( int i = 0; i < threadCount; i++){
        ranges[i].xStart = i * colsPerThread;
        ranges[i].xEnd = (i+1) * colsPerThread - 1;
        ranges[i].yStart = 0;
        ranges[i].yEnd = resolution -1;
    
    }

    // adjust the last thread's xend to cover the remaining columns
    ranges[threadCount-1].xEnd = resolution -1;

    return ranges;

    
}

/*
void testDivideCoordinates(int threadCount, int resolution){

    // call function
    struct coordinateRange* ranges = divideCoordinates(threadCount,resolution);
    if(ranges != NULL){

        for ( int i = 0; i < threadCount; i++)
        {
            printf("Thread %d: xStart=%d, xEnd=%d, yStart=%d, yEnd=%d\n",
             i+1, ranges[i].xStart, ranges[i].xEnd, ranges[i].yStart, ranges[i].yEnd);

        }

        // frees the allocated memory
        free(ranges);
    

    }
    else{
        printf(" Memory allocation failed.");
    }
    return;
}

int main(int argc, char* argv[]) {
    int threads = atoi(argv[1]);
    int res = atoi(argv[2]);
    testDivideCoordinates(threads, res);
    return 0;
}
*/
