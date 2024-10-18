/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 2

File name: memMap.c

Instructor: Marc Schroeder

Purpose:  creates a new file with the specified name, 
allocates a given amount of space for it on disk, and 
maps the file into memory for writing, returning a 
pointer to the mapped memory or NULL in case of errors.

*/

#include "memMap.h"


char* createFileMap(char* filename, int filesize) {
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600); // Modify flags and permissions accordingly
    if (fd == -1) {
        perror("Error opening file");
        return NULL;
    }

    if (ftruncate(fd, filesize) == -1) { // Truncate file to desired size
        perror("Error truncating file");
        close(fd);
        return NULL;
    }

    char *fileMap = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (fileMap == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        return NULL;
    }

    close(fd); // Closing file descriptor since it's mapped into memory

    return fileMap;
}
