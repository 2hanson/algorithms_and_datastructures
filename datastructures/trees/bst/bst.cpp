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
        else if (currentNode->key < key)
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
    else if (currentNode->key < key)
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
        
        if (data > m_root->key)
        {
            if (m_root->leftChild == NULL)
            {
                m_root->leftChild = (TreeNode *)malloc(sizeof(TreeNode));
                m_root->leftChild->rightChild = m_root->leftChild->leftChild = NULL;
                m_root->leftChild->key = data;

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

                return;
            }
            else
            {
                m_root = m_root->rightChild;
            }
        }
    }

}

void insertNode_Recusive(TreeNode *treeNode, int data)
{
    if (treeNode == NULL)
    {
        TreeNode * newNode = (TreeNode *)malloc(sizeof(TreeNode));
        newNode->key = data;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;

        treeNode = newNode;
    }
    else if (treeNode->key < newNode->key)
    {
        insertNode(treeNode->leftChild, newNode);
    }
    else
    {
        insertNode(treeNode->rightChild, newNode);
    }
}

int main()
{
    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
    
    return 0;
}

