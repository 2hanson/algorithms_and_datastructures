#ifndef AATREENODE
#define AATREENODE
#include <iostream>
#include "../../treeNode/TreeNode.h"
#endif

class AATreeNode: public TreeNode
{
    public:
        AATreeNode *leftChild;
        AATreeNode *rightChild;
        AATreeNode *parent;
        int level;
        AATreeNode(int value);
};

AATreeNode::AATreeNode(int value)
{
    this->value = value;
    this->leftChild = NULL;
    this->rightChild = NULL;
    this->parent = NULL;
    this->level = 1;
}
