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

int main()
{
    TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
    
    return 0;
}

