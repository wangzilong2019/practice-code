//
// Created by hanoi_ahoj on 2019/1/2.
//

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <stdbool.h>

typedef char BinTreeElemType;

typedef struct BinTreeNode
{
    struct BinTreeNode *lchild;
    struct BinTreeNode *rchild;
    BinTreeElemType val;
} BinTreeNode, *BinTree;

#define MAXSIZE 10

typedef BinTree QElemType;

typedef struct {
    QElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

typedef enum {
    OK = 1, ERROR = 0,
    FULL = 1, NOTFULL = 0,
    EMPTY = 1, NOTEMPTY = 0
} Status;

/*   循坏队列的顺序存储   */
// 初始化一个空队列
Status InitQueue(SqQueue *q);
// 返回队列的长度
int QueueLength(const SqQueue *q);
// 判满
Status IsFull(const SqQueue *q);
// 判空
Status IsEmpty(const SqQueue *q);
// 入队
Status EnQueue(SqQueue *q, const QElemType e);
// 出队
Status DeQueue(SqQueue *q, QElemType *e);

// 利用扩展二叉树建立一个二叉树
void CreateBinTreeByKeyBoard (BinTree *root);
//void CreateBinTreeByArr(BinTree *root, BinTreeElemType *pre_order_add);
// 根据前序遍历的数组来构建二叉树，size为传进来数组的size，used为构建过程中用掉的数组中的元素个数
//BinTree CreateTreeFromArr(BinTreeElemType *pre_order_arr, int size, int *used);

// 前序遍历二叉树
void PreOrderTraverse(BinTree root);

// 中序遍历二叉树
void InOrderTraverse(BinTree root);

// 后序遍历二叉树
void PostOrderTraverse(BinTree root);

// 求节点个数
// 1. 遍历
void TreeNodeNum(BinTree root, int *num);
// 2. 递推
int TreeNodeNum2(BinTree root);

// 叶子节点个数
// 1. 遍历
void TreeLeafNum1(BinTree root, int *leaf_num);
// 2. 递推
int TreeLeafNum2(BinTree root);

// 求第K层节点个数
int LevelKNodeNum(BinTree root, int k);

// 查找 val == x 的节点
BinTree TreeFindX(BinTree root, BinTreeElemType x);

// 层序遍历，用到队列
void LevelOrderTraversal(BinTree root);

// 判断一个树是否为完全二叉树
bool IsCompleteTree(BinTree root);


#endif //BINTREE_BINTREE_H
