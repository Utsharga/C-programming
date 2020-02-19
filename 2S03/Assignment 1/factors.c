/* Filename: factors.c Author:Utsharga Rozario, 400213114, rozariou */
#include <stdio.h>

int main(){
	unsigned int pos_int1, pos_int2;
	unsigned int cf[100];
	unsigned long i;


	printf("Enter two positive integers:");
	scanf("%u %u", &pos_int1, &pos_int2);
	int j = 0;
	unsigned int min_int, max_int;

	if (pos_int1 > pos_int2){
		max_int = pos_int1;
		min_int = pos_int2;
	}
	if (pos_int2 > pos_int1){
		max_int = pos_int2;
		min_int = pos_int1;
	}

	if (pos_int2 == pos_int1){
		max_int = pos_int2;
		min_int = pos_int1;
	}

	for (i = 1; i <= min_int; i++){
		if ((pos_int1 % i == 0) && (pos_int2 % i == 0)){
			cf[j] = i;
			j++;		
		}
	}

	int c;
	printf("Common factors of (%u, %u): ", pos_int1, pos_int2);
	for (c = 0; c < j; c++){
		printf("%u ", cf[c]);
	}
	printf("\n");

	printf("GCF: %u\n", cf[j - 1]);
	
	unsigned int low_mult = max_int;
	while (1){
		if ((low_mult%pos_int1 == 0) && (low_mult%pos_int2 == 0)){
			printf("LCM: %u", low_mult);
			break;
		}
		low_mult++;
	}
	printf("\n");
	
	unsigned long sum = 0;
	for(c = 0; c < j; c++){
		sum += cf[c];
	}
	sum += low_mult + cf[j -1];
	printf("sum: %lu\n", sum);

	return 0;
}
