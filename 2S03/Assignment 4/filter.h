#ifndef INCLUDED_FILTER_H
#define INCLUDED_FILTER_H

/* Type of filtering */
typedef struct { int size; double *kernel;} Filter;

/* RGB values */
typedef struct { unsigned char r, g, b; } RGB;
typedef struct { int w, h, max; RGB *im; } PPM;

Filter *loadFilter(char *filterfile);
void freeFilter(Filter *filter);

void filterImage(const PPM *in, int n, double *filter,  PPM *out);

PPM *readPPM(const char *file);
void writePPM(const char *file, const PPM *ppm);

#endif
