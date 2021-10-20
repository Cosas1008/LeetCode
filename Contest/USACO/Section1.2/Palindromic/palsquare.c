/*
ID: yuweiic1
LANG: C
TASK: palsquare
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFF 255

char converted[MAX_BUFF];

void intToBase(int number, int base)
{
    int index = 0;
    memset(converted,'\0',sizeof(converted)); // clear converted char array
    while( number > 0){
        // Bad implement, well understanding on ascii encode
        if(number%base > 9){
            converted[index] = number%base + '7'; // NOTE!!! this is array of char store value as "INT"!!!!
        }else{
            converted[index] = number%base + '0'; // NOTE!!! this is array of char store value as "INT"!!!!
        }
        // CASTING is Crutial here
        number /= base;
        index++;
    }
    // Added: ordering
    char tmp;
    int len = strlen(converted);
    for(int i =0; i < len/2; i++){
        tmp= converted[i];
        converted[i] = converted[len-i-1];
        converted[len-i-1] = tmp;
    }
}

int checkPalindrom()
{
    // int result;
    size_t len = strlen(converted);
    if(len == 1) return 1;
    for(int i = 0; i < len/2; i++){
        // result = strcmp(&converted[i],&converted[len-i-1]);
        // printf("converted:%s len:%d First:%c Second:%c i=%d Result=%d\n", converted, (int)len/2, converted[i], converted[len-i-1], i, result);
        if(converted[i] != converted[len-i-1]) return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    FILE* fin, *fout;
    int base, i = 1;
    fin = fopen("palsquare.in","r");
    fout = fopen("palsquare.out","w");
    fscanf(fin,"%d", &base);
    // printf("Base %d\n", base); // debug
    while(i <= 300)
    {
        // printf("i:%d converted:%s len:%d\n", i, converted, (int)strlen(converted));
        intToBase(i*i, base);
        if(checkPalindrom()){//success
            char tmp[MAX_BUFF];
            memset(tmp,'\0',sizeof(tmp)); // clear tmp char array
            strcpy(tmp,converted);
            intToBase(i,base);
            fprintf(fout,"%s %s\n",converted,tmp);
        }
        i++;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
