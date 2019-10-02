/* Filename: staircase2.c Author:Utsharga Rozario, 400213114, rozariou */
#include <stdio.h>
#include <stdlib.h>

int main(){
       
    int n, m, p, d, row, repeat;

    printf("Enter number of: staircases, stairs, rows: ");
    scanf("%d %d %d", &n, &m, &p);

	if (n < 1 || n > 100){
		printf("n=%d, must be in [1,100]\n", n);
		if (m < 1 || m > 9){
			printf("m=%d, must be in [1,9]\n", m);
				if (p < 1 || p > 100){
				printf("n=%d, must be in [1,100]\n", p);
				exit(0);
				}
			exit(0);
		}
		exit(0);
	}
	
	if (m < 1 || m > 9){
		printf("m=%d, must be in [1,9]\n", m);
		if (p < 1 || p > 100){
			printf("n=%d, must be in [1,100]\n", p);
			exit(0);
		}
		exit(0);
	}
	
	if (p < 1 || p > 100){
		printf("n=%d, must be in [1,100]\n", p);
		exit(0);
	}

    int remaining_col = n;

	for (repeat = 0; repeat < (float)n/p; repeat++){
	    for (row = 0; row < m; row++){   
		if (remaining_col >= p){
			d = p;
		}
		if (remaining_col < p && remaining_col > 0){
			d = remaining_col;
		}
		if (remaining_col < 0){
			break;
		}
		int i = 0;
		int col, col2;
		while (i < d){     
			for (col = 0; col < m - row - 1; col++){
	    			printf(" ");
	    		}	 
	    		for (col2 = 0; col2 < row + 1; col2++){
	    			printf("%d", m);
	    		}
			i++;
			printf(" ");
		}
	    printf("\n");
	    }
	remaining_col = remaining_col - p;
	}
	return 0;
}
  



