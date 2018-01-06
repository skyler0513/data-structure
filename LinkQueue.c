#include "define.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
/*
 |-------------------------------------------------------------------------------------------------
 |队列的链式存储结构
 |-------------------------------------------------------------------------------------------------
 |入队列的时间复杂度为O(1)
 |出队列的时间复杂度为O(1)
 |-------------------------------------------------------------------------------------------------
 */

/**
 * 申请新的节点
 */
ListNode static *applyNewNode()
{
    PListNode new = (ListNode *)malloc(sizeof(ListNode));
    if(new == NULL){
        printf("Apply a new node failed\n");
        exit(-1);
    }
    new->next = NULL;
    return new;
}

/**
 * 初始化
 */
int static initial(PLinkQueue p)
{
    //第一个节点
    PListNode new = applyNewNode();
    //head指向第一个节点
    p->head = new;
    p->head->next = NULL;
    p->rear = p->head;
    p->length = 0;
}

/**
 * 判断空
 */
int static checkEmpty(PLinkQueue p)
{
    if(p->length == 0) return 1;
    else return 0;
}

/**
 * 进队列
 */
int static enQueue(PLinkQueue p)
{
    int value;
    printf("Input the enqueue value\n");
    scanf("%d", &value);

    //如果现在队列为空，说明插入的是第一个节点
    if(checkEmpty(p)){
        p->head->data = value;
    }
    else{
        PListNode new = applyNewNode();
        new->data = value;
        p->rear->next = new;
        p->rear = new;
    }
    p->length++;
}

/**
 * 出队列
 */
int static deQueue(PLinkQueue p)
{
    int value;
    PListNode head;
    if(checkEmpty(p)){
        printf("The queue is empty\n");
        exit(0);
    }
    head = p->head;
    value = head->data;
    p->head = head->next;
    p->length--;
    free(head);
    printf("The dequeue value is %d\n", value);
}

/**
 * 遍历
 */
int static travesal(LinkQueue queue)
{
    PListNode index = queue.head;
    if(checkEmpty(&queue)){
        printf("Empty queue\n");
        exit(0);
    }

    printf("----------------traversal-------------------\n");
    for(int i = 0; i < queue.length; i++){
        printf("%d\n", index->data);
        index = index->next;
    }
    printf("----------------traversal-------------------\n");
}

int linkQueue()
{
    LinkQueue p;
    initial(&p);
    enQueue(&p);
    enQueue(&p);
    enQueue(&p);
    enQueue(&p);
    deQueue(&p);
    travesal(p);
}
