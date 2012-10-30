#ifndef AA_TREE
#define AA_TREE
#include "TreeNode/AATreeNode.h"
#endif

class AA_Tree
{
    private:
        AATreeNode *treeRoot;
        AATreeNode *skew(AATreeNode *curNode);
        AATreeNode *split(AATreeNode *curNode);
    public:
        AATreeNode *insertNode(AATreeNode *curNode, int value);
        AATreeNode *deleteNode(AATreeNode *curNode, int value);
        bool isLeaf(AATreeNode *curNode);
        AATreeNode *successor(AATreeNode *curNode);
        AATreeNode *predecessor(AATreeNode *curNode);
        AATreeNode *decreaseLevel(AATreeNode *curNode);
};

