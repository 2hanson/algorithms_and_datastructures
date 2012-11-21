#ifndef TREENODEH
#define TREENODEH
#include <iostream>
#endif

class TreeNode
{
    public:
        int value;
        TreeNode* leftChild;
        TreeNode* rightChild;
        TreeNode* parent;
        TreeNode(int value);
};

TreeNode::TreeNode(int value)
{
    this->value = value;
    this->leftChild = NULL;
    this->rightChild = NULL;
    this->parent = NULL;
}
