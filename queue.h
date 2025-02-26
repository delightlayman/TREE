#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct binarytreenode;//向前声明---Btree包含queue.h---故而不使用extern

//#define MaxQueue 10
typedef struct binarytreenode* QDataType;

typedef struct queuenode{
    QDataType data;
    struct queuenode* next; 
}Qnode;

typedef struct queue{
    int size;
    Qnode* head;
    Qnode* tail;
}Queue;


//节点创建
Qnode* CreatQNode(QDataType data);
//初始化
void InitQueue(Queue* q);
//摧毁
void DestQueue(Queue* q);
//空否？
bool isEmptyQueue(Queue* q);
//满否？
bool isFullQueue(Queue* q);
//大小
int QueueSzie(Queue* q);

//入队--尾部
void QueuePush(Queue* q,QDataType data);
//出队--头
void QueuePop(Queue* q);
//打印queue
//void QueuePrint(Queue* q);
//头尾值
QDataType QueueHead(Queue* q);
QDataType Queuetail(Queue* q);

