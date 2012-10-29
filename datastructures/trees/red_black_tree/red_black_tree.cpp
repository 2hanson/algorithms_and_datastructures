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

//Left Rotation of node P:
//Let Q be P's right child.
//Set Q to be the new root.
//Set P's right child to be Q's left child.
//Set Q's left child to be P.
void Red_Black_Tree::rotateLeft(RBTreeNode *parentNodeOfCur)
{
    RBTreeNode *pivot = parentNodeOfCur->rightChild;
    parentNodeOfCur->rightChild = pivot->leftChild;
    pivot->leftChild = parentNodeOfCur;
    parentNodeOfCur = pivot;
}

//Right Rotation of node Q:
//Let P be Q's left child.
//Set P to be the new root.
//Set Q's left child to be P's right child.
//Set P's right child to be Q.
void Red_Black_Tree::rotateRight(RBTreeNode *parentNodeOfCur)
{
    RBTreeNode *pivot = parentNodeOfCur->leftChild;
    parentNodeOfCur->leftChild = pivot->rightChild;
    pivot->rightChild = parentNodeOfCur;
    parentNodeOfCur = pivot;
}

void Red_Black_Tree::insertNodeCase4(RBTreeNode *newNode)
{
    RBTreeNode *gpNode = grandparent(newNode);

    if ((newNode == newNode->parent->rightChild) && (newNode->parent == gpNode->leftChild))
    {
        rotateLeft(newNode->parent);
        newNode = newNode->leftChild;
    }
    else if ((newNode == newNode->parent->leftChild) && (newNode->parent == gpNode->rightChild))
    {
        rotateRight(newNode->parent);
        newNode = newNode->rightChild;
    }

    insertNodeCase5(newNode);
}

void Red_Black_Tree::insertNodeCase5(RBTreeNode *newNode)
{
    RBTreeNode *gpNode = grandparent(newNode);
    
    newNode->parent->color = Black;
    gpNode->color = Red;

    if (newNode == newNode->parent->leftChild)
    {
        rotateRight(gpNode);
    }
    else
    {
        rotateLeft(gpNode);
    }
}

void Red_Black_Tree::restoreProperties(RBTreeNode *newNode)
{
    insertNodeCase1(newNode);
}

RBTreeNode *Red_Black_Tree::sibling(RBTreeNode *curNode)
{
    if (curNode == curNode->parent->rightChild)
    {
        return curNode->parent->leftChild;
    }
    else
    {
        return curNode->parent->rightChild;
    }
}

void Red_Black_Tree::replaceNode(RBTreeNode *curNode, RBTreeNode *newNode)
{
    if (curNode->parent != NULL)
    {
        if (curNode == curNode->parent->rightChild)
        {
            curNode->parent->rightChild = newNode;
        }
        else
        {
            curNode->parent->leftChild = newNode;
        }
    }

    if (newNode != NULL)
    {
        newNode->parent = curNode->parent;
    }
}

bool Red_Black_Tree::isLeaf(RBTreeNode *curNode)
{
    if (curNode == NULL)
        return true;

    return false;
}

void Red_Black_Tree::deleteOneChild(RBTreeNode *curNode)
{
    RBTreeNode *child = isLeaf(curNode->rightChild) ? curNode->leftChild : curNode->rightChild;

    replaceNode(curNode, child);
    if (curNode->color == Black)
    {
        if (child->color == Red)
        {
            child->color = Black;
        }
        else
        {
            deleteCase1(child);
        }
    }

    free(curNode);
}

void Red_Black_Tree::deleteCase1(RBTreeNode *curNode)
{
    if (curNode->parent != NULL)
    {
        deleteCase2(curNode);
    }
}

void Red_Black_Tree::deleteCase2(RBTreeNode *curNode)
{
    RBTreeNode *s = sibling(curNode);

    if (s->color == Red)
    {
        curNode->parent->color = Red;
        s->color = Black;
        if (curNode = curNode->parent->leftChild)
        {
            rotateLeft(curNode->parent);
        }
        else
        {
            rotateRight(curNode->parent);
        }
    }

    deleteCase3(curNode);
}

void Red_Black_Tree::deleteCase3(RBTreeNode *curNode)
{
   RBTreeNode *s = sibling(curNode);

   if (curNode->parent->color == Black && s->color == Black && 
           s->leftChild->color == Black && s->rightChild->color == Black)
   {
        s->color = Red;
        deleteCase1(curNode->parent);
   }
   else
   {
        deleteCase4(curNode);
   }
}

void Red_Black_Tree::deleteCase4(RBTreeNode *curNode)
{
    
   RBTreeNode *s = sibling(curNode);

   if (curNode->parent->color == Red && s->color == Black && 
           s->leftChild->color == Black && s->rightChild->color == Black)
   {
        s->color = Red;
        curNode->parent->color = Black;
   }
   else
   {
        deleteCase5(curNode);
   }
}

void Red_Black_Tree::deleteCase5(RBTreeNode *curNode)
{
    RBTreeNode *s = sibling(curNode);

    if (s->color == Black)
    {
        /* this if statement is trivial,
         * due to case 2 (even though case 2 changed the sibling to a sibling's child,
         * the sibling's child can't be red, since no red parent can have a red child). */
        /* the following statements just force the red to be on the left of the left of the parent,
         *    or right of the right, so case six will rotate correctly. */
        if ((curNode == curNode->parent->leftChild) && (s->rightChild->color == Black)
                && (s->leftChild->color == Red))
        {
            s->color = Red;
            s->leftChild->color = Black;
            rotateRight(s);
        }
        else if((curNode == curNode->parent->rightChild) && (s->rightChild->color == Red) 
                && (s->leftChild->color == Black))
        {
            s->color = Red;
            s->rightChild->color = Black;
            rotateLeft(s);
        }
    }

    deleteCase6(curNode);
}

void Red_Black_Tree::deleteCase6(RBTreeNode *curNode)
{
    RBTreeNode *s = sibling(curNode);

    s->color = curNode->parent->color;
    curNode->parent->color = Black;

    if (curNode = curNode->parent->leftChild)
    {
        s->rightChild->color = Black;
        rotateLeft(curNode->parent);
    }
    else
    {
        s->leftChild->color = Black;
        rotateRight(curNode->parent);
    }
}

int main()
{}

