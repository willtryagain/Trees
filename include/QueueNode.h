#ifndef QUEUENODE_H
#define QUEUENODE_H

#include "TreeNode.h"

typedef struct QueueNode {
    TreeNode *treeData;
    struct QueueNode *next;    
} QueueNode;



#endif