#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE
#include "TreeNode/RBTreeNode.h" 
#endif

class Red_Black_Tree
{
    private:
        RBTreeNode *treeRoot;

    public:
        Red_Black_Tree();
        Red_Black_Tree(int value);
        RBTreeNode *findTheNode(int value);
        RBTreeNode *grandparent(RBTreeNode *curNode);
        RBTreeNode *uncle(RBTreeNode *curNode);
        void insertNewNode(int value);
        void restoreProperties(RBTreeNode *newNode);
        void insertNodeCase1(RBTreeNode *newNode);
        void insertNodeCase2(RBTreeNode *newNode);
        void insertNodeCase3(RBTreeNode *newNode);
        void insertNodeCase4(RBTreeNode *newNode);
        void insertNodeCase5(RBTreeNode *newNode);
        void rotateLeft(RBTreeNode *curNode);
        void retotaLeft(RBTreeNode *parentNodeOfcur);
        void rotateRight(RBTreeNode *parentNodeOfcur);
};

