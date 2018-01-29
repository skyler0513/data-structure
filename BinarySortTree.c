#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "define.h"

/**
 * 顺序二叉树的搜索
 */
int static searchBST(PBinaryNode tree, int key, PBinaryNode parent, PBinaryNode *res)
{
    //tree是指向树中某一个节点的指针
    if(tree == NULL){
        *res = parent;
        return 0;
    }
    //变量res:如果找到就返回父母节点的地址如果找不到就返回“最亲近的节点”的地址
    else if(tree->data == key){
        *res = tree;
        return 1;
    }
    else if(tree->data > key) return searchBST(tree->lChild, key, tree, res);
    else  return searchBST(tree->rChild, key, tree, res);
};

/**
 * 顺序二叉树的插入
 */
int static insertBST(PBinaryNode *tree, int value)
{
    PBinaryNode res, node;
    //如果找不到
    if(searchBST(*tree, value, NULL, &res) == 0){
        //新的二叉树节点
        node = (BinaryNode *)malloc(sizeof(BinaryNode));
        node->data = value;
        node->lChild = node->rChild = NULL;

        //如果是空的二叉树，新节点就是根节点
        if(res == NULL) *tree = node;
        else if(res->data > value) res->lChild= node;
        else  res->rChild = node;

        return 1;
    }
    else return 0;
}

/**
 * 删除一个节点
 */
int static delete(PBinaryNode *tree)
{
    PBinaryNode tmp = *tree;
    //用左子树中的值最大的那个节点替换要被删除的节点
    PBinaryNode s = (*tree)->lChild;
    //右子树为空
    if((*tree)->rChild == NULL){
        *tree = (*tree)->lChild;
        free(tmp);
    }
    //左子树为空
    else if((*tree)->lChild == NULL){
        *tree = (*tree)->rChild;
        free(tmp);
    }
    else{
        //一路向右
        while(s->rChild != NULL){
            tmp = s;
            s = s->rChild;
        }
        (*tree)->data = s->data;
        if(tmp == (*tree)) tmp->lChild = s->lChild;
        else tmp->rChild = s->lChild;
    }
    return 1;
}

/**
 * 寻找并删除顺序二叉树中的一个节点
 */
int static deleteBST(PBinaryNode *tree, int value)
{
    if((*tree) == NULL) return 0;
    if((*tree)->data == value) return delete(tree);
    else if((*tree)->data > value) return deleteBST(&((*tree)->lChild), value);
    else return deleteBST(&((*tree)->rChild), value);
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

int testBinarySortTree()
{
    int a[] = {34,68,12,0,58,79,110,119,45,21,33,9,10,2,8,7};
    int size = sizeof(a) / sizeof(a[0]);
    PBinaryNode tree = NULL;

    for(int i = 0; i < size; i++){
        insertBST(&tree,a[i]);
    }
    middleTraversal(tree);
    deleteBST(&tree, 8);
    middleTraversal(tree);
}

