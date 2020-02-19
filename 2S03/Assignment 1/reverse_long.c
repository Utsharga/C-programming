/* Filename: reverse_long.c Author:Utsharga Rozario, 400213114, rozariou */
#include <stdio.h>

int main(){
	unsigned long int rev, rem, t, rev_num = 0;

	printf("Enter an integer: ");
	scanf("%lu", &rev);
	unsigned long int tmp = rev;
	while(tmp != 0){

		rev_num = rev_num * 10;
		rev_num = tmp%10 + rev_num;
		tmp /= 10;
	}
	printf("%lu\n", rev_num);
	
	return 0;
}
