#include <iostream>
#include "red_black_tree.h"

using namespace std;

Red_Black_Tree::Red_Black_Tree()
{
    this->treeRoot = NULL;
}

Red_Black_Tree::Red_Black_Tree(int value)
{
    this->treeRoot = new RBTreeNode(value);
    this->treeRoot->color = Black;
}

RBTreeNode *Red_Black_Tree::grandparent(RBTreeNode *curNode)
{
    if (curNode != NULL && curNode->parent != NULL)
        return curNode->parent->parent;

    return NULL;
}

RBTreeNode *Red_Black_Tree::uncle(RBTreeNode *curNode)
{
    RBTreeNode *gpNode = grandparent(curNode);

    if (gpNode == NULL)
        return NULL;

    if (curNode == gpNode->leftChild)
    {
        return gpNode->rightChild;
    }
    else
    {
        return gpNode->leftChild;
    }
}

RBTreeNode *Red_Black_Tree::findTheNode(int value)
{
    RBTreeNode *currentNode = this->treeRoot;

    while (currentNode != NULL)
    {
        if (currentNode->value == value)
        {
            return currentNode;
        }

        if (currentNode->value > value)
        {
            currentNode = currentNode->leftChild;
        }
        else
        {
            currentNode = currentNode->rightChild;
        }
    }
}

void Red_Black_Tree::insertNewNode(int value)
{
    if (this->treeRoot == NULL)
    {
        this->treeRoot = new RBTreeNode(value);
        restoreProperties(this->treeRoot);
        return;
    }
    RBTreeNode * tempRoot = this->treeRoot;
    while (tempRoot != NULL)
    {
        if (value == tempRoot->value)
        {
            return;
        }
        else if (value < tempRoot->value)
        {
            if (tempRoot->leftChild == NULL)
            {
                tempRoot->leftChild = new RBTreeNode(value);
                tempRoot->leftChild->parent = tempRoot;
                restoreProperties(tempRoot->leftChild);
                return;
            }
            else
            {
                tempRoot = tempRoot->leftChild;
            }
        }
        else
        {
            if (tempRoot->rightChild == NULL)
            {
                tempRoot->rightChild = new RBTreeNode(value);
                tempRoot->rightChild->parent = tempRoot;
                restoreProperties(tempRoot->leftChild);
                return;
            }
            else
            {
                tempRoot = tempRoot->rightChild;
            }
        }
    }
}

//insert case 1:
//The current node N is at the root of the tree. In this case, it is repainted black
void Red_Black_Tree::insertNodeCase1(RBTreeNode *newNode)
{
    if (newNode->parent == NULL)
    {
        newNode->color = Black;
    }
    else
    {
        insertNodeCase2(newNode);
    }
}

//Case 2: The current node's parent P is black, so property 4 (both children of every red node are black) is not invalidated. 
//In this case, the tree is still valid. property 5 (all paths from any given node to its leaf nodes contain the same number 
//of black nodes) is not threatened, because the current node N has two black leaf children, but because N is red, the paths 
//through each of its children have the same number of black nodes as the path through the leaf it replaced, which
//was black, and so this property remains satisfied.
void Red_Black_Tree::insertNodeCase2(RBTreeNode *newNode)
{
    
    if (newNode->parent->color == Black)
    {
        return; /* Tree is still valid */
    }
    else
    {
        insertNodeCase3(newNode);
    }
}

void Red_Black_Tree::insertNodeCase3(RBTreeNode *newNode)
{
    RBTreeNode *uncleNode = uncle(newNode);
    RBTreeNode *gpNode;
    if (newNode != NULL && uncleNode->color == Red)
    {
        newNode->parent->color = Black;
        uncleNode->color = Black;
        gpNode = grandparent(newNode);
        gpNode->color = Red;

        insertNodeCase1(gpNode);
    }
    else
    {
        insertNodeCase4(newNode);
    }
}

void Red_Black_Tree::insertNodeCase4(RBTreeNode *newNode)
{
    
}

void Red_Black_Tree::insertNodeCase5(RBTreeNode *newNode)
{
    
}

void Red_Black_Tree::restoreProperties(RBTreeNode *newNode)
{    
}

int main()
{}

