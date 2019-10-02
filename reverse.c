#include <stdio.h>

#define max_sent 80

int main(){
    char sent[max_sent], ch;

    for (int i = 0; i < max_sent; i++){
        ch = getchar();
        if (ch == '.' || ch == '?' || ch == '!'){
            break;
        }
        sent[i] = ch;
    }

    printf("%s\n", sent);
    return 0;
}