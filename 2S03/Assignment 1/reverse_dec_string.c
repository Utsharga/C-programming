/* Filename: reverse_dec_string.c Author:Utsharga Rozario, 400213114, rozariou */
#include <stdio.h>
#include <string.h>

int main(){

    char arr[20];
	char arr2[20];
	int top, end, count, queue;
	int i, j, k;
	count = 0;
	j = 0;
	k = 0;
	queue = 0;
	
    printf("Enter a decimal string: ");
    scanf("%s", arr);

	arr[20] = '\0';

	while(arr[count] != '\0'){
		count++;
	}	

	while(arr[j] == '0'){
		j++;
	}

	end = count - 1;

	for (top = 0; top < count - j; top++){
		arr2[top] = arr[end];
		end--;
		queue++;
	}

	while(arr2[k] == '0'){
		k++;
	}

    for (i = k; i < queue; i++){
		if (arr2[i] != '\0'){
				printf("%c", arr2[i]);
		}
    }
	
	printf("\n");

    return 0;

}
