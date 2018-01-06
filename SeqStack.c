#include "define.h"
#include <stdlib.h>
#include <stdio.h>

/*
 |-------------------------------------------------------------------------------------------------
 |栈的顺序存储结构，是一种只能在一端插入删除的顺序表
 |-------------------------------------------------------------------------------------------------
 |入栈的时间复杂度为O(1)
 |出栈的时间复杂度为O(1)
 */

/**
 * 初始化
 */
int static initial(PSeqStack p)
{
    p->top = (int *)malloc(sizeof(int) * MAX);
    p->length = 0;
    p->size = MAX;
}

/**
 * 检查栈是否已满
 */
int static checkFilled(PSeqStack p)
{
    if(p->length == p->size) return 1;
    else return 0;
}

/**
 * 检查栈是否为空
 */
int static checkEmpty(PSeqStack p)
{
    if(p->length == 0) return 1;
    else return 0;
}

/**
 * 入栈
 */
int static push(PSeqStack p)
{
    int value;
    if(checkFilled(p)){
        printf("The stack is filled\n");
        exit(0);
    }

    printf("Input the push value\n");
    scanf("%d",&value);

    p->top[p->length] = value;
    p->length++;
}

/**
 * 出栈
 */
int static pop(PSeqStack p)
{
    int value;
    if(checkEmpty(p)){
        printf("The stack is empty\n");
        exit(0);
    }

    value = p->top[p->length - 1];
    p->length--;

    printf("The pop value is %d\n", value);
}

/**
 * 遍历
 */
int static traveral(PSeqStack p)
{
    int i;
    if(checkEmpty(p)){
        printf("Empty stack\n");
        exit(0);
    }

    printf("The length of stack is %d\n", p->length);

    for(i = 0; i < p->length; i++){
        printf("%d\n", p->top[i]);
    }
}

int seqstack()
{
    SeqStack stack;
    initial(&stack);
    push(&stack);
    push(&stack);
    push(&stack);
    push(&stack);
    traveral(&stack);
    pop(&stack);
    traveral(&stack);
}