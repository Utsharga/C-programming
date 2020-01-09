/* Filename: staircase.c Author:Utsharga Rozario, 400213114, rozariou */
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n;
	printf("Enter number of staircase:");
	scanf("%d", &n);

	if (n < 1 || n > 100){
		printf("n=%d, must be in [1,100]\n", n);
		exit(1);
	}

    int num_stairs = 3;
    int d, row, repeat;
    int remaining_col = n;
	for (repeat = 0; repeat < (float)n/5; repeat++){
	    for (row = 0; row < num_stairs; row++){   
		if (remaining_col > 5){
			d = 5;
		}
		if (remaining_col < 5 && remaining_col > 0){
			d = remaining_col;
		}
		if (remaining_col < 0){
			break;
		}
		int m = 0;
		int col;
		int col2;
		while (m < d){     
			for (col = 0; col < num_stairs - row - 1; col++){
	    			printf(" ");
	    		}	 
	    		for (col2 = 0; col2 < row + 1; col2++){
	    			printf("#");
	    		}
			m++;
			printf(" ");
		}
	    printf("\n");
	    }
	remaining_col = remaining_col - 5;
	}
	return 0;
}
  



