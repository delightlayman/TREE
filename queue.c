#include "queue.h"

//节点创建
Qnode* CreatQNode(QDataType data){
    Qnode* node=(Qnode*)malloc(sizeof(Qnode));
    if(!node)
        return NULL;
    node->data=data;
    node->next=NULL;
    return node;
}
//初始化
void InitQueue(Queue* q){
    q->head=q->tail=NULL;
    q->size=0;
}
//摧毁
// void DestQueue(Queue* q){
//     while(q->size){
//         Qnode* temp=q->head;
//         q->head=temp->next;
//         free(temp);
//         q->size--;
//     }
//     q->head = q->tail = NULL;
// }
void DestQueue(Queue* q){
    assert(q);

    while(q->head){
        Qnode* temp=q->head->next;
        free(q->head);
        q->head=temp;
    }
        q->size=0;
        q->head = q->tail = NULL;
}
//空否？
bool isEmptyQueue(Queue* q){
    assert(q);
    return q->size==0;
}
//满否？---需设置队列最大长度MaxQueue
// bool isFullQueue(Queue* q){
//     return q->size==MaxQueue;
// }
//大小
int QueueSzie(Queue* q){
    assert(q);
    return q->size;
}

//入队--尾部
void QueuePush(Queue* q,QDataType data){
    assert(q);

    Qnode* node=CreatQNode(data);
    if(isEmptyQueue(q)){
        q->head=node;
        q->tail=node;
    }else{
        q->tail->next=node;
        q->tail=node;
    }
    q->size++;
}
//出队--头
void QueuePop(Queue* q){
    assert(q);
    assert(q->head);
    if(isEmptyQueue(q))
        return;
    Qnode* temp=q->head;
    q->head=temp->next;
    free(temp);
    q->size--;
}

// void QueuePrint(Queue* q){
//     Qnode *cur=q->head;
//     if(!cur)
//         printf("NULL"); 
//     while(cur){
//         printf("%c ",cur->data);
//         cur=cur->next;
//     }
// }

//头尾值

QDataType QueueHead(Queue* q){
    assert(q);
    return q->head->data;
}
QDataType Queuetail(Queue* q){
    assert(q);
    return q->tail->data;
}