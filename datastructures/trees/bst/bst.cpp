/* bst implementation in c++
 * copyright (c) 2012 Hanson Yu
 * 
 * implemention is according to this wiki: http://en.wikipedia.org/wiki/Binary_search_tree
 * */

#include <iostream>
using namespace std;

//treenode
typedef struct TREENODE
{
    TREENODE *parent;
    TREENODE *leftChild;
    TREENODE *rightChild;
    int key;
}TreeNode;

//Searching
//iterative process
TreeNode *find_Iterative(TreeNode *root, int key)
{
    TreeNode *currentNode = root;
    while (currentNode != NULL)
    {
        if (currentNode->key == key)
        {
            return currentNode;
        }
        else if (key < currentNode->key)
        {
            currentNode = currentNode->leftChild;
        }
        else
        {
            currentNode = currentNode->rightChild;
        }
    }

    return currentNode;
}

TreeNode *find_Recusive(TreeNode* currentNode, int key)
{
    if (currentNode->key == key)
    {
        return currentNode;
    }
    else if (key < currentNode->key)
    {
        find_Recusive(currentNode->leftChild, key);
    }
    else
    {
        find_Recusive(currentNode->rightChild, key);
    }
}

void insertNode_Iterative(TreeNode* root, int data)
{
    if (root == NULL)
    {
        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->key = data;
        root->leftChild = NULL;
        root->rightChild = NULL;

        return;
    }

    TreeNode *m_root = root;

    while (m_root != NULL)
    {
        if (data = m_root->key)
        {
            return;
        }
        
        if (data < m_root->key)
        {
            if (m_root->leftChild == NULL)
            {
                m_root->leftChild = (TreeNode *)malloc(sizeof(TreeNode));
                m_root->leftChild->rightChild = m_root->leftChild->leftChild = NULL;
                m_root->leftChild->key = data;
                m_root->leftChild->parent = m_root->leftChild;
                return;
            }
            else
            {
                m_root = m_root->leftChild;
            }
        }
        else
        {
            if (m_root->rightChild == NULL)
            {
                m_root->rightChild = (TreeNode *)malloc(sizeof(TreeNode));
                m_root->rightChild->rightChild = m_root->rightChild->leftChild = NULL;
                m_root->rightChild->key = data;
                m_root->rightChild->parent = m_root->rightChild;
                return;
            }
            else
            {
                m_root = m_root->rightChild;
            }
        }
    }

}

void insertNode_Recusive(TreeNode *treeNode, TreeNode* parent, int data)
{
    if (treeNode == NULL)
    {
        TreeNode * newNode = (TreeNode *)malloc(sizeof(TreeNode));
        newNode->key = data;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->parent = parent;
        treeNode = newNode;
    }
    else if (newNode->key < treeNode->key)
    {
        insertNode(treeNode->leftChild, treeNode, newNode);
    }
    else
    {
        insertNode(treeNode->rightChild, TreeNode, newNode);
    }
}

//find the smallest node that is a child of curNode
TreeNode* getSuccessor(TreeNode* curNode)
{
    TreeNode* tempNode = curNode;
    while (tempNode->leftChild)
    {
        tempNode = tempNode->leftChild;
    }

    return tempNode;
}

//remove the reference to curNode from curNode->parent and 
//replace it with newNode.
void replaceNodeInParent(TreeNode *curNode, TreeNode *newNode)
{
    if (curNode->parent)
    {
        if (curNode == curNode->parent->leftChild)
        {
            curNode->parent->leftChild = newNode;
        }
        else
        {
            curNode->parent->rightChild = newNode;
        }
    }

    if (newNode != NULL)
    {
        newNode->parent = curNode->parent;
    }
}

void deleteNode(TreeNode* curNode, int data)
{
    if (data < treeRoot->key)
    {
        deleteNode(treeRoot->leftChild, data);
    }
    else if (data > treeRoot->key)
    {
        deleteNode(treeRoot->rightChild, data);
    }
    //delete the node here
    else
    {
        //if both children are present
        if (curNode->rightChild != NULL && curNode->leftChild != NULL)
        {
            //get the smallest that bigger than curNode
            TreeNode* successor = getSuccessor(curNode->rightChild);
            curNode->key = successor->key;

            //if successor has a child, replace it with successor, 
            //at this point, it can only has a right child.
            //if it has no child, successor->rightChild will be NONE.
            replaceNodeInParent(successor, successor->rightChild);
        }
        else if (curNode->rightChild != NULL)
        {
            replaceNodeInParent(curNode, curNode->rightChild);
        }
        else if (curNode->leftChild != NULL)
        {
            replaceNodeInParent(curNode, curNode->leftChild);
        }
        else
        {
            replaceNodeInParent(curNode, NULL);
        }
    }
}

void inOrderTraversal(TreeNode *curNode)
{
   if (curNode == NULL)
       return;

   inOrderTraversal(curNode->leftChild);
   cout<<curNode->key;
   inOrderTraversal(curNode->rightChild);
}

int main()
{
    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
    
    return 0;
}

