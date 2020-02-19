#include <stdio.h>
#include <string.h>

int getcharval(const char *s, int idx) {
    if (idx < strlen(s))
        return s[strlen(s) - idx - 1] - 48; 
    return 0;
}

void add( char a[], char b[], char res[]){
    int i, wa=strlen(a), wb=strlen(b), width, sum, carry = 0;
    width = wa > wb ? wa : wb; 
    for(i=0; i<width; i++){
        char ca = getcharval(a, i); 
        char cb = getcharval(b, i); 
        sum = ca + cb + carry;
        carry = 0;
        if(sum > 9){ 
            carry = 1;
            sum-=10;
        }
        res[i] = sum+48;
    }   
    if(carry) 
        res[i++] = carry+48;
        res[i]= 0;
    for (i = 0; i < strlen(res) / 2; i++) {
        char t = res[i];
        res[i] = res[strlen(res) - i - 1]; 
        res[strlen(res) - i - 1] = t;
    }
}

void sub(char a[], char b[], char res[]){
    int i, wa=strlen(a), wb=strlen(b), width, diff, carry = 0;
    width = wa > wb ? wa : wb;
    if (wa == wb){
        width = wa;
            if (a[i] > b[i]){
                for(i=0; i<width; i++){
                    char ca = getcharval(a, i); 
                    char cb = getcharval(b, i); 
                    diff = ca - cb - carry;
                    carry = 0;
                    if(diff < 0){ 
                        carry = 1;
                        diff = 10 + diff;
                    }
                    res[i] = diff+48;
                }
                for (i = 0; i < strlen(res) / 2; i++) {
                    char t = res[i];
                    res[i] = res[strlen(res) - i - 1]; 
                    res[strlen(res) - i - 1] = t;
                }
            }
            if (a[i] < b[i]){
                for(i=0; i<width; i++){
                    char ca = getcharval(a, i); 
                    char cb = getcharval(b, i); 
                    diff = cb - ca - carry;
                    carry = 0;
                    if(diff < 0){ 
                        carry = 1;
                        diff = 10 + diff;
                    }
                    res[i] = diff+48;
                }
                for (i = 1; i < strlen(res) / 2; i++) {
                    char t = res[i];
                    res[i] = res[strlen(res) - i - 1]; 
                    res[strlen(res) - i -1] = t;
                    res[0] = '-';
                }
            }
        }
    if (wa > wb){
        for(i=0; i<width; i++){
            char ca = getcharval(a, i); 
            char cb = getcharval(b, i); 
            diff = ca - cb - carry;
            carry = 0;
            if(diff < 0){ 
                carry = 1;
                diff = 10 + diff;
            }
            res[i] = diff+48;
        }
        for (i = 0; i < strlen(res) / 2; i++) {
        char t = res[i];
        res[i] = res[strlen(res) - i - 1]; 
        res[strlen(res) - i - 1] = t;
        }
    }
    if (wa < wb){
        for(i=0; i<width; i++){
            char ca = getcharval(a, i); 
            char cb = getcharval(b, i); 
            diff = cb - ca - carry;
            carry = 0;
            if(diff < 0){ 
                carry = 1;
                diff = 10 + diff;
            }
            res[i] = diff+48;
        }
        for (i = 0; i < strlen(res) / 2; i++) {
        char t = res[i];
        res[i] = res[strlen(res) - i - 1]; 
        res[strlen(res) - i - 1] = t;
        res[0] = '-';
        }
    }
    
}