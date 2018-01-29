#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "define.h"

/*******************辅助队列start***********************/

/**
 * 创建一个辅助队列
 * @return
 */
PSeqQueue static createQueue()
{
    PSeqQueue p = (SeqQueue *)malloc(sizeof(SeqQueue));
    p->rear = 0;
    p->rear = 0;

    return p;
}

/**
 * 进队列
 * @param p
 * @param value
 * @return
 */
int static enQueue(PSeqQueue p, int value)
{
    p->data[p->rear] = value;
    p->rear = (p->rear + 1) % MAX;

    return 0;
}

/**
 * 出队列
 * @param p
 * @return
 */
int static deQueue(PSeqQueue p)
{
    int  value = p->data[p->front];
    p->front = (p->front + 1) % MAX;

    return value;
}

/**
 * 判断空
 * @param p
 * @return
 */
int static checkEmpty(PSeqQueue p)
{
    if(p->rear == p->front) return 1;
    else return 0;
}
/*******************辅助队列end***********************/

/*******************邻接矩阵start***********************/
/**
 * 邻接矩阵
 * @return
 */
PAdjMatrix static createAdjMatrix(int flag)
{
    int i, j;
    PAdjMatrix p = (AdjMatrix *)malloc(sizeof(AdjMatrix));

    printf("Begin to create adjacency matrix.input the quantity of vertex and lines\n");
    scanf("%d%d", &(p->vertexSize), &(p->lineSize));

    printf("Input the vertex\n");
    for(i = 0; i < p->vertexSize; i++) scanf("%d", &(p->vertex[i]));

    //初始化矩阵
    for(i = 0; i < p->lineSize; i++){
        for(j = 0; j < p->lineSize; j++)
            if(flag == 0) p->matrix[i][j] = 0;
            else p->matrix[i][j] = 666666;
    }

    //构建矩阵
    printf("Input the lines and power\n");
    for(i = 0; i < p->lineSize; i++) {
        int start, end, power;
        scanf("%d%d%d", &start, &end, &power);
        p->matrix[start][end] = power;
        //p->matrix[end][start] = 1;
    }

    return p;
}

/**
 * 邻接矩阵的深度优先算法的递归方法
 * @param value
 * @param visits
 * @param p
 * @return
 */
int AdjMatrixDFS(int value, int *visits, PAdjMatrix p)
{
    int i;
    if(visits[value] == 0){
        visits[value] = 1;
        printf("%d\n", value);
    }

    for(i = 0; i < p->lineSize; i++){
        if(p->matrix[value][i] == 1 && visits[i] == 0)
            AdjMatrixDFS(i, visits, p);
    }
}

/**
 * 邻接矩阵的广度优先算法
 * @param visits
 * @param p
 * @param queue
 * @return
 */
int AdjMatrixBFS(int *visits, PAdjMatrix p, PSeqQueue queue)
{
    int i, value;
    while( !checkEmpty(queue)){
        value = deQueue(queue);
        if(visits[value] == 0){
            visits[value] = 1;
            printf("%d\n", p->vertex[value]);
            //相邻的节点进队列
            for(i = 0; i < p->vertexSize; i++){
                if(p->matrix[value][i] == 1 && visits[i] ==0){
                    enQueue(queue, i);
                }
            }
        }
    }
}

/**
 * 邻接矩阵的遍历算法
 * @return
 */
int AdjMatrixTraversal()
{
    PAdjMatrix p = createAdjMatrix(0);

    int visits[p->vertexSize];
    for(int i = 0; i < p->vertexSize; i++) visits[i] = 0;

    PSeqQueue queue = createQueue();
    //深度优先
    //AdjMatrixDFS(0, visits, p);
    //广度优先，需要借助一个队列
    enQueue(queue, 0);
    AdjMatrixBFS(visits, p, queue);
}

int prime(PAdjMatrix p)
{
    //i和j只用于循环；index用于存储每一次加入元素的位置，previous
    //用于存储上一次加入元素的位置
    int i, j, index=0, previous = 0;
    int lowcost[p->vertexSize],adjVex[p->vertexSize];

    //初始化
    for(i = 0; i < p->vertexSize; i++){
        adjVex[i] = 0;
        lowcost[i] = p->matrix[0][i];
    }

    printf("The start vertex is %d\n", p->vertex[0]);
    //每一次循环都会找出一个权值最小的节点
    for(i = 1; i < p->vertexSize; i++) {
        int low = 666666;
        //找出lowcost中最小的那个数
        for(j = 0; j < p->vertexSize; j++){
            if(lowcost[j] < low && lowcost[j] != 0) {
                low = lowcost[j];
                index = j;
            }
        }
        adjVex[previous] = index;
        printf("The path is %d%d and the power is %d\n",p->vertex[previous],p->vertex[index],low);
        previous = index;
        lowcost[index] = 0;
        for(j = 0; j < p->vertexSize; j++){
            if(lowcost[j] > p->matrix[index][j] && lowcost[j] != 0)
                lowcost[j] = p->matrix[index][j];
        }
    }
}
/*******************邻接矩阵end***********************/

/*********************邻接表start***********************/

/**
 * 创建邻接表
 * @return
 */
PAdjVertex static createAdjVertex()
{
    PAdjVertex p = (AdjVertex *)malloc(sizeof(AdjVertex));
    if(p == NULL){
        printf("Malloc failed!\n");
        exit(-1);
    }

    printf("Input the quantity of vertex and lines\n");
    scanf("%d%d", &p->vertexSize, &p->lineSize);

    printf("Input the vertexes\n");
    for(int i = 0; i < p->vertexSize; i++){
        scanf("%d", &(p->vertex[i].data));
        p->vertex[i].next = NULL;
    }

    printf("Input the lines\n");
    for(int j = 0; j < p->lineSize; j++){
        int start, end;
        scanf("%d%d", &start, &end);
        //新的邻接点
        PAdjNode new = (AdjNode *)malloc(sizeof(AdjNode));
        if(new == NULL){
                printf("Malloc failed!\n");
                exit(-1);
        }

        new->data = p->vertex[end].data;
        new->next = p->vertex[start].next;
        p->vertex[start].next = new;
    }

    return p;
}

/**
 * 邻接表的深度优先遍历
 * @param visits
 * @param value
 * @param p
 * @return
 */
int adjVertexDFS(int *visits, int value, PAdjVertex p)
{
    //当前节点的第一个邻接点
    PAdjNode node = p->vertex[value].next;
    if(visits[value] == 0){
        printf("%d", p->vertex[value].data);
        visits[value] = 1;
    }
    while(node != NULL){
        if(visits[node->data] == 0)
            adjVertexDFS(visits, node->data, p); //递归
        node = node->next;
    }
}

/**
 * 邻接表的广度优先遍历
 * @param visits
 * @param p
 * @param queue
 * @return
 */
int adjVertexBFS(int *visits, PAdjVertex p, PSeqQueue queue)
{
    while( !checkEmpty(queue)){
        int value = deQueue(queue);
        if(visits[value] == 0){
            printf("%d\n", p->vertex[value]);
            visits[value] = 1;
        }

        //把邻接点加入队列中
        PAdjNode node = p->vertex[value].next;
        while(node != NULL && visits[node->data] == 0){
            enQueue(queue, node->data);
            node = node->next;
        }
    }
}

/**
 * 邻接表的遍历
 * @return
 */
int adjVertexTraversal()
{
    PAdjVertex p = createAdjVertex();
    int visists[p->vertexSize];
    for(int i = 0; i < p->vertexSize; i++) visists[i] = 0;

    //adjVertexDFS(visists, 0, p);

    PSeqQueue queue = createQueue();
    enQueue(queue,0);
    adjVertexBFS(visists, p, queue);
}

/*********************邻接表end***********************/
int main()
{
    //AdjMatrixTraversal();
    //adjVertexTraversal();
    PAdjMatrix p = createAdjMatrix(1);
    prime(p);
}
