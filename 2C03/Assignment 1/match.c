#include <stdio.h>
#include <string.h>

int main(){
    int ia = 0;
    int ib = 0;
    
    int a[5] = {1,3,5,7,9};
    int b[5] = {5,6,7,8,9};

    while (ia < sizeof(a)/sizeof(int) && ib < sizeof(b)/sizeof(int)) {
        if      (a[ia] < b[ib]) ia++;
        else if (a[ia] > b[ib]) ib++;
        else if (a[ia] == b[ib]) {
            printf("%d\n", a[ia]);
            ia++;
            ib++;
            }
        }

}