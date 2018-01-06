#include<stdlib.h>
#include <stdio.h>
#include "define.h"
#include <string.h>

int static initial(PString str, PString match)
{
    printf("Input the original string\n");
    gets(str.str);
    printf("Input the matched string\n");
    gets(match.str);

    str.length = strlen(str.str);
    match.length = strlen(match.str);

    if(match.length > str.length){
        printf("The matched string length is bigger than the string");
        exit(-1);
    }
}

int main()
{
    String str, match;
    initial(str, match);
}

int simplicity(PString str, PString match)
{
    int i = 1, j = 1;
    while(i <= str.length && j <= match.length){

    }
}

