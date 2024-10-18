/*

Authours: Alexander Pham, Kushal Saini and Nimrat Brar

Course: COMP 3659 - 001

Programming Project 2

File name: memMap.h

Instructor: Marc Schroeder

Purpose:  creates a new file with the specified name, 
allocates a given amount of space for it on disk, and 
maps the file into memory for writing, returning a 
pointer to the mapped memory or NULL in case of errors.

*/

#ifndef MEMMAP_H
#define MEMMAP_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>

/*

Function: createFileMap

Purpose: create a memory-mapped file with the specified filename and 
allocate the specified amount of disk space, returning a pointer to 
the mapped memory for subsequent read and write operations

Input: takes a string of the file in (pointer to a char)

      - takes in the number of bytes of the file that is to be mapped

Output: pointer to the memory-mapped region created for the file

Details:
The createFileMap function is designed to facilitate the creation of a memory-mapped file. 
It opens a file specified by filename with write-only access, creating the file 
if it does not exist. Subsequently, it allocates disk space for the file using fallocate to
ensure sufficient space is reserved. Finally, it utilizes mmap to map the file into memory, 
returning a pointer (char*) to the beginning of the memory-mapped region. The main purpose is
to provide a convenient interface for creating and accessing memory-mapped files

*/
char* createFileMap(char* filename, int filesize);

#endif
