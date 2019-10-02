#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define EMPTY '.'
int main(){
    srand(time(0));
    char array[N][N];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            array[i][j] = EMPTY;
        }

    } 
    int x = 0;
    int y = 0;
    char  letter = 'A';

    int direction = rand() % 4; //Up, Down, left, right

    int new_x, new_y;
    int attempts = 0;
    while (attempts < 4 && letter <= 'Z') {
        switch (direction) {
            case 0: new_x = x; new_y = y - 1; break; 
            case 1: new_x = x; new_y = y + 1; break; 
            case 2: new_x = x - 1; new_y = y; break; 
            case 3: new_x = x + 1; new_y = y; break; 
        }
        if (new_x >= 0 && new_x< N &&
            new_y >= 0 && new_y< N &&
            array[new_x][new_y] == EMPTY) {
                array[new_x][new_y] = letter++;
                x = new_x;
                y = new_y;
                attempts = 0;
                direction = rand() % 4;
            }else{
                attempts++;
            }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%c", array[i][j]);
        printf("\n");
        }
    } 
}