#include "Btree.h"
#include "queue.h"

int main(){
    BTNode* A=CreatBTNode('A');
    BTNode* B=CreatBTNode('B');
    BTNode* C=CreatBTNode('C');
    BTNode* D=CreatBTNode('D');
    BTNode* E=CreatBTNode('E');
    A->left=B;
    A->right=C;
    B->left=D;
    B->right=E;
    // printf("%s\n","前序遍历:");
    // BTPreOrder(A);
    // printf("\n");
    // printf("%s\n","中序遍历:");
    // BTInOrder(A);
    // printf("\n");
    // printf("%s\n","后序遍历:");
    // BTPostOrder(A);

    // int num=BTSize(A);
    // printf("%d\n",num);
    // int sum=0;
    // BTSize_EXV(A,&sum);
    // printf("%d\n",sum);

    // int sum_leaf=0;
    // sum_leaf=BTLeafSize(A);
    // printf("%d\n",sum_leaf);

    // int sum_k=0;
    // sum_k=BTTiersSize(A,3);
    // printf("%d\n",sum_k);
    // printf("%c",BTFind(A,'E')->data);
    BTLevelOrder(A);
    return 0; 
}