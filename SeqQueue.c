#include "define.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

/*
 |-------------------------------------------------------------------------------------------------
 |队列的线性存储结构(循环队列)
 |-------------------------------------------------------------------------------------------------
 |进队列的时间复杂度为O(1)
 |出队列的时间复杂的为O(1)
 |因为加了首尾指针并且首尾指针可以“循环”，这大大提高了进出队
 |列的效率
 |-------------------------------------------------------------------------------------------------
 */

/**
 * 初始化
 */
int initial(PSeqQueue p)
{
    p->front = 0;
    p->rear = 0;
}

/**
 * 检查是否已经满了
 */
int checkFilled(PSeqQueue p)
{
    int rear = p->data[p->rear];
    int front = p->data[p->front];
    if((rear + 1) % (MAX) == front) return 1;
    else return 0;
}

/**
 * 检查是否为空
 */
int checkEmpty(PSeqQueue p)
{
    if(p->rear == p->front) return 1;
    else return 0;
}

/**
 * 获取长度
 */
int getLength(PSeqQueue p)
{
    return (p->rear - p->front + MAX) % MAX;
}

/**
 * 进队列
 */
int enQueue(PSeqQueue p)
{
    int value;
    if (checkFilled(p)){
        printf("The queue is filled\n");
        exit(0);
    }

    printf("Input the enqueue value\n");
    scanf("%d", &value);

    p->data[p->rear] = value;
    p->rear = (p->rear + 1) % MAX;
}

/**
 * 出队列
 */
int deQueue(PSeqQueue p)
{
    int value;
    if(checkEmpty(p)){
        printf("Empty queue\n");
        exit(0);
    }

    value = p->data[p->front];
    p->front = (p->front + 1) % MAX;

    printf("The value is %d\n", value);
}

/**
 * 遍历
 */
int traversal(SeqQueue p)
{
   if(checkEmpty(&p)){
       printf("Empty queue\n");
       exit(0);
   }

    //C语言是“值传递”，也就是说传过来的是队列的一个副本，因此
    // 遍历的时候只需要将副本中的元素逐一出队列即可
    while ( ! checkEmpty(&p)){
        deQueue(&p);
    }

    free(&p);
}

int seqQueue()
{
    SeqQueue queue;
    initial(&queue);
    enQueue(&queue);
    enQueue(&queue);
    enQueue(&queue);
    enQueue(&queue);
    traversal(queue);
    deQueue(&queue);
    deQueue(&queue);
    traversal(queue);
}

