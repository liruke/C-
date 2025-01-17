#pragma once

#include"BTNode.h"

typedef BTNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;


void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType  QueueFront(Queue* pq);
QDataType  QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);