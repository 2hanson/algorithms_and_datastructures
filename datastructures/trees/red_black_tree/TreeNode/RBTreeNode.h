#ifndef RBTREENODE
#define RBTREENODE
#include "../../treeNode/TreeNode.h"
#include "Color.h"
#endif

class RBTreeNode:public TreeNode
{
    public:
        COLOR color;
        RBTreeNode *leftChild;
        RBTreeNode *rightChild;
        RBTreeNode *parent;

        RBTreeNode(int value);
};

RBTreeNode::RBTreeNode(int value)
{
    this->value = value;
    this->color = Red;
    this->parent = NULL;
    this->leftChild = NULL;
    this->rightChild = NULL;
}
