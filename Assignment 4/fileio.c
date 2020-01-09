#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "filter.h"

Filter *loadFilter(char *filterfile) {
    Filter *filter = malloc(sizeof(Filter));
    FILE* fd = fopen(filterfile, "r");
    fscanf(fd, "%d", &(filter->size));
    double scale=0;
    fscanf(fd, "%lf", &scale);
    double *kernel = malloc(filter->size * filter->size * sizeof(double));
    for (int i = 0; i < filter->size; i++)
        for(int j = 0; j < filter->size; j++)
	  {
            fscanf(fd, "%lf", kernel + i * filter->size + j);
	    kernel[i * filter->size + j]/= scale;
	  }
    filter->kernel = kernel;
    fclose(fd);
    return filter;
}

void freeFilter(Filter *filter) {
    free(filter->kernel);
    free(filter);
}

void writePPM(const char* file, const PPM* ppm)
{
    int i;

    // open file for writing
    FILE* fd;
    fd = fopen(file, "w");

    // output the header
    fprintf(fd, "P3\n");
    fprintf(fd, "%d %d\n%d\n", ppm->w, ppm->h, ppm->max);

    for (i = 0; i < ppm->h * ppm->w; i++) {
        const RGB* p = ppm->im + i;
        fprintf(fd, "%d %d %d ", p->r, p->g, p->b);
    }
    fclose(fd);
}

PPM* readPPM(const char* file)
{
    /* Read a PPM P3 image from a file into a buffer.  Return the
     buffer, w, h, and the max value in the image. */

    FILE* fd;
    char c;
    int i, n;
    char b[100];
    int red, green, blue;

    // check if P3 ppm format
    fd = fopen(file, "r");
    n = fscanf(fd, "%[^\n] ", b);
    if (b[0] != 'P' || b[1] != '3') {
        printf("%s is not a PPM file!\n", file);
        exit(0);
    }
    //  printf("%s is a PPM file\n", file);
    n = fscanf(fd, "%c", &c);
    while (c == '#') {
        n = fscanf(fd, "%[^\n] ", b);
        printf("%s\n", b);
        n = fscanf(fd, "%c", &c);
    }
    ungetc(c, fd);
    int w, h, max;
    n = fscanf(fd, "%d %d %d", &w, &h, &max);
    assert(n == 3);

    //  printf("%d x %d image, max value= %d\n", *w, *h, *max);

    // size of image
    int size = w * h;

    RGB* image = (RGB*)malloc(size * sizeof(RGB));
    assert(image);
    for (i = 0; i < size; i++) {
        n = fscanf(fd, "%d %d %d", &red, &green, &blue);
        assert(n == 3);
        image[i].r = red;
        image[i].g = green;
        image[i].b = blue;
    } 

    PPM *ppm = malloc(sizeof(PPM));
    ppm->h = h;
    ppm->w = w;
    ppm->max = max;
    ppm->im = image;

    fclose(fd);
    return ppm;
}

void freePPM(PPM *ppm) {
    free(ppm->im);
    free(ppm);
}
