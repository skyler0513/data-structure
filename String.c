#include<stdlib.h>
#include <stdio.h>
#include "define.h"
#include <string.h>

/*
 |-------------------------------------------------------------------------------------------------
 |字符串匹配，包括朴素算法和KMP算法；结果是以字符串的第一个
 |字符的位置为1（不是0）来展示的；str是“主串”，match是要匹配
 |的；
 |-------------------------------------------------------------------------------------------------
 */

/**
 * 初始化字符串
 */
int static initial(PString str, PString match)
{
    //输入字符串和要匹配的字符串
    printf("Input the original string\n");
    gets(str->str);
    printf("Input the matched string\n");
    gets(match->str);

    //计算长度
    str->length = strlen(str->str);
    match->length = strlen(match->str);

    if(match->length > str->length){
        printf("The matched string length is bigger than the string");
        exit(-1);
    }
}

/**
 * 朴素算法
 */
int simplicity(PString str, PString match)
{
    int i = 0, j = 0;
    while(i < str->length && j < match->length){
        //如果主串中要匹配的字符串长度小于要匹配的字符串长度就停止
        if((str->length - i < match->length) && j == 0) break;
        if(str->str[i] == match->str[j]) {
            j++;
            i++;
        }
        else{
            //开始的时候i和j是相等的，只要匹配不成功i就比j多1
            i = i - j + 1;
            j = 0;
        }
    }
    //printf("%d\n", i);
    if(j >= match->length) return i - j + 1;
    else return 0;
}

/**
 * KMP算法获取匹配串的next数组
 */
int getNext(PString match, int *next)
{
    int j = 0, i = 1;
    next[0] = next[1] = 0;

    while(i < match->length){
        if(match->str[i] == match->str[j] || j == 0){
            i++;
            j++;
            if(match->str[i] != match->str[j]) next[i] = j;
            else next[i] = next[j];
        }
        else j = next[j];
    }
}

/**
 * KMP算法
 */
int KMP(PString str, PString match)
{
    int i = 1, j = 1;
    int next[match->length];

    //获取匹配串的next数组
    getNext(match, next);

    while(i <= str->length && j <= match->length){
        if(str->str[i - 1] == match->str[j - 1] || j == 0){
            i++;
            j++;
        }
        else j = next[j];
    }

    if(j > match->length) return i - j +1;
    else return 0;
}

int testString()
{
    int position;
    String str, match;
    initial(&str, &match);
    //朴素算法
    //position = simplicity(&str, &match);
    //kmp算法
    position = KMP(&str, &match);
    printf("%d\n", position);
}
