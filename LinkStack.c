#include "define.h"
#include <stdlib.h>
#include <stdio.h>

/*
 |-------------------------------------------------------------------------------------------------
 |栈的链式存储结构
 |-------------------------------------------------------------------------------------------------
 |入栈的时间复杂度O(1)
 |出栈的时间复杂度O(1)
 |-------------------------------------------------------------------------------------------------
 */

/**
 * 创建一个新的节点
 */
ListNode static *applyNewNode()
{
    PListNode new = (ListNode *)malloc(sizeof(ListNode));
    if(new == NULL){
        printf("Apply a new node failed\n");
        exit(-1);
    }
    return new;
}

/**
 * 初始化
 */
int static initial(PLinkStack p)
{
    p->top = applyNewNode();
    p->length = 0;
    p->top->next = NULL;
}

/**
 * 检查空
 */
int static checkEmpty(PLinkStack p)
{
    if(p->length == 0) return 1;
    else return 0;
}

/**
 * 入栈
 */
int static push(PLinkStack p)
{
    int value;
    printf("Input the push value\n");
    scanf("%d", &value);

    if(checkEmpty(p)) p->top->data = value;
    else{
        PListNode new = applyNewNode();
        new->data = value;
        new->next = p->top;
        p->top = new;
    }
    p->length++;
}

/**
 * 出栈
 */
int static pop(PLinkStack p)
{
    int value;
    //当前的第一个元素
    //这里单独用一个变量存储第一个元素是为了后面释放这个元素所
    //占的空间
    PListNode first = p->top;
    if(checkEmpty(p)){
        printf("Empty stack\n");
        exit(0);
    }
    value = p->top->data;
    p->top = first->next;
    first->next = NULL;
    free(first);
    p->length--;

    printf("The pop value is %d\n", value);
}

/**
 * 遍历
 */
int static traversal(PLinkStack p)
{
    PListNode index = p->top;
    if(checkEmpty(p)){
        printf("Empty stack\n");
        exit(0);
    }

    printf("The length of stack is %d\n", p->length);
    while (index){
        printf("%d\n", index->data);
        index = index->next;
    }
}

int linkStack()
{
    LinkStack stack;
    initial(&stack);
    push(&stack);
    push(&stack);
    push(&stack);
    push(&stack);
    traversal(&stack);
    pop(&stack);
    traversal(&stack);
}
