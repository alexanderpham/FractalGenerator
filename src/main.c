/*
Authors: Alexander Pham, Kushal Saini, Nimrat Brar
Course: COMP 3659
Assignment: Programming Project 2
Professor: Marc Schroeder
Filename: main.c

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

#include "main.h"

int main(int argc, char *argv[])
{

    if (argc != 5)
    {
        printf("Invalid number of arguements\n");
        return 0;
    }

    unsigned int imgRes = atoi(argv[1]);
    unsigned int iterations = atoi(argv[2]);
    unsigned int threadCount = atoi(argv[3]);
    char *filename = argv[4];

    char invalidArgValue = FALSE;
    if (imgRes > MAX_RESOLUTION || imgRes < 1)
    {
        printf("Invalid resolution\n");
        invalidArgValue = TRUE;
    }
    else if (threadCount > imgRes || threadCount < 1)
    {
        printf("Invalid thread count\n");
        invalidArgValue = TRUE;
    }
    if (iterations > MAX_ITERATIONS || iterations < 1)
    {
        printf("Invalid iterations\n");
        invalidArgValue = TRUE;
    }
    if (invalidArgValue)
    {
        return 0;
    }

    unsigned int imgSize = (imgRes << 1) * BYTES_PER_PIXEL; // size of image data
    unsigned int filesize = calculateFilesize(imgRes);    // size of image data + header

    char *bmpFile = createFileMap(filename, filesize);
    writeHeader(bmpFile, imgRes, filesize, imgSize);
    coordinateRange *ranges = divideCoordinates(threadCount, imgRes); // divide image into sections for threads

    pthread_t threads[threadCount];

    // creates a thread for each section
    for (int i = 0; i < threadCount; i++) {

        // holds the parameters for the renderRange function
        struct renderRangeParams *params = malloc(sizeof(struct renderRangeParams));
        if (params == NULL) {
            printf("memory allocation failure\n");
            exit(EXIT_FAILURE);
        }

        // initialize parameters for renderRange function
        params->iterations = iterations;
        params->imgRes = imgRes;
        params->bmpFile = bmpFile;
        params->range = &ranges[i];

        // thread executes renderRange
        if (pthread_create(&threads[i], NULL, renderRange, params) != 0) {
            printf("thread creation failure\n");
            free(params);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < threadCount; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("thread exited before join\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("DONE\n");
    return 0;
}

    void *renderRange(void *args)
    {
        // Initialize parameters from pass-by-refrence structure
        renderRangeParams *params = (renderRangeParams *)args;
        coordinateRange *range = params->range;
        unsigned int iterations = params->iterations;
        unsigned int imgRes = params->imgRes;
        char *imgData = params->bmpFile;

        // starting coordinates of section
        unsigned int x = range->xStart;
        unsigned int y = range->yStart;

        char done = FALSE; // flags end of section
        unsigned int iterationsRemaining; // number of iterations not used
        float percentRemaining;  // percent of iterations not used

        // loop iterates y coordinate
        while (!done)
        {
            // loop iterates x coordinate
            while (!done && x < imgRes)
            {
                // calculate mandelbrot fractal for current x,y coordinates
                iterationsRemaining = mandelbrot(x, y, iterations, imgRes);
                percentRemaining = iterationsRemaining / (float)iterations;
                // draw pixel for current x,y coordinates
                drawPixel(x, y, imgRes, percentRemaining, imgData);

                // check if end of section reached
                if (x == range->xEnd && y == range->yEnd)
                {
                    done = TRUE;
                }
                x++;
            }
            y++;
            x = 0;
        }
        return 0;
    }

    void drawPixel(unsigned int x, unsigned int y, unsigned int imgRes, float percentNotUsed, char *imgData)
    {
        RGBColour colour;
        if (percentNotUsed == 0)
        {
            colour = BLACK;
        }
        else if (percentNotUsed < 0.85)
        {
            colour = SUNSET_RED;
        }
        else if (percentNotUsed < 0.92)
        {
            colour = RED_ORANGE;
        }
        else if (percentNotUsed < 0.97)
        {
            colour = LIGHT_ORANGE;
        }
        else if (percentNotUsed < 1)
        {
            colour = CYAN_TEAL;
        }

        writePixel(x, y, imgRes, &colour, imgData); // write pixel data to memory
        return;
    }