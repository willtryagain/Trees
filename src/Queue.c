#include "../include/Queue.h"
#include <stdbool.h>


QueueNode* newQueueNode(TreeNode *node) {
    QueueNode *qnode = malloc(sizeof(QueueNode));
    qnode->next = NULL;
    qnode->treeData = node;
    return qnode;
}

Queue* newQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->FRONT = q->REAR = NULL;
    return q;
}

bool isEmpty(Queue Q) {
    return (Q.FRONT == NULL);
}

void enqueue(Queue *Q, TreeNode *node) {
    QueueNode *qnode = newQueueNode(node);
    if (Q->FRONT == NULL) 
        Q->REAR = Q->FRONT = qnode;
    else {
        QueueNode *temp = Q->FRONT;
        while (temp -> next != NULL)
            temp = temp->next;
        temp->next = qnode;
        Q->REAR = qnode;
    }
}

QueueNode* dequeue(Queue *Q) {
    QueueNode *qnode = NULL;
    if (Q->FRONT == NULL) 
        printf("Queue is empty!\n");
    else {
        qnode = malloc(sizeof(QueueNode));
        qnode->treeData = Q->FRONT->treeData;
        Q->FRONT = Q->FRONT->next;
        if (Q->FRONT == NULL)
            Q->REAR = NULL;
    }
    return qnode;
}

