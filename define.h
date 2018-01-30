#ifndef DATA_STRUCTURE_DEFINE_H
#define DATA_STRUCTURE_DEFINE_H
#define MAX 100
//线性表的顺序存储结构
typedef struct
{
    //指向第一个节点的指针
    int *firstNode;
    //表当前的长度
    int length;
    //表最大的长度
    int size;
}SeqList, *PSeqList;

//线性表的链式存储结构中的节点
typedef struct
{
    int data;
    struct ListNode *next;
}ListNode, *PListNode;

//单链表
typedef struct
{
    int length;
    //头指针
    PListNode head;
}LinkList, *PLinkList;

//栈的顺序存储结构
typedef struct
{
    //栈顶指针
    int *top;
    //栈的当前长度
    int length;
    //栈的最大长度
    int size;
}SeqStack, *PSeqStack;

//栈的链式存储结构
typedef struct
{
    //指向头结点的指针
    PListNode top;
    int length;
}LinkStack, *PLinkStack;

//循环队列的顺序存储结构
typedef struct
{
    int data[MAX];
    int front;
    int rear;
}SeqQueue, *PSeqQueue;

//队列的链式存储结构
typedef struct
{
    //头指针
    PListNode head;
    //尾指针
    PListNode rear;
    //队列的当前长度
    int length;
}LinkQueue, *PLinkQueue;

//字符串
typedef struct
{
    int length;
    char str[MAX];
}String, *PString;

//二叉树的节点
typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *lChild, *rChild;
}BinaryNode, *PBinaryNode;

//邻接矩阵
typedef struct
{
    //存放顶点元素
    int vertex[MAX];
    //存放顶点元素间关系的矩阵
    int matrix[MAX][MAX];
    int vertexSize;
    int lineSize;
}AdjMatrix, *PAdjMatrix;

typedef struct AdjLinkListNode
{
    int data;
    struct vertexListNode *next;
}AdjNode, *PAdjNode;

typedef struct
{
    AdjNode vertex[MAX];
    int vertexSize;
    int lineSize;
}AdjVertex, *PAdjVertex;

typedef struct
{
    int start;
    int end;
    int power;
}Edge, *PEdge;
#endif //DATA_STRUCTURE_DEFINE_H
