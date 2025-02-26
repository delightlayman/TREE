#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct binarytreenode{
    BTDataType data;
    struct binarytreenode* left;
    struct binarytreenode* right;
}BTNode;
//创建节点
BTNode* CreatBTNode(BTDataType val);
//前序遍历
//void FrontOrder();
void BTPreOrder(BTNode* bt);
//中序遍历
void BTInOrder(BTNode* bt);
//后序遍历
//void RearOrder();
void BTPostOrder(BTNode* bt);
//层序遍历
void BTLevelOrder(BTNode* bt);
//建立二叉树
void BTBuilt();
//摧毁二叉树
void BTdest(BTNode* bt);
//增删查改---普通二叉树的增删查改无意义
// void BTPush(BTDataType data);
// void BTPop(BTDataType data);
// BTNode* BTFind(BTNode* bt,BTDataType data);
// void BTModi(BTNode* bt,BTDataType data);


//二叉树大小（节点数量）
void BTSize_EXV(BTNode* bt,int* size);
int BTSize(BTNode* bt);
//叶节点数量
int BTLeafSize(BTNode* bt);
//二叉树深度
int BTdepth(BTNode* bt);
//第K层节点的个数
int BTTiersSize(BTNode* bt);
