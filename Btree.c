#include "Btree.h"
//创建节点
BTNode* CreatBTNode(BTDataType val){
    BTNode* newnode=(BTNode*)malloc(sizeof(BTNode));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
//前序遍历
//void FrontOrder();
void BTPreOrder(BTNode* bt){
    if(!bt){
        printf("%s ","NULL");
        return;
    }     
    printf("%c ",bt->data);
    BTPreOrder(bt->left);
    BTPreOrder(bt->right);
}
//中序遍历
void BTInOrder(BTNode* bt){
    if(!bt){
        printf("%s ","NULL");
        return;
    }     
    BTInOrder(bt->left);
    printf("%c ",bt->data);
    BTInOrder(bt->right);
}
//后序遍历
//void RearOrder();
void BTPostOrder(BTNode* bt){
    if(!bt){
        printf("%s ","NULL");
        return;
    }     
    BTPostOrder(bt->left);
    BTPostOrder(bt->right);
    printf("%c ",bt->data);
}

//建立二叉树
void BTBuilt();
//摧毁二叉树
void BTdest(BTNode* bt);

//增删查改
void BTPush(BTDataType data);
void BTPop(BTDataType data);
BTNode* BTFind(BTNode* bt,BTDataType data){
    if(!bt)
        return NULL;
    if(bt->data==data)
        return bt;
    BTNode* node=BTFind(bt->left,data);
    if(node)
        return node;
    node=BTFind(bt->right,data);
    if(node)
        return node;
    
    return NULL;
}
void BTModi(BTNode* bt,BTDataType data);


//二叉树大小（节点数量）
void BTSize_EXV(BTNode* bt,int* size){//需要在函数外部创建计数变量size，传递指针以修改
    if(!bt)
        return;
    (*size)++;
    BTSize_EXV(bt->left,size);
    BTSize_EXV(bt->right,size);

} 
int BTSize(BTNode* bt){
    if(!bt)
        return 0;
    return 1+BTSize(bt->left)+BTSize(bt->right);
}
//叶节点数量
int BTLeafSize(BTNode* bt){
    if(!bt)
        return 0;
    if(!bt->left&&!bt->right)
        return 1;    
    return BTLeafSize(bt->left)+BTLeafSize(bt->right);
}
//二叉树深度
int BTdepth(BTNode* bt){
    if(!bt)
        return 0;
    return 1+fmax(BTdepth(bt->left),BTdepth(bt->right));    
}

//第K层节点的个数
//当前树的k层节点数 相当于 左右子树的k-1层节点数之和，直到k==1不再分解
int BTTiersSize(BTNode* bt,int k){
    if(!bt)
        return 0;
    if(k==1)
        return 1;
    return BTTiersSize(bt->left,k-1)+BTTiersSize(bt->right,k-1);    
}


//层序遍历--需要借助队列
void BTLevelOrder(BTNode* bt);
//是否完全二叉树
bool isCompleteBT(BTNode* bt);