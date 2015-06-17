/*
 * This library proivides access routines to allocate and release the shared memory block.
 *
 * Copyright (c) Embrisk Ltd 2012.
 * This is public domain software with no warranty.
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>

#include "embshmem.h"
static const char *devName = "/dev/embshmem0";
static int shmemLength;
static void *shmem;

/*
 * Get a pointer to the shared memory block of specified length.
 */
void *ShmemGet(int length)
{
    FILE *fp;
    int fd;
    
    fp = fopen(devName, "r+");
    if (!fp) {
        fprintf(stderr, "Unable to open file '%s'\n", devName);
        exit(1);
    }
    fd = fileno(fp);

    shmem = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED, fd, 0);
    if (shmem == (void *)MAP_FAILED) {
        fprintf(stderr, "Couldn't allocate shared memory.  Error %d\n", errno);
        perror(NULL);
        shmem = NULL;
        return(NULL);
    }
    printf("Got shared memory - address %p\n", shmem);

    shmemLength = length;
    fclose(fp);
    return(shmem);
}

/*
 * Release the previously allocated shared memory block.
 */
void ShmemRelease(void)
{
    if (shmem) {
        munmap(shmem, shmemLength);
    }
}
