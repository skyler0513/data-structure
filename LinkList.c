#include "define.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

/*
 |-------------------------------------------------------------------------------------------------
 |线性表的链式存储结构
 |-------------------------------------------------------------------------------------------------
 |查找某一位置的元素的时间复杂度为O(n)
 |查找某一元素的位置的时间复杂度为O(n)
 |
 |插入一个元素的时间复杂度为O(n),同时插入多个元素的时间复杂度
 |也是O(n)
 |
 |删除一个元素的时间复杂度为O(n)
 |
 |插入和删除都要先找到被操作位置的前一个位置
 |
 */

/**
 * 申请新节点
 */
static PListNode applyNewNode()
{
    PListNode new;
    new = (ListNode *)malloc(sizeof(ListNode));

    if(new == NULL){
        printf("Apply new node failed\n");
        exit(-1);
    }
    else return new;
}

/**
 * 判断空
 */
static int isEmpty(PLinkList p)
{
    if(p->length == 0) return 1;
    else return 0;
}

/**
 * 初始化
 */
static int initial(PLinkList p)
{
    //头指针指向头结点
    p->head = applyNewNode();
    p->length = 0;
    //头结点的下一个为NULL
    p->head->next = NULL;
}

/**
 * 插入
 * 时间复杂度为O(n)
 */
static int insert(PLinkList p)
{
    int value, position, i;
    //第一个节点
    PListNode node = p->head;
    PListNode new = applyNewNode();

    printf("Input the value you want to insert\n");
    scanf("%d", &value);
    printf("Input the position that you want to insert\n");
    scanf("%d", &position);
    new->data = value;

    if(isEmpty(p)){
        if(position != 1){
            printf("The list is empty.The value must insert into the first position\n");
        }
        new->next = p->head->next;
        p->head->next = new;
        p->length++;
    }
    else{
        if(position > p->length +1 || position < 0){
            printf("Invalid position\n");
            exit(0);
        }
        //找到要插入的位置前一个节点
        for(i = 1; i < position; i++) node = node->next;
        new->next = node->next;
        node->next = new;
        p->length++;
    }
}

/**
 * 删除
 * 时间复杂度为O(n)
 */
static int delete(PLinkList p)
{
    int position, i;
    PListNode preNode = p->head, currentNode;
    if(isEmpty(p)){
        printf("Empty list\n");
        exit(0);
    }

    printf("Input the position\n");
    scanf("%d", &position);

    if(position > p->length){
        printf("Invalid position.The length of list is %d\n",p->length);
        exit(0);
    }

    for(i = 1; i < position; i++) preNode = preNode->next;
    currentNode = preNode->next;
    preNode->next = currentNode->next;
    currentNode->next = NULL;
    p->length--;
    free(currentNode);
}

/**
 * 寻找某一个位置的值
 * 时间复杂度为O(n)
 */
static int get(PLinkList p)
{
    int position, i;
    PListNode node = p->head;
    if(isEmpty(p)){
        printf("Empty list");
        exit(0);
    }

    printf("Input the position you want to find\n");
    scanf("%d", &position);

    if(position > p->length){
        printf("Invalid position\n");
        exit(-1);
    }

    for(i = 0; i < position; i++){
        node = node->next;
    }
    printf("Position is %d and value is %d\n", position, node->data);
}

/**
 * 寻找某一值得位置
 * 时间弄复杂为O(n)
 */
static int getPosition(PLinkList p)
{
    int value, i = 0;
    PListNode node = p->head;
    if(isEmpty(p)){
        printf("Empty list\n");
        exit(0);
    }

    printf("Input the value you want to find\n");
    scanf("%d", &value);

    while((node = node->next)){
        if(node->data == value){
            i++;
            break;
        }
        i++;
    }

    if(node == NULL || i == 0){
        printf("Do not have this value\n");
        exit(0);
    }
    else{
        printf("The value is %d and the position is %d",value,i);
    }
}

/**
 * 遍历
 */
static int travesal(PLinkList p)
{
    //头结点的下一个节点也就是第一个节点
    PListNode node = p->head->next;

    if(p->head == NULL){
        printf("Invalid list\n");
        exit(-1);
    }

    if(isEmpty(p)){
        printf("Empty list\n");
        exit(0);
    }

    while (node != NULL){
        printf("%d\n",node->data);
        node = node->next;
    }
}

/**
 * 释放资源
 */
static int clear(PLinkList p)
{
    free(p);
}

int linkList()
{
    LinkList p;
    initial(&p);
    insert(&p);
    insert(&p);
    insert(&p);
    insert(&p);
    insert(&p);
    insert(&p);
    travesal(&p);
    delete(&p);
    get(&p);
    getPosition(&p);
}


