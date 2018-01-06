#include "define.h"
#include <stdio.h>
#include <stdlib.h>

/*
 |-------------------------------------------------------------------------------------------------
 |线性表的顺序存储结构
 |-------------------------------------------------------------------------------------------------
 |查找某一位置的元素的时间复杂度为O(1)
 |查找某一个值得位置的时间复杂度为O(n)
 |插入一个元素的时间复杂度为O(n)
 |删除一个元素的时间复杂度为O(n)
 |
 |通过指向第一个元素的指针来操作线性表
 |
 |顺序表查找起来比较方便但是初始化的时候要确定长度，对于空间
 |得使用不是很好
 */

/**
 * 初始化
 */
static int initial(PSeqList p)
{
    //顺序表的当前长度为0
    p->length = 0;
    //顺序表的最大长度在初始化的时候要“唯一确定”
    p->size = MAX;
    //指向顺序表的第一个元素的指针
    p->firstNode = (int *)malloc(sizeof(int)*(p->size));
}

/**
 * 创建
*/
static int create(PSeqList p)
{
    int i, length;
    int *index = p->firstNode;

    if(p->firstNode == NULL){
        printf("Invalid list\n");
        exit(-1);
    }

    printf("Input the length of the list\n");
    scanf("%d", &length);

    p->length = length;

    //按顺序插入
    for(i = 0; i < length; i++){
        printf("Input the node value\n");
        scanf("%d", index++);
    }
}

/**
 * 判断为空
 */
static int isEmpty(PSeqList p)
{
    if(p->length == 0) return 1;
    else return 0;
}

/**
 * 获取某一位置的节点的值
 * 时间复杂的为O(1)
 */
static int get(PSeqList p)
{
    int position;
    printf("Input the position you find\n");
    scanf("%d", &position);

    if(position > p->length || position <= 0){
        printf("Invalid position %d\n",position);
        exit(-1);
    }

    printf("%d\n", p->firstNode[position - 1]);
    return p->firstNode[position - 1];
}

/**
 * 获取某一个值的位置
 * 时间复杂度为O(n)
 */
static int getPosition(PSeqList p)
{
    int i, e, *index = p->firstNode;
    if(isEmpty(p)){
        printf("Empty list\n");
        exit(0);
    }

    printf("Input the value you find\n");
    scanf("%d", &e);

    for(i = 0; i < p->length; i++){
        if((*index) == e){
            printf("The position is %d\n", i+1);
            break;
        }
        index++;
    }

    if(i == p->length){
        printf("Do not have this value in the list\n");
    }
}

/**
 * 遍历
 */
static int travesal(PSeqList p)
{
    int i;
    if(isEmpty(p)){
        printf("Empty list\n");
        exit(0);
    }

    for(i = 0; i < p->length; i++){
        //在这里用数组的方式表示节点的值
        printf("%d\n", p->firstNode[i]);
    }
}

/**
 * 插入
 * 时间复杂度O(n)
 */
static int insert(PSeqList p)
{
    int i, e, position;
    if(isEmpty(p)){
        printf("Empty list\n");
        exit(0);
    }

    if(p->length >= p->size){
        printf("The list is filled\n");
        exit(0);
    }

    printf("Input the value and position\n");
    scanf("%d%d", &e, &position);

    if(p->length + 1 < position){
        printf("Invalid position\n");
        exit(-1);
    }

    if(position == p->length + 1){
        p->firstNode[position - 1] = e;
        p->length++;
    }
    else{
        for(i = p->length; i >= position; i--)
            p->firstNode[i] = p->firstNode[i - 1];

        p->firstNode[i] = e;
        p->length++;
    }
}

/**
 * 删除
 * 时间复杂度为O(n)
 */
static int delete(PSeqList p)
{
    int i, value, position;

    if(isEmpty(p)){
        printf("Empty list\n");
        exit(0);
    }

    printf("Input the position you want to delete\n");
    scanf("%d", &position);

    if(position > p->length){
        printf("Invalid position %d\n", position);
        exit(-1);
    }

    value = p->firstNode[position - 1];

    if(position == p->length) p->length--;
    else{
        for(i = position; i <= p->length - 1; i++){
            p->firstNode[i - 1] = p->firstNode[i];
        }
        p->length--;
    }

    return value;
}

/**
 * 释放空间
 */
static int clear(PSeqList p)
{
    free(p);
}

