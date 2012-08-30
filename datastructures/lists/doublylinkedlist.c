/* double linked list implementation in c.
 * copyright (c) 2012 Hanson Yu.
 *
 * in this implementaion, the first element of doubly link can 
 * immediately access (i.e., accessible without travelsal, and usually call
 * head). therefore allow tarversal of the list from the beginning of the list.
 * what's more, any node of a doubly linked list, once gotten, can be used to 
 * begin a new traversal of the list, in either direction (towards beginning 
 * or end). from the given node.
 * */

#include <stdio.h>
#include <stdlib.h>

//link node
typedef struct NODE
{
    struct NODE *pre;
    struct NODE *next;
    int value;
} linkNode;

//doubly link object, the head node donot contain
//any value, just a sentinel.
typedef struct
{
    linkNode *head;
}doublyLink;

int dLinkInit(doublyLink *dlink)
{
    dlink->head = (linkNode *)malloc(sizeof(linkNode));
    if (dlink->head == NULL)
        return 0;//false

    dlink->head->pre = NULL;
    
    return 1;
}

//insert at the beginning position. 
int insertBeginning(doublyLink *dlink, int value)
{
    linkNode *newnode = NULL;
    newnode = (linkNode *)malloc(sizeof(linkNode));
    if (newnode == NULL)
        return 0;
    newnode->value = value;
    
    newnode->next = dlink->head->next;
    newnode->pre = dlink->head;
    if (dlink->head->next != NULL)
    {
        dlink->head->next->pre = newnode;
    }
    dlink->head->next = newnode;
    
    return 1;
}

int insertEnd(doublyLink *dlink, int value)
{
    linkNode *newnode = (linkNode *)malloc(sizeof(linkNode));
    if (newnode == NULL)
        return 0;
    newnode->value = value;

    //forward to tail
    linkNode *curnode = dlink->head;
    while (curnode->next != NULL)
    {
        curnode = curnode->next;
    }

    curnode->next = newnode;
    newnode->pre = curnode;
    newnode->next = NULL;
    return 1;
}

int removeNode(doublyLink *dlink, int value)
{
    linkNode *curnode = dlink->head->next;//head contain nothing valuable.

    while (curnode != NULL)
    {
        if (curnode->value == value)
        {
            //
            curnode->pre->next = curnode->next;
            curnode->next->pre = curnode->pre;

            free(curnode);
            return 1;
        }
        else
        {
            curnode = curnode->next;
        }
    }

    return 0;
}

void traversalList(doublyLink *dlink)
{

    linkNode *curnode = dlink->head->next;//head contain nothing valuable.

    while (curnode != NULL)//curnode->next == null,then curnode is tail
    {
        printf("%d\n", curnode->value);
        curnode = curnode->next;
    }
}

int main()
{
    int index = 0;
    doublyLink dlink;
    dLinkInit(&dlink);

    //test
    for (index = 0; index < 3; ++index)
    {
        insertBeginning(&dlink, index);
    }

    traversalList(&dlink);
   
    removeNode(&dlink, 1);

    traversalList(&dlink);
    for (index = 0; index < 3; ++index)
    {
        insertEnd(&dlink, index);
    }
    traversalList(&dlink);
}

