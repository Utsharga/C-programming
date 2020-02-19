#include "filter.h"
#include <stdlib.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) < (b) ? (a) : (b)

/* i = -k:k, e.g. -2:2
   i1 = i+k = 0:2k
*/
/* h rows , w cols */
#define F(i,j,k,n)  filter[(i+k)*n+(j+k)]
#define I(i,j,c) (((i)<0||(i)>h || (j)<0||(j)>w)? 0: in->im[(i)*w+(j)].c)
#define O(i,j) out->im[i*w+j]


#define SET_COLOR(rgb,r,c)  rgb.r = MIN(MAX(0,c),255)

void filterImage(const PPM *in, int n, double *filter, PPM *out)
{
  int w = in->w;
  int h = in->h;
  
  out->im = (RGB*)malloc(w * h * sizeof(RGB));
  out->w = w;
  out->h = h;
  out->max = 0;
  int i, j, k,p;
  int N = n/2;
  
  for (i = 0; i < h; i++) 
    {
      for (j = 0; j < w; j++) {
		double r=0, b=0, g=0;
		RGB rgb;
		for (k=-N; k<=N; k++)
			for (p=-N; p<=N; p++)
				{
				r+= I(i+k,j+k,r)*F(k,p,N, n);
				b+= I(i+k,j+k,b)*F(k,p,N, n);
				g+= I(i+k,j+k,g)*F(k,p,N, n);
				}

		SET_COLOR(rgb,r, r);
		SET_COLOR(rgb,g, g);
		SET_COLOR(rgb,b, b);
		

		O(i,j) = rgb;
		
		if (rgb.r > out->max) out->max = rgb.r;
		if (rgb.g > out->max) out->max = rgb.g;
		if (rgb.b > out->max) out->max = rgb.b;
      }
    }
}
