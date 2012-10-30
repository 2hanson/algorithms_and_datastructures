#include <iostream>
#include "aa_tree.h"

using namespace std;

//Skew is a right rotation to replace a subtree containing a left horizontal 
//link with one containing a right horizontal link instead.
//input: curNode, a node representing an AA tree that needs to be rebalanced.
//output: Another node representing the rebalanced AA tree.
AATreeNode *AA_Tree::skew(AATreeNode *curNode)
{
    if (curNode == NULL)
    {
        return NULL;
    }
   
    if (curNode->leftChild == NULL)
    {
        return curNode;
    }
    
    if (curNode->level == curNode->leftChild->level)
    {
        //Swap the pointers of horizontal left links.
        AATreeNode *L = curNode->leftChild;
        curNode->leftChild = L->rightChild;
        L->rightChild = curNode;

        return L;
    }

    return curNode;
}

//Split is a left rotation and level increase to replace a subtree containing 
//two or more consecutive right horizontal links with one containing two fewer
//consecutive right horizontal links.
//input: curNode, a node representing an AA tree that needs to be rebalanced.
//output: Another node representing the rebalanced AA tree.
AATreeNode *AA_Tree::split(AATreeNode *curNode)
{
    if (curNode == NULL)
    {
        return NULL;
    }

    if (curNode->rightChild == NULL || curNode->rightChild->rightChild == NULL)
        return curNode;

    if (curNode->level == curNode->rightChild->rightChild->level)
    {
        AATreeNode *R = curNode->rightChild;
        curNode->rightChild = R->leftChild;
        R->leftChild = curNode;
        R->level++;

        return R;
    }

    return curNode;
}

//input: value, the value to be inserted, and curNode, the root of the tree to insert it into.
//output: A balanced version tree including new value.
AATreeNode *AA_Tree::insertNode(AATreeNode *curNode, int value)
{
    //Do the normal binary tree insertion procedure. Set the result of the
    //recursive call to the correct child in case a new node was created or the
    //root of the subtree changes.

    if (curNode == NULL)
    {
        //Create a new leaf node with value.
        return new AATreeNode(value);
    }

    if (value < curNode->value)
    {
        curNode->leftChild = insertNode(curNode->leftChild, value);
    }
    else if (value > curNode->value)
    {
        curNode->rightChild = insertNode(curNode->rightChild, value);
    }
    //Note that the case of X == value(T) is unspecified. As given, an insert
    //will have no effect. The implementor may desire different behavior.
    //
    //Perform skew and then split. The conditionals that determine whether or
    //not a rotation will occur or not are inside of the procedures, as given above.
    curNode = skew(curNode);
    curNode = split(curNode);
}

//input: value, the value to delete, and curNode, the root of the tree from which it should be deleted.
//Tree, balanced, without the value.
AATreeNode *AA_Tree::deleteNode(AATreeNode *curNode, int value)
{
    if (curNode == NULL)
    {
        return curNode;
    }
    
    if (value > curNode->value)
    {
        curNode->rightChild = deleteNode(curNode->rightChild, value);
    }
    else if (value < curNode->value)
    {
        curNode->leftChild = deleteNode(curNode->leftChild, value);
    }
    else
    {
        //If we're a leaf, easy, otherwise reduce to leaf case. 
        if (isLeaf(curNode))
        {
            return NULL;
        }

        AATreeNode *nearNode;
        
        if (curNode->leftChild == NULL)
        {
            nearNode = successor(curNode);
            curNode->rightChild = deleteNode(curNode->rightChild, nearNode->value);
            curNode->value = nearNode->value;
        }
        else
        {
            nearNode = predecessor(curNode);
            curNode->leftChild = deleteNode(curNode->leftChild, nearNode->value);
            curNode->value = nearNode->value;
        }
    }
    
    //Rebalance the tree. Decrease the level of all nodes in this level if
    //    necessary, and then skew and split all nodes in the new level.

    curNode = decreaseLevel(curNode);
    curNode = skew(curNode);
    curNode->rightChild = skew(curNode->rightChild);
    curNode->rightChild->rightChild = skew(curNode->rightChild->rightChild);
    curNode = split(curNode);
    curNode->rightChild = split(curNode->rightChild);

    return curNode;
}

//input: T, a tree for which we want to remove links that skip levels.
//    output: T with its level decreased.
AATreeNode *AA_Tree::decreaseLevel(AATreeNode *curNode)
{
    int shouldBe = 1;
    if (curNode->leftChild != NULL)
    {
        shouldBe = curNode->leftChild->level + 1;
    }

    if (curNode->rightChild != NULL)
    {
        if (shouldBe > curNode->rightChild->level + 1)
        {
            shouldBe = curNode->rightChild->level + 1;
        }
    }

    if (shouldBe < curNode->level)
    {
        curNode->level = shouldBe;
        if (shouldBe < curNode->rightChild->level)
        {
            curNode->rightChild->level = shouldBe;
        }
    }

    return curNode;
}

AATreeNode *AA_Tree::successor(AATreeNode *curNode)
{
    AATreeNode *sucNode = curNode->rightChild;
    while (sucNode->leftChild != NULL)
    {
        sucNode = sucNode->leftChild;
    }

    return sucNode;
}
        
AATreeNode *AA_Tree::predecessor(AATreeNode *curNode)
{
    AATreeNode *preNode = curNode->leftChild;
    while (preNode->rightChild != NULL)
    {
        preNode = preNode->rightChild;
    }

    return preNode;
}

bool AA_Tree::isLeaf(AATreeNode *curNode)
{
    return curNode->level == 1;
}

int main()
{
    return 0;
}
