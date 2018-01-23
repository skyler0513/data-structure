#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "define.h"

/*
 |-------------------------------------------------------------------------------------------------
 |二叉树的遍历，理解递归思想的好例子
 |-------------------------------------------------------------------------------------------------
 */
/**
 * 构建二叉树
 * @param node
 * @return
 */
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

/**
 * 二叉树的前序遍历
 * @param node
 * @return
 */
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

/**
 * 二叉树的中序遍历
 * @param node
 * @return
 */
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

/**
 * 二叉树的后序遍历
 * @param node
 * @return
 */
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

int testBinary()
{
    //根节点的指针
    PBinaryNode root;
    root = createBinaryNode(root);
    //frontTraversal(root);
    //middleTraversal(root);
    behindTraversal(root);
}