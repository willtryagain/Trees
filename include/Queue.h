#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "QueueNode.h"

typedef struct Queue {
    QueueNode *FRONT;
    QueueNode *REAR;
} Queue;

Queue* newQueue();
void enqueue(Queue *Q, TreeNode *node);
QueueNode* dequeue(Queue* Q);
bool isEmpty(Queue Q);

#endif