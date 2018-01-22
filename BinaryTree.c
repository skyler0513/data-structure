#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "define.h"
PBinaryNode static createBinaryNode(PBinaryNode node)
{
    int value;
    printf("Input the value\n");
    scanf("%d", &value);
    if(value == 0) node = NULL;
    else{
        node = (BinaryNode *)malloc(sizeof(BinaryNode));
        node->data = value;
        node->lChild = createBinaryNode(node->lChild);
        node->rChild = createBinaryNode(node->rChild);
    }

    return node;
}

int static frontTraversal(PBinaryNode node)
{
    if(node == NULL) return 0;
    else{
        printf("%d\n", node->data);
        frontTraversal(node->lChild);
        frontTraversal(node->rChild);
        return 0;
    }
}

int static middleTraversal(PBinaryNode node)
{
    if(node == NULL) return 0;
    else{
        middleTraversal(node->lChild);
        printf("%d\n", node->data);
        middleTraversal(node->rChild);
        return 0;
    }
}

int static behindTraversal(PBinaryNode node)
{
    if(node == NULL) return 0;
    else{
        behindTraversal(node->lChild);
        behindTraversal(node->rChild);
        printf("%d\n", node->data);
        return 0;
    }
}

int test()
{
    //根节点的指针
    PBinaryNode root;
    root = createBinaryNode(root);
    //frontTraversal(root);
    //middleTraversal(root);
    behindTraversal(root);
}