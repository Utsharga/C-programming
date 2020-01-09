#include "filter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double getTime(int);

int main(int argc, char** argv)
{
    if (argc != 4) {
        printf("Usage ./filter <input file>  <filter file> <output file> \n");
        return 1;
    }

    PPM *oldPPM, *newPPM;

    char *infile = argv[1], *filterfile = argv[2], *outfile = argv[3];

    // Load filter file into a filter struct
    printf("\nLoading filter%s\n", filterfile);
    double time = getTime(2);
    Filter *filter= loadFilter(filterfile);
    printf("*** %10s filter loaded in %.1e seconds\n", infile, getTime(2) - time);
   
    printf("\nReading file %s\n", infile);
    time = getTime(2);
    oldPPM = readPPM(infile);
    printf("*** %10s read in %.1e seconds\n", infile, getTime(2) - time);
    
    // Create new PPM
    newPPM = malloc(sizeof(PPM));
    newPPM->h = oldPPM->h;
    newPPM->w = oldPPM->w;
    newPPM->max = oldPPM->max;
    newPPM->im = malloc(oldPPM->h * oldPPM->w * sizeof(RGB));

    printf("\nApplying filter %s to %s\n", filterfile, infile);
    time = getTime(2);
    //Filter function
    filterImage(oldPPM, filter->size, filter->kernel, newPPM);
    printf("*** %10s read in %.1e seconds\n", infile, getTime(2) - time);

    printf("\nWriting file %s\n", outfile);
    time = getTime(2);
    writePPM(outfile, newPPM);
    printf("*** %10s written in %.1e seconds\n\n", outfile, getTime(2) - time);


    free(oldPPM->im);
    free(oldPPM);
    free(newPPM->im);
    free(newPPM);

    return (0);
}
