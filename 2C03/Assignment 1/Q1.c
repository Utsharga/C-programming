#include <stdio.h>

int main(){
    //Lets say stack of 5
    int push = 0;
    int pop = 0;
    //char ary[10] = {'1', '2', '3', '7' , 'x' , '4' , '6' , '5' , 'x' , 'x' };
    char ary[10] = {'1', '2', '3', 'x' , 'x' , 'x' , 'x' , '5' , '7' , 'x' };

    for (int i = 0; i < 10; i++){
        if (ary[i] != 'x') push++;
        if (ary[i] == 'x') pop++;

        /*if ((push - pop) > 5) {
            printf("stack overflow\n");
            break;
        }*/

        if (pop > push) {
            printf("stack underflow %c\n", ary[i]);
            break;
        }
        if ((push - pop) < 5) printf("stack okay, %c \n", ary[i]);
    }
}
