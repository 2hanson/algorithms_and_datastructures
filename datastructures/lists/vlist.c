/*
 * An implementation of vlist, it combines the fast indexing of arrays 
 * with the easy extension of singly linked lists.
 * for example. here is one possible VList holding six elements.
 *
 *      +------+    +------+     +------+
 *      | next | -->| next | --> | next | --> nil
 *      +------+    +------+     +------+
 * nil<-| pre  | <--| pre  | <-- | pre  |
 *      +------+    +------+     +------+
 *      | null |    |   2  |     |  0   |
 *      +------+    +------+     +------+
 *      |   5  |    |   1  |
 *      +------+    +------+
 *      |   4  |
 *      +------+
 *      |   3  |
 *      +------+
 *
 * each column represents a linked list cell containing a fix size of array.
 * the size of array in the nth column from the end is 2^n. in this manner.
 * for a uniformly-randomly chosen position, the expected time to look up that
 * element is O(1), though in the worst case is O(log n). this random access is
 * significantly better than linked list, but in the worst cast is not good as
 * dynamic array.
 *
 * @author Hanson Yu (hangzhong.yu@gmail.com)
 * */
#include <stdlib.h>
#include <stdio.h>

//vlist column
typedef struct BLOCK
{
    struct BLOCK *pre;
    struct BLOCK *next;
    int *elems;
    int elemNum;
    int totalNum;
}vlistBlock;

void vlistInit(vlistBlock *head, int size)
{
    vlistBlock *cur;
    int cursize = 1;
    while (size > 0)
    {
        cur = (vlistBlock *)malloc(sizeof(vlistBlock));
        cur->elems = (int *)malloc(sizeof(cursize));
        
        cur->pre = NULL;
        cur->next = NULL;
        if (size == 1)
        {
            head = cur;
        }
        else
        {
            head->pre = cur;
            cur->next = head;

            head = cur;
        }

        cur->totalNum = cur->elemNum = cursize;
        size -= cursize;
        cursize *= 2;
    }

    //size if negtive num, as an example, size is -1, curcize is 4.
    //they should set elemnum to -1 + 4,
    cur->elemNum = curzise + size; 
}

/* remove the element at the position index.
 * @param elem
 *      the index at which to remove the element.
 * */
void removeFromVlist(vlistBlock *head, int index)
{
}

/*reset the element at the position index.
 * @param elem
 *      the index at which to reset the element.
 * */
void set(int index, int value)
{
    
}

/*get the element at the position index.
 * @param elem
 *      the index at which to look up the element.
 * @param elem
 *      the element at the position.
 * */
int locate(int index, vlistBlock *locBlock)
{
    if (head == NULL)
        return -1;
}

/*add a new element to the end of the array.
 * @param elem
 *      the element to add.
 * */
void add(int value)
{}

int main()
{
    vlistBlock head;

    vlistInit(&head, 1);
    return 0;
}

