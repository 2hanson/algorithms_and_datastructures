/* double linked list implementation in c.
 * copyright (c) 2012 Hanson Yu.
 *
 * in this implementaion, the first and last element of doubly link can 
 * immediately access (i.e., accessible without travelsal, and usually call
 * head and tail). therefore allow tarversal of the list from the beginning 
 * or end of the list.
 * what's more, any node of a doubly linked list, once gotten, can be used to 
 * begin a new traversal of the list, in either direction (towards beginning 
 * or end). from the given node.
 * */

#include <stdio.h>

//link node
typedef struct NODE
{
    struct NODE *pre;
    struct NODE *next;
    int value;
} linkNode;

//doubly link object
typedef struct
{
    linkNode *head;
    linkNode *tail;
}doublyLink;

int main()
{
    doublyLink dlink;
}

