#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

char* fib_string(int n)
{
  char* f1 = (char*)malloc(2);
  strcpy(f1, "1");
  char* f2 = (char*)malloc(2);
  strcpy(f2, "0");
  char* tmp = 0;
  int i;
  for (i = 3; i <= n; i++) {
    char* f3 = (char*)malloc(strlen(f1) + strlen(f2) + 1);
    if (!f3) {
      free(f1);
      free(f2);
      return NULL;
    }
    strcpy(f3, f2);
    strcat(f3, f1);
    free(f1);
    tmp = f3;
    f1 = f2;
    f2 = f3;
  }
  free(f1);
  return tmp;
}

typedef enum { north,
	       south,
	       east,
	       west } direction;

#define a(i, j, R, G, B)        \
  {				\
    image[i * w + j].r = R;	\
    image[i * w + j].g = R;	\
    image[i * w + j].b = R;	\
    }
#define set_a(i,j,c) image[i * w + j] = c;

void draw(int x, int y, int xn, int yn, RGB c, int w, int h, RGB* image)
{
    int i, j;
    if (yn == y) {
        for (i = x; i < xn; i++)
	  set_a(yn, i,c);
        for (i = x; i > xn; i--)
	  set_a(yn, i,c);
    }
    else /* (xn == x) */
      {
        for (j = y; j < yn; j++)
	  set_a(j, xn,c);
        for (j = y; j > yn; j--)
	  set_a(j, xn,c)
      }
}

int fib(int n, int x, int y, int step, RGB bc, RGB fc, int w, int h, RGB* image)
/*Input
   n>=3  
   x,y  starting position
   step>=2 how many pixels to move when drawing a segment forward
   bc background color
   fc foreground, drawing color
   w width of image in pixels
   h height of image in pixels
   The input x,y must be in [0,w-1] and [0,h-1], respectively.
   
  Output
   image is a pointer to a w*h array of RGB values
  Returns
    0 if this function fails, e.g. if a step results in coordinates outside the image window or if unable to allocate memory.
   >0 the number of steps the algorithm takes, which is also the length of the nth Fibonacci word.
   */
{
    int dx = step, dy = step;
    char* f = fib_string(n);
    if (!f)
        return 0;

    int i;
    for (i = 0; i < w*h; i++)
      image[i] = bc;

    int slen = strlen(f);
    direction d = north;
    int fx = 0, fy = dy;

    int xmax=0, ymax=0, xmin=w,ymin=h;
    for (i = 0; i < strlen(f); i++) {
      int xn = x+fx, yn=y+fy;
      if (xn>xmax) xmax = xn;
      if (yn>ymax) ymax = yn;

      if (xn<xmin) xmin = xn;
      if (yn<ymin) ymin = yn;

        if (xn < 0 || xn >= w) {
            printf("x+fx=%d must be un [0,%d]\n",xn, w - 1);
            return 0;
        }

        if (yn <0  || yn >= h) {
            printf("y+fy=%d must be in [0,%d]\n", yn, h - 1);
            return 0;
        }

	draw(x, y, xn, yn, fc, w, h, image);
        x = xn;
        y = yn;
        if (f[i] == '0') {
            fx = 0;
            fy = 0;
	    /* i+1 is even when i is odd
	       int even = (i + 1) % 2 == 0; */
	    int even = 0x01 & i;
            if (even) { /* turn left */
                switch (d) {
                case north:
                    fx = -dx;
                    d = west;
                    break;
                case south:
                    fx = dx;
                    d = east;
                    break;
                case east:
                    fy = dy;
                    d = north;
                    break;
                case west:
                    fy = -dy;
                    d = south;
                    break;
                }
            } else
            /* turn right*/
            {
                switch (d) {
                case north:
                    fx = dx;
                    d = east;
                    break;
                case south:
                    fx = -dx;
                    d = west;
                    break;
                case east:
                    fy = -dy;
                    d = south;
                    break;
                case west:
                    fy = dy;
                    d = north;
                    break;
                }
            }
        }
	
        if ((i + 1) % (10000) == 0)
	  {
	    
            printf("i=%d % .1f%% done  x,y=%d,%d \n", (i + 1), ((double)i) / (slen)*100.0, 
		   x+fx, y+fy);
	  }
    }
    printf("done xmin,xmax=[%d,%d], ymin,ymax=[%d,%d] \n", 
	   xmin,xmax, ymin,ymax);
    
    int l = strlen(f);
    free(f);
    return l;
}
