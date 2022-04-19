#include "../include/TreeNode.h"
#include "../include/Queue.h"

TreeNode *newTreeNode(int data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void postorder(TreeNode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void levelorder(TreeNode *root) {
    Queue* Q = newQueue();
    if (root == NULL)
        return;
    enqueue(Q, root);
    while (!isEmpty(*Q)) {
        QueueNode *cur = dequeue(Q);
     
        printf("%d ", cur->treeData->data);
        if (cur->treeData->left)
            enqueue(Q, cur->treeData->left);
        if (cur->treeData->right)
            enqueue(Q, cur->treeData->right);
    }
}

void insert(TreeNode **root, TreeNode *node) {
    Queue* Q = newQueue();
    if (*root == NULL) {
        *root = node;
        return;
    }
    enqueue(Q, *root);
    while (!isEmpty(*Q)) {
        QueueNode *cur = dequeue(Q);

        if (!cur->treeData->left) {
            cur->treeData->left = node;
            return;
        } else 
            enqueue(Q, cur->treeData->left);

        if (!cur->treeData->right) {
            cur->treeData->right = node;
            return;
        } else 
            enqueue(Q, cur->treeData->right);
    }
}

int main() {
    //how to insert nodes in the tree
    TreeNode *ROOT = NULL;
    for (int i = 0; i < 5; ++i) {
        insert(&ROOT, newTreeNode(i));
    }
    postorder(ROOT);
    return 0;
} 