#include <stdio.h>
int main(){
    int n = 6;
    int sum = 0;
    for (int i = 1; i < n; i*= 2){
        for (int j = 0; j < n; j++){
            sum++;
        }
    }
    printf("%d\n", sum);
}